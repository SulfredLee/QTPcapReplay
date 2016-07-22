#ifndef NETSPEEDMEASUREMENT_H
#define NETSPEEDMEASUREMENT_H

#include <QtCore/qthread.h>

#include <Windows.h>

class NetSpeedMeasurement : public QThread
{
	Q_OBJECT
public:
	NetSpeedMeasurement(QObject *parent = 0);
	~NetSpeedMeasurement();

	void run(); // inherit from QThread
	void AddSentLen(const UINT32& sentLen);
private:
	UINT32 m_accuByte;
	bool m_threadRun;
	QMutex m_mutex;
signals:
	void UpdateNetSpeed(double bytePerSec);
};

#endif