#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

//Transaction class
class transaction {
public:
	double amount;
	string type;

	transaction(string t, double a) :type(t), amount(a) {}
};
//Account class
class Account{
public:
	int accnumber;
	double balance;
	vector<transaction>history; //transaction history

	Account(int num, double initialbalance) {
		accnumber = num;
		balance = initialbalance;
	}
	void deposit(double amount) {
		balance += amount;
		history.push_back(transaction("Deposit", amount)); //record transaction
		cout << "Deposited $ " << amount << " Successfully!\n";
	}
	void withdraw(double amount) {
		if (amount > balance) {
			cout << "Insufficient funds! Withdrawal failed.\n";
			return;
		}
		else {
			balance -= amount;
			history.push_back(transaction("Withdrawal", amount)); //record transaction
			cout << "Withdrawn $ " << amount << " Successfully!\n";
		}
	}
	void showhistory() {
		cout << "--------Transaction History--------\n";
		if (history.empty()) {
			cout << "No Transaction History Available.\n";
			return;
		}
		for (auto& t : history) {
			cout << t.type << ":$ " << t.amount << "\n";
		}
		
	}
	void showinfo() {
		cout << "-----------Account Information-----------\n";
		cout << "Account Nuumber: " << accnumber << endl;
		cout << "Balance: $" << balance << endl;
	}
};
//customer class
class customer {
public:
	string name;
	Account account;

	customer(string n, int accnum, double initialbalance)
		:name(n), account(accnum, initialbalance) {}
};
//transfer between accounts
void transfer(Account& from, Account& to, double amount) {
	if (amount > from.balance) {
		cout << "Insufficient funds! Transfer failed.\n";
		return;
	}
	else {
		from.balance -= amount;
		to.balance += amount;
		from.history.push_back(transaction("Transfer Out", amount)); //record transaction
		to.history.push_back(transaction("Transfer In", amount)); //record transaction
		cout << "Transferred $ " << amount << " Successfully!\n";
	}
}
int main() {
	customer c1("Aliaa", 1006, 500.0);
	customer c2("Mohamed", 1007, 300.0);
	int choice;
	cout << "----------Welcome to the Banking System----------\n";
	while (true) {
		cout << "1. Deposit\n2. Withdraw\n3. Transfer \n4. Show Account Info\n5. Show Transaction History\n6. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				double amount;
				cout << "Enter amount to deposit:";
				cin >> amount;
				c1.account.deposit(amount);
				break;
			case 2:
				cout << "Enter amount to withdraw:";
				cin >> amount;
				c1.account.withdraw(amount);
				break;
			case 3:
				cout << "Enter amount to transfer:";
				cin >> amount;
				transfer(c1.account, c2.account, amount);
				break;
			
			case 4:
				c1.account.showinfo();
				break;

			case 5:
				c1.account.showhistory();
				break;

			case 6:
				cout << "Thank you for using the Banking System. Goodbye!\n";
				return 0;

			default:
				cout << "Invalid choice! Please try again.\n";
			}
			
	}
}


