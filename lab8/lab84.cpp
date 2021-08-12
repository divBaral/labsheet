/*Write a program that stores the information about students (name, student id, department, and address) in a structure and then transfers the information to a file in your directory. Finally, retrieve the information from your file and print it in the proper format on your output screen.*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student
{
	char name[15];
	int id;
	char department[15];
	char address[12];

};

void show(Student& s){
	cout << left << setw(6) << "Name: " << setw(20) << s.name << endl;
	cout << setw(6) << "ID: " << setw(20) << s.id << endl;
	cout << setw(6) << "Department: " << setw(20) << s.department << endl;
	cout << setw(6) << "Address: " << setw(20) << s.address << endl;
}

int main(){
	Student s1;
	char ch;


	fstream file;
	file.open("Student.dat", ios::out|ios::binary);
	if ( file.bad() ){
		std::cerr << "File can't created\n";
		return -11;
	}

	cout << "---Fill the details below---\n\n" << endl;

	do{	
		cout << "Enter name: ";
		cin >> s1.name;
		cout << "Enter ID: ";
		cin >> s1.id;
		cout << "Enter department's name: ";
		cin >> s1.department;
		cout << "Enter address: ";
		cin >> s1.address; 

		file.write(reinterpret_cast<char *>(&s1), sizeof(s1));
		cout << "Do you want to fill again(y/n)? ";
		cin >> ch;
		
	}while(ch == 'y' || ch == 'Y');

	file.close();

	Student s2;
	ifstream ifile;
	ifile.open("Student.dat", ios::in|ios::binary);
	while(!ifile.eof()){
		cout << endl << endl;
		ifile.read(reinterpret_cast<char *>(&s2), sizeof(s2));
		if( ifile.good() )
			show(s2);
	}
	ifile.close();

	cout << endl;
	return 0;
}