/*
Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.
*/
#include <iostream>
#include <cstring>

using namespace std;

class Animal {
public:
	static int serial_no;
	Animal(const char* p_name)
	{
		strcpy(name, p_name);
		serial_no++;
	}
	void bark()
	{
		std::cout << name << " is barking!" << std::endl;
	}
	void jump()
	{
		std::cout << name << " is jumping!" << std::endl;
	}
	void sleep()
	{
		std::cout << name << " is sleeping!" << std::endl;
	}
	static void show_objects()
	{
		std::cout << "No of objects created:" << serial_no << std::endl;
		
	}
private:
	char name[25];
	int size;

};

int Animal::serial_no = 0;

int main()
{
	
	Animal d1("Dog");
	d1.bark();

	Animal d2("Fox");
	d2.jump();

	Animal d3("Cat");
	d3.sleep();
	
	Animal::show_objects();

	return 0;
}