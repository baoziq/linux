#include "mq.h"

void MQ::put(Message m) {
	std::unique_lock<std::mutex> ul(mu);
	/****
	while (!mqs.empty()) {
		isEmpty.wait(ul);
	}
	****/
	isEmpty.wait(ul, [this](){return mqs.empty();});
	mqs.push(m); 
	isNotEmpty.notify_one();
}

Message MQ::get() {
	std::unique_lock<std::mutex> ul(mu);
	/*
	while (mqs.empty()) { 
		isNotEmpty.wait(ul); 
	}
	*/
	isNotEmpty.wait(ul, [this](){return !mqs.empty();});
	Message m = mqs.front();
	mqs.pop();
	isEmpty.notify_one();
	return m;
}
