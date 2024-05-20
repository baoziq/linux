#include"message.h"
std::istream& operator>>(std::istream& in,Message& m)
{
	in>>m.operand1>>m.op>>m.operand2;
	return in;
}
std::ostream& operator<<(std::ostream& out,const Message& m)
{
	out<<m.operand1<<m.op<<m.operand2<<"="<<m.result;
}
void process(Message* pm)
{
	switch(pm->op)
	{
		case '+':
			pm->result=pm->operand1+pm->operand2;
			break;
		case '-':
			pm->result=pm->operand1-pm->operand2;
			break;
		case '*':
			pm->result=pm->operand1*pm->operand2;
			break;
		case '/':
			break;
	}
}
