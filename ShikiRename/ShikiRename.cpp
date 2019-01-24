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
#include <QThread>
#include <qtconcurrentrun.h>
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

	ui->buttonOpen->setIcon(QIcon(this->style()->standardIcon(QStyle::SP_DirOpenIcon)));
	connect(ui->buttonOpen, SIGNAL(clicked()), this, SLOT(on_actionOpen_triggered()));
	ui->editDirectory->setPlaceholderText("<directory>");

	//Filename lists
	ui->currentList->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui->renamePreview->setSelectionMode(QAbstractItemView::NoSelection);

	invalidFnCharset_win = QString(R"(\/:*?"<>|)");	//charset of invalid Windows filename characters
	QRegExp rgx_validFnCharset_win = QRegExp(QString("[^") % QRegExp::escape(invalidFnCharset_win) % QString("]+"));
	QRegExpValidator* WIN_INVALID_FN = new QRegExpValidator(rgx_validFnCharset_win, this);

	fileTypes_video = QStringList({ "mkv", "mp4", "avi" });

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
	////Tooltip strings
	QString tt_SNAME = "Name of the series";
	QString tt_EPNSS = "Source to use for episode names";
	QString tt_EPNLS = "Language to use for episode names";
	QString tt_SPREF = "Prefix for season numbers";
	QString tt_SNUMB = "Season numbers";
	QString tt_EPREF = "Prefix for episode numbers";
	QString tt_ENUMB = "Episode numbers";
	QString tt_ENABS = "Absolute episode numbers (Total episodes, not divided into seasons)";
	QString tt_GEPNR = "Tries to find the episode number without a season number. Uses the first found number while ignoring repeating filename patterns.";
	QString tt_ENAME = "Name of the episodes (provided by the selected source)";
	QString tt_RYEAR = "Year the series (or season) started";
	QString tt_SLANG = "Primary language of the release, possibly subtitle language if important (e.g. <i>German</i> or <i>Japanese Dubbed German Subbed</i> or <i>JAP-Dub GER-Sub</i>)";
	QString tt_AUDIO = "Primary audio codec (e.g. <i>DTS</i> or <i>AC3</i>)";
	QString tt_RESOL = "Video resolution (e.g. <i>1080p</i> or <i>720p</i>)";
	QString tt_SOURC = "Primary source of the release (usually refers to video source) (e.g. <i>BluRay</i> or <i>HDDVD</i>)";
	QString tt_VIDEO = "Used video codec (e.g. <i>x264</i> or <i>XViD</i>)";
	QString tt_GROUP = "The scene group providing this release (obviously refers to pirated copies)";
	QString tt_CNAME = QString("Schema of the target file names. Default is setup to work with Plex. <p>Available tags:</p>")
		% QString("<b>&lt;NAME&gt;</b> - ") % tt_SNAME
		% QString("<br><b>&lt;SEASON PREFIX&gt;</b> - ") % tt_SPREF
		% QString("<br><b>&lt;SEASON&gt;</b> - ") % tt_SNUMB
		% QString("<br><b>&lt;EPISODE PREFIX&gt;</b> - ") % tt_EPREF
		% QString("<br><b>&lt;EPISODE&gt;</b> - ") % tt_ENUMB
		% QString("<br><b>&lt;EPISODE ABSOLUTE&gt;</b> - ") % tt_ENABS
		% QString("<br><b>&lt;EPISODE NAME&gt;</b> - ") % tt_ENAME
		% QString("<br><b>&lt;YEAR&gt;</b> - ") % tt_RYEAR
		% QString("<br><b>&lt;LANGUAGE&gt;</b> - ") % tt_SLANG
		% QString("<br><b>&lt;AUDIO&gt;</b> - ") % tt_AUDIO
		% QString("<br><b>&lt;RESOLUTION&gt;</b> - ") % tt_RESOL
		% QString("<br><b>&lt;SOURCE&gt;</b> - ") % tt_SOURC
		% QString("<br><b>&lt;VIDEO&gt;</b> - ") % tt_VIDEO
		% QString("<br><b>&lt;SCENE GROUP&gt;</b> - ") % tt_GROUP;
	////Tooltip setup
	ui->editCustomFileName->setText(DEFAULT_MEDIA_FILENAME_STRUCTURE);
	ui->editCustomFileName->setEnabled(false);
	ui->editCustomFileName->setToolTip(tt_CNAME);
	ui->editName->setValidator(WIN_INVALID_FN);
	ui->editName->setToolTip(tt_SNAME);
	ui->comboEpisodeNameSrc->setToolTip(tt_EPNSS);
	ui->comboEpisodeNameLang->addItem("");
	ui->comboEpisodeNameLang->setToolTip(tt_EPNLS);
	ui->editSeasonNrPrefix->setValidator(WIN_INVALID_FN);
	ui->editSeasonNrPrefix->setToolTip(tt_SPREF);
	ui->editSeasonNrDigits->setValidator(new QIntValidator(1, MAX_INT, this));
	ui->editSeasonNrDigits->setToolTip(tt_SNUMB);
	ui->editEpisodeNrPrefix->setValidator(WIN_INVALID_FN);
	ui->editEpisodeNrPrefix->setToolTip(tt_EPREF);
	ui->editEpisodeNrDigits->setValidator(new QIntValidator(1, MAX_INT, this));
	ui->editEpisodeNrDigits->setToolTip(tt_ENUMB);
	ui->checkboxNoSeason->setToolTip(tt_GEPNR);

	//Menubar
	ui->actionUndo->setEnabled(false);
	ui->actionRedo->setEnabled(false);
	ui->actionUndo->setShortcut(tr("CTRL+Z"));
	ui->actionRedo->setShortcut(tr("CTRL+Y"));
	ui->actionRefresh->setDisabled(true);

	ui->buttonRename->setDisabled(true);

	//Multithread
	connect(&dirWatcherFW, SIGNAL(finished()), this, SLOT(on_actionRefresh_triggered()));	//restarts the directory watcher checking for the next file change

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

	renameConfirmationDialog = new RenameConfirmationDialog(this);

}
ShikiRename::~ShikiRename()
{
	dirWatcher.cancel();
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
void ShikiRename::on_editDirectory_returnPressed()
{
	this->open(QDir::fromNativeSeparators(ui->editDirectory->text()));
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
void ShikiRename::on_editSeasonNrPrefix_textChanged(const QString &arg1)
{
	if (!arg1.isEmpty()) {
		input_vid_sPrefix = arg1;
	}
	else {
		input_vid_sPrefix = ui->editSeasonNrPrefix->placeholderText();
	}
	this->previewRename();
}
void ShikiRename::on_editSeasonNrDigits_textChanged(const QString &arg1)
{
	if (arg1.isEmpty())
		input_vid_sDigits = ui->editSeasonNrDigits->placeholderText().toInt();
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
void ShikiRename::on_checkboxNoSeason_toggled(const bool &checked) {
	input_vid_noSeason = checked;
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
		searchEpisode_startIdx = -1;
		this->previewRename();
	}
}
bool ShikiRename::isSelectedInList(QString filename) {
	return (!input_onlySelected || input_onlySelected && selectedFilenames.contains(filename));
}

void ShikiRename::open(QDir dir) {
	if (!dir.exists()) {
		return;				//TODO maybe, do stuff?
	}
	curDir = dir.absolutePath();
	ui->actionRefresh->setEnabled(true);
	ui->editDirectory->setText(QDir::toNativeSeparators(curDir));

	dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	infoList = dir.entryInfoList();
	ui->renamePreview->clear();
	ui->currentList->clear();
	searchEpisode_startIdx = -1;

	for (int i = 0; i < infoList.count(); i++) {
		QString fn = infoList.at(i).fileName();
		ui->renamePreview->addItem(fn);
		ui->currentList->addItem(fn);
	}

	watchFileChanges();
	previewRename();
}

/**
 * Starts watching the current working directory for any file changes
 */
void ShikiRename::watchFileChanges() {
	if (!mediaInfoCache.isEmpty()) {
		for (auto item : mediaInfoCache.keys()) {
			if (item.startsWith(curDir)) {
				qDebug() << "Removing" << item << "from mediaInfoCache.";
				mediaInfoCache.remove(item);
			}
		}
	}
	if (!dirWatcherFW.isFinished()) {
		qDebug() << "Aborting current directory watch...";
		dirWatcher.cancel();
	}
	wchar_t* winDir = new wchar_t[curDir.length() + 1];
	curDir.toWCharArray(winDir);	//convert path to wchar
	winDir[curDir.length()] = 0;	//null termination
	QFuture<int> future = QtConcurrent::run(&this->dirWatcher, &DirWatcher::watchDirectory, winDir); //starts the DirWatcher in another thread
	dirWatcherFW.setFuture(future);
}

void ShikiRename::on_actionOpen_triggered() {
	QString openDir;
	if (!curDir.isEmpty())
		openDir = curDir;
	else
		openDir = QDir::homePath();

	QDir dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"), openDir, QFileDialog::ShowDirsOnly);

	if (dir.path() != ".") {
		this->open(dir);
	}
	else {
		qDebug() << "Selection is already the current working directory.";
	}
}
void ShikiRename::on_actionRefresh_triggered() {
	this->open(curDir);
}
void ShikiRename::on_actionQuit_triggered() {
	QCoreApplication::quit();
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
	QMutableListIterator<QFileInfo> it(infoList);
	int cur_num = input_num_init;							//keeps track of our current number for the consecutive numeration operation
	ui->renamePreview->clear();

	while (it.hasNext())									//iterates through every file
	{
		bool selected = false;
		QString v = it.next().completeBaseName();			//v = original filename without file extension
		if (isSelectedInList(it.value().fileName())) {		//if enabled, checks if the file has been selected.
			QString filePath = it.value().absoluteFilePath();

			selected = true;
			if (ui->tabWidget->currentIndex() == 0) {
				//Remove left operation
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
				ShikiRename::cacheMediaInfo(it.value());
				QRegExp rgx_invalidFnCharset_win = QRegExp(QString("[") % QRegExp::escape(invalidFnCharset_win) % QString("]+"));
				std::pair<int, int> s_e = this->searchSeasonAndEpisode(v);
				int season;
				int ep;
				if (!input_vid_noSeason) {
					season = s_e.first;
					ep = s_e.second;
				}
				else {
					season = 1;
					ep = this->searchEpisode(v);
				}

				QString episodeName;
				QString episodeAbsolute;
				QString episodeYear;
				if (!episodeData.empty() && !episodeData.first().toObject().value("episodeName").isUndefined()) {
					for (auto item : episodeData) {
						QJsonObject jo = item.toObject();
						if (jo.value("airedSeason").toInt() == season && jo.value("airedEpisodeNumber").toInt() == ep) {
							episodeName = jo.value("episodeName").toString();
							episodeName.remove(rgx_invalidFnCharset_win);	//probably redundant because we're tidying it up again at the end anyway
							episodeAbsolute = QString::number(jo.value("absoluteNumber").toInt());
							episodeYear = jo.value("firstAired").toString().left(4);
							break;
						}
					}
				}

				v = input_vid_customFileNameRaw;
				v.replace(QString("<NAME>"), input_vid_name)
					.replace(QString("<SEASON PREFIX>"), input_vid_sPrefix)
					.replace(QString("<SEASON>"), this->zerofy(QString::number(season), input_vid_sDigits))
					.replace(QString("<EPISODE PREFIX>"), input_vid_ePrefix)
					.replace(QString("<EPISODE>"), this->zerofy(QString::number(ep), input_vid_eDigits))
					.replace(QString("<EPISODE ABSOLUTE>"), this->zerofy(episodeAbsolute, input_vid_eDigits))
					.replace(QString("<EPISODE NAME>"), episodeName)
					.replace(QString("<YEAR>"), episodeYear)
					.replace(QString("<LANGUAGE>"), "")
					.replace(QString("<AUDIO>"), "")
					.replace(QString("<RESOLUTION>"), mediaInfoCache[filePath]["resolution"])
					.replace(QString("<SOURCE>"), "")
					.replace(QString("<VIDEO>"), mediaInfoCache[filePath]["codec"])
					.replace(QString("<SCENE GROUP>"), "");
				v.remove(rgx_invalidFnCharset_win);
			}
		}
		QString fullFilename = v % QChar('.') % it.value().suffix();
		QListWidgetItem* qListWidgetItem = new QListWidgetItem(fullFilename);
		qListWidgetItem->setFlags(Qt::ItemNeverHasChildren);
		if (selected) {
			qListWidgetItem->setTextColor(Qt::black);
		}
		ui->renamePreview->addItem(qListWidgetItem);
	}

	ui->buttonRename->setEnabled(ui->renamePreview->count() > 0);
}

void ShikiRename::cacheMediaInfo(QFileInfo fileInfo) {
	QString filePath = fileInfo.absoluteFilePath();

	if (mediaInfoCache.contains(filePath))
		return;	//it's already cached

	MI.Open(filePath.toStdWString());
	QMap<QString, QString> mediaInfo;
	QString fileType = fileInfo.suffix();
	mediaInfo["fileType"] = fileType;

	if (fileTypes_video.contains(fileType, Qt::CaseInsensitive)) {
		QString resolution = QString::fromStdWString(MI.Get(MediaInfoDLL::Stream_Video, 0, __T("Height"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name));
		if (!resolution.isEmpty())
			resolution.append("p");
		mediaInfo["resolution"] = resolution;

		QString codecID = QString::fromStdWString(MI.Get(MediaInfoDLL::Stream_Video, 0, __T("CodecID"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name));
		if (codecID.compare("V_MPEG4/ISO/AVC", Qt::CaseInsensitive) == 0) {
			mediaInfo["codec"] = "x264";
		}
		else if (codecID.compare("V_MPEGH/ISO/HEVC", Qt::CaseInsensitive) == 0) {
			mediaInfo["codec"] = "x265";
		}
		else if (codecID.compare("XVID", Qt::CaseInsensitive) == 0) {
			mediaInfo["codec"] = "XviD";
		}
	}

	qDebug() << "Adding" << fileInfo.absoluteFilePath() << "to mediaInfoCache";
	mediaInfoCache[fileInfo.absoluteFilePath()] = mediaInfo;
}

void ShikiRename::on_buttonRename_clicked()
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
	renameConfirmationDialog->setTargetNameList(targetNames);
	if (renameConfirmationDialog->exec()) {
		targetNames = renameConfirmationDialog->getTargetNameList();
	}
	else {
		return;
	}

	ui->renamePreview->clear();
	ui->renamePreview->addItems(targetNames);
	QStringList targetNames_sorted = targetNames;
	targetNames_sorted.sort();

	bool dupe_found = false;
	QList<QColor> appropiateTextColors = { Qt::red, Qt::blue, Qt::green, Qt::cyan, Qt::magenta, Qt::darkYellow };
	int appropiateTextColorIterator = 0;
	for (int i = 0; i < targetNames_sorted.count() - 1; i++) {
		if (targetNames_sorted.at(i).compare(targetNames_sorted.at(i + 1), Qt::CaseInsensitive) == 0) {							//check if there are duplicate filenames
			dupe_found = true;																							//there are dupes, so we won't rename
			QList<QListWidgetItem *> li = ui->renamePreview->findItems(targetNames_sorted.at(i), Qt::MatchFixedString);			//get all dupe items in preview
			for (auto item : li)
				item->setTextColor(appropiateTextColors.at(appropiateTextColorIterator%appropiateTextColors.length()));		//mark dupes in preview
			appropiateTextColorIterator++;
		}
	}
	if (dupe_found) {
		//ui->buttonRename->setDisabled(true);	//user may edit it manually, so we no longer disable the rename button.
		errorDialog_renameFailed.setInformativeText("Rename failed because duplicate filenames have been found. Check your preview list and resolve any marked conflicts.");
		errorDialog_renameFailed.exec();
		return;
	}

	for (int i = 0; i < ui->renamePreview->count(); i++) {
		if (isSelectedInList(ui->currentList->item(i)->text())) {
			QString oldName = infoList.at(i).absoluteFilePath();														//original file
			QString newName = infoList.at(i).absolutePath() % QChar('/') % ui->renamePreview->item(i)->text();		//new file

			if (oldName != newName) {
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
	}

	QDir dir = QDir(infoList.first().absolutePath() + QString("\\"));
	this->open(dir);	//reload everything so it shows the new current state of the files
	this->previewRename();
}

QString ShikiRename::zerofy(QString string, int digits) {
	return QString(digits - string.length(), '0') + string;
}

/**
 * Tries to find season and episode number inside a given string using a currently hardcoded pattern.
 *
 * @param filename_qs Text containing a type of naming pattern representing a season and an episode number
 * @return Two numbers we assume to be season and episode numbers or (0,0) if detection failed. (Season, Episode)
 */
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
int ShikiRename::searchEpisode(QString filename) {
	if (searchEpisode_startIdx < 0) {
		searchEpisode_startIdx = -1;
		QVector<QString> fileNames;

		for (auto item : infoList) {
			if (item.fileName().isEmpty()) {	//shouldn't happen
				fileNames.clear();
				break;
			}
			fileNames.append(item.fileName());
		}
		if (!fileNames.isEmpty()) {
			for (int i = 0; i < fileNames.count() - 1; i++) {
				QString s1 = fileNames.at(i);
				if (isSelectedInList(s1)) {											//current idx must be in selection
					QString s2 = fileNames.at(i + 1);
					int j = i + 2;
					for (; !isSelectedInList(s2) && j < fileNames.count(); j++) {	//next idx must be in selection as well
						i = j - 1;													//next s1 shall be current s2, so move our s1 idx in front of our s2 idx so the next loop increments to s2 idx
						s2 = fileNames.at(j);
					}
					if (!isSelectedInList(s2)) {									//last item reached & is not in selection
						break;
					}
					//compare strings until a difference is found or until we've reached a previously determined index of a difference
					for (int k = 0; k < s1.length() && (searchEpisode_startIdx == -1 || k < searchEpisode_startIdx); k++) {
						if (s1.at(k) != s2.at(k)) {
							searchEpisode_startIdx = k;
							break;
						}
					}
				}
			}
		}
	}

	std::string string = filename.mid(searchEpisode_startIdx).toStdString();
	std::regex rgx(R"([\D0]*(\d+)[\s\S]*)");
	std::smatch match;
	int result = -1;
	if (std::regex_search(string, match, rgx)) {
		result = std::stoi(match.str(1));
	}
	return result;
}

void ShikiRename::openDialogSeriesSelection(QJsonArray seriesData) {
	seriesSelectionDialog->setData(seriesData);
	seriesSelectionDialog->show();
}
void ShikiRename::on_seriesSelectedDialog_closed(const int &id, const QString &name) {
	if (id == -1) {
		this->previewRename();
	}
	else {
		ongoingSeriesSelection = true;
		ui->editName->setText(name);
		ongoingSeriesSelection = false;
		this->tvdbFindEpisodes(id, 1);
	}
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

			this->tvdbFindEpisodes(seasonId, page + 1);

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
	tvdbAuthTimer->start(TVDB_TIMEOUT);
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