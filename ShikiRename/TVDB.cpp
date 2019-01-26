#include "TVDB.h"

TVDB::TVDB()
{
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkReply(QNetworkReply*)));
	requestAuth();
}

TVDB::~TVDB()
{
}

/**
 * Sets the language we request our data in.
 *
 * @param lang Short name of the language
 */
void TVDB::setRequestLanguage(QString lang) {
	requestLanguage = lang;
}

/**
 * Returns all available languages on TheTVDB.com.
 *
 * @return A list of all available languages on TheTVDB.com
 */
std::list<std::pair<QString, QString>> TVDB::getLanguages() {
	return tvdbLanguages;
}

/**
 * Returns the received episode data for the most recently requested series.
 *
 * @return A list of all available languages on TheTVDB.com
 */
QJsonArray TVDB::getEpisodeData() {
	return episodeData;
}

/**
 * Adds our auth token to the given request header.
 *
 * @param request The network request the auth token is going to be added to
 */
void TVDB::authorizeRequest(QNetworkRequest* request) {
	request->setRawHeader(QByteArray("Authorization"), QByteArray("Bearer " + tvdbAuthToken));
}

/**
 * Sends a network request for an authorization token.
 */
void TVDB::requestAuth() {
	QJsonObject json
	{
		{"apikey","2323B61F3A9DA8C8"},
		{"username","elpingu42"},
		{"userkey","52EB4C6A3C24B288"}
	};

	QUrl url("https://api.thetvdb.com/login");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	manager->post(request, QJsonDocument(json).toJson());

	tvdbAuthTimer = new QTimer(this);
	tvdbAuthTimer->setSingleShot(true);
	tvdbAuthTimer->start(TVDB_TIMEOUT);
	connect(tvdbAuthTimer, SIGNAL(timeout()), this, SLOT(authTimeout()));
}

/**
 * Notifies the user about TVDB being unavailable due to the service being unresponsive.
 */
void TVDB::authTimeout() {
	tvdbAuthTimer->stop();
	if (tvdbAuthToken.isNull()) {
		qDebug() << "TVDB - Authentification timed out.";
		QMessageBox errorDialog_tvdbAuthFailed;
		errorDialog_tvdbAuthFailed.setWindowTitle("Authentication timeout");
		errorDialog_tvdbAuthFailed.setText("<b>Failed to connect to TheTVDB.com.</b>");
		errorDialog_tvdbAuthFailed.setInformativeText(QString("Episode names won't be available, as TheTVDB.com appears to be unresponsive."));
		errorDialog_tvdbAuthFailed.setIcon(QMessageBox::Warning);
		errorDialog_tvdbAuthFailed.exec();
		emit authTimeoutSignal();
	}
}

/**
 * Checks if we have an auth token. (Does not actually check if the service is still reachable and that's probably bad.)
 *
 * @return true if our auth token appears to be valid, else false.
 */
bool TVDB::isAvailable() {
	qDebug() << "TVDB - Checking TheTVDB.com availability";
	if (!tvdbAuthToken.isNull() && !tvdbAuthToken.isEmpty()) {
		qDebug() << "TVDB - TheTVDB.com is available";
		return true;
	}
	qDebug() << "TVDB - TheTVDB.com is unavailable";
	return false;
}

/**
 * Sends a network request for all available languages.
 */
void TVDB::requestLanguages() {
	qDebug() << "TVDB - Requesting languages";
	if (!isAvailable())
		return;

	QUrl url("https://api.thetvdb.com/languages");
	QNetworkRequest request(url);
	authorizeRequest(&request);
	manager->get(request);
}

/**
 * Sends a network request for all series matching the given name.
 *
 * @param name Substring to search for
 */
void TVDB::requestsSeries(QString name) {
	qDebug() << "TVDB - Requesting series data for" << name;
	if (!isAvailable())
		return;

	if (!name.isNull() && !name.isEmpty()) {
		QUrl url("https://api.thetvdb.com/search/series");
		QUrlQuery query;
		query.addQueryItem("name", name);
		url.setQuery(query);
		QNetworkRequest request(url);
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
		authorizeRequest(&request);
		request.setRawHeader(QByteArray("Accept-Language"), requestLanguage.toLocal8Bit());
		manager->get(request);
	}
}

/**
 * Sends a network request for all episodes of a given series.
 *
 * @param seriesId ID of the series
 * @param page Reply page number. TVDB returns 100 results per page.
 */
void TVDB::requestEpisodes(int seriesId, int page) {
	if (!isAvailable())
		return;

	QUrl url("https://api.thetvdb.com/series/" + QString::number(seriesId) + "/episodes/query");
	QUrlQuery query;
	query.addQueryItem("page", QString::number(page));
	url.setQuery(query);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	authorizeRequest(&request);
	request.setRawHeader(QByteArray("Accept-Language"), requestLanguage.toLocal8Bit());
	manager->get(request);
}

/**
 * Handles the incoming network replies to issued requests
 *
 * @param reply The received reply from TVDB
 */
void TVDB::handleNetworkReply(QNetworkReply* reply) {
	qDebug() << "TVDB - Handling network reply";
	std::string requestUrl = reply->request().url().toString().toStdString();
	std::regex rgx_replyType(R"(api\.thetvdb\.com\/(?:\w+\/)?(?:\d+\/)?(\w+))");
	std::smatch match_replyType;
	QString replyType;

	if (std::regex_search(requestUrl, match_replyType, rgx_replyType)) {
		replyType = QString::fromStdString(match_replyType.str(1));
	}
	QJsonObject json = QJsonDocument::fromJson(reply->readAll()).object();
	qDebug() << "TVDB - Received data:\n" << json;

	if (replyType == "login") {
		tvdbAuthToken = json.value("token").toVariant().toByteArray();
		if (!tvdbAuthToken.isEmpty() && !tvdbAuthToken.isNull()) {
			tvdbAuthTimer->stop();
			qDebug() << "TVDB - Login confirmed";
			emit loggedIn();
		}
	}
	else if (replyType == "languages") {
		QJsonArray data = json.value("data").toArray();
		for (auto item : data) {
			QJsonObject jo = item.toObject();
			std::pair<QString, QString> lang_name = std::make_pair(jo.value("englishName").toString(), jo.value("abbreviation").toString());
			tvdbLanguages.push_back(lang_name);
		}
		tvdbLanguages.sort();
		QStringList displayNames;
		for (auto item : tvdbLanguages) {
			displayNames.append(item.first);
		}
		emit receivedLanguageList(displayNames);
	}
	else if (replyType == "series") {
		QJsonArray data = json.value("data").toArray();
		if (!data.isEmpty()) {
			emit openDialogSeriesSelection(data);
		}
		else {
			QMessageBox errorDialog_seriesNotFound;
			errorDialog_seriesNotFound.setWindowTitle("Series not found");
			errorDialog_seriesNotFound.setText("<b>Series search on TVDB returned empty.</b>");
			errorDialog_seriesNotFound.setInformativeText(QString("Episode names won't be available.\nTheTVDB.com reports: \"") % json.value("Error").toString() % QChar('"'));
			errorDialog_seriesNotFound.setIcon(QMessageBox::Warning);
			errorDialog_seriesNotFound.exec();
		}
	}
	else if (replyType == "episodes") {
		QJsonArray data = json.value("data").toArray();
		int seasonId = -1;
		int page = -1;
		std::regex rgx_seasonId_page(R"(series\/(\d+)\/episodes\/query\?page\=(\d+))");
		std::smatch match_seasonId_page;

		if (std::regex_search(requestUrl, match_seasonId_page, rgx_seasonId_page)) {
			seasonId = std::stoi(match_seasonId_page.str(1));
			page = std::stoi(match_seasonId_page.str(2));
		}
		if (episodeData.empty() || page == 1) {
			episodeData = data;
		}
		else {
			for (auto item : data) {
				episodeData.append(item);
			}
		}
		if (episodeData.count() % 100 == 0) {
			this->requestEpisodes(seasonId, page + 1);
		}
		else {
			qDebug() << "TVDB - Finished receiving episode data";
			emit episodeDataReceived();
		}
	}
}
