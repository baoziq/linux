#include <iostream>

struct Message{
	long mtype;
	long ctype;
	int operand1;
	char op;
	int operand2;
	double result;
};

std::istream& operator >> (std::istream& in, Message& m);
std::ostream& operator << (std::ostream& out, const Message& m);
void process(Message* pm);

