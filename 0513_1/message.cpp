#include "message.h"

std::istream& operator>>(std::istream& in, Message& m) {
	in >> m.name >> m.passwd;
	return in;
}

std::ostream& operator << (std::ostream& out, Message& m) {
	out << "name:" << m.name << "\n" << "passwd:" << m.passwd << "\n";
	return out;
}
