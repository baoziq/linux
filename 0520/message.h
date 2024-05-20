#include<iostream>
struct Message{
	int operand1;
	char op;
	int operand2;
	int result;
};
std::istream& operator>>(std::istream& in,Message& m);
std::ostream& operator<<(std::ostream& out,const Message& m);
void process(Message* m);
