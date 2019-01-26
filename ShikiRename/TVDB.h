#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <regex>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTimer>
#include <QMessageBox>
#include <QUrlQuery>
#include <QString>
#include <QStringBuilder>

class TVDB : public QObject
{
	Q_OBJECT

public:
	TVDB();
	~TVDB();
	void setRequestLanguage(QString lang);
	std::list<std::pair<QString, QString>> getLanguages();
	QJsonArray getEpisodeData();
	void authorizeRequest(QNetworkRequest *request);
	void requestAuth();
	bool isAvailable();
	void requestLanguages();
	void requestsSeries(QString name);
	void requestEpisodes(int seriesId, int page);

signals:
	void receivedSeriesData(QJsonArray);
	void receivedLanguageList(QStringList);
	void authTimeoutSignal();
	void receivedAuthToken();
	void receivedEpisodesData();

private slots:
	void authTimeout();
	void handleNetworkReply(QNetworkReply* reply);

private:
	const int TVDB_TIMEOUT = 20000;	//ms
	QNetworkAccessManager *manager;
	QByteArray tvdbAuthToken;
	QTimer *tvdbAuthTimer;
	std::list<std::pair<QString, QString>> tvdbLanguages;
	QString requestLanguage;
	QJsonArray episodeData;
};
