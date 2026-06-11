#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool userExists(const string & username) {   //checks if username is alreadry taken
		ifstream file("users.txt");
		string u, p;

		while (file >> u >> p) {
			if (u == username) {
				return true;
			}
		}
		return false;
	}
//Registration 
void registeruser() {
	string username, password;

	cout << "Enter Username: ";
	cin >> username;

	if (userExists(username)) {
		cout << "Username already Taken, Please choose another one." << endl;
		return;
	}
	cout << "Enter Password: ";
	cin >> password;

	ofstream file("users.txt", ios::app); //appends to the file instead of overwriting
	file << username << " " << password << "\n";
	cout << "Registration Successful! Welcome, " << username << "!" << endl;
}
void login(){
	string username, password;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	ifstream file("users.txt");
	string u, p;
	while (file >> u >> p) {
		if (u == username && p == password) {   //if username and password match
			cout << "Login Successful! Welcome, " << username << "!" << endl;
			return;
		}
	}
	cout << "Invalid username or password. Please try again." << endl; //if u and p don't match
}
int main() {
	int choice;
	cout << "------Registeration and Login System------" << endl;
	cout << "1.Register\n2.Login\n3.Exit\n";
	  while (true) {
		  cout << "Enter your choice: ";
		  cin >> choice;
		  switch (choice) {
		  case 1:
			  registeruser();
			  break;
		  case 2:
			  login();
			  break;
		  case 3:
			  cout << "Exiting the program. Goodbye!" << endl;
			  return 0;
			  break;
		  default:
			  cout << "Invalid choice, Please try again." << endl;
		  }

	   }
}
