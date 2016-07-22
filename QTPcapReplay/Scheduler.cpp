#include "Scheduler.h"

Scheduler::Scheduler(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);

	m_isWeekly = false;
	m_isOneTime = false;
	m_isSchedulerEnable = false;

	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(myAccept()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	connect(ui.calendarWidget, SIGNAL(clicked(const QDate &)), this, SLOT(DateClicked(const QDate &)));
	connect(ui.timeEdit, SIGNAL(timeChanged(QTime)), this, SLOT(TimeClicked(QTime)));
	connect(ui.weekly_radioButton, SIGNAL(clicked()), this, SLOT(WeeklyClicked()));
	connect(ui.oneTime_radioButton, SIGNAL(clicked()), this, SLOT(OneTimeClicked()));
	connect(ui.scheduler_checkBox, SIGNAL(stateChanged(int)), this, SLOT(SchedulerEnable(int)));

	

	// variable init
	//m_date = t.date();
	//m_time = t.time();
}

Scheduler::~Scheduler()
{

}

void Scheduler::SchedulerEnable(int state)
{
	if (ui.scheduler_checkBox->checkState() == 0) // unchecked
	{
		ui.weekly_radioButton->setDisabled(true);
		ui.oneTime_radioButton->setDisabled(true);

		ui.weekly_radioButton->clicked(false);
		ui.oneTime_radioButton->clicked(false);

		ui.sunday_checkBox->setDisabled(true);
		ui.monday_checkBox->setDisabled(true);
		ui.tuesday_checkBox->setDisabled(true);
		ui.wednesday_checkBox->setDisabled(true);
		ui.thursday_checkBox->setDisabled(true);
		ui.friday_checkBox->setDisabled(true);
		ui.saturday_checkBox->setDisabled(true);


	}
	else if (ui.scheduler_checkBox->checkState() == 2) // checked
	{
		ui.weekly_radioButton->setDisabled(false);
		ui.oneTime_radioButton->setDisabled(false);

		ui.oneTime_radioButton->click();
	}
}

void Scheduler::WeeklyClicked()
{
	ui.sunday_checkBox->setDisabled(false);
	ui.monday_checkBox->setDisabled(false);
	ui.tuesday_checkBox->setDisabled(false);
	ui.wednesday_checkBox->setDisabled(false);
	ui.thursday_checkBox->setDisabled(false);
	ui.friday_checkBox->setDisabled(false);
	ui.saturday_checkBox->setDisabled(false);
}

void Scheduler::OneTimeClicked()
{
	ui.sunday_checkBox->setDisabled(true);
	ui.monday_checkBox->setDisabled(true);
	ui.tuesday_checkBox->setDisabled(true);
	ui.wednesday_checkBox->setDisabled(true);
	ui.thursday_checkBox->setDisabled(true);
	ui.friday_checkBox->setDisabled(true);
	ui.saturday_checkBox->setDisabled(true);
}
void Scheduler::InitUI()
{
	// display init
	QDateTime t = QDateTime::currentDateTime();
	//ui.calendarWidget->showToday();
	ui.calendarWidget->setSelectedDate(t.date());
	m_date = t.date();
	ui.timeEdit->setTime(t.time());
	m_time = t.time();

	ui.sunday_checkBox->setDisabled(true);
	ui.monday_checkBox->setDisabled(true);
	ui.tuesday_checkBox->setDisabled(true);
	ui.wednesday_checkBox->setDisabled(true);
	ui.thursday_checkBox->setDisabled(true);
	ui.friday_checkBox->setDisabled(true);
	ui.saturday_checkBox->setDisabled(true);

	ui.oneTime_radioButton->setDisabled(true);
	ui.weekly_radioButton->setDisabled(true);
}

int Scheduler::exec()
{
	if (m_isSchedulerEnable)
	{
		ui.scheduler_checkBox->setChecked(true);
		ui.calendarWidget->setSelectedDate(m_date);
		ui.timeEdit->setTime(m_time);

		if (m_isOneTime)
		{
			ui.oneTime_radioButton->setChecked(true);

			ui.sunday_checkBox->setDisabled(true);
			ui.monday_checkBox->setDisabled(true);
			ui.tuesday_checkBox->setDisabled(true);
			ui.wednesday_checkBox->setDisabled(true);
			ui.thursday_checkBox->setDisabled(true);
			ui.friday_checkBox->setDisabled(true);
			ui.saturday_checkBox->setDisabled(true);

			return QDialog::exec();
		}
		if (m_isWeekly)
		{
			ui.weekly_radioButton->setChecked(true);

			ui.sunday_checkBox->setDisabled(false);
			ui.monday_checkBox->setDisabled(false);
			ui.tuesday_checkBox->setDisabled(false);
			ui.wednesday_checkBox->setDisabled(false);
			ui.thursday_checkBox->setDisabled(false);
			ui.friday_checkBox->setDisabled(false);
			ui.saturday_checkBox->setDisabled(false);
		}

		for (int i = 0; i < m_weeklySelection.size(); i++)
		{
			if (m_weeklySelection[i])
			{
				switch (i)
				{
				case 0:
					ui.sunday_checkBox->setChecked(true);
					break;
				case 1:
					ui.monday_checkBox->setChecked(true);
					break;
				case 2:
					ui.tuesday_checkBox->setChecked(true);
					break;
				case 3:
					ui.wednesday_checkBox->setChecked(true);
					break;
				case 4:
					ui.thursday_checkBox->setChecked(true);
					break;
				case 5:
					ui.friday_checkBox->setChecked(true);
					break;
				case 6:
					ui.saturday_checkBox->setChecked(true);
					break;
				default:
					break;
				}
			}
		}
	}
	else
	{
		InitUI();
	}
	return QDialog::exec();
}
void Scheduler::myAccept()
{
	m_isSchedulerEnable = ui.scheduler_checkBox->isChecked();
	m_isWeekly = false;
	m_isOneTime = false;
	m_weeklySelection.clear();
	m_weeklySelection.resize(7);

	for (int i = 0; i < m_weeklySelection.size(); i++)
	{
		m_weeklySelection[i] = false;
	}

	if (m_isSchedulerEnable)
	{
		switch (HandleRaioButtons())
		{
		case 1:
			close();
			return;
		case 2:
			return;
		default:
			break;
		}

		if (m_isWeekly)
		{
			switch (HandleWeeklySelection())
			{
			case 1:
				close();
				return;
			case 2:
				return;
			default:
				break;
			}
		}
	}

	close(); // when all configurations are set correctly
}

int Scheduler::HandleWeeklySelection()
{	
	m_weeklySelection[Sunday] = ui.sunday_checkBox->isChecked();
	m_weeklySelection[Monday] = ui.monday_checkBox->isChecked();
	m_weeklySelection[Tuesday] = ui.tuesday_checkBox->isChecked();
	m_weeklySelection[Wednesday] = ui.wednesday_checkBox->isChecked();
	m_weeklySelection[Thursday] = ui.thursday_checkBox->isChecked();
	m_weeklySelection[Friday] = ui.friday_checkBox->isChecked();
	m_weeklySelection[Saturday] = ui.saturday_checkBox->isChecked();

	for (int i = 0; i < m_weeklySelection.size(); i++)
	{
		if (m_weeklySelection[i])
			return 0; // when any checkbox is selected
	}

	QMessageBox::StandardButton reply;
	reply = QMessageBox::warning(this, "Message", "You have not select any weekday",
		QMessageBox::Ok);
	if (reply == QMessageBox::Ok)
		return 2; // keep dialog
	else
		return 2; // keep dialog

	//QMessageBox::StandardButton reply;
	//reply = QMessageBox::question(this, "Message", "You have not select any weekday, Quit?",
	//	QMessageBox::Yes | QMessageBox::No);
	//if (reply == QMessageBox::Yes)
	//	return 1; // close dialog
	//else
	//	return 2; // keep dialog
}
int Scheduler::HandleRaioButtons()
{
	// handle radio buttons
	QList<QRadioButton *> allButtons = ui.radio_groupBox->findChildren<QRadioButton *>();
	bool buttonClicked = false;
	for (int i = 0; i < allButtons.size(); i++)
	{
		if (allButtons[i]->isChecked())
		{
			if (allButtons[i]->isChecked())
			{
				buttonClicked = true;
				if (allButtons[i]->objectName() == "weekly_radioButton")
				{
					m_isWeekly = true;
				}
				else if (allButtons[i]->objectName() == "oneTime_radioButton")
				{
					m_isOneTime = true;
				}
			}
		}
	}
	if (!buttonClicked)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::warning(this, "Message", "You have not select Weekly or One Time",
			QMessageBox::Ok);
		if (reply == QMessageBox::Ok)
			return 2; // keep dialog
		else
			return 2; // keep dialog
		//reply = QMessageBox::question(this, "Message", "You have not select Weekly or One Time, Quit?",
		//	QMessageBox::Yes | QMessageBox::No);
		//if (reply == QMessageBox::Yes)
		//	return 1; // close dialog
		//else
		//	return 2; // keep dialog
	}
	return 0; // get radio button information
}
void Scheduler::DateClicked(const QDate & date)
{
	m_date = date;
}

void Scheduler::TimeClicked(QTime time)
{
	m_time = time;
}