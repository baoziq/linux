#include <sys/ipc.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "client.h"

const int PROJID = 10;
int main(int argc, char* argv[]) {
	key_t msgkey = ftok(argv[1], PROJID);
	if (msgkey == -1) {
		perror("ftok");
		return -1;
	}
	int msgid = msgget(msgkey, IPC_CREAT|0664);
	if (msgid == -1) {
		perror("msgget");
		return -1;
	}
	
	client(msgid, atol(argv[2]));
	return 0;
}
