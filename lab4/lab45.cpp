/*
Write a program that illustrates the following relationship and comment on them. 

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function
*/



#include <iostream>
using namespace std;

class Date {
public:
	Date(int p_yr=0, int p_mon=0, int p_day=0)
	: yr{p_yr}, mon{p_mon}, day{p_yr}
	{}
	Date(Date &d)
	{
		cout << "oh damn";
	}
	void show() const // cost member function
	{
		std::cout << yr << '/' << mon << '/' << day << std::endl;
	}
	void modify(int y=0, int m=0, int d=0) // non-const memberfunction
	{
		yr=y;
		mon=m;
		day=d;
	}
private:
	int yr,mon,day;

};
int main()
{
	Date d1;
	const Date d2 =  {2072, 10, 11};
	
	d1 = Date{2001, 12, 13};

	d1.show(); // non-const obj.const_memberfunction
	d2.show(); // const obj.const_memberfunction
	//d2.modify(); // const obj.non_const_memberfunction
	d1.modify(2078, 5, 20); // non-const obj.non-const member function
	d1.show();
}