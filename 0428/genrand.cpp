#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int* arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand()%100;
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	return 0;
}
