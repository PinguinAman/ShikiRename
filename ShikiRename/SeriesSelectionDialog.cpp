#include "SeriesSelectionDialog.h"
#include "ui_SeriesSelectionDialog.h"

#include <QDebug>

SeriesSelectionDialog::SeriesSelectionDialog(QWidget *parent) :
	QDialog(parent),
	ui_seriesSelect(new Ui::SeriesSelectionDialog)
{
	ui_seriesSelect->setupUi(this);
	this->setFixedSize(this->geometry().width(), this->geometry().height());
}

SeriesSelectionDialog::~SeriesSelectionDialog()
{
	delete ui_seriesSelect;
}

void SeriesSelectionDialog::on_buttonCancel_clicked() {
	this->close();
}

void SeriesSelectionDialog::setData(QJsonArray seriesData) {
	int totalRows = seriesData.count();
	int curRow = 0;
	ui_seriesSelect->tableSeriesSelect->setRowCount(totalRows);
	ui_seriesSelect->tableSeriesSelect->setColumnCount(4);
	ui_seriesSelect->tableSeriesSelect->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
	ui_seriesSelect->tableSeriesSelect->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
	ui_seriesSelect->tableSeriesSelect->setHorizontalHeaderItem(2, new QTableWidgetItem("Year"));
	ui_seriesSelect->tableSeriesSelect->setHorizontalHeaderItem(3, new QTableWidgetItem("Overview"));
	ui_seriesSelect->tableSeriesSelect->setColumnHidden(0, true);
	ui_seriesSelect->tableSeriesSelect->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	ui_seriesSelect->tableSeriesSelect->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui_seriesSelect->tableSeriesSelect->setSelectionMode(QAbstractItemView::SingleSelection);
	ui_seriesSelect->tableSeriesSelect->setEditTriggers(QAbstractItemView::NoEditTriggers);

	for (auto item : seriesData) {
		QJsonObject jo = item.toObject();
		QString seriesId(QString::number(jo.value("id").toInt()));
		QString seriesName(jo.value("seriesName").toString());
		QString seriesFirstAired(jo.value("firstAired").toString());
		QString seriesOverview(jo.value("overview").toString());
		QTableWidgetItem* seriesOverviewItem = new QTableWidgetItem(seriesOverview/*.mid(0, 50)*/);
		seriesOverviewItem->setToolTip("<font>" + seriesOverview + "</font>");

		ui_seriesSelect->tableSeriesSelect->setItem(curRow, 0, new QTableWidgetItem(seriesId));
		ui_seriesSelect->tableSeriesSelect->setItem(curRow, 1, new QTableWidgetItem(seriesName));
		ui_seriesSelect->tableSeriesSelect->setItem(curRow, 2, new QTableWidgetItem(seriesFirstAired.remove(4, seriesFirstAired.length())));
		ui_seriesSelect->tableSeriesSelect->item(curRow, 2)->setTextAlignment(Qt::AlignCenter);
		ui_seriesSelect->tableSeriesSelect->setItem(curRow++, 3, seriesOverviewItem);
	}
	ui_seriesSelect->tableSeriesSelect->resizeColumnToContents(0);
	ui_seriesSelect->tableSeriesSelect->resizeColumnToContents(1);
}

void SeriesSelectionDialog::on_buttonOK_clicked() {
	int selectedRow = ui_seriesSelect->tableSeriesSelect->currentRow();
	int seriesId = ui_seriesSelect->tableSeriesSelect->item(selectedRow, 0)->text().toInt();
	emit closed(seriesId);
	this->close();
}



