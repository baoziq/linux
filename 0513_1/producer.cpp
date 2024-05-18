#include <iostream>
#include "producer.h"
#include "message.h"

void producer(MQ& mq) {
	Message m;
	std::cin >> m;
	mq.put(m);
}
