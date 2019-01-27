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
#include <QtGui/QIcon>
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkboxCustomFileName;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonCustomFileNameReset;
    QLineEdit *editCustomFileName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelName;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonLookup;
    QLineEdit *editName;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelSeasonNrPrefix;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *editSeasonNrPrefix;
    QLabel *labelSeasonNrDigits;
    QLineEdit *editSeasonNrDigits;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelDUMMY;
    QCheckBox *checkboxNoSeason;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelEpisodeNrPrefix;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *editEpisodeNrPrefix;
    QLabel *labelEpisodeNrDigits;
    QLineEdit *editEpisodeNrDigits;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelEpisodeNameSrc;
    QComboBox *comboEpisodeNameSrc;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelEpisodeNameLang;
    QComboBox *comboEpisodeNameLang;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShikiRenameClass)
    {
        if (ShikiRenameClass->objectName().isEmpty())
            ShikiRenameClass->setObjectName(QString::fromUtf8("ShikiRenameClass"));
        ShikiRenameClass->resize(1202, 887);
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ShikiRename/shell32icons/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOpen->setIcon(icon);

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
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(2, 3, 474, 210));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkboxCustomFileName = new QCheckBox(verticalLayoutWidget);
        checkboxCustomFileName->setObjectName(QString::fromUtf8("checkboxCustomFileName"));
        checkboxCustomFileName->setMinimumSize(QSize(150, 0));
        checkboxCustomFileName->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_4->addWidget(checkboxCustomFileName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonCustomFileNameReset = new QPushButton(verticalLayoutWidget);
        buttonCustomFileNameReset->setObjectName(QString::fromUtf8("buttonCustomFileNameReset"));
        sizePolicy.setHeightForWidth(buttonCustomFileNameReset->sizePolicy().hasHeightForWidth());
        buttonCustomFileNameReset->setSizePolicy(sizePolicy);
        buttonCustomFileNameReset->setMinimumSize(QSize(24, 24));
        buttonCustomFileNameReset->setMaximumSize(QSize(24, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ShikiRename/shell32icons/297.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCustomFileNameReset->setIcon(icon1);

        horizontalLayout->addWidget(buttonCustomFileNameReset);

        editCustomFileName = new QLineEdit(verticalLayoutWidget);
        editCustomFileName->setObjectName(QString::fromUtf8("editCustomFileName"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editCustomFileName->sizePolicy().hasHeightForWidth());
        editCustomFileName->setSizePolicy(sizePolicy2);
        editCustomFileName->setMinimumSize(QSize(281, 0));
        editCustomFileName->setSizeIncrement(QSize(0, 0));

        horizontalLayout->addWidget(editCustomFileName);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelName = new QLabel(verticalLayoutWidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMinimumSize(QSize(150, 0));
        labelName->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_6->addWidget(labelName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonLookup = new QPushButton(verticalLayoutWidget);
        buttonLookup->setObjectName(QString::fromUtf8("buttonLookup"));
        sizePolicy.setHeightForWidth(buttonLookup->sizePolicy().hasHeightForWidth());
        buttonLookup->setSizePolicy(sizePolicy);
        buttonLookup->setMinimumSize(QSize(24, 24));
        buttonLookup->setMaximumSize(QSize(24, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ShikiRename/shell32icons/22.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLookup->setIcon(icon2);

        horizontalLayout_2->addWidget(buttonLookup);

        editName = new QLineEdit(verticalLayoutWidget);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setMinimumSize(QSize(281, 0));

        horizontalLayout_2->addWidget(editName);


        horizontalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelSeasonNrPrefix = new QLabel(verticalLayoutWidget);
        labelSeasonNrPrefix->setObjectName(QString::fromUtf8("labelSeasonNrPrefix"));
        labelSeasonNrPrefix->setMinimumSize(QSize(150, 0));
        labelSeasonNrPrefix->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_7->addWidget(labelSeasonNrPrefix);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        editSeasonNrPrefix = new QLineEdit(verticalLayoutWidget);
        editSeasonNrPrefix->setObjectName(QString::fromUtf8("editSeasonNrPrefix"));
        editSeasonNrPrefix->setMinimumSize(QSize(200, 0));
        editSeasonNrPrefix->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(editSeasonNrPrefix);

        labelSeasonNrDigits = new QLabel(verticalLayoutWidget);
        labelSeasonNrDigits->setObjectName(QString::fromUtf8("labelSeasonNrDigits"));
        labelSeasonNrDigits->setMinimumSize(QSize(50, 0));
        labelSeasonNrDigits->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(labelSeasonNrDigits);

        editSeasonNrDigits = new QLineEdit(verticalLayoutWidget);
        editSeasonNrDigits->setObjectName(QString::fromUtf8("editSeasonNrDigits"));
        editSeasonNrDigits->setMinimumSize(QSize(50, 0));
        editSeasonNrDigits->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(editSeasonNrDigits);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        labelDUMMY = new QLabel(verticalLayoutWidget);
        labelDUMMY->setObjectName(QString::fromUtf8("labelDUMMY"));
        labelDUMMY->setMinimumSize(QSize(150, 0));
        labelDUMMY->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_11->addWidget(labelDUMMY);

        checkboxNoSeason = new QCheckBox(verticalLayoutWidget);
        checkboxNoSeason->setObjectName(QString::fromUtf8("checkboxNoSeason"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkboxNoSeason->sizePolicy().hasHeightForWidth());
        checkboxNoSeason->setSizePolicy(sizePolicy3);
        checkboxNoSeason->setMinimumSize(QSize(312, 22));
        checkboxNoSeason->setMaximumSize(QSize(16777215, 16777215));
        checkboxNoSeason->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_11->addWidget(checkboxNoSeason);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelEpisodeNrPrefix = new QLabel(verticalLayoutWidget);
        labelEpisodeNrPrefix->setObjectName(QString::fromUtf8("labelEpisodeNrPrefix"));
        labelEpisodeNrPrefix->setMinimumSize(QSize(150, 0));
        labelEpisodeNrPrefix->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_8->addWidget(labelEpisodeNrPrefix);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        editEpisodeNrPrefix = new QLineEdit(verticalLayoutWidget);
        editEpisodeNrPrefix->setObjectName(QString::fromUtf8("editEpisodeNrPrefix"));
        sizePolicy2.setHeightForWidth(editEpisodeNrPrefix->sizePolicy().hasHeightForWidth());
        editEpisodeNrPrefix->setSizePolicy(sizePolicy2);
        editEpisodeNrPrefix->setMinimumSize(QSize(200, 0));
        editEpisodeNrPrefix->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(editEpisodeNrPrefix);

        labelEpisodeNrDigits = new QLabel(verticalLayoutWidget);
        labelEpisodeNrDigits->setObjectName(QString::fromUtf8("labelEpisodeNrDigits"));
        labelEpisodeNrDigits->setMinimumSize(QSize(50, 0));
        labelEpisodeNrDigits->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(labelEpisodeNrDigits);

        editEpisodeNrDigits = new QLineEdit(verticalLayoutWidget);
        editEpisodeNrDigits->setObjectName(QString::fromUtf8("editEpisodeNrDigits"));
        editEpisodeNrDigits->setMinimumSize(QSize(50, 0));
        editEpisodeNrDigits->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(editEpisodeNrDigits);


        horizontalLayout_8->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelEpisodeNameSrc = new QLabel(verticalLayoutWidget);
        labelEpisodeNameSrc->setObjectName(QString::fromUtf8("labelEpisodeNameSrc"));
        labelEpisodeNameSrc->setMinimumSize(QSize(150, 0));
        labelEpisodeNameSrc->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_9->addWidget(labelEpisodeNameSrc);

        comboEpisodeNameSrc = new QComboBox(verticalLayoutWidget);
        comboEpisodeNameSrc->addItem(QString());
        comboEpisodeNameSrc->addItem(QString());
        comboEpisodeNameSrc->setObjectName(QString::fromUtf8("comboEpisodeNameSrc"));
        comboEpisodeNameSrc->setMinimumSize(QSize(312, 0));
        comboEpisodeNameSrc->setMaximumSize(QSize(312, 16777215));

        horizontalLayout_9->addWidget(comboEpisodeNameSrc);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labelEpisodeNameLang = new QLabel(verticalLayoutWidget);
        labelEpisodeNameLang->setObjectName(QString::fromUtf8("labelEpisodeNameLang"));
        labelEpisodeNameLang->setMinimumSize(QSize(150, 0));
        labelEpisodeNameLang->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_10->addWidget(labelEpisodeNameLang);

        comboEpisodeNameLang = new QComboBox(verticalLayoutWidget);
        comboEpisodeNameLang->setObjectName(QString::fromUtf8("comboEpisodeNameLang"));
        comboEpisodeNameLang->setMinimumSize(QSize(312, 0));
        comboEpisodeNameLang->setMaximumSize(QSize(312, 16777215));

        horizontalLayout_10->addWidget(comboEpisodeNameLang);


        verticalLayout->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_2, QString());

        vLayout_Main->addWidget(tabWidget);


        gLayout_centralWidget->addLayout(vLayout_Main, 1, 2, 1, 2);

        ShikiRenameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShikiRenameClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1202, 21));
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
        QWidget::setTabOrder(editNumDigits, buttonRename);

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
        editDirectory->setPlaceholderText(QApplication::translate("ShikiRenameClass", "<directory>", nullptr));
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
        checkboxCustomFileName->setText(QApplication::translate("ShikiRenameClass", "Customize File Name", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonCustomFileNameReset->setToolTip(QApplication::translate("ShikiRenameClass", "Reset", nullptr));
#endif // QT_NO_TOOLTIP
        buttonCustomFileNameReset->setText(QString());
        labelName->setText(QApplication::translate("ShikiRenameClass", "Name", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonLookup->setToolTip(QApplication::translate("ShikiRenameClass", "Lookup", nullptr));
#endif // QT_NO_TOOLTIP
        buttonLookup->setText(QString());
        labelSeasonNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Season Number", nullptr));
        editSeasonNrPrefix->setText(QString());
        editSeasonNrPrefix->setPlaceholderText(QApplication::translate("ShikiRenameClass", "s", nullptr));
        labelSeasonNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", nullptr));
        editSeasonNrDigits->setText(QString());
        editSeasonNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "2", nullptr));
        labelDUMMY->setText(QString());
        checkboxNoSeason->setText(QApplication::translate("ShikiRenameClass", "No season numbers", nullptr));
        labelEpisodeNrPrefix->setText(QApplication::translate("ShikiRenameClass", "Prefix Episode Number", nullptr));
        editEpisodeNrPrefix->setText(QString());
        editEpisodeNrPrefix->setPlaceholderText(QApplication::translate("ShikiRenameClass", "e", nullptr));
        labelEpisodeNrDigits->setText(QApplication::translate("ShikiRenameClass", "Digits", nullptr));
        editEpisodeNrDigits->setText(QString());
        editEpisodeNrDigits->setPlaceholderText(QApplication::translate("ShikiRenameClass", "2", nullptr));
        labelEpisodeNameSrc->setText(QApplication::translate("ShikiRenameClass", "Online Source", nullptr));
        comboEpisodeNameSrc->setItemText(0, QString());
        comboEpisodeNameSrc->setItemText(1, QApplication::translate("ShikiRenameClass", "TheTVDB.com", nullptr));

        labelEpisodeNameLang->setText(QApplication::translate("ShikiRenameClass", "Language", nullptr));
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
