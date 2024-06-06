#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>

int main() {
	int fd[2];
	char buffer[100];
	int ret = pipe(fd);
	if (ret == -1) {
		perror("fork");
	}

	int pid = fork();
	if (pid == -1) {
		perror("pid");
	}
	if (pid == 0) {
		std::cout << "child is writing!\n";
		close(fd[0]);
		std::cout << "input:\n";
		std::cin >> buffer;
		write(fd[1], buffer, strlen(buffer) + 1);
		close(fd[1]);
		exit(1);
	} else {
		std::cout << "parent is reading\n";
		close(fd[1]);
		read(fd[0], buffer, 100);
		for (int i = 0; i < strlen(buffer); ++i) {
			buffer[i] = toupper(buffer[i]);
		}
		std::cout << buffer << std::endl;
		close(fd[0]);
		exit(1);
	}
	return 0;
}
