#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if (mkfifo(argv[1], 0664) == -1) {
		perror("mkfifo");
		return -1;
	}	

	int rfd = open(argv[1]. O_RDWR);

	if (rfd == -1) {
		perror("open");
		return -1;
	}

	int wfd = open(argv[2], O_WRONLY);
	if (wfd == -1) {
		perror("opne");
	}

	client(rfd, wfd);
	return 0;
}
