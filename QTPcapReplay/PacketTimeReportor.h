#ifndef PACKETTIMEREPORTOR_H
#define PACKETTIMEREPORTOR_H

#include <QtCore/qthread.h>
#include <Windows.h>
#include <ctime>

class PacketTimeReportor : public QThread
{
	Q_OBJECT
public:
	PacketTimeReportor(QObject *parent = 0);
	~PacketTimeReportor();

	void run(); // inherit from QThread
	void InsertPacketTime(const double& inTime);
private:
	double m_time;
	bool m_threadRun;
	QMutex m_mutex;
	


signals :
	void UpdateTimeReport(QString timeReport);
};

#endif