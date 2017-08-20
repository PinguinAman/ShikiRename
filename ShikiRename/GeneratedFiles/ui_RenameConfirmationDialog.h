/********************************************************************************
** Form generated from reading UI file 'RenameConfirmationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMECONFIRMATIONDIALOG_H
#define UI_RENAMECONFIRMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenameConfirmationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *targetFilenameEditor;
    QFormLayout *buttonLayout;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUi(QWidget *RenameConfirmationDialog)
    {
        if (RenameConfirmationDialog->objectName().isEmpty())
            RenameConfirmationDialog->setObjectName(QStringLiteral("RenameConfirmationDialog"));
        RenameConfirmationDialog->resize(950, 419);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RenameConfirmationDialog->sizePolicy().hasHeightForWidth());
        RenameConfirmationDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(RenameConfirmationDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        targetFilenameEditor = new QListWidget(RenameConfirmationDialog);
        targetFilenameEditor->setObjectName(QStringLiteral("targetFilenameEditor"));
        targetFilenameEditor->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        targetFilenameEditor->setTabKeyNavigation(true);
        targetFilenameEditor->setProperty("showDropIndicator", QVariant(false));
        targetFilenameEditor->setSelectionMode(QAbstractItemView::SingleSelection);
        targetFilenameEditor->setSelectionBehavior(QAbstractItemView::SelectItems);

        verticalLayout->addWidget(targetFilenameEditor);

        buttonLayout = new QFormLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setLabelAlignment(Qt::AlignCenter);
        buttonLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        buttonLayout->setHorizontalSpacing(10);
        buttonLayout->setContentsMargins(0, -1, 0, -1);
        buttonOK = new QPushButton(RenameConfirmationDialog);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setMaximumSize(QSize(100, 23));

        buttonLayout->setWidget(0, QFormLayout::LabelRole, buttonOK);

        buttonCancel = new QPushButton(RenameConfirmationDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
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
        RenameConfirmationDialog->setWindowTitle(QApplication::translate("RenameConfirmationDialog", "Form", Q_NULLPTR));
        buttonOK->setText(QApplication::translate("RenameConfirmationDialog", "OK", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("RenameConfirmationDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RenameConfirmationDialog: public Ui_RenameConfirmationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMECONFIRMATIONDIALOG_H
