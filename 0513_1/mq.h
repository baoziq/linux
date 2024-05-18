#ifndef _MQ_H
#define _MQ_H

#include <queue>
#include <condition_variable>
#include <mutex>
#include "message.h"

class MQ {
public:
	void put(Message m);
	Message get();
private:
	std::queue<Message> mqs;
	std::mutex mu;
	std::condition_variable isNotEmpty;
	std::condition_variable isEmpty;
};

#endif
