/********************************************************************************
** Form generated from reading UI file 'ShikiRename.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIKIRENAME_H
#define UI_SHIKIRENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShikiRenameClass
{
public:
    QAction *actionOpen;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *confirmButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *dirTable;
    QListWidget *renamePreview;
    QCheckBox *checkboxOnlySelected;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *editRemoveAt2;
    QLabel *labelRemoveLeft2;
    QLabel *labelRemoveRight2;
    QLabel *labelInsert1;
    QLabel *labelRemoveAt1;
    QLabel *labelReplace2;
    QLineEdit *editInsert1;
    QLineEdit *editRemoveLeft;
    QLabel *labelPrefix;
    QLabel *labelSuffix;
    QLineEdit *editSuffix;
    QLabel *labelNumIdx;
    QLineEdit *editNumIdx;
    QLineEdit *editPrefix;
    QLabel *labelRemoveAt2;
    QLineEdit *editReplace2;
    QLineEdit *editRemoveRight;
    QLabel *labelRemoveLeft1;
    QLabel *labelReplace1;
    QLabel *labelRemoveRight1;
    QLineEdit *editRemoveAt1;
    QLineEdit *editReplace1;
    QLabel *labelInsert2;
    QLineEdit *editInsert2;
    QLabel *labelNumDigits2;
    QLineEdit *editNumInc;
    QLabel *labelNumDigits;
    QLabel *labelNumInc;
    QLineEdit *editNumInitV;
    QLabel *labelNumInitV;
    QLineEdit *editNumDigits;
    QFrame *line;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QFrame *line2;
    QLineEdit *editSeriesNrPrefix;
    QLineEdit *editYear;
    QComboBox *comboEpisodeNameLang;
    QLineEdit *editSource;
    QLineEdit *editEpisodeNrPrefix;
    QLabel *labelEpisodeNrDigits;
    QLabel *labelYear;
    QLineEdit *editEpisodeNrDigits;
    QLabel *labelSeriesNrDigits;
    QLabel *labelEpisodeNameSrc;
    QLabel *labelAudio;
    QLineEdit *editResolution;
    QLineEdit *editName;
    QLabel *labelScreneGrp;
    QLabel *labelEpisodeNrPrefix;
    QLabel *labelSeriesNrPrefix;
    QLineEdit *editVideo;
    QLabel *labelSource;
    QLineEdit *editSeriesNrDigits;
    QLabel *labelName;
    QLineEdit *editAudio;
    QLabel *labelResolution;
    QLabel *labelEpisodeNameLang;
    QLabel *labelVideo;
    QComboBox *comboEpisodeNameSrc;
    QLineEdit *editSceneGrp;
    QCheckBox *checkBoxEpDetection;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShikiRenameClass)
    {
        if (ShikiRenameClass->objectName().isEmpty())
            ShikiRenameClass->setObjectName(QStringLiteral("ShikiRenameClass"));
        ShikiRenameClass->resize(1288, 795);
        actionOpen = new QAction(ShikiRenameClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionUndo = new QAction(ShikiRenameClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(ShikiRenameClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        centralWidget = new QWidget(ShikiRenameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setToolTipDuration(-1);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        confirmButton = new QPushButton(centralWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        gridLayout_2->addWidget(confirmButton, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dirTable = new QTableWidget(centralWidget);
        dirTable->setObjectName(QStringLiteral("dirTable"));
        dirTable->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(dirTable);

        renamePreview = new QListWidget(centralWidget);
        renamePreview->setObjectName(QStringLiteral("renamePreview"));

        horizontalLayout_2->addWidget(renamePreview);


        verticalLayout->addLayout(horizontalLayout_2);

        checkboxOnlySelected = new QCheckBox(centralWidget);
        checkboxOnlySelected->setObjectName(QStringLiteral("checkboxOnlySelected"));

        verticalLayout->addWidget(checkboxOnlySelected);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 1151, 144));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        editRemoveAt2 = new QLineEdit(layoutWidget);
        editRemoveAt2->setObjectName(QStringLiteral("editRemoveAt2"));

        gridLayout->addWidget(editRemoveAt2, 2, 8, 1, 1);

        labelRemoveLeft2 = new QLabel(layoutWidget);
        labelRemoveLeft2->setObjectName(QStringLiteral("labelRemoveLeft2"));

        gridLayout->addWidget(labelRemoveLeft2, 0, 2, 1, 1);

        labelRemoveRight2 = new QLabel(layoutWidget);
        labelRemoveRight2->setObjectName(QStringLiteral("labelRemoveRight2"));

        gridLayout->addWidget(labelRemoveRight2, 0, 7, 1, 1);

        labelInsert1 = new QLabel(layoutWidget);
        labelInsert1->setObjectName(QStringLiteral("labelInsert1"));

        gridLayout->addWidget(labelInsert1, 2, 0, 1, 1);

        labelRemoveAt1 = new QLabel(layoutWidget);
        labelRemoveAt1->setObjectName(QStringLiteral("labelRemoveAt1"));

        gridLayout->addWidget(labelRemoveAt1, 2, 5, 1, 1);

        labelReplace2 = new QLabel(layoutWidget);
        labelReplace2->setObjectName(QStringLiteral("labelReplace2"));

        gridLayout->addWidget(labelReplace2, 1, 2, 1, 1);

        editInsert1 = new QLineEdit(layoutWidget);
        editInsert1->setObjectName(QStringLiteral("editInsert1"));

        gridLayout->addWidget(editInsert1, 2, 1, 1, 1);

        editRemoveLeft = new QLineEdit(layoutWidget);
        editRemoveLeft->setObjectName(QStringLiteral("editRemoveLeft"));

        gridLayout->addWidget(editRemoveLeft, 0, 1, 1, 1);

        labelPrefix = new QLabel(layoutWidget);
        labelPrefix->setObjectName(QStringLiteral("labelPrefix"));

        gridLayout->addWidget(labelPrefix, 3, 0, 1, 1);

        labelSuffix = new QLabel(layoutWidget);
        labelSuffix->setObjectName(QStringLiteral("labelSuffix"));

        gridLayout->addWidget(labelSuffix, 3, 5, 1, 1);

        editSuffix = new QLineEdit(layoutWidget);
        editSuffix->setObjectName(QStringLiteral("editSuffix"));

        gridLayout->addWidget(editSuffix, 3, 6, 1, 1);

        labelNumIdx = new QLabel(layoutWidget);
        labelNumIdx->setObjectName(QStringLiteral("labelNumIdx"));

        gridLayout->addWidget(labelNumIdx, 4, 0, 1, 1);

        editNumIdx = new QLineEdit(layoutWidget);
        editNumIdx->setObjectName(QStringLiteral("editNumIdx"));

        gridLayout->addWidget(editNumIdx, 4, 1, 1, 1);

        editPrefix = new QLineEdit(layoutWidget);
        editPrefix->setObjectName(QStringLiteral("editPrefix"));

        gridLayout->addWidget(editPrefix, 3, 1, 1, 1);

        labelRemoveAt2 = new QLabel(layoutWidget);
        labelRemoveAt2->setObjectName(QStringLiteral("labelRemoveAt2"));

        gridLayout->addWidget(labelRemoveAt2, 2, 7, 1, 1);

        editReplace2 = new QLineEdit(layoutWidget);
        editReplace2->setObjectName(QStringLiteral("editReplace2"));

        gridLayout->addWidget(editReplace2, 1, 3, 1, 1);

        editRemoveRight = new QLineEdit(layoutWidget);
        editRemoveRight->setObjectName(QStringLiteral("editRemoveRight"));

        gridLayout->addWidget(editRemoveRight, 0, 6, 1, 1);

        labelRemoveLeft1 = new QLabel(layoutWidget);
        labelRemoveLeft1->setObjectName(QStringLiteral("labelRemoveLeft1"));

        gridLayout->addWidget(labelRemoveLeft1, 0, 0, 1, 1);

        labelReplace1 = new QLabel(layoutWidget);
        labelReplace1->setObjectName(QStringLiteral("labelReplace1"));

        gridLayout->addWidget(labelReplace1, 1, 0, 1, 1);

        labelRemoveRight1 = new QLabel(layoutWidget);
        labelRemoveRight1->setObjectName(QStringLiteral("labelRemoveRight1"));

        gridLayout->addWidget(labelRemoveRight1, 0, 5, 1, 1);

        editRemoveAt1 = new QLineEdit(layoutWidget);
        editRemoveAt1->setObjectName(QStringLiteral("editRemoveAt1"));

        gridLayout->addWidget(editRemoveAt1, 2, 6, 1, 1);

        editReplace1 = new QLineEdit(layoutWidget);
        editReplace1->setObjectName(QStringLiteral("editReplace1"));

        gridLayout->addWidget(editReplace1, 1, 1, 1, 1);

        labelInsert2 = new QLabel(layoutWidget);
        labelInsert2->setObjectName(QStringLiteral("labelInsert2"));

        gridLayout->addWidget(labelInsert2, 2, 2, 1, 1);

        editInsert2 = new QLineEdit(layoutWidget);
        editInsert2->setObjectName(QStringLiteral("editInsert2"));

        gridLayout->addWidget(editInsert2, 2, 3, 1, 1);

        labelNumDigits2 = new QLabel(layoutWidget);
        labelNumDigits2->setObjectName(QStringLiteral("labelNumDigits2"));

        gridLayout->addWidget(labelNumDigits2, 4, 9, 1, 1);

        editNumInc = new QLineEdit(layoutWidget);
        editNumInc->setObjectName(QStringLiteral("editNumInc"));

        gridLayout->addWidget(editNumInc, 4, 6, 1, 1);

        labelNumDigits = new QLabel(layoutWidget);
        labelNumDigits->setObjectName(QStringLiteral("labelNumDigits"));

        gridLayout->addWidget(labelNumDigits, 4, 7, 1, 1);

        labelNumInc = new QLabel(layoutWidget);
        labelNumInc->setObjectName(QStringLiteral("labelNumInc"));

        gridLayout->addWidget(labelNumInc, 4, 5, 1, 1);

        editNumInitV = new QLineEdit(layoutWidget);
        editNumInitV->setObjectName(QStringLiteral("editNumInitV"));

        gridLayout->addWidget(editNumInitV, 4, 3, 1, 1);

        labelNumInitV = new QLabel(layoutWidget);
        labelNumInitV->setObjectName(QStringLiteral("labelNumInitV"));

        gridLayout->addWidget(labelNumInitV, 4, 2, 1, 1);

        editNumDigits = new QLineEdit(layoutWidget);
        editNumDigits->setObjectName(QStringLiteral("editNumDigits"));

        gridLayout->addWidget(editNumDigits, 4, 8, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 4, 5, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1251, 299));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, 10, 10, 10);
        line2 = new QFrame(gridLayoutWidget);
        line2->setObjectName(QStringLiteral("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line2, 4, 0, 1, 4);

        editSeriesNrPrefix = new QLineEdit(gridLayoutWidget);
        editSeriesNrPrefix->setObjectName(QStringLiteral("editSeriesNrPrefix"));

        gridLayout_3->addWidget(editSeriesNrPrefix, 1, 1, 1, 1);

        editYear = new QLineEdit(gridLayoutWidget);
        editYear->setObjectName(QStringLiteral("editYear"));

        gridLayout_3->addWidget(editYear, 5, 1, 1, 1);

        comboEpisodeNameLang = new QComboBox(gridLayoutWidget);
        comboEpisodeNameLang->setObjectName(QStringLiteral("comboEpisodeNameLang"));

        gridLayout_3->addWidget(comboEpisodeNameLang, 3, 3, 1, 1);

        editSource = new QLineEdit(gridLayoutWidget);
        editSource->setObjectName(QStringLiteral("editSource"));

        gridLayout_3->addWidget(editSource, 9, 1, 1, 1);

        editEpisodeNrPrefix = new QLineEdit(gridLayoutWidget);
        editEpisodeNrPrefix->setObjectName(QStringLiteral("editEpisodeNrPrefix"));

        gridLayout_3->addWidget(editEpisodeNrPrefix, 2, 1, 1, 1);

        labelEpisodeNrDigits = new QLabel(gridLayoutWidget);
        labelEpisodeNrDigits->setObjectName(QStringLiteral("labelEpisodeNrDigits"));

        gridLayout_3->addWidget(labelEpisodeNrDigits, 2, 2, 1, 1);

        labelYear = new QLabel(gridLayoutWidget);
        labelYear->setObjectName(QStringLiteral("labelYear"));

        gridLayout_3->addWidget(labelYear, 5, 0, 1, 1);

        editEpisodeNrDigits = new QLineEdit(gridLayoutWidget);
        editEpisodeNrDigits->setObjectName(QStringLiteral("editEpisodeNrDigits"));

        gridLayout_3->addWidget(editEpisodeNrDigits, 2, 3, 1, 1);

        labelSeriesNrDigits = new QLabel(gridLayoutWidget);
        labelSeriesNrDigits->setObjectName(QStringLiteral("labelSeriesNrDigits"));

        gridLayout_3->addWidget(labelSeriesNrDigits, 1, 2, 1, 1);

        labelEpisodeNameSrc = new QLabel(gridLayoutWidget);
        labelEpisodeNameSrc->setObjectName(QStringLiteral("labelEpisodeNameSrc"));

        gridLayout_3->addWidget(labelEpisodeNameSrc, 3, 0, 1, 1);

        labelAudio = new QLabel(gridLayoutWidget);
        labelAudio->setObjectName(QStringLiteral("labelAudio"));

        gridLayout_3->addWidget(labelAudio, 6, 0, 1, 1);

        editResolution = new QLineEdit(gridLayoutWidget);
        editResolution->setObjectName(QStringLiteral("editResolution"));

        gridLayout_3->addWidget(editResolution, 7, 1, 1, 1);

        editName = new QLineEdit(gridLayoutWidget);
        editName->setObjectName(QStringLiteral("editName"));

        gridLayout_3->addWidget(editName, 0, 1, 1, 1);

        labelScreneGrp = new QLabel(gridLayoutWidget);
        labelScreneGrp->setObjectName(QStringLiteral("labelScreneGrp"));

        gridLayout_3->addWidget(labelScreneGrp, 10, 0, 1, 1);

        labelEpisodeNrPrefix = new QLabel(gridLayoutWidget);
        labelEpisodeNrPrefix->setObjectName(QStringLiteral("labelEpisodeNrPrefix"));

        gridLayout_3->addWidget(labelEpisodeNrPrefix, 2, 0, 1, 1);

        labelSeriesNrPrefix = new QLabel(gridLayoutWidget);
        labelSeriesNrPrefix->setObjectName(QStringLiteral("labelSeriesNrPrefix"));

        gridLayout_3->addWidget(labelSeriesNrPrefix, 1, 0, 1, 1);

        editVideo = new QLineEdit(gridLayoutWidget);
        editVideo->setObjectName(QStringLiteral("editVideo"));

        gridLayout_3->addWidget(editVideo, 8, 1, 1, 1);

        labelSource = new QLabel(gridLayoutWidget);
        labelSource->setObjectName(QStringLiteral("labelSource"));

        gridLayout_3->addWidget(labelSource, 9, 0, 1, 1);

        editSeriesNrDigits = new QLineEdit(gridLayoutWidget);
        editSeriesNrDigits->setObjectName(QStringLiteral("editSeriesNrDigits"));

        gridLayout_3->addWidget(editSeriesNrDigits, 1, 3, 1, 1);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout_3->addWidget(labelName, 0, 0, 1, 1);

        editAudio = new QLineEdit(gridLayoutWidget);
        editAudio->setObjectName(QStringLiteral("editAudio"));

        gridLayout_3->addWidget(editAudio, 6, 1, 1, 1);

        labelResolution = new QLabel(gridLayoutWidget);
        labelResolution->setObjectName(QStringLiteral("labelResolution"));

        gridLayout_3->addWidget(labelResolution, 7, 0, 1, 1);

        labelEpisodeNameLang = new QLabel(gridLayoutWidget);
        labelEpisodeNameLang->setObjectName(QStringLiteral("labelEpisodeNameLang"));

        gridLayout_3->addWidget(labelEpisodeNameLang, 3, 2, 1, 1);

        labelVideo = new QLabel(gridLayoutWidget);
        labelVideo->setObjectName(QStringLiteral("labelVideo"));

        gridLayout_3->addWidget(labelVideo, 8, 0, 1, 1);

        comboEpisodeNameSrc = new QComboBox(gridLayoutWidget);
        comboEpisodeNameSrc->setObjectName(QStringLiteral("comboEpisodeNameSrc"));

        gridLayout_3->addWidget(comboEpisodeNameSrc, 3, 1, 1, 1);

        editSceneGrp = new QLineEdit(gridLayoutWidget);
        editSceneGrp->setObjectName(QStringLiteral("editSceneGrp"));

        gridLayout_3->addWidget(editSceneGrp, 10, 1, 1, 1);

        checkBoxEpDetection = new QCheckBox(tab_2);
        checkBoxEpDetection->setObjectName(QStringLiteral("checkBoxEpDetection"));
        checkBoxEpDetection->setGeometry(QRect(10, 320, 231, 17));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 2);

        ShikiRenameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShikiRenameClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1288, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        ShikiRenameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ShikiRenameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ShikiRenameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ShikiRenameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ShikiRenameClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(ShikiRenameClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ShikiRenameClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShikiRenameClass)
    {
        ShikiRenameClass->setWindowTitle(QApplication::translate("ShikiRenameClass", "ShikiRename", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ShikiRenameClass", "Open Directory ...", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("ShikiRenameClass", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("ShikiRenameClass", "Redo", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ShikiRenameClass", "Rename", Q_NULLPTR));
        checkboxOnlySelected->setText(QApplication::translate("ShikiRenameClass", "Rename only selected entries", Q_NULLPTR));
        labelRemoveLeft2->setText(QApplication::translate("ShikiRenameClass", "characters", Q_NULLPTR));
        labelRemoveRight2->setText(QApplication::translate("ShikiRenameClass", "characters", Q_NULLPTR));
        labelInsert1->setText(QApplication::translate("ShikiRenameClass", "Insert at index", Q_NULLPTR));
        labelRemoveAt1->setText(QApplication::translate("ShikiRenameClass", "Remove", Q_NULLPTR));
        labelReplace2->setText(QApplication::translate("ShikiRenameClass", "with", Q_NULLPTR));
        editRemoveLeft->setText(QString());
        editRemoveLeft->setPlaceholderText(QApplication::translate("ShikiRenameClass", "0", Q_NULLPTR));
        labelPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix filename", Q_NULLPTR));
        labelSuffix->setText(QApplication::translate("ShikiRenameClass", "Suffix filename", Q_NULLPTR));
        labelNumIdx->setText(QApplication::translate("ShikiRenameClass", "Number at index", Q_NULLPTR));
        labelRemoveAt2->setText(QApplication::translate("ShikiRenameClass", "characters past index", Q_NULLPTR));
        editRemoveRight->setPlaceholderText(QApplication::translate("ShikiRenameClass", "0", Q_NULLPTR));
        labelRemoveLeft1->setText(QApplication::translate("ShikiRenameClass", "Remove the first", Q_NULLPTR));
        labelReplace1->setText(QApplication::translate("ShikiRenameClass", "Replace", Q_NULLPTR));
        labelRemoveRight1->setText(QApplication::translate("ShikiRenameClass", "Remove last", Q_NULLPTR));
        editRemoveAt1->setPlaceholderText(QApplication::translate("ShikiRenameClass", "0", Q_NULLPTR));
        labelInsert2->setText(QApplication::translate("ShikiRenameClass", "the text", Q_NULLPTR));
        labelNumDigits2->setText(QApplication::translate("ShikiRenameClass", "digits", Q_NULLPTR));
        editNumInc->setText(QString());
        editNumInc->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", Q_NULLPTR));
        labelNumDigits->setText(QApplication::translate("ShikiRenameClass", "using", Q_NULLPTR));
        labelNumInc->setText(QApplication::translate("ShikiRenameClass", "incrementing by", Q_NULLPTR));
        editNumInitV->setText(QString());
        editNumInitV->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", Q_NULLPTR));
        labelNumInitV->setText(QApplication::translate("ShikiRenameClass", "starting with", Q_NULLPTR));
        editNumDigits->setText(QString());
        editNumDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ShikiRenameClass", "Edit", Q_NULLPTR));
        editSeriesNrPrefix->setText(QString());
        editEpisodeNrPrefix->setText(QString());
        labelEpisodeNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", Q_NULLPTR));
        labelYear->setText(QApplication::translate("ShikiRenameClass", "Release Year", Q_NULLPTR));
        editEpisodeNrDigits->setText(QString());
        editEpisodeNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", Q_NULLPTR));
        labelSeriesNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", Q_NULLPTR));
        labelEpisodeNameSrc->setText(QApplication::translate("ShikiRenameClass", "Episode Name Source", Q_NULLPTR));
        labelAudio->setText(QApplication::translate("ShikiRenameClass", "Audio Info", Q_NULLPTR));
        labelScreneGrp->setText(QApplication::translate("ShikiRenameClass", "Scene Group", Q_NULLPTR));
        labelEpisodeNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Episode Number", Q_NULLPTR));
        labelSeriesNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Series Number", Q_NULLPTR));
        labelSource->setText(QApplication::translate("ShikiRenameClass", "Source", Q_NULLPTR));
        editSeriesNrDigits->setText(QString());
        editSeriesNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", Q_NULLPTR));
        labelName->setText(QApplication::translate("ShikiRenameClass", "Name", Q_NULLPTR));
        labelResolution->setText(QApplication::translate("ShikiRenameClass", "Video Resolution", Q_NULLPTR));
        labelEpisodeNameLang->setText(QApplication::translate("ShikiRenameClass", "Language", Q_NULLPTR));
        labelVideo->setText(QApplication::translate("ShikiRenameClass", "Video Info", Q_NULLPTR));
        comboEpisodeNameSrc->clear();
        comboEpisodeNameSrc->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("ShikiRenameClass", "TheTVDB.com", Q_NULLPTR)
        );
        checkBoxEpDetection->setText(QApplication::translate("ShikiRenameClass", "Auto-detect season and episode numbers", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ShikiRenameClass", "Movies / Episodes", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("ShikiRenameClass", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("ShikiRenameClass", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShikiRenameClass: public Ui_ShikiRenameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIKIRENAME_H
