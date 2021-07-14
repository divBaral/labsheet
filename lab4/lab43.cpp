/*
Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.
*/
#include <iostream>

class Department {
public:
	Department(int p_id=0, std::string p_name="")
	:id{p_id}, name{p_name}
	{
	}
	void display()
	{
		std::cout << id << "." << name << std::endl;
	}
	~Department()
	{
		std::cout << "Object " << name << " goes out of scope" << std::endl;
	}

private:
	int id;
	std::string name;	

};


int main()
{


	Department d1(101, "Computer");
	Department d2(102, "Mechanical");
	Department d3(103, "Physics");

	
	return 0;

}
