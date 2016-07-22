#include "PlayerTimer.h"

void* PlayerTimer::run(void* inputPara)
{
	while (true)
	{
		while (IsPause())
			Sleep(1);
		::EnterCriticalSection(&m_jcs);
		m_curSec += 0.1;
		::LeaveCriticalSection(&m_jcs);
		clock_t begin = clock();
		double elapsed_secs = 0;
		while (elapsed_secs < 0.1) // count for 100ms
		{
			clock_t end = clock();
			elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			Sleep(1);
		}
	}
	return NULL;
}
void* PlayerTimer::notify(void* inputPara) // inherit from task
{
	return NULL;
}