#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <iostream>

struct Message {
	char name[20];
	char passwd[20];
};

std::istream& operator >> (std::istream& in, Message& m);
std::ostream& operator << (std::ostream& out, Message& m);

#endif
