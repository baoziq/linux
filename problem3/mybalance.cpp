#include <thread>
#include <iostream>
#include <mutex>

mutex mtx;
int total = 10000;

void consumer(int no) {
	mtx.lock();
	if (no == 1) {
		std::cout << "ATM: ";
		total += 5000;
		std::cout << "total:" << total << std::endl;
	} else if (no == 2) {
		std::cout << "counter:";
		total -= 3000;
		std::cout << "total:" << total << std::endl;
	} else {
		std::cout << "net:";
		total -= 6000;
		std::cout << "total" << total << std::endl;
	}
	mtx.unlock();

}
int main() {
	std::thread t1(consumer, 1);
	std::thread t2(consumer, 2);
	std::thread t3(consumer, 3);
	t1.join();
	t2.join();
	t3.join();
	return 0;
	
}
