#include "RenameConfirmationDialog.h"
#include "ui_RenameConfirmationDialog.h"

#include <QDebug>

RenameConfirmationDialog::RenameConfirmationDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::RenameConfirmationDialog)
{
	ui->setupUi(this);
	this->setFixedSize(this->geometry().width(), this->geometry().height());
}

RenameConfirmationDialog::~RenameConfirmationDialog()
{
	delete ui;
}

void RenameConfirmationDialog::on_buttonOK_clicked() {
	this->accept();
}

void RenameConfirmationDialog::on_buttonCancel_clicked() {
	ui->targetFilenameEditor->setRowCount(0);
	this->reject();
}

void RenameConfirmationDialog::setTargetNameList(const QList<QTableWidgetItem*> items) {
	ui->targetFilenameEditor->setRowCount(items.count());
	for (auto item : items) {
		item->setFlags(item->flags() | Qt::ItemIsEditable);
		ui->targetFilenameEditor->setItem(item->data(Qt::UserRole).toInt(), 0, item->clone());
	}
}

QList<QTableWidgetItem*> RenameConfirmationDialog::getTargetNameList() {
	QList<QTableWidgetItem*> items = ui->targetFilenameEditor->findItems("*", Qt::MatchWildcard);
	for (auto item : items) {
		qDebug() << "RenameConfirmationDialog::getTargetNameList - old flags:" << item->flags();
		item->setFlags(item->flags() & (~Qt::ItemIsEditable));
		qDebug() << "RenameConfirmationDialog::getTargetNameList - new flags:" << item->flags();
	}
	ui->targetFilenameEditor->setRowCount(0);
	return items;
}