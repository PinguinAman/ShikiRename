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
	ui->targetFilenameEditor->clear();
	this->reject();
}

void RenameConfirmationDialog::setTargetNameList(QStringList names) {
	ui->targetFilenameEditor->clear();
	for (auto name : names) {
		QListWidgetItem* item = new QListWidgetItem(name);
		item->setFlags(item->flags() | Qt::ItemIsEditable);
		ui->targetFilenameEditor->addItem(item);
	}
	//ui->targetFilenameEditor->addItems(names);
}

QStringList RenameConfirmationDialog::getTargetNameList() {
	QList<QListWidgetItem*> items = ui->targetFilenameEditor->findItems("*", Qt::MatchWildcard);
	QStringList targetNames;
	if (ui->targetFilenameEditor->count() <= 0 || this->isVisible()) {
		qDebug() << "RenameConfirmationDialog::getTargetNameList() returning empty.";
		targetNames.clear();
		return targetNames;
	}

	for (auto item : items) {
		targetNames.append(item->text());
	}
	return targetNames;
}