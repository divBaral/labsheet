/*
Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments

-  veena, guitar, sitar, sarod and mandolin under string()

-  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()

-  tabla, mridangam, bangos, drums and tambour under perc()

It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows

Type of instruments to be displayed

a.  String instruments

b.  Wind instruments

c.  Percussion instruments

The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.
*/
#include <iostream>
#include <string>
using namespace std;

class Musicians{
protected:
	std::string str[5];
	std::string wnd[5];
	std::string per[5];
public:	

	void string(){
		std::string str1[] = {"veena", "guitar", "sitar", "sarod", "mandolin"};
		cout << "String Instruments: ";
		for(int i = 0; i < 5; i++){
			str[i] = str1[i];
			cout << str[i] << ", ";
		}
	}

	void wind(){
		std::string str2[] = {"flute", "clarinet", "saxophone", "nadhaswaram", "piccolo"};
		cout << "Wind Instruments: ";
		for(int i = 0; i < 5; i++){
			wnd[i] = str2[i];
			cout << wnd[i] << ", ";
		}
	}

	void perc(){
		std::string str3[] = {"tabla", "mridangam", "bangos", "drums", "tambour"};
		cout << "Percussion Instruments: ";
		for(int i = 0; i < 5; i++){
			per[i] = str3[i];
			cout << per[i] << ", ";
		}
	}
};

class TypeIns: public Musicians{
private:
	char choice;
public:
	void get(){
		cout << "Types of intruments to be displayed " << endl 
		<< "a. String instruments" << endl << "b. Wind instruments"
		<< endl << "c. Percussion instruments" << endl;

		cout << "Give your choice(a,b,c):";
		cin >> choice;
	}
	void display_stringIns(){
		cout << "String Instruments: ";
		for(int i = 0; i < 5; i++){
			cout << str[i] << endl;
		}
	}

	void display_windIns(){

		cout << "Wind Instruments: " << endl;
		for(int i = 0; i < 5; i++) {
			cout << wnd[i] << endl;

		}
	}

	void display_percIns(){
		cout << "Percussion Instruments: ";
		for(int i = 0; i < 5; i++){
			cout << per[i] << endl;
		}
	}
	void show();
};

void TypeIns::show()
{

	switch(choice){
		case 'a':
			display_stringIns();
			cout << endl;
			break;
		case 'b':
			display_windIns();
			cout << endl;
			break;
		case 'c':
			display_percIns();
			cout << endl;
			break;
		default:
			cout << endl << "Invalid choice\n";
			break;
	}
}

int main()
{
	TypeIns Ins;

	Ins.string();
	cout << endl;
	Ins.wind();
	cout << endl;
	Ins.perc();
	cout << endl;
	Ins.get();
	cout << endl;
	Ins.show();

	cout << endl;
	return 0;
}