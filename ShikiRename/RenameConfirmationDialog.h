#ifndef SHIKIRENAME_RCD_H
#define SHIKIRENAME_RCD_H

#include <QDialog>
#include <QString>
#include <QTableWidgetItem>

namespace Ui {
	class RenameConfirmationDialog;
}

class RenameConfirmationDialog : public QDialog
{
	Q_OBJECT

public:
	explicit RenameConfirmationDialog(QWidget *parent);
	~RenameConfirmationDialog();

	void setTargetNameList(QList<QTableWidgetItem*> names);
	QList<QTableWidgetItem*> getTargetNameList();

	signals:


	private slots :
	void on_buttonOK_clicked();
	void on_buttonCancel_clicked();


private:
	Ui::RenameConfirmationDialog *ui;
};

#endif // SHIKIRENAME_RCD_H
