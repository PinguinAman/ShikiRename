#ifndef SHIKIRENAME_SSD_H
#define SHIKIRENAME_SSD_H

#include <QDialog>
#include <QString>
#include <QTableWidgetItem>
#include <QJsonArray>
#include <QJsonObject>

namespace Ui {
	class SeriesSelectionDialog;
}

class SeriesSelectionDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SeriesSelectionDialog(QWidget *parent);
	~SeriesSelectionDialog();

	void setData(QJsonArray seriesData);

	signals:
	void seriesSelected(int id);

	private slots:
	void on_buttonOK_clicked();
	void on_buttonCancel_clicked();


private:
	Ui::SeriesSelectionDialog *ui_seriesSelect;
};

#endif // SHIKIRENAME_SSD_H
