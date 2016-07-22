#ifndef PLAYERTIMER_H
#define PLAYERTIMER_H

#include "threadPool.h"
#include <ctime>

class PlayerTimer : public task
{
public:
	enum EventName
	{
		EVENT_TICK
	};
	// class LOCK
	class LOCK
	{
	public:
		LOCK(LPCRITICAL_SECTION pcs) : m_pcs(pcs)
		{
			::EnterCriticalSection(pcs);
		}
		~LOCK()
		{
			::LeaveCriticalSection(m_pcs);
		}
	private:
		LPCRITICAL_SECTION m_pcs;
	};
public:
	PlayerTimer(){ m_curSec = 0; ::InitializeCriticalSection(&m_jcs); m_pause = false; m_stop = false; ::InitializeCriticalSection(&m_jp); }
	~PlayerTimer(){}

	void ResetTimer(){ m_curSec = 0; }
	double GetCurTime(){ LOCK Lock(&m_jcs); return m_curSec; }
	void SetPause(){ LOCK Lock(&m_jp); m_pause = !m_pause; }
	bool IsPause(){ LOCK Lock(&m_jp); return m_pause; }
	void SetStop(bool inSelect){ LOCK Lock(&m_jp); m_stop = inSelect; }
	bool IsStop(){ LOCK Lock(&m_jp); return m_stop; }

	void* run(void* inputPara); // inherit from task
	void* notify(void* inputPara); // inherit from task
private:
	double m_curSec;
	CRITICAL_SECTION m_jcs;
	CRITICAL_SECTION m_jp;
	bool m_pause;
	bool m_stop;
};

#endif