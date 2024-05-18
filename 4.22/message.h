//#ifndef _MY_MESSAGE
//#define _MY_MESSAGE

#pragma once

#include <iostream>

struct Message {
	int operand1;
	char op;
	int operand2;
	char status;
	double result;
	char msg[20];
};

std::istream& operator >> (std::istream& in, Message& m);
std::ostream& operator << (std::ostream& out, const Message& m);
void process(Message* &pm);

//#endif
