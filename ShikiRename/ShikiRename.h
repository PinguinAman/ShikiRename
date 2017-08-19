#ifndef SHIKIRENAME_H
#define SHIKIRENAME_H

#include <QMainWindow>
#include <QString>
#include <QStringBuilder>
#include <QFileInfo>
#include <limits>
#include <QtNetwork/QNetworkReply>
#include <SeriesSelectionDialog.h>
#include <QList>
#include <QTableWidgetItem>
#include <QJsonArray>
#include <regex>

namespace Ui {
	class ShikiRenameClass;
}

class ShikiRename : public QMainWindow
{
	Q_OBJECT

public:
	const int MAX_INT = std::numeric_limits<int>::max();
	explicit ShikiRename(QWidget *parent = 0);
	~ShikiRename();

	private slots:
	void on_tabWidget_currentChanged(const int &index);

	void on_editRemoveRight_textChanged(const QString &arg1);
	void on_editRemoveLeft_textChanged(const QString &arg1);
	void on_editReplace1_textChanged(const QString &arg1);
	void on_editReplace2_textChanged(const QString &arg1);
	void on_editInsert1_textChanged(const QString &arg1);
	void on_editInsert2_textChanged(const QString &arg1);
	void on_editRemoveAt1_textChanged(const QString &arg1);
	void on_editRemoveAt2_textChanged(const QString &arg1);
	void on_editPrefix_textChanged(const QString &arg1);
	void on_editSuffix_textChanged(const QString &arg1);
	void on_editNumIdx_textChanged(const QString &arg1);
	void on_editNumInitV_textChanged(const QString &arg1);
	void on_editNumInc_textChanged(const QString &arg1);
	void on_editNumDigits_textChanged(const QString &arg1);

	void on_buttonCustomFileNameReset_clicked();
	void on_checkboxCustomFileName_toggled(const bool &checked);
	void on_editCustomFileName_textChanged(const QString &arg1);
	void on_editName_textChanged(const QString &arg1);
	void on_editSeriesNrPrefix_textChanged(const QString &arg1);
	void on_editEpisodeNrPrefix_textChanged(const QString &arg1);
	void on_editSeriesNrDigits_textChanged(const QString &arg1);
	void on_editEpisodeNrDigits_textChanged(const QString &arg1);
	void on_comboEpisodeNameSrc_currentIndexChanged(const int &index);
	void on_comboEpisodeNameLang_currentIndexChanged(const int &index);
	void on_editYear_textChanged(const QString &arg1);
	void on_editLang_textChanged(const QString &arg1);
	void on_editAudio_textChanged(const QString &arg1);
	void on_editResolution_textChanged(const QString &arg1);
	void on_editVideo_textChanged(const QString &arg1);
	void on_editSource_textChanged(const QString &arg1);
	void on_editSceneGrp_textChanged(const QString &arg1);

	void on_checkboxOnlySelected_toggled(const bool &checked);
	void on_currentList_itemSelectionChanged();

	void on_actionOpen_triggered();
	void on_actionUndo_triggered();
	void on_actionRedo_triggered();

	void on_confirmButton_clicked();

	void openDialogSeriesSelection(QJsonArray seriesData);
	void on_seriesSelectedDialog_closed(int id, QString name);

	void handleNetworkReply(QNetworkReply* reply);
	void tvdbAuthError();
	void tvdbFindSeries(QString name);

private:
	Ui::ShikiRenameClass *ui;
	SeriesSelectionDialog *seriesSelectionDialog;

	const QString DEFAULT_MEDIA_FILENAME_STRUCTURE = "<NAME> - <SEASON PREFIX><SEASON><EPISODE PREFIX><EPISODE> - <EPISODE NAME> - [<YEAR> <LANGUAGE> <AUDIO> <RESOLUTION> <SOURCE> <VIDEO> - <SCENE GROUP>]";
	const enum MetaDB { None = 0, TheTVDB = 1 };
	QString invalidFnCharset_win;

	void resizeEvent(QResizeEvent * event);
	void changeEvent(QEvent * event);
	void fixGridLayoutWidth();

	bool isSelectedInList(QString filename);

	void open(QDir dir);
	void addToHistory(int id, QString o, QString n);
	void previewRename();

	QString zerofy(QString string, int digits);
	std::pair<int, int> searchSeasonAndEpisode(QString filename_qs);

	bool onlineDbAvailable();

	void tvdbAuth();
	void tvdbAuthorizeRequest(QNetworkRequest *request);
	void tvdbFindEpisodes(int seriesId, int page);
	void tvdbGetLanguages();

	QFileInfoList infoList;
	QStringList filenames;
	QStringList fileextensions;
	QStringList selectedFilenames;
	std::vector<std::tuple<int, QString, QString>> hist_undo; //id, old, new
	std::vector<std::tuple<int, QString, QString>> hist_redo; //id, new, old

	//tab 1
	int input_remLeft = 0;
	int input_remRight = 0;
	QString input_replace1;
	QString input_replace2;
	int input_insert_idx = -1;
	QString input_insert_string;
	int input_removeAt_amount = 0;
	int input_removeAt_idx = -1;
	bool input_onlySelected = false;
	QString input_prefix;
	QString input_suffix;
	int input_num_idx = -1;
	int input_num_init = 1;
	int input_num_inc = 1;
	int input_num_digits = 1;
	//tab 2
	QString input_vid_customFileNameRaw;
	QString input_vid_name;
	QString input_vid_sPrefix = "s";
	int input_vid_sDigits = 2;
	QString input_vid_ePrefix = "e";
	int input_vid_eDigits = 2;
	MetaDB input_vid_eNameSrc;
	QString input_vid_eNameLang = "en";
	QString input_vid_releaseYear;
	QString input_vid_language;
	QString input_vid_audio;
	QString input_vid_videoResolution;
	QString input_vid_video;
	QString input_vid_src;
	QString input_vid_sceneGrp;
	QString releaseDataSuffix;
	bool input_epDetection = false;
	bool ongoingSeriesSelection = false;
	QNetworkAccessManager *manager;
	QByteArray tvdbAuthToken;
	QTimer *tvdbAuthTimer;
	std::list<std::pair<QString, QString>> tvdbLanguages;
	QTimer *tvdbSearchDelayTimer;

	QJsonArray episodeData;


};

#endif // SHIKIRENAME_H
