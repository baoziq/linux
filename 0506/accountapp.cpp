#include <iostream>
#include <thread>
#include "account.h"

int main(int argc, char* argv) {
	Account acc{"10001"};
	std::thread t1(withdraw, std::ref(acc), 5000);
	std::thread t2(deposit, std::ref(acc), 10000);
	t1.join();
	t2.join();
	std::cout << acc << std::endl;
	return 0;
}
