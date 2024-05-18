#include <thread>
#include "mq.h"
#include "producer.h"
#include "consumer.h"

int main(int argc, char* argv[]) {
	MQ mq;
	std::thread p(producer, std::ref(mq));
	std::thread c(consumer, std::ref(mq));
	p.join();
	c.join();
	return 0;
}
