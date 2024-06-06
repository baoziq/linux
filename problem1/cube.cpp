#include <iostream>
#include "cube.h"

void cubesum(int m) {
	int a = m / 100;
	int b = m /10 % 10;
	int c = m %10;
	//std::cout << "a" << a << "b" << b << "c" << c << std::endl;
	int sum = a * a * a + b * b * b + c * c * c;
	std::cout << sum << std::endl;
	
}
