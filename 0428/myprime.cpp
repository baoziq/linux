#include <stdlib.h>
#include <thread>
#include "prime.h"

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	//allprimes(n);
	//std::thread t(allprimes, n);
	Prime p;
	//std::thread t(p, n);
	std::thread t(&Prime::allprimes, &p, n);
	t.join();
	
	return 0;
}
