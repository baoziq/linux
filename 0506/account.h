struct Account {
	char accno[10];
	double balance;
	int num;
	Account(const char* no, double balance = 0, int num = 0) {
		strcpy(accno, no, strlen(no));
	}

};

std::ostream& operator<<(std::ostream& out, const Account& acc);

void deposit(Account& acc, double amount);
void withdraw(Account& acc, double amount);
