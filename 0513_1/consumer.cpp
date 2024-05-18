#include <iostream>
#include "message.h"
#include "consumer.h"

void consumer(MQ& mq) {
	Message m = mq.get();
	std::cout << m << std::endl;
}
