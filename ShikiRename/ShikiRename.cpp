#include "ShikiRename.h"
#include "ui_ShikiRename.h"
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QMutableListIterator>
#include <QUrlQuery>
#include <regex>
#include <QtNetwork/QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QtNetwork/QNetworkReply>
#include <QTimer>
#include <QList>
#include <QMessageBox>
#include <QWindowStateChangeEvent>

ShikiRename::ShikiRename(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ShikiRenameClass)
{
	ui->setupUi(this);
	ui->tab_2_gridLayout->setGeometry(ui->tab_2->geometry());

	//Filename lists
	ui->currentList->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui->renamePreview->setSelectionMode(QAbstractItemView::NoSelection);

	invalidFnCharset_win = QString(R"(\/:*?"<>|)");
	QRegExp rgx_validFnCharset_win = QRegExp(QString("[^") % QRegExp::escape(invalidFnCharset_win) % QString("]+"));
	QRegExpValidator* WIN_INVALID_FN = new QRegExpValidator(rgx_validFnCharset_win, this);

	//TAB1
	ui->editRemoveRight->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editRemoveLeft->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editReplace2->setValidator(WIN_INVALID_FN);
	ui->editInsert1->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editInsert2->setValidator(WIN_INVALID_FN);
	ui->editRemoveAt1->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editRemoveAt2->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editPrefix->setValidator(WIN_INVALID_FN);
	ui->editSuffix->setValidator(WIN_INVALID_FN);
	ui->editNumIdx->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editNumInitV->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editNumInc->setValidator(new QIntValidator(0, MAX_INT, this));
	ui->editNumDigits->setValidator(new QIntValidator(1, MAX_INT, this));

	//TAB2
	ui->editCustomFileName->setText(DEFAULT_MEDIA_FILENAME_STRUCTURE);
	ui->editCustomFileName->setEnabled(false);
	ui->editCustomFileName->setToolTip(
		QString("<p>Available tags:</p>")
		% QString("<b>&lt;NAME&gt;</b> - Name of the series")
		% QString("<br><b>&lt;SEASON PREFIX&gt;</b> - Prefix for season numbers")
		% QString("<br><b>&lt;SEASON&gt;</b> - Season numbers")
		% QString("<br><b>&lt;EPISODE PREFIX&gt;</b> - Prefix for episode numbers")
		% QString("<br><b>&lt;EPISODE&gt;</b> - Episode numbers")
		% QString("<br><b>&lt;EPISODE NAME&gt;</b> - Name of the episodes (provided by the selected source)")
		% QString("<br><b>&lt;YEAR&gt;</b> - Year the series (or season) started")
		% QString("<br><b>&lt;LANGUAGE&gt;</b> - Primary language of the release, possibly subtitle language if important (e.g. <i>German</i> or <i>Japanese Dubbed German Subbed</i> or <i>JAP-Dub GER-Sub</i>)")
		% QString("<br><b>&lt;AUDIO&gt;</b> - Primary audio codec (e.g. <i>DTS</i> or <i>AC3</i>)")
		% QString("<br><b>&lt;RESOLUTION&gt;</b> - Video resolution (e.g. <i>1080p</i> or <i>720p</i>)")
		% QString("<br><b>&lt;SOURCE&gt;</b> - Primary source of the release (usually refers to video source) (e.g. <i>BluRay</i> or <i>HDDVD</i>)")
		% QString("<br><b>&lt;VIDEO&gt;</b> - Used video codec (e.g. <i>x264</i> or <i>XViD</i>)")
		% QString("<br><b>&lt;SCENE GROUP&gt;</b> - The scene group providing this release (obviously refers to pirated copies)"));
	ui->editName->setValidator(WIN_INVALID_FN);
	ui->comboEpisodeNameLang->addItem("");
	ui->editSeriesNrPrefix->setValidator(WIN_INVALID_FN);
	ui->editSeriesNrDigits->setValidator(new QIntValidator(1, MAX_INT, this));
	ui->editEpisodeNrPrefix->setValidator(WIN_INVALID_FN);
	ui->editEpisodeNrDigits->setValidator(new QIntValidator(1, MAX_INT, this));
	ui->editYear->setValidator(WIN_INVALID_FN);
	ui->editLang->setValidator(WIN_INVALID_FN);
	ui->editAudio->setValidator(WIN_INVALID_FN);
	ui->editResolution->setValidator(WIN_INVALID_FN);
	ui->editSource->setValidator(WIN_INVALID_FN);
	ui->editVideo->setValidator(WIN_INVALID_FN);
	ui->editSceneGrp->setValidator(WIN_INVALID_FN);

	//Menubar
	ui->actionUndo->setEnabled(false);
	ui->actionRedo->setEnabled(false);
	ui->actionUndo->setShortcut(tr("CTRL+Z"));
	ui->actionRedo->setShortcut(tr("CTRL+Y"));

	//Network requests
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkReply(QNetworkReply*)));
	this->tvdbAuth();

	//Don't search for every character input, but wait till the user stops typing.
	tvdbSearchDelayTimer = new QTimer(this);
	tvdbSearchDelayTimer->setSingleShot(true);
	connect(tvdbSearchDelayTimer, &QTimer::timeout, this, [this] { tvdbFindSeries(input_vid_name); });	//https://stackoverflow.com/a/22411267

	seriesSelectionDialog = new SeriesSelectionDialog(this);
	connect(seriesSelectionDialog, SIGNAL(closed(int, QString)), this, SLOT(on_seriesSelectedDialog_closed(int, QString)));
	
}
ShikiRename::~ShikiRename()
{
	delete ui;
}

void ShikiRename::resizeEvent(QResizeEvent *event) {
	this->fixGridLayoutWidth();
}
void ShikiRename::changeEvent(QEvent *event) {
	if (event->type() == QEvent::WindowStateChange && this->windowState() == Qt::WindowMaximized) {
		this->fixGridLayoutWidth();
	}
}
void ShikiRename::on_tabWidget_currentChanged(const int &index) {
	this->fixGridLayoutWidth();
	this->previewRename();
}
void ShikiRename::fixGridLayoutWidth() {
	QRect newSize1 = ui->tab_1->geometry();
	newSize1.setHeight(ui->layoutWidget->height());
	ui->layoutWidget->setGeometry(newSize1);
	QRect newSize2 = ui->tab_2->geometry();
	newSize2.setHeight(ui->gridLayoutWidget->height());
	ui->gridLayoutWidget->setGeometry(newSize2);
}

void ShikiRename::on_editRemoveLeft_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_remLeft = ui->editRemoveLeft->placeholderText().toInt();
	else
		input_remLeft = arg1.toInt();
	this->previewRename();
}
void ShikiRename::on_editRemoveRight_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_remRight = ui->editRemoveRight->placeholderText().toInt();
	else
		input_remRight = arg1.toInt();
	this->previewRename();
}
void ShikiRename::on_editReplace1_textChanged(const QString &arg1)
{
	input_replace1 = arg1;
	this->previewRename();
}
void ShikiRename::on_editReplace2_textChanged(const QString &arg1)
{
	input_replace2 = arg1;
	if (!input_replace1.isEmpty() && !input_replace1.isNull())
		this->previewRename();
}
void ShikiRename::on_editInsert1_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_insert_idx = -1;
	else
		input_insert_idx = arg1.toInt();
	if (!input_insert_string.isEmpty() && !input_insert_string.isNull())
		this->previewRename();
}
void ShikiRename::on_editInsert2_textChanged(const QString &arg1)
{
	input_insert_string = arg1;
	if (input_insert_idx >= 0)
		this->previewRename();
}
void ShikiRename::on_editRemoveAt1_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_removeAt_amount = ui->editRemoveAt1->placeholderText().toInt();
	else
		input_removeAt_amount = arg1.toInt();
	if (input_removeAt_idx >= 0)
		this->previewRename();
}
void ShikiRename::on_editRemoveAt2_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_removeAt_idx = -1;
	else
		input_removeAt_idx = arg1.toInt();
	if (input_removeAt_amount > 0)
		this->previewRename();
}
void ShikiRename::on_editPrefix_textChanged(const QString &arg1)
{
	input_prefix = arg1;
	this->previewRename();
}
void ShikiRename::on_editSuffix_textChanged(const QString &arg1)
{
	input_suffix = arg1;
	this->previewRename();
}
void ShikiRename::on_editNumIdx_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_num_idx = -1;
	else
		input_num_idx = arg1.toInt();
	if (input_num_init >= 0 && input_num_digits > 0 && input_num_inc >= 0)
		this->previewRename();
}
void ShikiRename::on_editNumInc_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_num_inc = ui->editNumInc->placeholderText().toInt();
	else
		input_num_inc = arg1.toInt();
	if (input_num_idx >= 0 && input_num_digits > 0 && input_num_init >= 0)
		this->previewRename();
}
void ShikiRename::on_editNumInitV_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_num_init = ui->editNumInitV->placeholderText().toInt();
	else
		input_num_init = arg1.toInt();
	if (input_num_idx >= 0 && input_num_inc >= 0 && input_num_digits > 0)
		this->previewRename();
}
void ShikiRename::on_editNumDigits_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_num_digits = ui->editNumDigits->placeholderText().toInt();
	else
		input_num_digits = arg1.toInt();
	if (input_num_idx >= 0 && input_num_init >= 0 && input_num_inc >= 0)
		this->previewRename();
}

void ShikiRename::on_buttonCustomFileNameReset_clicked() {
	ui->editCustomFileName->setText(DEFAULT_MEDIA_FILENAME_STRUCTURE);
}
void ShikiRename::on_checkboxCustomFileName_toggled(const bool &checked)
{
	ui->editCustomFileName->setEnabled(checked);
}
void ShikiRename::on_editCustomFileName_textChanged(const QString &arg1)
{
	input_vid_customFileNameRaw = arg1;

	this->previewRename();
}
void ShikiRename::on_editName_textChanged(const QString &arg1)
{
	input_vid_name = arg1;

	if (onlineDbAvailable() && !ongoingSeriesSelection) {
		tvdbSearchDelayTimer->start(1000);
	}
	else {
		this->previewRename();
	}
}
void ShikiRename::on_editSeriesNrPrefix_textChanged(const QString &arg1)
{
	if (!arg1.isEmpty()) {
		input_vid_sPrefix = arg1;
	}
	else {
		input_vid_sPrefix = ui->editSeriesNrPrefix->placeholderText();
	}
	this->previewRename();
}
void ShikiRename::on_editSeriesNrDigits_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_vid_sDigits = ui->editSeriesNrDigits->placeholderText().toInt();
	else
		input_vid_sDigits = arg1.toInt();
	this->previewRename();
}
void ShikiRename::on_editEpisodeNrPrefix_textChanged(const QString &arg1)
{
	if (!arg1.isEmpty()) {
		input_vid_ePrefix = arg1;
	}
	else {
		input_vid_ePrefix = ui->editEpisodeNrPrefix->placeholderText();
	}
	this->previewRename();
}
void ShikiRename::on_editEpisodeNrDigits_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_vid_eDigits = ui->editEpisodeNrDigits->placeholderText().toInt();
	else
		input_vid_eDigits = arg1.toInt();
	this->previewRename();
}
void ShikiRename::on_comboEpisodeNameSrc_currentIndexChanged(const int &index)
{
	input_vid_eNameSrc = MetaDB(index);
	switch (index) {
	case 1:
		if (onlineDbAvailable()) {
			tvdbSearchDelayTimer->start(1000);
			break;	//else default
		}
	case 0:
	default:
		this->previewRename();
	}
}
void ShikiRename::on_comboEpisodeNameLang_currentIndexChanged(const int &index)
{
	QString selectedLang = ui->comboEpisodeNameLang->itemText(index);
	for (auto item : tvdbLanguages) {
		if (item.first == selectedLang && input_vid_eNameLang != item.second) {	//long name equals selected long name & short name is not already selected
			input_vid_eNameLang = item.second;
			if (onlineDbAvailable()) {
				tvdbSearchDelayTimer->start(1000);
			}
			break;
		}
	}
}
void ShikiRename::on_editYear_textChanged(const QString &arg1)
{
	input_vid_releaseYear = arg1;
	this->previewRename();
}
void ShikiRename::on_editLang_textChanged(const QString &arg1)
{
	input_vid_language = arg1;
	this->previewRename();
}
void ShikiRename::on_editAudio_textChanged(const QString &arg1)
{
	input_vid_audio = arg1;
	this->previewRename();
}
void ShikiRename::on_editResolution_textChanged(const QString &arg1)
{
	input_vid_videoResolution = arg1;
	this->previewRename();
}
void ShikiRename::on_editVideo_textChanged(const QString &arg1)
{
	input_vid_video = arg1;
	this->previewRename();
}
void ShikiRename::on_editSource_textChanged(const QString &arg1)
{
	input_vid_src = arg1;
	this->previewRename();
}
void ShikiRename::on_editSceneGrp_textChanged(const QString &arg1)
{
	input_vid_sceneGrp = arg1;
	this->previewRename();
}

void ShikiRename::on_checkboxOnlySelected_toggled(const bool &checked)
{
	input_onlySelected = checked;
	this->previewRename();
}
void ShikiRename::on_currentList_itemSelectionChanged()
{
	QList<QListWidgetItem *> selectedItems = ui->currentList->selectedItems();
	selectedFilenames.clear();
	for (auto item : selectedItems) {
		selectedFilenames.append(item->text());
	}
	if (input_onlySelected) {
		this->previewRename();
	}
}
bool ShikiRename::isSelectedInList(QString filename) {
	return (!input_onlySelected || input_onlySelected && selectedFilenames.contains(filename));
}

void ShikiRename::open(QDir dir) {
	dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	infoList = dir.entryInfoList();

	ui->renamePreview->clear();
	ui->currentList->clear();

	for (int i = 0; i < infoList.count(); i++) {
		QString fn = infoList.at(i).fileName();
		ui->renamePreview->addItem(fn);
		ui->currentList->addItem(fn);
	}
	previewRename();
}
void ShikiRename::on_actionOpen_triggered()
{
	QDir dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly);

	if (dir.path() != ".") {
		this->open(dir);
	}
	else {
		qDebug() << "Current directory selected, assuming dialog has been canceled.";
	}
}
void ShikiRename::on_actionUndo_triggered()
{
	if (hist_undo.size() <= 0)
		return;

	int curid = std::get<0>(hist_undo.back());

	for (int i = hist_undo.size(); i > 0 && std::get<0>(hist_undo.back()) == curid; i--) {
		if (!QFile::rename(std::get<2>(hist_undo.back()), std::get<1>(hist_undo.back()))) {
		}
		else
		{
			hist_redo.push_back(hist_undo.back());
			if (!ui->actionRedo->isEnabled()) {
				ui->actionRedo->setEnabled(true);
			}
			hist_undo.pop_back();
			if (hist_undo.size() <= 0) {
				ui->actionUndo->setEnabled(false);
			}
		}
	}

	QDir dir = QDir(infoList.first().absolutePath() + QString("\\"));
	this->open(dir);
	this->previewRename();
}
void ShikiRename::on_actionRedo_triggered()
{
	if (hist_redo.size() <= 0)
		return;
	int curid = std::get<0>(hist_redo.back());
	for (int i = hist_redo.size(); i > 0 && std::get<0>(hist_redo.back()) == curid; i--) {
		if (!QFile::rename(std::get<1>(hist_redo.back()), std::get<2>(hist_redo.back()))) {
		}
		else
		{
			hist_undo.push_back(hist_redo.back());
			if (!ui->actionUndo->isEnabled()) {
				ui->actionUndo->setEnabled(true);
			}
			hist_redo.pop_back();
			if (hist_redo.size() <= 0) {
				ui->actionRedo->setEnabled(false);
			}
		}
	}

	QDir dir = QDir(infoList.first().absolutePath() + QString("\\"));
	this->open(dir);
	this->previewRename();
}
void ShikiRename::addToHistory(int id, QString o, QString n) {
	hist_undo.push_back(std::make_tuple(id, o, n));
}
void ShikiRename::previewRename() {
	QStringList previewFilenames;
	QMutableListIterator<QFileInfo> it(infoList);
	int cur_num = input_num_init;							//keeps track of the consecutive numeration

	while (it.hasNext())									//iterates through every file
	{
		QString v = it.next().completeBaseName();			//v = original filename without file extension
		if (isSelectedInList(it.value().fileName())) {		//if enabled, checks if the file has been selected.
			if (ui->tabWidget->currentIndex() == 0) {
				//Remove left
				if (input_remLeft > 0)
					v = v.remove(0, input_remLeft);

				//Remove right
				if (input_remRight > 0)
					v = v.remove(v.length() - input_remRight, input_remRight);

				//Replace x with y
				if (!input_replace1.isNull() && !input_replace1.isEmpty()) {
					if (input_replace2.isNull())
						input_replace2 = "";

					for (int idx = v.length(); (idx = v.lastIndexOf(input_replace1, idx - 1)) != -1;)
					{
						v = v.replace(idx, input_replace1.length(), input_replace2);
						if (idx == 0) break;
					}
				}

				//Insert at idx a string
				if (input_insert_idx >= 0 && !input_insert_string.isEmpty() && !input_insert_string.isNull() && input_insert_idx <= v.length())
					v.insert(input_insert_idx, input_insert_string);

				//Remove x characters after index y
				if (input_removeAt_amount > 0 && input_removeAt_idx >= 0 && input_removeAt_idx <= v.length())
					v = v.left(input_removeAt_idx) + v.right(v.length() - input_removeAt_idx - input_removeAt_amount);

				//Prefix
				if (!input_prefix.isNull())
					v = v.prepend(input_prefix);

				//Suffix
				if (!input_suffix.isNull())
					v = v.append(input_suffix);

				//Consecutive numeration
				if (input_num_idx >= 0 && input_num_init >= 0 && input_num_inc >= 0 && input_num_digits > 0) {
					QString num_s = this->zerofy(QString::number(cur_num), input_num_digits);
					v = v.insert(input_num_idx, num_s);
					cur_num = cur_num + input_num_inc;
				}

			}
			else if (ui->tabWidget->currentIndex() == 1) {
				QRegExp rgx_invalidFnCharset_win = QRegExp(QString("[") % QRegExp::escape(invalidFnCharset_win) % QString("]+"));
				std::pair<int, int> s_e = this->searchSeasonAndEpisode(v);
				QString episodeName;
				if (!episodeData.empty() && !episodeData.first().toObject().value("episodeName").isUndefined()) {
					for (auto item : episodeData) {
						QJsonObject jo = item.toObject();
						if (jo.value("airedSeason").toInt() == s_e.first && jo.value("airedEpisodeNumber").toInt() == s_e.second) {
							episodeName = jo.value("episodeName").toString();
							episodeName.remove(rgx_invalidFnCharset_win);
							break;
						}
					}
				}

				v = input_vid_customFileNameRaw;
				v.replace(QString("<NAME>"), input_vid_name)
					.replace(QString(R"(<SEASON PREFIX>)"), input_vid_sPrefix)
					.replace(QString(R"(<SEASON>)"), this->zerofy(QString::number(s_e.first), input_vid_sDigits))
					.replace(QString(R"(<EPISODE PREFIX>)"), input_vid_ePrefix)
					.replace(QString(R"(<EPISODE>)"), this->zerofy(QString::number(s_e.second), input_vid_eDigits))
					.replace(QString(R"(<EPISODE NAME>)"), episodeName)
					.replace(QString(R"(<YEAR>)"), input_vid_releaseYear)
					.replace(QString(R"(<LANGUAGE>)"), input_vid_language)
					.replace(QString(R"(<AUDIO>)"), input_vid_audio)
					.replace(QString(R"(<RESOLUTION>)"), input_vid_videoResolution)
					.replace(QString(R"(<SOURCE>)"), input_vid_src)
					.replace(QString(R"(<VIDEO>)"), input_vid_video)
					.replace(QString(R"(<SCENE GROUP>)"), input_vid_sceneGrp);
				v.remove(rgx_invalidFnCharset_win);
			}
		}
		previewFilenames.append(v % QChar('.') % it.value().suffix());
	}

	ui->renamePreview->clear();
	ui->renamePreview->insertItems(0, previewFilenames);
}
void ShikiRename::on_confirmButton_clicked()
{
	QMessageBox errorDialog_renameFailed;
	errorDialog_renameFailed.setText("<b>Rename failed!</b>");
	errorDialog_renameFailed.setIcon(QMessageBox::Critical);
	errorDialog_renameFailed.setWindowTitle(this->windowTitle() % " - Rename failed!");

	int actionHistoryId;		//Allows grouping of actions, so later on we can undo and redo all actions triggered by this button press.
	if (hist_undo.size() > 0)
	{
		actionHistoryId = std::get<0>(hist_undo.back()) + 1;	//find unused id
	}
	else
	{
		actionHistoryId = 0;
	}

	QStringList targetNames;
	for (int i = 0; i < ui->renamePreview->count(); i++) {
		targetNames.append(ui->renamePreview->item(i)->text());
	}
	targetNames.sort();

	bool dupe_found = false;
	QList<QColor> appropiateTextColors = {Qt::red, Qt::blue, Qt::green, Qt::cyan, Qt::magenta, Qt::darkYellow};
	int appropiateTextColorIterator = 0;
	for (int i = 0; i < targetNames.count() - 1; i++) {
		if (targetNames.at(i).compare(targetNames.at(i + 1), Qt::CaseInsensitive) == 0) {							//check if there are duplicate filenames
			dupe_found = true;																							//there are dupes, so we won't rename
			QList<QListWidgetItem *> li = ui->renamePreview->findItems(targetNames.at(i), Qt::MatchFixedString);			//get all dupe items in preview
			for (auto item : li)
				item->setTextColor(appropiateTextColors.at(appropiateTextColorIterator%appropiateTextColors.length()));		//mark dupes in preview
			appropiateTextColorIterator++;
		}
	}
	if (dupe_found) {
		errorDialog_renameFailed.setInformativeText("Rename failed because duplicate filenames have been found. Check your preview list and resolve any marked conflicts.");
		errorDialog_renameFailed.exec();
		return;
	}

	for (int i = 0; i < ui->renamePreview->count(); i++) {
		if (isSelectedInList(ui->currentList->item(i)->text())) {
			QString oldName = infoList.at(i).absoluteFilePath();														//original file
			QString newName = infoList.at(i).absolutePath() % QString("\\") % ui->renamePreview->item(i)->text();		//new file

			if (!QFile::rename(oldName, newName)) {		//rename file
				errorDialog_renameFailed.setInformativeText("Failed to rename \"" % oldName % "\" to \"" % newName % "\"!");
				errorDialog_renameFailed.exec();
			}
			else
			{
				this->addToHistory(actionHistoryId, oldName, newName);													//add rename to history
				if (!ui->actionUndo->isEnabled()) {
					ui->actionUndo->setEnabled(true);																	//activate undo button in menu bar
				}
			}
		}
	}

	QDir dir = QDir(infoList.first().absolutePath() + QString("\\"));
	this->open(dir);	//reload everything so it shows the new current state of the files
	this->previewRename();
}

QString ShikiRename::zerofy(QString string, int digits) {
	return QString(digits - string.length(), '0') + string;
}
std::pair<int, int> ShikiRename::searchSeasonAndEpisode(QString filename_qs) {
	std::string filename = filename_qs.toStdString();
	std::regex rgx(R"([sS][^\d]*0*(\d+)[\s]*[^A-Za-z0-9]*[eE][^\d]*0*(\d+))");
	std::smatch match;
	std::pair<int, int> result;
	if (std::regex_search(filename, match, rgx)) {
		int s = std::stoi(match.str(1));
		int e = std::stoi(match.str(2));
		result = std::make_pair(s, e);
	}
	return result;
}

void ShikiRename::openDialogSeriesSelection(QJsonArray seriesData) {
	seriesSelectionDialog->setData(seriesData);
	seriesSelectionDialog->show();
}
void ShikiRename::on_seriesSelectedDialog_closed(int id, QString name) {
	ongoingSeriesSelection = true;
	ui->editName->setText(name);
	ongoingSeriesSelection = false;
	this->tvdbFindEpisodes(id, 1);
}

void ShikiRename::handleNetworkReply(QNetworkReply* reply) {
	std::string requestUrl = reply->request().url().toString().toStdString();
	std::regex rgx_replyType(R"(api\.thetvdb\.com\/(?:\w+\/)?(?:\d+\/)?(\w+))");
	std::smatch match_replyType;
	QString replyType;

	if (std::regex_search(requestUrl, match_replyType, rgx_replyType)) {
		replyType = QString::fromStdString(match_replyType.str(1));
	}
	QJsonObject json = QJsonDocument::fromJson(reply->readAll()).object();
	qDebug() << "json: " << json;

	if (replyType == "login") {
		tvdbAuthToken = json.value("token").toVariant().toByteArray();
		if (!tvdbAuthToken.isEmpty() && !tvdbAuthToken.isNull()) {
			tvdbAuthTimer->stop();
			ui->comboEpisodeNameSrc->setCurrentIndex(MetaDB::TheTVDB);
			if (ui->comboEpisodeNameLang->count() <= 1) {
				this->tvdbGetLanguages();
			}
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
		for (auto item : tvdbLanguages) {
			ui->comboEpisodeNameLang->addItem(item.first);
		}
	}
	else if (replyType == "series") {
		QJsonArray data = json.value("data").toArray();
		if (!data.isEmpty()) {
			this->openDialogSeriesSelection(data);
		}
		else {
			QMessageBox errorDialog_seriesNotFound;
			errorDialog_seriesNotFound.setText("<b>Series not found!</b>");
			errorDialog_seriesNotFound.setInformativeText(QString("Episode names won't be available.\nTheTVDB.com reports: \"") % json.value("Error").toString() % QChar('"'));
			errorDialog_seriesNotFound.setIcon(QMessageBox::Warning);
			errorDialog_seriesNotFound.setWindowTitle(this->windowTitle() % " - Series not found!");
			errorDialog_seriesNotFound.exec();
		}
	}
	else if (replyType == "episodes") {
		QJsonArray data = json.value("data").toArray();
		if (episodeData.empty()) {
			episodeData = data;
		}
		else {
			for (auto item : data) {
				episodeData.append(item);
			}
		}
		if (episodeData.count() % 100 == 0) {
			std::regex rgx_seasonId_page(R"(series\/(\d+)\/episodes\/query\?page\=(\d+))");
			std::smatch match_seasonId_page;

			if (std::regex_search(requestUrl, match_seasonId_page, rgx_seasonId_page)) {
				int seasonId = std::stoi(match_seasonId_page.str(1));
				int page = std::stoi(match_seasonId_page.str(2)) + 1;
				this->tvdbFindEpisodes(seasonId, page);
			}
		}
		else {
			previewRename();
		}

	}
}
bool ShikiRename::onlineDbAvailable() {
	if (input_vid_eNameSrc == MetaDB::TheTVDB && !tvdbAuthToken.isEmpty() && !tvdbAuthToken.isNull())
		return true;

	qDebug() << "Selected online meta database is not available.";
	return false;
}

void ShikiRename::tvdbAuth() {
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
	tvdbAuthTimer->start(5000);
	connect(tvdbAuthTimer, SIGNAL(timeout()), this, SLOT(tvdbAuthError()));
}
void ShikiRename::tvdbAuthError() {
	tvdbAuthTimer->stop();
	if (tvdbAuthToken.isNull()) {
		qDebug() << "TheTVDB.com Authentification Failure: timed out.";
		ui->comboEpisodeNameSrc->setEnabled(false);
		ui->comboEpisodeNameLang->setEnabled(false);
		ui->comboEpisodeNameSrc->setItemText(1, ui->comboEpisodeNameSrc->itemText(1) + tr(" [CONNECTION FAILED]"));
		ui->comboEpisodeNameLang->setDisabled(true);

		QMessageBox errorDialog_tvdbAuthFailed;
		errorDialog_tvdbAuthFailed.setWindowTitle(this->windowTitle() % " - Authentication timed out!");
		errorDialog_tvdbAuthFailed.setText("<b>Couldn't connect to TheTVDB.com!</b>");
		errorDialog_tvdbAuthFailed.setInformativeText(QString("Episode names won't be available, as TheTVDB.com seems unreachable."));
		errorDialog_tvdbAuthFailed.setIcon(QMessageBox::Warning);
		errorDialog_tvdbAuthFailed.exec();
	}
	this->tvdbGetLanguages();
}
void ShikiRename::tvdbAuthorizeRequest(QNetworkRequest *request) {
	request->setRawHeader(QByteArray("Authorization"), QByteArray("Bearer " + tvdbAuthToken));
}
void ShikiRename::tvdbFindSeries(QString name) {
	tvdbSearchDelayTimer->stop();
	if (!onlineDbAvailable())
		return;

	if (!name.isNull() && !name.isEmpty()) {
		QUrl url("https://api.thetvdb.com/search/series");
		QUrlQuery query;
		query.addQueryItem("name", name);
		url.setQuery(query);
		QNetworkRequest request(url);
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
		tvdbAuthorizeRequest(&request);
		request.setRawHeader(QByteArray("Accept-Language"), input_vid_eNameLang.toLocal8Bit());
		manager->get(request);
	}
}
void ShikiRename::tvdbFindEpisodes(int seriesId, int page) {
	if (!onlineDbAvailable())
		return;

	QUrl url("https://api.thetvdb.com/series/" + QString::number(seriesId) + "/episodes/query");
	QUrlQuery query;
	query.addQueryItem("page", QString::number(page));
	url.setQuery(query);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	tvdbAuthorizeRequest(&request);
	request.setRawHeader(QByteArray("Accept-Language"), input_vid_eNameLang.toLocal8Bit());
	manager->get(request);
}
void ShikiRename::tvdbGetLanguages() {
	if (!onlineDbAvailable())
		return;

	QUrl url("https://api.thetvdb.com/languages");
	QNetworkRequest request(url);
	tvdbAuthorizeRequest(&request);
	manager->get(request);
}