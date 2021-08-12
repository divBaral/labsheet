/*
Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.
*/
#include <iostream>
using namespace std;

class Distance
{
public:
	Distance( float p_m , float p_cm )
	:m{p_m}, cm{p_cm}
	{}
	Distance(float p_m)
	{
		m = static_cast<int>(p_m);
		cm = (p_m - m)*100;

	}

	operator float()
	{
		return m + cm / 100;
	}
	
	void show()
	{
		cout << m << " m " << cm << " cm" << endl;
	}
	
private:
	float m, cm;
	
};



int main()
{
	Distance d{23, 23};

	float f = (float) d;

	Distance d1 = (Distance) f;

	cout << f << endl;
	d1.show();

	return 0;
}
