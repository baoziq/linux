#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include"server.h"
using SAI=struct sockaddr_in;
using SA=struct sockaddr;
int main(int argc,char* argv[])
{
	int port=atoi(argv[1]);
	int listenfd=socket(AF_INET,SOCK_STREAM,0);
	if(listenfd==-1)
	{
		perror("socket");
		return 1;
	}
	SAI saddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(port);
	saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(listenfd,(SA*)&saddr,sizeof(saddr))==-1)
	{
		perror("bind");
		return 1;
	}
	if(listen(listenfd,5)==-1)
	{
		perror("bind");
		return 1;
	}
	server(listenfd);
	close(listenfd);
	return 0;
}
