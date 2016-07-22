#include "SchedulerTimer.h"

SchedulerTimer::SchedulerTimer(QObject *parent)
: QThread(parent)
{

}

SchedulerTimer::~SchedulerTimer()
{

}

void SchedulerTimer::run() // inherit from QThread
{

}

void SchedulerTimer::setTimer(const QDate& date, const QTime& time, const QVector<bool>& weeklySelection, const bool& isWeekly, const bool& isOneTime)
{
	m_date = date;
	m_time = time;
	m_weeklySelection = weeklySelection;
	m_isWeekly = isWeekly;
	m_isOneTime = isOneTime;

	QDateTime curDateTime = QDateTime::currentDateTime();
	qint64 msecForTimer;

	if (m_isWeekly)
	{
		m_date = curDateTime.date();
		QDateTime DateTime(m_date, m_time);
		msecForTimer = curDateTime.msecsTo(DateTime);
		while (msecForTimer < 0) // loop until calculated the next day time interval
		{
			m_date = m_date.addDays(1);
			DateTime.setDate(m_date);
			msecForTimer = curDateTime.msecsTo(DateTime);
		}
	}
	else
	{
		QDateTime DateTime(m_date, m_time);
		msecForTimer = curDateTime.msecsTo(DateTime);
	}

	m_timer.setInterval(msecForTimer);
	m_timer.start();

	//start();
}

void SchedulerTimer::ReStartForNextDay()
{
	QDateTime curDateTime = QDateTime::currentDateTime();
	m_date = m_date.addDays(1);
	QDateTime DateTime(m_date, m_time);
	qint64 msecForTimer = curDateTime.msecsTo(DateTime);
	m_timer.setInterval(msecForTimer);
	m_timer.start();
}

bool SchedulerTimer::IsTodayRun()
{
	QDateTime curDateTime = QDateTime::currentDateTime();
	if (m_weeklySelection[curDateTime.date().dayOfWeek() % 7])
		return true;
	return false;
}