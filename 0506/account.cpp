#include "account.h"

std::ostream operator<<(std::ostream& out, const Account& acc) {
	out << acc.accno << " " << acc.balance << " " << acc. num;
	return out;
}

void deposit(Account& acc, double amount) {
	std::lock_guard<std::mutex> lg(mu);
	acc.balance += amount;
}

void withdraw(Account& acc, double  amount) {
	std::lock_guard<std::mutex> lg(mu);
	if (acc.balance > amount) {
		acc.balance -= amount;
	} else {
		std::cout << "no enough balance\n";
	}
}
