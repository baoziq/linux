#include "func.h"

int func(int a) {
	int sum = 1;
	for (int i = 1; i <= a; i++) {
		sum *= i;
	}
	return sum;
}
