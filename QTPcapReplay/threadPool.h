#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <Windows.h>
#include <deque>


class threadPool;

class task {
	friend class threadPool;
private:
	threadPool *myPool;
protected:
	void* returnParm;
	void* inputParm;
public:
	virtual void* run(void*) = 0;
	virtual void* notify(void*) = 0;
};


class PCSqueue {
private:
	CRITICAL_SECTION access;
	std::deque<task*> *objectQueue;
	HANDLE queueSema;
public:
	PCSqueue();
	void push(task *ref);
	bool pop(task **ref, DWORD timeout);
};

class threadPool {
private:
	int threadCount;
public:
	PCSqueue *queue;
	threadPool(int initThreads);
	static DWORD _stdcall staticThreadRun(void *param){
		threadPool *myPool = (threadPool *)param;
		task *thisTask;
		while (myPool->queue->pop(&thisTask, INFINITE)){
			thisTask->returnParm = thisTask->run(thisTask->inputParm);
			thisTask->notify(thisTask->inputParm);
			delete thisTask;
		}
		return 0;
	}
	void submit(task *aTask);
};

#endif