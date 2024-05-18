#include <iostream>
#include "client.h"
#include "mysem.h"

const int SMUTEX = 0;
const int CMUTEX = 1;
void client(Message* &pm, int semid) {
	while (true) {
		std::cin >> (*pm);
		if (std::cin.eof()) break;

		sem_v(semid, SMUTEX);

		sem_p(semid, CMUTEX);

		std::cout << (*pm) << std::endl;
	}
}
