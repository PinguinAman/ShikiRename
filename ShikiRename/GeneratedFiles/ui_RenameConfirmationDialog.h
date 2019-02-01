/********************************************************************************
** Form generated from reading UI file 'RenameConfirmationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMECONFIRMATIONDIALOG_H
#define UI_RENAMECONFIRMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenameConfirmationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *targetFilenameEditor;
    QFormLayout *buttonLayout;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUi(QWidget *RenameConfirmationDialog)
    {
        if (RenameConfirmationDialog->objectName().isEmpty())
            RenameConfirmationDialog->setObjectName(QString::fromUtf8("RenameConfirmationDialog"));
        RenameConfirmationDialog->resize(950, 419);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RenameConfirmationDialog->sizePolicy().hasHeightForWidth());
        RenameConfirmationDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(RenameConfirmationDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        targetFilenameEditor = new QTableWidget(RenameConfirmationDialog);
        if (targetFilenameEditor->columnCount() < 1)
            targetFilenameEditor->setColumnCount(1);
        targetFilenameEditor->setObjectName(QString::fromUtf8("targetFilenameEditor"));
        targetFilenameEditor->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        targetFilenameEditor->setTabKeyNavigation(true);
        targetFilenameEditor->setProperty("showDropIndicator", QVariant(false));
        targetFilenameEditor->setSelectionMode(QAbstractItemView::SingleSelection);
        targetFilenameEditor->setSelectionBehavior(QAbstractItemView::SelectItems);
        targetFilenameEditor->setColumnCount(1);
        targetFilenameEditor->horizontalHeader()->setVisible(false);
        targetFilenameEditor->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(targetFilenameEditor);

        buttonLayout = new QFormLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        buttonLayout->setLabelAlignment(Qt::AlignCenter);
        buttonLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        buttonLayout->setHorizontalSpacing(10);
        buttonLayout->setContentsMargins(0, -1, 0, -1);
        buttonOK = new QPushButton(RenameConfirmationDialog);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setMaximumSize(QSize(100, 23));

        buttonLayout->setWidget(0, QFormLayout::LabelRole, buttonOK);

        buttonCancel = new QPushButton(RenameConfirmationDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setMaximumSize(QSize(100, 23));

        buttonLayout->setWidget(0, QFormLayout::FieldRole, buttonCancel);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(RenameConfirmationDialog);

        QMetaObject::connectSlotsByName(RenameConfirmationDialog);
    } // setupUi

    void retranslateUi(QWidget *RenameConfirmationDialog)
    {
        RenameConfirmationDialog->setWindowTitle(QApplication::translate("RenameConfirmationDialog", "Form", nullptr));
        buttonOK->setText(QApplication::translate("RenameConfirmationDialog", "OK", nullptr));
        buttonCancel->setText(QApplication::translate("RenameConfirmationDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenameConfirmationDialog: public Ui_RenameConfirmationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMECONFIRMATIONDIALOG_H
