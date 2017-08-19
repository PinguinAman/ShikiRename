/********************************************************************************
** Form generated from reading UI file 'SeriesSelectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIESSELECTIONDIALOG_H
#define UI_SERIESSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            SeriesSelectionDialog->setObjectName(QStringLiteral("SeriesSelectionDialog"));
        SeriesSelectionDialog->resize(950, 419);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SeriesSelectionDialog->sizePolicy().hasHeightForWidth());
        SeriesSelectionDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SeriesSelectionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableSeriesSelect = new QTableWidget(SeriesSelectionDialog);
        tableSeriesSelect->setObjectName(QStringLiteral("tableSeriesSelect"));

        verticalLayout->addWidget(tableSeriesSelect);

        buttonLayout = new QFormLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setLabelAlignment(Qt::AlignCenter);
        buttonLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        buttonLayout->setHorizontalSpacing(10);
        buttonLayout->setContentsMargins(0, -1, 0, -1);
        buttonOK = new QPushButton(SeriesSelectionDialog);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setMaximumSize(QSize(100, 23));

        buttonLayout->setWidget(0, QFormLayout::LabelRole, buttonOK);

        buttonCancel = new QPushButton(SeriesSelectionDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
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
        SeriesSelectionDialog->setWindowTitle(QApplication::translate("SeriesSelectionDialog", "Form", Q_NULLPTR));
        buttonOK->setText(QApplication::translate("SeriesSelectionDialog", "OK", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("SeriesSelectionDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SeriesSelectionDialog: public Ui_SeriesSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIESSELECTIONDIALOG_H
