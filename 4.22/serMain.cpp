#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include "mysem.h"
#include "server.h"
#include "message.h"

const int PROJID = 10;
const int SHMSIZ = 4096;
const int SEMSIZ = 2;
const int SMUTEX = 0;
const int CMUTEX = 1;

int main(int argc, char* argv[]) {
	key_t shmkey = ftok(argv[1], PROJID);
	if (shmkey == -1) {
		perror("ftok");
		return -1;
	}

	key_t semkey = ftok(argv[2], PROJID);
	if (semkey == -1) {
		perror("ftok");
		return -1;
	}

	int shmid = shmget(shmkey, SHMSIZ, IPC_CREAT|0664);
	if (shmid == -1) {
		perror("shmget");
		return -1;
	}
	Message*  pm = (Message*)shmat(shmid, NULL, 0);

	int semid = semget(semkey,SEMSIZ,IPC_CREAT|0664);
	if (semid == -1) {
		perror("semget");
		return -1;
	}
	
	sem_init(semid, SMUTEX, 0);	
	sem_init(semid, CMUTEX, 0);

	server(pm, semid);
	return 0;
}
