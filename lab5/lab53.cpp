/*
Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=) and less than or equal to(<=) operators using member operator functions.
*/

#include <iostream>
using namespace std;

class myInt {
	
public:
	myInt(const int& p_val)
	:val{p_val}
	{}

	bool operator==( const myInt i )
	{
		return val == i.val;
	}
	bool operator>( const myInt i )
	{
		return val > i.val;
	}
	bool operator<( const myInt i )
	{
		return val < i.val;
	}
	bool operator<=( const myInt i )
	{
		return val <= i.val;
	}
	bool operator>=( const myInt i )
	{
		return val >= i.val;
	}
	bool operator!=( const myInt i )
	{
		return val != i.val;
	}
private:
	int val;

};
int main()
{
	myInt p(33);
	myInt q(34);


	if ( p == q )
		cout << "p and q are equal\n";
	else if (p != q) {
		if ( p > q && p >= q) 
		cout << "p is greater than q\n";
		else
			cout << "q is greater than p\n";

		if (p < q && p <= q)
			cout << "p is less than q\n";
		else
			cout << "q is less than p\n";
	}
	return 0;
	
}