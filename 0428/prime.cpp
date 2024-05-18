#include <iostream>
#include <unistd.h>
#include "prime.h"

/*
bool isPrime(int i) {
	for (int j = 2; j < i; j++) {
		if (i % j == 0) {
			return false;
		}
	}
	return true;
}

void allprimes(int n) {
	sleep(60);
	for (int  i = 2; i <= n; i++) {
		if (isPrime(i)) {
			std::cout << "prime:" << i << std::endl;
		}
	}
}
*/

bool Prime::isPrime(int i) {
	for (int j = 2; j < i; j++) {
		if (i % j == 0) {
			return false;
		}
	}
	return true;
}
void Prime:: allprimes(int n) {
	sleep(60);
	for (int  i = 2; i <= n; i++) {
		if (isPrime(i)) {
			std::cout << "prime:" << i << std::endl;
		}
	}
}
/*
void Prime::operator()(int n) {
	sleep(60);
	for (int  i = 2; i <= n; i++) {
		if (isPrime(i)) {
			std::cout << "prime:" << i << std::endl;
		}
	}
}
*/
