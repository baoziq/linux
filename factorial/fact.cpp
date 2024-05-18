#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "func.h"
int main(int argc, char* argv[]) {
	int num = atoi(argv[1]);
	int a = func(num);	
	std::cout << a << std::endl;
	return 0;
}
