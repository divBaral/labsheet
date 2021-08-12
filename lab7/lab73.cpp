/*Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.

*/
#include <iostream>
#include <string>
using namespace std;

//abstract class
class Student
{
public:
	virtual void showdata() = 0;
	void getStudentData()
	{
		cout << "Enter name:";
		cin >> name;
		cout << "Enter roll no:";
		cin >> rollno;
	}
	void displayRollno()
	{
		cout << "My Roll no is " << rollno << endl;
	}

protected:
	string name;
	int  rollno;
};
class Engineering : public Student
{
public:
	void showdata()
	{

		cout << "My name is " << name << ".I am Engineering student.";
	}


};
class Medicine : public Student 
{
public:
	void showdata()
	{
		cout << "My name is " << name << ".I am Medicine student.";
	}
};
class Science : public Student
{
public:
	void showdata()
	{
		cout << "My name is " << name << ".I am Science student.";
	}
};




int main()
{
	Engineering en;
	Medicine md;
	Science sc;
	//array of base pointer
	Student* data[3];
	data[0] = &en;
	data[1] = &md;
	data[2] = &sc;

	for (int i =0 ; i<3; ++i)
		data[i]->getStudentData();
	for (int i =0 ; i<3; ++i) {
		data[i]->showdata();
		data[i]->displayRollno();
	}
	




}