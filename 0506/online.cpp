#include <thread>
#include <stdlib.h>
#include <iostream>
#include <atomic>
#include "entlea.h"

int main(int argc, char* argv[]) {
	//std::atomic<int> online{0};
	int online(0);
	std::thread t1(enter, std::ref(online), atoi(argv[1]));
	std::thread t2(leave, std::ref(online), atoi(argv[2]));
	t1.join();
	t2.join();
	std::cout << online << " online\n";
	return 0;
}
