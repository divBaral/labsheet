/*Write a program for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account-number, last-name, first-name, total-balance).

*/


#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Transaction{
private:
	unsigned accountno;
	char last_name[10];
	char first_name[10];
	double balance;
public:
	static void add_record()
	{
		char ch;
		ofstream file;
		file.open("Transaction.dat", ios::app|ios::out|ios::binary);
		if(file.good())
		{	
			do{
				Transaction t;

				cout << "Enter first name: ";
				cin >> t.first_name;
				cout << "Enter last name: ";
				cin >> t.last_name;
				cout << "Enter account number: ";
				cin >> t.accountno;
				cout << "Enter balance: ";
				cin >> t.balance;

				file.write(reinterpret_cast<char *>(&t), sizeof(t));
				cout << "Do you want to add another record(y/n)? ";
				cin >> ch;
			}while(ch == 'y' || ch == 'Y');
		}
		file.close();
	}

	static void delete_record()
	{
		char name[10];
		Transaction t;
		fstream file("Transaction.dat", ios::in|ios::binary);
		fstream new_file("temp.dat", ios::app|ios::out|ios::binary);

		cout << "Enter first name of the person whose record you wish to delete: ";
		cin >> name;
		while(!file.eof())
		{
			file.read(reinterpret_cast<char *>(&t), sizeof(t));
			if(file)
			{
				if(strcmp(name, t.first_name) != 0)
				{
					new_file.write(reinterpret_cast<char *>(&t), sizeof(t));
				}
				else if(strcmp(name, t.first_name) == 0)
				{
					cout << "\nRecord deleted successfully.\n";
				}
			}
		}
		file.close();
		new_file.close();

		remove("Transaction.dat");
		rename("temp.dat", "Transaction.dat");
	}

	static void update_record()
	{	
		int pos = -1;
		char name[10];
		Transaction t;
		fstream file("Transaction.dat", ios::out|ios::in|ios::binary);
		//fstream new_file("temp.dat", ios::app|ios::out|ios::binary);

		cout << "Enter first name of the person whose record you wish to update: ";
		cin >> name;
		
		while(!file.eof())
		{	
			file.read(reinterpret_cast<char *>(&t), sizeof(t));
			if(file)
			{
				if(strcmp(name, t.first_name) == 0)
				{
					pos = file.tellg();
					break;
				}
			}
		}
		if(pos != -1)
		{
			cout << "Enter new account number: ";
			cin >> t.accountno;
			cout << "Enter new balance: ";
			cin >> t.balance;

			file.seekp(pos-sizeof(t));
			file.write(reinterpret_cast<char *>(&t), sizeof(t));

			cout << "\nRecord updated successfully.\n";
		}else
			cout << "Record not found.\n";
		file.close();
	}

	static void displayRecords()
	{	
		Transaction a2;
		fstream file("Transaction.dat", ios::in|ios::binary);
		while(!file.eof())
		{
			file.read(reinterpret_cast<char *>(&a2), sizeof(a2));
			if(file)
			{
				cout.setf(ios::fixed);
				cout << endl;
				cout << a2;
				cout << endl;
			}
		}
		file.close();
	}

	friend ostream& operator << (ostream&, Transaction&);
};

ostream& operator << (ostream& s, Transaction& t)
{
	s << endl << "Name: " << t.first_name << " " << t.last_name << endl
	<< "Transaction Number: " << t.accountno << endl << "Balance: " << t.balance << endl;

	return s;

}

int main(){
	int ch;
	bool quit = false;

	do
	{
		cout << "\n--Welcome to Transaction Manager--\n";
		cout << "1. Add records\n2. Update record\n3. Delete record\n4. Display records\n5. Quit\n";
		cout << "Enter choice(1,2,3,4,5)? ";
		cin >> ch;

		switch(ch)
		{
			case 1:
			Transaction::add_record();
			break;
			case 2:
			Transaction::update_record();
			break;
			case 3:
			Transaction::delete_record();
			break;
			case 4:
			Transaction::displayRecords();
			break;
			case 5:
			quit = true;
			break;
			default:
			cout << "\n Choose a number between 1 and 4.\n";
			continue;
		}
	}while(!quit);

	cout << endl;
	return 0;
}