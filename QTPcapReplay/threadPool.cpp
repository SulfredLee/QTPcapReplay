#include "threadPool.h"

PCSqueue::PCSqueue(){
	objectQueue = new std::deque<task*>;
	InitializeCriticalSection(&access);
	queueSema = CreateSemaphore(NULL, 0, MAXINT, NULL);
};

void PCSqueue::push(task *ref){
	EnterCriticalSection(&access);
	objectQueue->push_front(ref);
	LeaveCriticalSection(&access);
	ReleaseSemaphore(queueSema, 1, NULL);
};

bool PCSqueue::pop(task **ref, DWORD timeout){
	if (WAIT_OBJECT_0 == WaitForSingleObject(queueSema, timeout)) {
		EnterCriticalSection(&access);
		*ref = objectQueue->back();
		objectQueue->pop_back();
		LeaveCriticalSection(&access);
		return(true);
	}
	else
		return(false);
};

threadPool::threadPool(int initThreads){
	queue = new PCSqueue();
	for (threadCount = 0; threadCount != initThreads; threadCount++){
		CreateThread(NULL, 0, staticThreadRun, this, 0, 0);
	};
};

void threadPool::submit(task *aTask){
	aTask->myPool = this;
	queue->push(aTask);
};