#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <iostream>
#include "message.h"
#include "client.h"

const int MSGSIZ = sizeof(Message);

void client(int msgid, long mtype) {
	while (true) {
		char buf[MSGSIZ+1] = {'\0'};
		Message* pm = (Message*)buf;
		std::cin >> (*pm);
		if (std::cin.eof()) break;
		long ctype = getpid();
		pm->mtype = mtype;
		pm->ctype = ctype;
		msgsnd(msgid, buf, MSGSIZ - sizeof(long), 0);
		
		msgrcv(msgid, buf, MSGSIZ - sizeof(long), ctype, 0);
		std::cout << (*pm) << std::endl;
	}
}
