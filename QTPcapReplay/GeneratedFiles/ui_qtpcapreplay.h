/********************************************************************************
** Form generated from reading UI file 'qtpcapreplay.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPCAPREPLAY_H
#define UI_QTPCAPREPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTPcapReplayClass
{
public:
    QAction *actionFiles;
    QAction *actionFrom_Folder;
    QAction *actionClose;
    QAction *actionNew_Window;
    QAction *actionNew_Window_Dynamic;
    QAction *actionSchduler;
    QAction *actionScheduler;
    QAction *actionSave_Config;
    QAction *actionLoad_Config;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QComboBox *IPComboBox;
    QListWidget *listWidget;
    QLabel *schedulerStatus;
    QLabel *StatusReportLabel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *curPcapPackage;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *speed_LineEdit;
    QPushButton *startReplayButton;
    QPushButton *pauseReplayButton;
    QPushButton *stopReplayButton;
    QPushButton *removeFileButton;
    QPushButton *exitAppButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *offSet_lineEdit;
    QCheckBox *onlyFirstFile_checkbox;
    QPushButton *regularReplayButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *netSpeedMon;
    QLabel *packetTimeLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOther;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTPcapReplayClass)
    {
        if (QTPcapReplayClass->objectName().isEmpty())
            QTPcapReplayClass->setObjectName(QStringLiteral("QTPcapReplayClass"));
        QTPcapReplayClass->resize(643, 518);
        QIcon icon;
        icon.addFile(QStringLiteral("images.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTPcapReplayClass->setWindowIcon(icon);
        actionFiles = new QAction(QTPcapReplayClass);
        actionFiles->setObjectName(QStringLiteral("actionFiles"));
        actionFrom_Folder = new QAction(QTPcapReplayClass);
        actionFrom_Folder->setObjectName(QStringLiteral("actionFrom_Folder"));
        actionClose = new QAction(QTPcapReplayClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionNew_Window = new QAction(QTPcapReplayClass);
        actionNew_Window->setObjectName(QStringLiteral("actionNew_Window"));
        actionNew_Window_Dynamic = new QAction(QTPcapReplayClass);
        actionNew_Window_Dynamic->setObjectName(QStringLiteral("actionNew_Window_Dynamic"));
        actionSchduler = new QAction(QTPcapReplayClass);
        actionSchduler->setObjectName(QStringLiteral("actionSchduler"));
        actionScheduler = new QAction(QTPcapReplayClass);
        actionScheduler->setObjectName(QStringLiteral("actionScheduler"));
        actionSave_Config = new QAction(QTPcapReplayClass);
        actionSave_Config->setObjectName(QStringLiteral("actionSave_Config"));
        actionLoad_Config = new QAction(QTPcapReplayClass);
        actionLoad_Config->setObjectName(QStringLiteral("actionLoad_Config"));
        centralWidget = new QWidget(QTPcapReplayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        IPComboBox = new QComboBox(centralWidget);
        IPComboBox->setObjectName(QStringLiteral("IPComboBox"));

        verticalLayout_2->addWidget(IPComboBox);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMovement(QListView::Static);
        listWidget->setResizeMode(QListView::Fixed);

        verticalLayout_2->addWidget(listWidget);

        schedulerStatus = new QLabel(centralWidget);
        schedulerStatus->setObjectName(QStringLiteral("schedulerStatus"));

        verticalLayout_2->addWidget(schedulerStatus);

        StatusReportLabel = new QLabel(centralWidget);
        StatusReportLabel->setObjectName(QStringLiteral("StatusReportLabel"));

        verticalLayout_2->addWidget(StatusReportLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        curPcapPackage = new QLabel(centralWidget);
        curPcapPackage->setObjectName(QStringLiteral("curPcapPackage"));

        horizontalLayout_2->addWidget(curPcapPackage);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(100);
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        speed_LineEdit = new QLineEdit(centralWidget);
        speed_LineEdit->setObjectName(QStringLiteral("speed_LineEdit"));

        horizontalLayout->addWidget(speed_LineEdit);

        startReplayButton = new QPushButton(centralWidget);
        startReplayButton->setObjectName(QStringLiteral("startReplayButton"));

        horizontalLayout->addWidget(startReplayButton);

        pauseReplayButton = new QPushButton(centralWidget);
        pauseReplayButton->setObjectName(QStringLiteral("pauseReplayButton"));

        horizontalLayout->addWidget(pauseReplayButton);

        stopReplayButton = new QPushButton(centralWidget);
        stopReplayButton->setObjectName(QStringLiteral("stopReplayButton"));

        horizontalLayout->addWidget(stopReplayButton);

        removeFileButton = new QPushButton(centralWidget);
        removeFileButton->setObjectName(QStringLiteral("removeFileButton"));

        horizontalLayout->addWidget(removeFileButton);

        exitAppButton = new QPushButton(centralWidget);
        exitAppButton->setObjectName(QStringLiteral("exitAppButton"));

        horizontalLayout->addWidget(exitAppButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        offSet_lineEdit = new QLineEdit(centralWidget);
        offSet_lineEdit->setObjectName(QStringLiteral("offSet_lineEdit"));

        horizontalLayout_3->addWidget(offSet_lineEdit);

        onlyFirstFile_checkbox = new QCheckBox(centralWidget);
        onlyFirstFile_checkbox->setObjectName(QStringLiteral("onlyFirstFile_checkbox"));

        horizontalLayout_3->addWidget(onlyFirstFile_checkbox);

        regularReplayButton = new QPushButton(centralWidget);
        regularReplayButton->setObjectName(QStringLiteral("regularReplayButton"));

        horizontalLayout_3->addWidget(regularReplayButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        netSpeedMon = new QLabel(centralWidget);
        netSpeedMon->setObjectName(QStringLiteral("netSpeedMon"));

        horizontalLayout_4->addWidget(netSpeedMon);

        packetTimeLabel = new QLabel(centralWidget);
        packetTimeLabel->setObjectName(QStringLiteral("packetTimeLabel"));

        horizontalLayout_4->addWidget(packetTimeLabel);


        verticalLayout_2->addLayout(horizontalLayout_4);

        QTPcapReplayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTPcapReplayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOther = new QMenu(menuBar);
        menuOther->setObjectName(QStringLiteral("menuOther"));
        QTPcapReplayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTPcapReplayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTPcapReplayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTPcapReplayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTPcapReplayClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOther->menuAction());
        menuFile->addAction(actionFiles);
        menuFile->addAction(actionFrom_Folder);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad_Config);
        menuFile->addAction(actionSave_Config);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuOther->addAction(actionNew_Window);
        menuOther->addAction(actionNew_Window_Dynamic);
        menuOther->addSeparator();
        menuOther->addAction(actionScheduler);
        mainToolBar->addAction(actionFiles);
        mainToolBar->addAction(actionFrom_Folder);
        mainToolBar->addAction(actionSave_Config);
        mainToolBar->addAction(actionLoad_Config);

        retranslateUi(QTPcapReplayClass);

        QMetaObject::connectSlotsByName(QTPcapReplayClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTPcapReplayClass)
    {
        QTPcapReplayClass->setWindowTitle(QApplication::translate("QTPcapReplayClass", "QTPcapReplay", 0));
        actionFiles->setText(QApplication::translate("QTPcapReplayClass", "Open Files...", 0));
        actionFrom_Folder->setText(QApplication::translate("QTPcapReplayClass", "Open Folder...", 0));
        actionClose->setText(QApplication::translate("QTPcapReplayClass", "Close", 0));
        actionNew_Window->setText(QApplication::translate("QTPcapReplayClass", "New Window", 0));
        actionNew_Window_Dynamic->setText(QApplication::translate("QTPcapReplayClass", "New Window Dynamic", 0));
        actionSchduler->setText(QApplication::translate("QTPcapReplayClass", "Schduler", 0));
        actionScheduler->setText(QApplication::translate("QTPcapReplayClass", "Scheduler", 0));
        actionSave_Config->setText(QApplication::translate("QTPcapReplayClass", "Save Config", 0));
        actionLoad_Config->setText(QApplication::translate("QTPcapReplayClass", "Load Config", 0));
        schedulerStatus->setText(QApplication::translate("QTPcapReplayClass", "TextLabel", 0));
        StatusReportLabel->setText(QApplication::translate("QTPcapReplayClass", "TextLabel", 0));
        curPcapPackage->setText(QApplication::translate("QTPcapReplayClass", "TextLabel", 0));
        label->setText(QApplication::translate("QTPcapReplayClass", "Speed:", 0));
        startReplayButton->setText(QApplication::translate("QTPcapReplayClass", "Play", 0));
        pauseReplayButton->setText(QApplication::translate("QTPcapReplayClass", "Pause", 0));
        stopReplayButton->setText(QApplication::translate("QTPcapReplayClass", "Stop", 0));
        removeFileButton->setText(QApplication::translate("QTPcapReplayClass", "Remove", 0));
        exitAppButton->setText(QApplication::translate("QTPcapReplayClass", "Close", 0));
        label_2->setText(QApplication::translate("QTPcapReplayClass", "OffSet:", 0));
        onlyFirstFile_checkbox->setText(QApplication::translate("QTPcapReplayClass", "Only First File", 0));
        regularReplayButton->setText(QApplication::translate("QTPcapReplayClass", "Regular Replay", 0));
        netSpeedMon->setText(QApplication::translate("QTPcapReplayClass", "TextLabel", 0));
        packetTimeLabel->setText(QApplication::translate("QTPcapReplayClass", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("QTPcapReplayClass", "File", 0));
        menuOther->setTitle(QApplication::translate("QTPcapReplayClass", "Other", 0));
    } // retranslateUi

};

namespace Ui {
    class QTPcapReplayClass: public Ui_QTPcapReplayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPCAPREPLAY_H
