#include "PacketTimeReportor.h"

PacketTimeReportor::PacketTimeReportor(QObject *parent)
: QThread(parent)
{
	m_time = 0;
	m_threadRun = true;
	start();
}
PacketTimeReportor::~PacketTimeReportor()
{
	m_threadRun = false;
}

void PacketTimeReportor::run()
{
	while (m_threadRun)
	{
		Sleep(1000);
		m_mutex.lock();
		
		struct timeval tv;
		time_t nowtime;
		struct tm *nowtm;
		char tmbuf[64], buf[64];

		nowtime = (int)m_time;
		nowtm = localtime(&nowtime);
		strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d,%H:%M:%S", nowtm);
		sprintf_s(buf, sizeof buf, "%s.%06d", tmbuf, (long)((m_time - (UINT32)m_time) * 1000000));

		//m_time = 0;
		
		emit UpdateTimeReport(buf);

		m_mutex.unlock();
	}
}

void PacketTimeReportor::InsertPacketTime(const double& inTime)
{
	m_mutex.lock();
	m_time = inTime;
	m_mutex.unlock();
}