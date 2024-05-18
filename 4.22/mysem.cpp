#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "mysem.h"

void sem_init(int semid, int num, int val) {
	semun su;
	su.val = val;
	semctl(semid, num, SETVAL, su);
}

void sem_p(int semid, int num) {
	struct sembuf sb;
	sb.sem_num = num;
	sb.sem_op = -1;
	sb.sem_flg = SEM_UNDO;
	semop(semid, &sb, 1);

}

void sem_v(int semid, int num) {
	struct sembuf sb;
	sb.sem_num = num;
	sb.sem_op = 1;
	sb.sem_flg = SEM_UNDO;
	semop(semid, &sb, 1);
}

