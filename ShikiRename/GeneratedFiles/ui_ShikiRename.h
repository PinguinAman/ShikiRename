/********************************************************************************
** Form generated from reading UI file 'ShikiRename.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIKIRENAME_H
#define UI_SHIKIRENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShikiRenameClass
{
public:
    QAction *actionOpen;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionQuit;
    QAction *actionRefresh;
    QWidget *centralWidget;
    QGridLayout *gLayout_centralWidget;
    QPushButton *buttonRename;
    QVBoxLayout *vLayout_Main;
    QHBoxLayout *hLayout_Directory;
    QPushButton *buttonOpen;
    QLineEdit *editDirectory;
    QHBoxLayout *hLayout_Lists;
    QListWidget *currentList;
    QListWidget *renamePreview;
    QCheckBox *checkboxOnlySelected;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *layoutWidget;
    QGridLayout *tab_1_gridLayout;
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
    QGridLayout *tab_2_gridLayout;
    QLineEdit *editSeasonNrPrefix;
    QLabel *labelResolution;
    QLineEdit *editEpisodeNrPrefix;
    QComboBox *comboEpisodeNameSrc;
    QLabel *labelEpisodeNameLang;
    QLabel *labelName;
    QLineEdit *editSceneGrp;
    QLineEdit *editSource;
    QLabel *labelEpisodeNrDigits;
    QLabel *labelEpisodeNameSrc;
    QLineEdit *editAudio;
    QLabel *labelEpisodeNrPrefix;
    QLabel *labelAudio;
    QLineEdit *editYear;
    QLabel *labelVideo;
    QLabel *labelYear;
    QLabel *labelSource;
    QLabel *labelScreneGrp;
    QCheckBox *checkboxCustomFileName;
    QLabel *label;
    QLabel *labelSeasonNrDigits;
    QLabel *labelSeasonNrPrefix;
    QPushButton *buttonCustomFileNameReset;
    QLineEdit *editLang;
    QLineEdit *editResolution;
    QComboBox *comboEpisodeNameLang;
    QLineEdit *editVideo;
    QLineEdit *editName;
    QLineEdit *editCustomFileName;
    QFrame *labelLang;
    QLineEdit *editSeasonNrDigits;
    QLineEdit *editEpisodeNrDigits;
    QCheckBox *checkboxNoSeason;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShikiRenameClass)
    {
        if (ShikiRenameClass->objectName().isEmpty())
            ShikiRenameClass->setObjectName(QString::fromUtf8("ShikiRenameClass"));
        ShikiRenameClass->resize(1387, 887);
        actionOpen = new QAction(ShikiRenameClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionUndo = new QAction(ShikiRenameClass);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(ShikiRenameClass);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionQuit = new QAction(ShikiRenameClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionRefresh = new QAction(ShikiRenameClass);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        centralWidget = new QWidget(ShikiRenameClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setToolTipDuration(-1);
        gLayout_centralWidget = new QGridLayout(centralWidget);
        gLayout_centralWidget->setSpacing(6);
        gLayout_centralWidget->setContentsMargins(11, 11, 11, 11);
        gLayout_centralWidget->setObjectName(QString::fromUtf8("gLayout_centralWidget"));
        gLayout_centralWidget->setContentsMargins(8, 8, 8, 8);
        buttonRename = new QPushButton(centralWidget);
        buttonRename->setObjectName(QString::fromUtf8("buttonRename"));

        gLayout_centralWidget->addWidget(buttonRename, 2, 3, 1, 1);

        vLayout_Main = new QVBoxLayout();
        vLayout_Main->setSpacing(6);
        vLayout_Main->setObjectName(QString::fromUtf8("vLayout_Main"));
        vLayout_Main->setSizeConstraint(QLayout::SetDefaultConstraint);
        vLayout_Main->setContentsMargins(0, -1, -1, -1);
        hLayout_Directory = new QHBoxLayout();
        hLayout_Directory->setSpacing(6);
        hLayout_Directory->setObjectName(QString::fromUtf8("hLayout_Directory"));
        buttonOpen = new QPushButton(centralWidget);
        buttonOpen->setObjectName(QString::fromUtf8("buttonOpen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy);
        buttonOpen->setMinimumSize(QSize(24, 24));
        buttonOpen->setMaximumSize(QSize(24, 24));

        hLayout_Directory->addWidget(buttonOpen);

        editDirectory = new QLineEdit(centralWidget);
        editDirectory->setObjectName(QString::fromUtf8("editDirectory"));

        hLayout_Directory->addWidget(editDirectory);


        vLayout_Main->addLayout(hLayout_Directory);

        hLayout_Lists = new QHBoxLayout();
        hLayout_Lists->setSpacing(6);
        hLayout_Lists->setObjectName(QString::fromUtf8("hLayout_Lists"));
        currentList = new QListWidget(centralWidget);
        currentList->setObjectName(QString::fromUtf8("currentList"));
        currentList->setMaximumSize(QSize(16777215, 16777215));

        hLayout_Lists->addWidget(currentList);

        renamePreview = new QListWidget(centralWidget);
        renamePreview->setObjectName(QString::fromUtf8("renamePreview"));

        hLayout_Lists->addWidget(renamePreview);


        vLayout_Main->addLayout(hLayout_Lists);

        checkboxOnlySelected = new QCheckBox(centralWidget);
        checkboxOnlySelected->setObjectName(QString::fromUtf8("checkboxOnlySelected"));

        vLayout_Main->addWidget(checkboxOnlySelected);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        layoutWidget = new QWidget(tab_1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 1241, 144));
        tab_1_gridLayout = new QGridLayout(layoutWidget);
        tab_1_gridLayout->setSpacing(6);
        tab_1_gridLayout->setContentsMargins(11, 11, 11, 11);
        tab_1_gridLayout->setObjectName(QString::fromUtf8("tab_1_gridLayout"));
        tab_1_gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tab_1_gridLayout->setContentsMargins(10, 10, 10, 10);
        editRemoveAt2 = new QLineEdit(layoutWidget);
        editRemoveAt2->setObjectName(QString::fromUtf8("editRemoveAt2"));

        tab_1_gridLayout->addWidget(editRemoveAt2, 2, 8, 1, 1);

        labelRemoveLeft2 = new QLabel(layoutWidget);
        labelRemoveLeft2->setObjectName(QString::fromUtf8("labelRemoveLeft2"));

        tab_1_gridLayout->addWidget(labelRemoveLeft2, 0, 2, 1, 1);

        labelRemoveRight2 = new QLabel(layoutWidget);
        labelRemoveRight2->setObjectName(QString::fromUtf8("labelRemoveRight2"));

        tab_1_gridLayout->addWidget(labelRemoveRight2, 0, 7, 1, 1);

        labelInsert1 = new QLabel(layoutWidget);
        labelInsert1->setObjectName(QString::fromUtf8("labelInsert1"));

        tab_1_gridLayout->addWidget(labelInsert1, 2, 0, 1, 1);

        labelRemoveAt1 = new QLabel(layoutWidget);
        labelRemoveAt1->setObjectName(QString::fromUtf8("labelRemoveAt1"));

        tab_1_gridLayout->addWidget(labelRemoveAt1, 2, 5, 1, 1);

        labelReplace2 = new QLabel(layoutWidget);
        labelReplace2->setObjectName(QString::fromUtf8("labelReplace2"));

        tab_1_gridLayout->addWidget(labelReplace2, 1, 2, 1, 1);

        editInsert1 = new QLineEdit(layoutWidget);
        editInsert1->setObjectName(QString::fromUtf8("editInsert1"));

        tab_1_gridLayout->addWidget(editInsert1, 2, 1, 1, 1);

        editRemoveLeft = new QLineEdit(layoutWidget);
        editRemoveLeft->setObjectName(QString::fromUtf8("editRemoveLeft"));

        tab_1_gridLayout->addWidget(editRemoveLeft, 0, 1, 1, 1);

        labelPrefix = new QLabel(layoutWidget);
        labelPrefix->setObjectName(QString::fromUtf8("labelPrefix"));

        tab_1_gridLayout->addWidget(labelPrefix, 3, 0, 1, 1);

        labelSuffix = new QLabel(layoutWidget);
        labelSuffix->setObjectName(QString::fromUtf8("labelSuffix"));

        tab_1_gridLayout->addWidget(labelSuffix, 3, 5, 1, 1);

        editSuffix = new QLineEdit(layoutWidget);
        editSuffix->setObjectName(QString::fromUtf8("editSuffix"));

        tab_1_gridLayout->addWidget(editSuffix, 3, 6, 1, 1);

        labelNumIdx = new QLabel(layoutWidget);
        labelNumIdx->setObjectName(QString::fromUtf8("labelNumIdx"));

        tab_1_gridLayout->addWidget(labelNumIdx, 4, 0, 1, 1);

        editNumIdx = new QLineEdit(layoutWidget);
        editNumIdx->setObjectName(QString::fromUtf8("editNumIdx"));

        tab_1_gridLayout->addWidget(editNumIdx, 4, 1, 1, 1);

        editPrefix = new QLineEdit(layoutWidget);
        editPrefix->setObjectName(QString::fromUtf8("editPrefix"));

        tab_1_gridLayout->addWidget(editPrefix, 3, 1, 1, 1);

        labelRemoveAt2 = new QLabel(layoutWidget);
        labelRemoveAt2->setObjectName(QString::fromUtf8("labelRemoveAt2"));

        tab_1_gridLayout->addWidget(labelRemoveAt2, 2, 7, 1, 1);

        editReplace2 = new QLineEdit(layoutWidget);
        editReplace2->setObjectName(QString::fromUtf8("editReplace2"));

        tab_1_gridLayout->addWidget(editReplace2, 1, 3, 1, 1);

        editRemoveRight = new QLineEdit(layoutWidget);
        editRemoveRight->setObjectName(QString::fromUtf8("editRemoveRight"));

        tab_1_gridLayout->addWidget(editRemoveRight, 0, 6, 1, 1);

        labelRemoveLeft1 = new QLabel(layoutWidget);
        labelRemoveLeft1->setObjectName(QString::fromUtf8("labelRemoveLeft1"));

        tab_1_gridLayout->addWidget(labelRemoveLeft1, 0, 0, 1, 1);

        labelReplace1 = new QLabel(layoutWidget);
        labelReplace1->setObjectName(QString::fromUtf8("labelReplace1"));

        tab_1_gridLayout->addWidget(labelReplace1, 1, 0, 1, 1);

        labelRemoveRight1 = new QLabel(layoutWidget);
        labelRemoveRight1->setObjectName(QString::fromUtf8("labelRemoveRight1"));

        tab_1_gridLayout->addWidget(labelRemoveRight1, 0, 5, 1, 1);

        editRemoveAt1 = new QLineEdit(layoutWidget);
        editRemoveAt1->setObjectName(QString::fromUtf8("editRemoveAt1"));

        tab_1_gridLayout->addWidget(editRemoveAt1, 2, 6, 1, 1);

        editReplace1 = new QLineEdit(layoutWidget);
        editReplace1->setObjectName(QString::fromUtf8("editReplace1"));

        tab_1_gridLayout->addWidget(editReplace1, 1, 1, 1, 1);

        labelInsert2 = new QLabel(layoutWidget);
        labelInsert2->setObjectName(QString::fromUtf8("labelInsert2"));

        tab_1_gridLayout->addWidget(labelInsert2, 2, 2, 1, 1);

        editInsert2 = new QLineEdit(layoutWidget);
        editInsert2->setObjectName(QString::fromUtf8("editInsert2"));

        tab_1_gridLayout->addWidget(editInsert2, 2, 3, 1, 1);

        labelNumDigits2 = new QLabel(layoutWidget);
        labelNumDigits2->setObjectName(QString::fromUtf8("labelNumDigits2"));

        tab_1_gridLayout->addWidget(labelNumDigits2, 4, 9, 1, 1);

        editNumInc = new QLineEdit(layoutWidget);
        editNumInc->setObjectName(QString::fromUtf8("editNumInc"));

        tab_1_gridLayout->addWidget(editNumInc, 4, 6, 1, 1);

        labelNumDigits = new QLabel(layoutWidget);
        labelNumDigits->setObjectName(QString::fromUtf8("labelNumDigits"));

        tab_1_gridLayout->addWidget(labelNumDigits, 4, 7, 1, 1);

        labelNumInc = new QLabel(layoutWidget);
        labelNumInc->setObjectName(QString::fromUtf8("labelNumInc"));

        tab_1_gridLayout->addWidget(labelNumInc, 4, 5, 1, 1);

        editNumInitV = new QLineEdit(layoutWidget);
        editNumInitV->setObjectName(QString::fromUtf8("editNumInitV"));

        tab_1_gridLayout->addWidget(editNumInitV, 4, 3, 1, 1);

        labelNumInitV = new QLabel(layoutWidget);
        labelNumInitV->setObjectName(QString::fromUtf8("labelNumInitV"));

        tab_1_gridLayout->addWidget(labelNumInitV, 4, 2, 1, 1);

        editNumDigits = new QLineEdit(layoutWidget);
        editNumDigits->setObjectName(QString::fromUtf8("editNumDigits"));

        tab_1_gridLayout->addWidget(editNumDigits, 4, 8, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        tab_1_gridLayout->addWidget(line, 0, 4, 5, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1071, 260));
        tab_2_gridLayout = new QGridLayout(gridLayoutWidget);
        tab_2_gridLayout->setSpacing(6);
        tab_2_gridLayout->setContentsMargins(11, 11, 11, 11);
        tab_2_gridLayout->setObjectName(QString::fromUtf8("tab_2_gridLayout"));
        tab_2_gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tab_2_gridLayout->setContentsMargins(10, 10, 10, 10);
        editSeasonNrPrefix = new QLineEdit(gridLayoutWidget);
        editSeasonNrPrefix->setObjectName(QString::fromUtf8("editSeasonNrPrefix"));

        tab_2_gridLayout->addWidget(editSeasonNrPrefix, 2, 1, 1, 1);

        labelResolution = new QLabel(gridLayoutWidget);
        labelResolution->setObjectName(QString::fromUtf8("labelResolution"));

        tab_2_gridLayout->addWidget(labelResolution, 7, 2, 1, 1);

        editEpisodeNrPrefix = new QLineEdit(gridLayoutWidget);
        editEpisodeNrPrefix->setObjectName(QString::fromUtf8("editEpisodeNrPrefix"));

        tab_2_gridLayout->addWidget(editEpisodeNrPrefix, 3, 1, 1, 1);

        comboEpisodeNameSrc = new QComboBox(gridLayoutWidget);
        comboEpisodeNameSrc->addItem(QString());
        comboEpisodeNameSrc->addItem(QString());
        comboEpisodeNameSrc->setObjectName(QString::fromUtf8("comboEpisodeNameSrc"));

        tab_2_gridLayout->addWidget(comboEpisodeNameSrc, 4, 1, 1, 1);

        labelEpisodeNameLang = new QLabel(gridLayoutWidget);
        labelEpisodeNameLang->setObjectName(QString::fromUtf8("labelEpisodeNameLang"));

        tab_2_gridLayout->addWidget(labelEpisodeNameLang, 4, 2, 1, 1);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        tab_2_gridLayout->addWidget(labelName, 1, 0, 1, 1);

        editSceneGrp = new QLineEdit(gridLayoutWidget);
        editSceneGrp->setObjectName(QString::fromUtf8("editSceneGrp"));

        tab_2_gridLayout->addWidget(editSceneGrp, 9, 1, 1, 1);

        editSource = new QLineEdit(gridLayoutWidget);
        editSource->setObjectName(QString::fromUtf8("editSource"));

        tab_2_gridLayout->addWidget(editSource, 8, 1, 1, 1);

        labelEpisodeNrDigits = new QLabel(gridLayoutWidget);
        labelEpisodeNrDigits->setObjectName(QString::fromUtf8("labelEpisodeNrDigits"));

        tab_2_gridLayout->addWidget(labelEpisodeNrDigits, 3, 2, 1, 1);

        labelEpisodeNameSrc = new QLabel(gridLayoutWidget);
        labelEpisodeNameSrc->setObjectName(QString::fromUtf8("labelEpisodeNameSrc"));

        tab_2_gridLayout->addWidget(labelEpisodeNameSrc, 4, 0, 1, 1);

        editAudio = new QLineEdit(gridLayoutWidget);
        editAudio->setObjectName(QString::fromUtf8("editAudio"));

        tab_2_gridLayout->addWidget(editAudio, 7, 1, 1, 1);

        labelEpisodeNrPrefix = new QLabel(gridLayoutWidget);
        labelEpisodeNrPrefix->setObjectName(QString::fromUtf8("labelEpisodeNrPrefix"));

        tab_2_gridLayout->addWidget(labelEpisodeNrPrefix, 3, 0, 1, 1);

        labelAudio = new QLabel(gridLayoutWidget);
        labelAudio->setObjectName(QString::fromUtf8("labelAudio"));

        tab_2_gridLayout->addWidget(labelAudio, 7, 0, 1, 1);

        editYear = new QLineEdit(gridLayoutWidget);
        editYear->setObjectName(QString::fromUtf8("editYear"));

        tab_2_gridLayout->addWidget(editYear, 6, 1, 1, 1);

        labelVideo = new QLabel(gridLayoutWidget);
        labelVideo->setObjectName(QString::fromUtf8("labelVideo"));

        tab_2_gridLayout->addWidget(labelVideo, 8, 2, 1, 1);

        labelYear = new QLabel(gridLayoutWidget);
        labelYear->setObjectName(QString::fromUtf8("labelYear"));

        tab_2_gridLayout->addWidget(labelYear, 6, 0, 1, 1);

        labelSource = new QLabel(gridLayoutWidget);
        labelSource->setObjectName(QString::fromUtf8("labelSource"));

        tab_2_gridLayout->addWidget(labelSource, 8, 0, 1, 1);

        labelScreneGrp = new QLabel(gridLayoutWidget);
        labelScreneGrp->setObjectName(QString::fromUtf8("labelScreneGrp"));

        tab_2_gridLayout->addWidget(labelScreneGrp, 9, 0, 1, 1);

        checkboxCustomFileName = new QCheckBox(gridLayoutWidget);
        checkboxCustomFileName->setObjectName(QString::fromUtf8("checkboxCustomFileName"));

        tab_2_gridLayout->addWidget(checkboxCustomFileName, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        tab_2_gridLayout->addWidget(label, 6, 2, 1, 1);

        labelSeasonNrDigits = new QLabel(gridLayoutWidget);
        labelSeasonNrDigits->setObjectName(QString::fromUtf8("labelSeasonNrDigits"));

        tab_2_gridLayout->addWidget(labelSeasonNrDigits, 2, 2, 1, 1);

        labelSeasonNrPrefix = new QLabel(gridLayoutWidget);
        labelSeasonNrPrefix->setObjectName(QString::fromUtf8("labelSeasonNrPrefix"));

        tab_2_gridLayout->addWidget(labelSeasonNrPrefix, 2, 0, 1, 1);

        buttonCustomFileNameReset = new QPushButton(gridLayoutWidget);
        buttonCustomFileNameReset->setObjectName(QString::fromUtf8("buttonCustomFileNameReset"));

        tab_2_gridLayout->addWidget(buttonCustomFileNameReset, 0, 4, 1, 1);

        editLang = new QLineEdit(gridLayoutWidget);
        editLang->setObjectName(QString::fromUtf8("editLang"));

        tab_2_gridLayout->addWidget(editLang, 6, 3, 1, 2);

        editResolution = new QLineEdit(gridLayoutWidget);
        editResolution->setObjectName(QString::fromUtf8("editResolution"));

        tab_2_gridLayout->addWidget(editResolution, 7, 3, 1, 2);

        comboEpisodeNameLang = new QComboBox(gridLayoutWidget);
        comboEpisodeNameLang->setObjectName(QString::fromUtf8("comboEpisodeNameLang"));

        tab_2_gridLayout->addWidget(comboEpisodeNameLang, 4, 3, 1, 2);

        editVideo = new QLineEdit(gridLayoutWidget);
        editVideo->setObjectName(QString::fromUtf8("editVideo"));

        tab_2_gridLayout->addWidget(editVideo, 8, 3, 1, 2);

        editName = new QLineEdit(gridLayoutWidget);
        editName->setObjectName(QString::fromUtf8("editName"));

        tab_2_gridLayout->addWidget(editName, 1, 1, 1, 4);

        editCustomFileName = new QLineEdit(gridLayoutWidget);
        editCustomFileName->setObjectName(QString::fromUtf8("editCustomFileName"));

        tab_2_gridLayout->addWidget(editCustomFileName, 0, 1, 1, 3);

        labelLang = new QFrame(gridLayoutWidget);
        labelLang->setObjectName(QString::fromUtf8("labelLang"));
        labelLang->setFrameShape(QFrame::HLine);
        labelLang->setFrameShadow(QFrame::Sunken);

        tab_2_gridLayout->addWidget(labelLang, 5, 0, 1, 5);

        editSeasonNrDigits = new QLineEdit(gridLayoutWidget);
        editSeasonNrDigits->setObjectName(QString::fromUtf8("editSeasonNrDigits"));

        tab_2_gridLayout->addWidget(editSeasonNrDigits, 2, 3, 1, 1);

        editEpisodeNrDigits = new QLineEdit(gridLayoutWidget);
        editEpisodeNrDigits->setObjectName(QString::fromUtf8("editEpisodeNrDigits"));

        tab_2_gridLayout->addWidget(editEpisodeNrDigits, 3, 3, 1, 1);

        checkboxNoSeason = new QCheckBox(gridLayoutWidget);
        checkboxNoSeason->setObjectName(QString::fromUtf8("checkboxNoSeason"));

        tab_2_gridLayout->addWidget(checkboxNoSeason, 2, 4, 2, 1);

        tab_2_gridLayout->setColumnStretch(1, 25);
        tab_2_gridLayout->setColumnStretch(3, 25);
        tabWidget->addTab(tab_2, QString());

        vLayout_Main->addWidget(tabWidget);

        vLayout_Main->setStretch(1, 100);
        vLayout_Main->setStretch(3, 70);

        gLayout_centralWidget->addLayout(vLayout_Main, 1, 2, 1, 2);

        ShikiRenameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShikiRenameClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1387, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        ShikiRenameClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ShikiRenameClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ShikiRenameClass->setStatusBar(statusBar);
        QWidget::setTabOrder(currentList, renamePreview);
        QWidget::setTabOrder(renamePreview, checkboxOnlySelected);
        QWidget::setTabOrder(checkboxOnlySelected, tabWidget);
        QWidget::setTabOrder(tabWidget, editRemoveLeft);
        QWidget::setTabOrder(editRemoveLeft, editRemoveRight);
        QWidget::setTabOrder(editRemoveRight, editReplace1);
        QWidget::setTabOrder(editReplace1, editReplace2);
        QWidget::setTabOrder(editReplace2, editInsert1);
        QWidget::setTabOrder(editInsert1, editInsert2);
        QWidget::setTabOrder(editInsert2, editRemoveAt1);
        QWidget::setTabOrder(editRemoveAt1, editRemoveAt2);
        QWidget::setTabOrder(editRemoveAt2, editPrefix);
        QWidget::setTabOrder(editPrefix, editSuffix);
        QWidget::setTabOrder(editSuffix, editNumIdx);
        QWidget::setTabOrder(editNumIdx, editNumInitV);
        QWidget::setTabOrder(editNumInitV, editNumInc);
        QWidget::setTabOrder(editNumInc, editNumDigits);
        QWidget::setTabOrder(editNumDigits, editName);
        QWidget::setTabOrder(editName, editSeasonNrPrefix);
        QWidget::setTabOrder(editSeasonNrPrefix, editSeasonNrDigits);
        QWidget::setTabOrder(editSeasonNrDigits, editEpisodeNrPrefix);
        QWidget::setTabOrder(editEpisodeNrPrefix, editEpisodeNrDigits);
        QWidget::setTabOrder(editEpisodeNrDigits, comboEpisodeNameSrc);
        QWidget::setTabOrder(comboEpisodeNameSrc, comboEpisodeNameLang);
        QWidget::setTabOrder(comboEpisodeNameLang, editYear);
        QWidget::setTabOrder(editYear, buttonRename);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionRefresh);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(ShikiRenameClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ShikiRenameClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShikiRenameClass)
    {
        ShikiRenameClass->setWindowTitle(QApplication::translate("ShikiRenameClass", "ShikiRename", nullptr));
        actionOpen->setText(QApplication::translate("ShikiRenameClass", "Open Directory ...", nullptr));
        actionUndo->setText(QApplication::translate("ShikiRenameClass", "Undo", nullptr));
        actionRedo->setText(QApplication::translate("ShikiRenameClass", "Redo", nullptr));
        actionQuit->setText(QApplication::translate("ShikiRenameClass", "Quit", nullptr));
        actionRefresh->setText(QApplication::translate("ShikiRenameClass", "Refresh", nullptr));
        buttonRename->setText(QApplication::translate("ShikiRenameClass", "Rename", nullptr));
        buttonOpen->setText(QString());
        checkboxOnlySelected->setText(QApplication::translate("ShikiRenameClass", "Rename only selected entries", nullptr));
        labelRemoveLeft2->setText(QApplication::translate("ShikiRenameClass", "characters", nullptr));
        labelRemoveRight2->setText(QApplication::translate("ShikiRenameClass", "characters", nullptr));
        labelInsert1->setText(QApplication::translate("ShikiRenameClass", "Insert at index", nullptr));
        labelRemoveAt1->setText(QApplication::translate("ShikiRenameClass", "Remove", nullptr));
        labelReplace2->setText(QApplication::translate("ShikiRenameClass", "with", nullptr));
        editRemoveLeft->setText(QString());
        editRemoveLeft->setPlaceholderText(QApplication::translate("ShikiRenameClass", "0", nullptr));
        labelPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix filename", nullptr));
        labelSuffix->setText(QApplication::translate("ShikiRenameClass", "Suffix filename", nullptr));
        labelNumIdx->setText(QApplication::translate("ShikiRenameClass", "Number at index", nullptr));
        labelRemoveAt2->setText(QApplication::translate("ShikiRenameClass", "characters past index", nullptr));
        editRemoveRight->setPlaceholderText(QApplication::translate("ShikiRenameClass", "0", nullptr));
        labelRemoveLeft1->setText(QApplication::translate("ShikiRenameClass", "Remove the first", nullptr));
        labelReplace1->setText(QApplication::translate("ShikiRenameClass", "Replace", nullptr));
        labelRemoveRight1->setText(QApplication::translate("ShikiRenameClass", "Remove last", nullptr));
        editRemoveAt1->setPlaceholderText(QApplication::translate("ShikiRenameClass", "0", nullptr));
        labelInsert2->setText(QApplication::translate("ShikiRenameClass", "the text", nullptr));
        labelNumDigits2->setText(QApplication::translate("ShikiRenameClass", "digits", nullptr));
        editNumInc->setText(QString());
        editNumInc->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", nullptr));
        labelNumDigits->setText(QApplication::translate("ShikiRenameClass", "using", nullptr));
        labelNumInc->setText(QApplication::translate("ShikiRenameClass", "incrementing by", nullptr));
        editNumInitV->setText(QString());
        editNumInitV->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", nullptr));
        labelNumInitV->setText(QApplication::translate("ShikiRenameClass", "starting with", nullptr));
        editNumDigits->setText(QString());
        editNumDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("ShikiRenameClass", "Edit", nullptr));
        editSeasonNrPrefix->setText(QString());
        editSeasonNrPrefix->setPlaceholderText(QApplication::translate("ShikiRenameClass", "s", nullptr));
        labelResolution->setText(QApplication::translate("ShikiRenameClass", "Video Resolution", nullptr));
        editEpisodeNrPrefix->setText(QString());
        editEpisodeNrPrefix->setPlaceholderText(QApplication::translate("ShikiRenameClass", "e", nullptr));
        comboEpisodeNameSrc->setItemText(0, QString());
        comboEpisodeNameSrc->setItemText(1, QApplication::translate("ShikiRenameClass", "TheTVDB.com", nullptr));

        labelEpisodeNameLang->setText(QApplication::translate("ShikiRenameClass", "Language", nullptr));
        labelName->setText(QApplication::translate("ShikiRenameClass", "Name", nullptr));
        labelEpisodeNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", nullptr));
        labelEpisodeNameSrc->setText(QApplication::translate("ShikiRenameClass", "Episode Name Source", nullptr));
        labelEpisodeNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Episode Number", nullptr));
        labelAudio->setText(QApplication::translate("ShikiRenameClass", "Audio Info", nullptr));
        labelVideo->setText(QApplication::translate("ShikiRenameClass", "Video Info", nullptr));
        labelYear->setText(QApplication::translate("ShikiRenameClass", "Release Year", nullptr));
        labelSource->setText(QApplication::translate("ShikiRenameClass", "Source", nullptr));
        labelScreneGrp->setText(QApplication::translate("ShikiRenameClass", "Scene Group", nullptr));
        checkboxCustomFileName->setText(QApplication::translate("ShikiRenameClass", "Customize File Name", nullptr));
        label->setText(QApplication::translate("ShikiRenameClass", "Language", nullptr));
        labelSeasonNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", nullptr));
        labelSeasonNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Season Number", nullptr));
        buttonCustomFileNameReset->setText(QApplication::translate("ShikiRenameClass", "Reset", nullptr));
        editSeasonNrDigits->setText(QString());
        editSeasonNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "2", nullptr));
        editEpisodeNrDigits->setText(QString());
        editEpisodeNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "2", nullptr));
        checkboxNoSeason->setText(QApplication::translate("ShikiRenameClass", "No season numbers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ShikiRenameClass", "Movies / Episodes", nullptr));
        menuFile->setTitle(QApplication::translate("ShikiRenameClass", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("ShikiRenameClass", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShikiRenameClass: public Ui_ShikiRenameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIKIRENAME_H
