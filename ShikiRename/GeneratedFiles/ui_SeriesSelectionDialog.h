/********************************************************************************
** Form generated from reading UI file 'SeriesSelectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIESSELECTIONDIALOG_H
#define UI_SERIESSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeriesSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableSeriesSelect;
    QFormLayout *buttonLayout;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUi(QWidget *SeriesSelectionDialog)
    {
        if (SeriesSelectionDialog->objectName().isEmpty())
            SeriesSelectionDialog->setObjectName(QString::fromUtf8("SeriesSelectionDialog"));
        SeriesSelectionDialog->resize(950, 419);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SeriesSelectionDialog->sizePolicy().hasHeightForWidth());
        SeriesSelectionDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SeriesSelectionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableSeriesSelect = new QTableWidget(SeriesSelectionDialog);
        tableSeriesSelect->setObjectName(QString::fromUtf8("tableSeriesSelect"));

        verticalLayout->addWidget(tableSeriesSelect);

        buttonLayout = new QFormLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        buttonLayout->setLabelAlignment(Qt::AlignCenter);
        buttonLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        buttonLayout->setHorizontalSpacing(10);
        buttonLayout->setContentsMargins(0, -1, 0, -1);
        buttonOK = new QPushButton(SeriesSelectionDialog);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setMaximumSize(QSize(100, 23));

        buttonLayout->setWidget(0, QFormLayout::LabelRole, buttonOK);

        buttonCancel = new QPushButton(SeriesSelectionDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setMaximumSize(QSize(100, 23));

        buttonLayout->setWidget(0, QFormLayout::FieldRole, buttonCancel);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(SeriesSelectionDialog);

        QMetaObject::connectSlotsByName(SeriesSelectionDialog);
    } // setupUi

    void retranslateUi(QWidget *SeriesSelectionDialog)
    {
        SeriesSelectionDialog->setWindowTitle(QApplication::translate("SeriesSelectionDialog", "Form", nullptr));
        buttonOK->setText(QApplication::translate("SeriesSelectionDialog", "OK", nullptr));
        buttonCancel->setText(QApplication::translate("SeriesSelectionDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeriesSelectionDialog: public Ui_SeriesSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIESSELECTIONDIALOG_H
