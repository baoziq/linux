union semun {
	int val;

};
void sem_init(int semid, int num, int val);

void sem_p(int semid, int num);

void sem_v(int semid, int num);
