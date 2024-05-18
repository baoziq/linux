#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "server.h"
#include "message.h"
const int MSGSIZ = sizeof(Message);

void server(int msgid, long mtype) {
	while (true) {
		char buf[MSGSIZ + 1] = {'\0'};
		msgrcv(msgid, buf, MSGSIZ - sizeof(long), mtype, 0);
		Message* pm = (Message*)buf;
		process(pm);
		pm->mtype = pm->ctype;
		msgsnd(msgid, buf, MSGSIZ- sizeof(long), 0);
		
	}
}
