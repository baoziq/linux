#include"server.h"
#include<thread>
#include<sys/types.h>
#include<sys/socket.h>
#include"message.h"
#include<unistd.h>
#include<arpa/inet.h>
const int MSGSIZ=sizeof(Message);
void serv(int confd)
{
	while(true)
	{
		char buf[MSGSIZ+1]={'\0'};
		if(read(confd,buf,MSGSIZ)<=0)
		{
			std::cerr<<"client close\n";
				close(confd);
			break;
		}
		Message* pm=(Message*)buf;
		pm->operand1=ntohl(pm->operand1);
		pm->operand2=ntohl(pm->operand2);
		process(pm);
		pm->operand1=htonl(pm->operand1);
		pm->operand2=htonl(pm->operand2);
		pm->result=htonl(pm->result);
		write(confd,buf,MSGSIZ);
	}
}
void server(int listenfd)
{
	while(true)
	{
		int confd=accept(listenfd,NULL,NULL);
		std::thread s(serv,confd);
		s.detach();
	}
}

