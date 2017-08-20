#include "SeriesSelectionDialog.h"
#include "ui_SeriesSelectionDialog.h"

#include <QDebug>

SeriesSelectionDialog::SeriesSelectionDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SeriesSelectionDialog)
{
	ui->setupUi(this);
	this->setFixedSize(this->geometry().width(), this->geometry().height());
}

SeriesSelectionDialog::~SeriesSelectionDialog()
{
	delete ui;
}

void SeriesSelectionDialog::on_buttonCancel_clicked() {
	emit closed(-1, NULL);
	this->close();
}

void SeriesSelectionDialog::setData(QJsonArray seriesData) {
	int totalRows = seriesData.count();
	int curRow = 0;
	ui->tableSeriesSelect->setRowCount(totalRows);
	ui->tableSeriesSelect->setColumnCount(4);
	ui->tableSeriesSelect->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
	ui->tableSeriesSelect->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
	ui->tableSeriesSelect->setHorizontalHeaderItem(2, new QTableWidgetItem("Year"));
	ui->tableSeriesSelect->setHorizontalHeaderItem(3, new QTableWidgetItem("Overview"));
	ui->tableSeriesSelect->setColumnHidden(0, true);
	ui->tableSeriesSelect->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	ui->tableSeriesSelect->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableSeriesSelect->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableSeriesSelect->setEditTriggers(QAbstractItemView::NoEditTriggers);

	for (auto item : seriesData) {
		QJsonObject jo = item.toObject();
		QString seriesId(QString::number(jo.value("id").toInt()));
		QString seriesName(jo.value("seriesName").toString());
		QString seriesFirstAired(jo.value("firstAired").toString());
		QString seriesOverview(jo.value("overview").toString());
		QTableWidgetItem* seriesOverviewItem = new QTableWidgetItem(seriesOverview/*.mid(0, 50)*/);
		seriesOverviewItem->setToolTip("<font>" + seriesOverview + "</font>");

		ui->tableSeriesSelect->setItem(curRow, 0, new QTableWidgetItem(seriesId));
		ui->tableSeriesSelect->setItem(curRow, 1, new QTableWidgetItem(seriesName));
		ui->tableSeriesSelect->setItem(curRow, 2, new QTableWidgetItem(seriesFirstAired.remove(4, seriesFirstAired.length())));
		ui->tableSeriesSelect->item(curRow, 2)->setTextAlignment(Qt::AlignCenter);
		ui->tableSeriesSelect->setItem(curRow++, 3, seriesOverviewItem);
	}
	ui->tableSeriesSelect->resizeColumnToContents(0);
	ui->tableSeriesSelect->resizeColumnToContents(1);
}

void SeriesSelectionDialog::on_buttonOK_clicked() {
	int selectedRow = ui->tableSeriesSelect->currentRow();
	int seriesId = ui->tableSeriesSelect->item(selectedRow, 0)->text().toInt();
	QString seriesName = ui->tableSeriesSelect->item(selectedRow, 1)->text();
	
	emit closed(seriesId, seriesName);
	this->close();
}



