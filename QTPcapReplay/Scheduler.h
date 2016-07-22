#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "ui_scheduler.h"
#include <QtCore/qthread.h>
#include <qmessagebox.h>

#include <qvector.h>

class Scheduler : public QDialog
{
	Q_OBJECT

public:
	Scheduler(QWidget *parent = 0);
	~Scheduler();

	QDate GetDate(){ return m_date; }
	QTime GetTime(){ return m_time; }
	void SetDate(const QDate& date){ m_date = date; }
	void SetTime(const QTime& time){ m_time = time; }
	QVector<bool> GetWeeklySelection(){ return m_weeklySelection; }
	void SetWeeklySelection(const QVector<bool>& weeklySelection){ m_weeklySelection = weeklySelection; }
	bool IsSchedularEnable(){ return m_isSchedulerEnable; }
	void SetSchedularEnable(const bool& schedularEnable){ m_isSchedulerEnable = schedularEnable; }
	bool IsOneTimeSchedu(){ return m_isOneTime; }
	void SetOneTimeSchedu(const bool& oneTime){ m_isOneTime = oneTime; }
	bool IsWeeklySchedu(){ return m_isWeekly; }
	void SetWeeklySchedu(const bool& weeklySchedu){ m_isWeekly = weeklySchedu; }

	void InitUI();

	int exec();
private:
	enum weekDay
	{
		Sunday = 0,
		Monday = 1,
		Tuesday = 2,
		Wednesday = 3,
		Thursday = 4,
		Friday = 5,
		Saturday = 6
	};
	Ui::SchedulerClass ui;

	QDate m_date;
	QTime m_time;

	bool m_isWeekly;
	bool m_isOneTime;
	bool m_isSchedulerEnable;
	QVector<bool> m_weeklySelection;

	int HandleRaioButtons();
	int HandleWeeklySelection();
private slots:
	void myAccept();
	void DateClicked(const QDate & date);
	void TimeClicked(QTime time);
	void WeeklyClicked();
	void OneTimeClicked();
	void SchedulerEnable(int state);
};

#endif