#include"client.h"
#include"message.h"
#include<iostream>
#include<unistd.h>
#include<arpa/inet.h>
const int MSGSIZ=sizeof(Message);
void client(int confd)
{
	while(true)
	{
		char buf[MSGSIZ]={'\0'};
		Message* pm=(Message*)buf;
		std::cin>>(*pm);
		pm->operand1=htonl(pm->operand1);
		pm->operand2=htonl(pm->operand2);
		write(confd,buf,MSGSIZ);
		read(confd,buf,MSGSIZ);
		pm->operand1=ntohl(pm->operand1);
		pm->operand2=ntohl(pm->operand2);
		pm->result=ntohl(pm->result);
		std::cout<<(*pm)<<std::endl;
	}
}
