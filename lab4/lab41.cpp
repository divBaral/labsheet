/*Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.*/


#include <iostream>

class Time {
public:
	Time()
	:hr{0}, min{0}, sec{0}
	{}
	Time(int p_hr, int p_min, int p_sec)
	:hr{p_hr}, min{p_min}, sec{p_sec}
	{}

	Time add(const Time& t1,const Time& t2)
	{
		Time t;
		t.sec = (t1.hr + t2.hr)*3600 + (t1.min + t2.min)*60 + (t1.sec + t2.sec);
		t.min = t.sec / 60;
		t.hr = t.min / 60;

		t.min = t.min - t.hr*60;
		t.sec = t.sec - t.min*60 - t.hr*3600;
		return t;

	}
	void display()
	{
		std::cout << hr << ":" << min << ":" << sec << std::endl;
	}
private:
	int hr,min,sec;
};
int main()
{
	Time t1, t2, t3; // default constructer invoked
	int hr, min, sec;
	std::cout << "Enter time 1 (hr,min,sec):";
	std::cin >> hr >> min >> sec;
	t1 = Time{hr, min, sec}; //explict copy

	std::cout << "Enter time 2 (hr,min,sec):";
	std::cin >> hr >> min >> sec;
	t2 = Time{hr, min, sec}; //explict copy
	t3 = t3.add(t1, t2);

	std::cout << "After adding ";
	t3.display();
	
	return 0;

}
