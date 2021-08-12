/*
Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.
*/
#include <iostream>

using namespace std;

class ScientificLength;

class BritishLength {
public:
	BritishLength( int p_ft=0, int p_in=0 )
	:ft{p_ft}, in{p_in}
	{}
	void show()
	{
		cout << ft << " ft " << in << " inches " ;
	}
	operator ScientificLength();

private:
	int ft, in;
};

class ScientificLength 
{
public:
	ScientificLength( int p_m=0, int p_cm=0 )
	:m{p_m}, cm{p_cm}
	{}
	operator BritishLength()
	{
		int  total = m*100 + cm;
		float inch = total / 2.54;
		int ft = inch / 12;
		inch -= ft*12;
		return BritishLength(ft, static_cast<int>(inch) );
	}
	void show()
	{
		cout << m << " m " << cm << " cm " ;
	}
private:
	int m, cm;

};
int main()
{
	BritishLength bu(12, 6);
	ScientificLength su(12, 67);
	BritishLength bl = (BritishLength) su;
	ScientificLength sl = (ScientificLength) bu;

	cout << "\nUnit conversions\n";
	bu.show();
	cout << " = ";
	sl.show();
	cout << "\nUnit conversions\n";
	su.show();
	cout << " = ";
	bl.show();





}
BritishLength::operator ScientificLength()
{
	int total = ft*12 + in;
	float cm = total* 2.54;
	int m = cm / 100;
	cm -= m*100;

	return ScientificLength{ m, static_cast<int>(cm) };
}