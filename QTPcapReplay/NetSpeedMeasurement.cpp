#include "NetSpeedMeasurement.h"

NetSpeedMeasurement::NetSpeedMeasurement(QObject *parent) 
: QThread(parent)
{
	m_accuByte = 0; 
	m_threadRun = true;
	start();
}
NetSpeedMeasurement::~NetSpeedMeasurement()
{
	m_threadRun = false;
}

void NetSpeedMeasurement::run() // inherit from QThread
{
	while (m_threadRun)
	{
		Sleep(1000);
		m_mutex.lock();
		emit UpdateNetSpeed((double)m_accuByte);
		m_accuByte = 0;
		m_mutex.unlock();
	}
}

void NetSpeedMeasurement::AddSentLen(const UINT32& sentLen)
{
	m_mutex.lock();
	m_accuByte += sentLen;
	m_mutex.unlock();
}