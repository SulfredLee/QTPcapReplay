/********************************************************************************
** Form generated from reading UI file 'scheduler.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULER_H
#define UI_SCHEDULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SchedulerClass
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QTimeEdit *timeEdit;
    QCheckBox *scheduler_checkBox;
    QGroupBox *radio_groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *weekly_radioButton;
    QRadioButton *oneTime_radioButton;
    QGroupBox *weekDay_groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *sunday_checkBox;
    QCheckBox *monday_checkBox;
    QCheckBox *tuesday_checkBox;
    QCheckBox *wednesday_checkBox;
    QCheckBox *thursday_checkBox;
    QCheckBox *friday_checkBox;
    QCheckBox *saturday_checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SchedulerClass)
    {
        if (SchedulerClass->objectName().isEmpty())
            SchedulerClass->setObjectName(QStringLiteral("SchedulerClass"));
        SchedulerClass->resize(644, 439);
        verticalLayout = new QVBoxLayout(SchedulerClass);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(SchedulerClass);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setFirstDayOfWeek(Qt::Sunday);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        verticalLayout->addWidget(calendarWidget);

        timeEdit = new QTimeEdit(SchedulerClass);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        verticalLayout->addWidget(timeEdit);

        scheduler_checkBox = new QCheckBox(SchedulerClass);
        scheduler_checkBox->setObjectName(QStringLiteral("scheduler_checkBox"));

        verticalLayout->addWidget(scheduler_checkBox);

        radio_groupBox = new QGroupBox(SchedulerClass);
        radio_groupBox->setObjectName(QStringLiteral("radio_groupBox"));
        horizontalLayout_2 = new QHBoxLayout(radio_groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        weekly_radioButton = new QRadioButton(radio_groupBox);
        weekly_radioButton->setObjectName(QStringLiteral("weekly_radioButton"));

        horizontalLayout_2->addWidget(weekly_radioButton);

        oneTime_radioButton = new QRadioButton(radio_groupBox);
        oneTime_radioButton->setObjectName(QStringLiteral("oneTime_radioButton"));

        horizontalLayout_2->addWidget(oneTime_radioButton);


        verticalLayout->addWidget(radio_groupBox);

        weekDay_groupBox = new QGroupBox(SchedulerClass);
        weekDay_groupBox->setObjectName(QStringLiteral("weekDay_groupBox"));
        horizontalLayout = new QHBoxLayout(weekDay_groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sunday_checkBox = new QCheckBox(weekDay_groupBox);
        sunday_checkBox->setObjectName(QStringLiteral("sunday_checkBox"));

        horizontalLayout->addWidget(sunday_checkBox);

        monday_checkBox = new QCheckBox(weekDay_groupBox);
        monday_checkBox->setObjectName(QStringLiteral("monday_checkBox"));

        horizontalLayout->addWidget(monday_checkBox);

        tuesday_checkBox = new QCheckBox(weekDay_groupBox);
        tuesday_checkBox->setObjectName(QStringLiteral("tuesday_checkBox"));

        horizontalLayout->addWidget(tuesday_checkBox);

        wednesday_checkBox = new QCheckBox(weekDay_groupBox);
        wednesday_checkBox->setObjectName(QStringLiteral("wednesday_checkBox"));

        horizontalLayout->addWidget(wednesday_checkBox);

        thursday_checkBox = new QCheckBox(weekDay_groupBox);
        thursday_checkBox->setObjectName(QStringLiteral("thursday_checkBox"));

        horizontalLayout->addWidget(thursday_checkBox);

        friday_checkBox = new QCheckBox(weekDay_groupBox);
        friday_checkBox->setObjectName(QStringLiteral("friday_checkBox"));

        horizontalLayout->addWidget(friday_checkBox);

        saturday_checkBox = new QCheckBox(weekDay_groupBox);
        saturday_checkBox->setObjectName(QStringLiteral("saturday_checkBox"));

        horizontalLayout->addWidget(saturday_checkBox);


        verticalLayout->addWidget(weekDay_groupBox);

        buttonBox = new QDialogButtonBox(SchedulerClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SchedulerClass);

        QMetaObject::connectSlotsByName(SchedulerClass);
    } // setupUi

    void retranslateUi(QDialog *SchedulerClass)
    {
        SchedulerClass->setWindowTitle(QApplication::translate("SchedulerClass", "Dialog", 0));
        timeEdit->setDisplayFormat(QApplication::translate("SchedulerClass", "h:mm:ss AP", 0));
        scheduler_checkBox->setText(QApplication::translate("SchedulerClass", "Scheduler Enable", 0));
        radio_groupBox->setTitle(QString());
        weekly_radioButton->setText(QApplication::translate("SchedulerClass", "Weekly", 0));
        oneTime_radioButton->setText(QApplication::translate("SchedulerClass", "One Time", 0));
        weekDay_groupBox->setTitle(QString());
        sunday_checkBox->setText(QApplication::translate("SchedulerClass", "Sunday", 0));
        monday_checkBox->setText(QApplication::translate("SchedulerClass", "Monday", 0));
        tuesday_checkBox->setText(QApplication::translate("SchedulerClass", "Tuesday", 0));
        wednesday_checkBox->setText(QApplication::translate("SchedulerClass", "Wednesday", 0));
        thursday_checkBox->setText(QApplication::translate("SchedulerClass", "Thursday", 0));
        friday_checkBox->setText(QApplication::translate("SchedulerClass", "Friday", 0));
        saturday_checkBox->setText(QApplication::translate("SchedulerClass", "Saturday", 0));
    } // retranslateUi

};

namespace Ui {
    class SchedulerClass: public Ui_SchedulerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULER_H
