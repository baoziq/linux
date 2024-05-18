#include "server.h"
#include "mysem.h"



const int SMUTEX = 0;
const int CMUTEX = 1;

void server(Message* &pm, int semid) {
	while (true) {
		sem_p(semid, SMUTEX);
		process(pm);
		sem_v(semid, CMUTEX);
	}
}
