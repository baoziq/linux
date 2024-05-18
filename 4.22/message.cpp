#include <string.h>
#include "message.h"


const char* msg = "divid by zero";

std::istream& operator >> (std::istream& in, Message& m) {
	in >> m.operand1 >> m.op >> m.operand2;
	return in;
}

std::ostream& operator << (std::ostream& out, const Message& m) {
	if (m.status == 'F') {
		out << msg;
	} else {
		out << m.operand1 << m.op << m.operand2 << "=" << m.result;
	}

	return out;
		

}
void process(Message* &pm) {
	pm -> status = 'T';
	switch (pm -> op) {
		case '+':
			pm -> result = pm -> operand1 + pm -> operand2;
			break;
		case '-':
			pm -> result = pm -> operand1 -  pm -> operand2;
			break;

		case '*':
			pm -> result = pm -> operand1 + pm -> operand2;
			break;
		case '/':
			if (pm -> operand2 == 0) {
				pm -> status = 'F';
				strncpy(pm -> msg, msg, strlen(msg));
			} else {
				pm -> result = double(pm -> operand1 / pm -> operand2);
			}
			break;

	}
}
