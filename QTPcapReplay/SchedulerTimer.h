#ifndef SCHEDULERTIMER_H
#define SCHEDULERTIMER_H

#include <QtCore/qthread.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qtimer.h>
#include <qvector.h>


class SchedulerTimer : public QThread
{
	Q_OBJECT
public:
	SchedulerTimer(QObject *parent = 0);
	~SchedulerTimer();

	void run(); // inherit from QThread
	bool IsTodayRun();
	bool IsOneTimeSchedu(){ return m_isOneTime; }
	bool IsWeeklySchedu(){ return m_isWeekly; }

	QTimer m_timer;
private:
	QDate m_date;
	QTime m_time;
	QVector<bool> m_weeklySelection;
	bool m_isWeekly;
	bool m_isOneTime;
	
public slots:
	void setTimer(const QDate& date, const QTime& time, const QVector<bool>& weeklySelection, const bool& isWeekly, const bool& isOneTime);
	void ReStartForNextDay();
};

#endif