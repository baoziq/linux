#include <mutex>
#include "entlea.h"

std::mutex mu;
/*
void enter(std::atomic<int>& online,  int num) {
	for (int i = 0; i < num; i++) {
		online++;
	}	
}

void leave(std::atomic<int>& online,  int num) {
	for (int i = 0; i < num; i++) {
		online--;
	}
}
*/

/*
void enter(int& online,  int num) {
	for (int i = 0; i < num;  i++) {
		mu.lock();
		online++;
		mu.unlock();
		//
	}
}

void leave(int&  online, int num) {
	for (int i = 0; i < num; i++) {
		mu.lock();
		online--;
		mu.unlock();
	}
}
*/




