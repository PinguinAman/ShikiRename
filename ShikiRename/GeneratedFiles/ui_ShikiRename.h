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
    QLineEdit *editSeriesNrPrefix;
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
    QLabel *labelSeriesNrDigits;
    QLabel *labelSeriesNrPrefix;
    QPushButton *buttonCustomFileNameReset;
    QLineEdit *editSeriesNrDigits;
    QLineEdit *editLang;
    QLineEdit *editEpisodeNrDigits;
    QLineEdit *editResolution;
    QComboBox *comboEpisodeNameLang;
    QLineEdit *editVideo;
    QLineEdit *editName;
    QLineEdit *editCustomFileName;
    QFrame *labelLang;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShikiRenameClass)
    {
        if (ShikiRenameClass->objectName().isEmpty())
            ShikiRenameClass->setObjectName(QStringLiteral("ShikiRenameClass"));
        ShikiRenameClass->resize(1533, 887);
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
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        currentList = new QListWidget(centralWidget);
        currentList->setObjectName(QStringLiteral("currentList"));
        currentList->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(currentList);

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
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        layoutWidget = new QWidget(tab_1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 1241, 144));
        tab_1_gridLayout = new QGridLayout(layoutWidget);
        tab_1_gridLayout->setSpacing(6);
        tab_1_gridLayout->setContentsMargins(11, 11, 11, 11);
        tab_1_gridLayout->setObjectName(QStringLiteral("tab_1_gridLayout"));
        tab_1_gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tab_1_gridLayout->setContentsMargins(10, 10, 10, 10);
        editRemoveAt2 = new QLineEdit(layoutWidget);
        editRemoveAt2->setObjectName(QStringLiteral("editRemoveAt2"));

        tab_1_gridLayout->addWidget(editRemoveAt2, 2, 8, 1, 1);

        labelRemoveLeft2 = new QLabel(layoutWidget);
        labelRemoveLeft2->setObjectName(QStringLiteral("labelRemoveLeft2"));

        tab_1_gridLayout->addWidget(labelRemoveLeft2, 0, 2, 1, 1);

        labelRemoveRight2 = new QLabel(layoutWidget);
        labelRemoveRight2->setObjectName(QStringLiteral("labelRemoveRight2"));

        tab_1_gridLayout->addWidget(labelRemoveRight2, 0, 7, 1, 1);

        labelInsert1 = new QLabel(layoutWidget);
        labelInsert1->setObjectName(QStringLiteral("labelInsert1"));

        tab_1_gridLayout->addWidget(labelInsert1, 2, 0, 1, 1);

        labelRemoveAt1 = new QLabel(layoutWidget);
        labelRemoveAt1->setObjectName(QStringLiteral("labelRemoveAt1"));

        tab_1_gridLayout->addWidget(labelRemoveAt1, 2, 5, 1, 1);

        labelReplace2 = new QLabel(layoutWidget);
        labelReplace2->setObjectName(QStringLiteral("labelReplace2"));

        tab_1_gridLayout->addWidget(labelReplace2, 1, 2, 1, 1);

        editInsert1 = new QLineEdit(layoutWidget);
        editInsert1->setObjectName(QStringLiteral("editInsert1"));

        tab_1_gridLayout->addWidget(editInsert1, 2, 1, 1, 1);

        editRemoveLeft = new QLineEdit(layoutWidget);
        editRemoveLeft->setObjectName(QStringLiteral("editRemoveLeft"));

        tab_1_gridLayout->addWidget(editRemoveLeft, 0, 1, 1, 1);

        labelPrefix = new QLabel(layoutWidget);
        labelPrefix->setObjectName(QStringLiteral("labelPrefix"));

        tab_1_gridLayout->addWidget(labelPrefix, 3, 0, 1, 1);

        labelSuffix = new QLabel(layoutWidget);
        labelSuffix->setObjectName(QStringLiteral("labelSuffix"));

        tab_1_gridLayout->addWidget(labelSuffix, 3, 5, 1, 1);

        editSuffix = new QLineEdit(layoutWidget);
        editSuffix->setObjectName(QStringLiteral("editSuffix"));

        tab_1_gridLayout->addWidget(editSuffix, 3, 6, 1, 1);

        labelNumIdx = new QLabel(layoutWidget);
        labelNumIdx->setObjectName(QStringLiteral("labelNumIdx"));

        tab_1_gridLayout->addWidget(labelNumIdx, 4, 0, 1, 1);

        editNumIdx = new QLineEdit(layoutWidget);
        editNumIdx->setObjectName(QStringLiteral("editNumIdx"));

        tab_1_gridLayout->addWidget(editNumIdx, 4, 1, 1, 1);

        editPrefix = new QLineEdit(layoutWidget);
        editPrefix->setObjectName(QStringLiteral("editPrefix"));

        tab_1_gridLayout->addWidget(editPrefix, 3, 1, 1, 1);

        labelRemoveAt2 = new QLabel(layoutWidget);
        labelRemoveAt2->setObjectName(QStringLiteral("labelRemoveAt2"));

        tab_1_gridLayout->addWidget(labelRemoveAt2, 2, 7, 1, 1);

        editReplace2 = new QLineEdit(layoutWidget);
        editReplace2->setObjectName(QStringLiteral("editReplace2"));

        tab_1_gridLayout->addWidget(editReplace2, 1, 3, 1, 1);

        editRemoveRight = new QLineEdit(layoutWidget);
        editRemoveRight->setObjectName(QStringLiteral("editRemoveRight"));

        tab_1_gridLayout->addWidget(editRemoveRight, 0, 6, 1, 1);

        labelRemoveLeft1 = new QLabel(layoutWidget);
        labelRemoveLeft1->setObjectName(QStringLiteral("labelRemoveLeft1"));

        tab_1_gridLayout->addWidget(labelRemoveLeft1, 0, 0, 1, 1);

        labelReplace1 = new QLabel(layoutWidget);
        labelReplace1->setObjectName(QStringLiteral("labelReplace1"));

        tab_1_gridLayout->addWidget(labelReplace1, 1, 0, 1, 1);

        labelRemoveRight1 = new QLabel(layoutWidget);
        labelRemoveRight1->setObjectName(QStringLiteral("labelRemoveRight1"));

        tab_1_gridLayout->addWidget(labelRemoveRight1, 0, 5, 1, 1);

        editRemoveAt1 = new QLineEdit(layoutWidget);
        editRemoveAt1->setObjectName(QStringLiteral("editRemoveAt1"));

        tab_1_gridLayout->addWidget(editRemoveAt1, 2, 6, 1, 1);

        editReplace1 = new QLineEdit(layoutWidget);
        editReplace1->setObjectName(QStringLiteral("editReplace1"));

        tab_1_gridLayout->addWidget(editReplace1, 1, 1, 1, 1);

        labelInsert2 = new QLabel(layoutWidget);
        labelInsert2->setObjectName(QStringLiteral("labelInsert2"));

        tab_1_gridLayout->addWidget(labelInsert2, 2, 2, 1, 1);

        editInsert2 = new QLineEdit(layoutWidget);
        editInsert2->setObjectName(QStringLiteral("editInsert2"));

        tab_1_gridLayout->addWidget(editInsert2, 2, 3, 1, 1);

        labelNumDigits2 = new QLabel(layoutWidget);
        labelNumDigits2->setObjectName(QStringLiteral("labelNumDigits2"));

        tab_1_gridLayout->addWidget(labelNumDigits2, 4, 9, 1, 1);

        editNumInc = new QLineEdit(layoutWidget);
        editNumInc->setObjectName(QStringLiteral("editNumInc"));

        tab_1_gridLayout->addWidget(editNumInc, 4, 6, 1, 1);

        labelNumDigits = new QLabel(layoutWidget);
        labelNumDigits->setObjectName(QStringLiteral("labelNumDigits"));

        tab_1_gridLayout->addWidget(labelNumDigits, 4, 7, 1, 1);

        labelNumInc = new QLabel(layoutWidget);
        labelNumInc->setObjectName(QStringLiteral("labelNumInc"));

        tab_1_gridLayout->addWidget(labelNumInc, 4, 5, 1, 1);

        editNumInitV = new QLineEdit(layoutWidget);
        editNumInitV->setObjectName(QStringLiteral("editNumInitV"));

        tab_1_gridLayout->addWidget(editNumInitV, 4, 3, 1, 1);

        labelNumInitV = new QLabel(layoutWidget);
        labelNumInitV->setObjectName(QStringLiteral("labelNumInitV"));

        tab_1_gridLayout->addWidget(labelNumInitV, 4, 2, 1, 1);

        editNumDigits = new QLineEdit(layoutWidget);
        editNumDigits->setObjectName(QStringLiteral("editNumDigits"));

        tab_1_gridLayout->addWidget(editNumDigits, 4, 8, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        tab_1_gridLayout->addWidget(line, 0, 4, 5, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1071, 260));
        tab_2_gridLayout = new QGridLayout(gridLayoutWidget);
        tab_2_gridLayout->setSpacing(6);
        tab_2_gridLayout->setContentsMargins(11, 11, 11, 11);
        tab_2_gridLayout->setObjectName(QStringLiteral("tab_2_gridLayout"));
        tab_2_gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tab_2_gridLayout->setContentsMargins(10, 10, 10, 10);
        editSeriesNrPrefix = new QLineEdit(gridLayoutWidget);
        editSeriesNrPrefix->setObjectName(QStringLiteral("editSeriesNrPrefix"));

        tab_2_gridLayout->addWidget(editSeriesNrPrefix, 2, 1, 1, 1);

        labelResolution = new QLabel(gridLayoutWidget);
        labelResolution->setObjectName(QStringLiteral("labelResolution"));

        tab_2_gridLayout->addWidget(labelResolution, 7, 2, 1, 1);

        editEpisodeNrPrefix = new QLineEdit(gridLayoutWidget);
        editEpisodeNrPrefix->setObjectName(QStringLiteral("editEpisodeNrPrefix"));

        tab_2_gridLayout->addWidget(editEpisodeNrPrefix, 3, 1, 1, 1);

        comboEpisodeNameSrc = new QComboBox(gridLayoutWidget);
        comboEpisodeNameSrc->setObjectName(QStringLiteral("comboEpisodeNameSrc"));

        tab_2_gridLayout->addWidget(comboEpisodeNameSrc, 4, 1, 1, 1);

        labelEpisodeNameLang = new QLabel(gridLayoutWidget);
        labelEpisodeNameLang->setObjectName(QStringLiteral("labelEpisodeNameLang"));

        tab_2_gridLayout->addWidget(labelEpisodeNameLang, 4, 2, 1, 1);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName(QStringLiteral("labelName"));

        tab_2_gridLayout->addWidget(labelName, 1, 0, 1, 1);

        editSceneGrp = new QLineEdit(gridLayoutWidget);
        editSceneGrp->setObjectName(QStringLiteral("editSceneGrp"));

        tab_2_gridLayout->addWidget(editSceneGrp, 9, 1, 1, 1);

        editSource = new QLineEdit(gridLayoutWidget);
        editSource->setObjectName(QStringLiteral("editSource"));

        tab_2_gridLayout->addWidget(editSource, 8, 1, 1, 1);

        labelEpisodeNrDigits = new QLabel(gridLayoutWidget);
        labelEpisodeNrDigits->setObjectName(QStringLiteral("labelEpisodeNrDigits"));

        tab_2_gridLayout->addWidget(labelEpisodeNrDigits, 3, 2, 1, 1);

        labelEpisodeNameSrc = new QLabel(gridLayoutWidget);
        labelEpisodeNameSrc->setObjectName(QStringLiteral("labelEpisodeNameSrc"));

        tab_2_gridLayout->addWidget(labelEpisodeNameSrc, 4, 0, 1, 1);

        editAudio = new QLineEdit(gridLayoutWidget);
        editAudio->setObjectName(QStringLiteral("editAudio"));

        tab_2_gridLayout->addWidget(editAudio, 7, 1, 1, 1);

        labelEpisodeNrPrefix = new QLabel(gridLayoutWidget);
        labelEpisodeNrPrefix->setObjectName(QStringLiteral("labelEpisodeNrPrefix"));

        tab_2_gridLayout->addWidget(labelEpisodeNrPrefix, 3, 0, 1, 1);

        labelAudio = new QLabel(gridLayoutWidget);
        labelAudio->setObjectName(QStringLiteral("labelAudio"));

        tab_2_gridLayout->addWidget(labelAudio, 7, 0, 1, 1);

        editYear = new QLineEdit(gridLayoutWidget);
        editYear->setObjectName(QStringLiteral("editYear"));

        tab_2_gridLayout->addWidget(editYear, 6, 1, 1, 1);

        labelVideo = new QLabel(gridLayoutWidget);
        labelVideo->setObjectName(QStringLiteral("labelVideo"));

        tab_2_gridLayout->addWidget(labelVideo, 8, 2, 1, 1);

        labelYear = new QLabel(gridLayoutWidget);
        labelYear->setObjectName(QStringLiteral("labelYear"));

        tab_2_gridLayout->addWidget(labelYear, 6, 0, 1, 1);

        labelSource = new QLabel(gridLayoutWidget);
        labelSource->setObjectName(QStringLiteral("labelSource"));

        tab_2_gridLayout->addWidget(labelSource, 8, 0, 1, 1);

        labelScreneGrp = new QLabel(gridLayoutWidget);
        labelScreneGrp->setObjectName(QStringLiteral("labelScreneGrp"));

        tab_2_gridLayout->addWidget(labelScreneGrp, 9, 0, 1, 1);

        checkboxCustomFileName = new QCheckBox(gridLayoutWidget);
        checkboxCustomFileName->setObjectName(QStringLiteral("checkboxCustomFileName"));

        tab_2_gridLayout->addWidget(checkboxCustomFileName, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        tab_2_gridLayout->addWidget(label, 6, 2, 1, 1);

        labelSeriesNrDigits = new QLabel(gridLayoutWidget);
        labelSeriesNrDigits->setObjectName(QStringLiteral("labelSeriesNrDigits"));

        tab_2_gridLayout->addWidget(labelSeriesNrDigits, 2, 2, 1, 1);

        labelSeriesNrPrefix = new QLabel(gridLayoutWidget);
        labelSeriesNrPrefix->setObjectName(QStringLiteral("labelSeriesNrPrefix"));

        tab_2_gridLayout->addWidget(labelSeriesNrPrefix, 2, 0, 1, 1);

        buttonCustomFileNameReset = new QPushButton(gridLayoutWidget);
        buttonCustomFileNameReset->setObjectName(QStringLiteral("buttonCustomFileNameReset"));

        tab_2_gridLayout->addWidget(buttonCustomFileNameReset, 0, 4, 1, 1);

        editSeriesNrDigits = new QLineEdit(gridLayoutWidget);
        editSeriesNrDigits->setObjectName(QStringLiteral("editSeriesNrDigits"));

        tab_2_gridLayout->addWidget(editSeriesNrDigits, 2, 3, 1, 2);

        editLang = new QLineEdit(gridLayoutWidget);
        editLang->setObjectName(QStringLiteral("editLang"));

        tab_2_gridLayout->addWidget(editLang, 6, 3, 1, 2);

        editEpisodeNrDigits = new QLineEdit(gridLayoutWidget);
        editEpisodeNrDigits->setObjectName(QStringLiteral("editEpisodeNrDigits"));

        tab_2_gridLayout->addWidget(editEpisodeNrDigits, 3, 3, 1, 2);

        editResolution = new QLineEdit(gridLayoutWidget);
        editResolution->setObjectName(QStringLiteral("editResolution"));

        tab_2_gridLayout->addWidget(editResolution, 7, 3, 1, 2);

        comboEpisodeNameLang = new QComboBox(gridLayoutWidget);
        comboEpisodeNameLang->setObjectName(QStringLiteral("comboEpisodeNameLang"));

        tab_2_gridLayout->addWidget(comboEpisodeNameLang, 4, 3, 1, 2);

        editVideo = new QLineEdit(gridLayoutWidget);
        editVideo->setObjectName(QStringLiteral("editVideo"));

        tab_2_gridLayout->addWidget(editVideo, 8, 3, 1, 2);

        editName = new QLineEdit(gridLayoutWidget);
        editName->setObjectName(QStringLiteral("editName"));

        tab_2_gridLayout->addWidget(editName, 1, 1, 1, 4);

        editCustomFileName = new QLineEdit(gridLayoutWidget);
        editCustomFileName->setObjectName(QStringLiteral("editCustomFileName"));

        tab_2_gridLayout->addWidget(editCustomFileName, 0, 1, 1, 3);

        labelLang = new QFrame(gridLayoutWidget);
        labelLang->setObjectName(QStringLiteral("labelLang"));
        labelLang->setFrameShape(QFrame::HLine);
        labelLang->setFrameShadow(QFrame::Sunken);

        tab_2_gridLayout->addWidget(labelLang, 5, 0, 1, 5);

        tab_2_gridLayout->setColumnStretch(1, 25);
        tab_2_gridLayout->setColumnStretch(3, 25);
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 100);
        verticalLayout->setStretch(2, 70);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 2);

        ShikiRenameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShikiRenameClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1533, 21));
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
        QWidget::setTabOrder(editName, editSeriesNrPrefix);
        QWidget::setTabOrder(editSeriesNrPrefix, editSeriesNrDigits);
        QWidget::setTabOrder(editSeriesNrDigits, editEpisodeNrPrefix);
        QWidget::setTabOrder(editEpisodeNrPrefix, editEpisodeNrDigits);
        QWidget::setTabOrder(editEpisodeNrDigits, comboEpisodeNameSrc);
        QWidget::setTabOrder(comboEpisodeNameSrc, comboEpisodeNameLang);
        QWidget::setTabOrder(comboEpisodeNameLang, editYear);
        QWidget::setTabOrder(editYear, confirmButton);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(ShikiRenameClass);

        tabWidget->setCurrentIndex(0);


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
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("ShikiRenameClass", "Edit", Q_NULLPTR));
        editSeriesNrPrefix->setText(QString());
        editSeriesNrPrefix->setPlaceholderText(QApplication::translate("ShikiRenameClass", "s", Q_NULLPTR));
        labelResolution->setText(QApplication::translate("ShikiRenameClass", "Video Resolution", Q_NULLPTR));
        editEpisodeNrPrefix->setText(QString());
        editEpisodeNrPrefix->setPlaceholderText(QApplication::translate("ShikiRenameClass", "e", Q_NULLPTR));
        comboEpisodeNameSrc->clear();
        comboEpisodeNameSrc->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("ShikiRenameClass", "TheTVDB.com", Q_NULLPTR)
        );
        labelEpisodeNameLang->setText(QApplication::translate("ShikiRenameClass", "Language", Q_NULLPTR));
        labelName->setText(QApplication::translate("ShikiRenameClass", "Name", Q_NULLPTR));
        labelEpisodeNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", Q_NULLPTR));
        labelEpisodeNameSrc->setText(QApplication::translate("ShikiRenameClass", "Episode Name Source", Q_NULLPTR));
        labelEpisodeNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Episode Number", Q_NULLPTR));
        labelAudio->setText(QApplication::translate("ShikiRenameClass", "Audio Info", Q_NULLPTR));
        labelVideo->setText(QApplication::translate("ShikiRenameClass", "Video Info", Q_NULLPTR));
        labelYear->setText(QApplication::translate("ShikiRenameClass", "Release Year", Q_NULLPTR));
        labelSource->setText(QApplication::translate("ShikiRenameClass", "Source", Q_NULLPTR));
        labelScreneGrp->setText(QApplication::translate("ShikiRenameClass", "Scene Group", Q_NULLPTR));
        checkboxCustomFileName->setText(QApplication::translate("ShikiRenameClass", "Customize File Name", Q_NULLPTR));
        label->setText(QApplication::translate("ShikiRenameClass", "Language", Q_NULLPTR));
        labelSeriesNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", Q_NULLPTR));
        labelSeriesNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Series Number", Q_NULLPTR));
        buttonCustomFileNameReset->setText(QApplication::translate("ShikiRenameClass", "Reset", Q_NULLPTR));
        editSeriesNrDigits->setText(QString());
        editSeriesNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "2", Q_NULLPTR));
        editEpisodeNrDigits->setText(QString());
        editEpisodeNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "2", Q_NULLPTR));
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
