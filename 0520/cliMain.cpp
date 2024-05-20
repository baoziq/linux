#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include"server.h"
#include<stdlib.h>
#include"client.h"
using SAI=struct sockaddr_in;
using SA=struct sockaddr;
int main(int argc,char* argv[])
{
	char* ip=argv[1];
	int port=atoi(argv[2]);
	int confd=socket(AF_INET,SOCK_STREAM,0);
	if(confd==-1)
	{
		perror("socket");
		return 1;
	}
	SAI saddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(port);
	//saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	inet_pton(AF_INET,ip,&(saddr.sin_addr));
	if(connect(confd,(SA*)&saddr,sizeof(saddr))==-1)
	{
		perror("connect");
		return 1;
	}
	client(confd);
	close(confd);
	return 0;
}
