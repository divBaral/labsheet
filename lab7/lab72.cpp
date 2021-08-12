/*Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.

*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	 void getdata()
	{
		cout << "Enter name:";
		cin >> name;
		cout << "Enter age:";
		cin >> age;
	}

protected:
	string name;
	int age;

};
class Empolyee : virtual public Person
{
public:
	 void getdata()
	{
		
		cout << "Enter salary:";
		cin >> salary;
	}
protected:
	double salary;
};

class Student : virtual public Person
{
public:
	 void getdata( )
	{
		
		cout << "Enter Name of your College:";
		cin >> clzName;
	}
protected:
	string clzName;
};

class Manager : public Empolyee, Student
{
public:
	void getdata()
	{
		Person::getdata();
		Empolyee::getdata();
		Student::getdata();
		
		cout << "Enter name of your working firm:";
		cin >> firmName;
	}
	void showdata()
	{
		cout << "\n\nManager Details:" << endl;
		cout << name << endl;
		cout << age << endl;
		cout << salary << endl;
		cout << clzName << endl;
		cout << firmName << endl;
	}

private:
	string firmName;

};
int main()
{
	Manager m;
	m.getdata();
	m.showdata();

}