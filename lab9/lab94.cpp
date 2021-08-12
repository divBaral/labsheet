/*Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exceptions.

*/
#include <iostream>
using namespace std;

class Derror{};

int divide(int x, int y)
{

	try 
	{
		if (y!=0)
			return x/y;
		else 
			throw Derror();
	}
	catch(Derror)
	{
		cout << "Partial Handler\n";
		throw;
	}
}
int main()
{
	int a = 1, b = 0;
	try {
		cout << divide(a,b);
		cout << divide(22,22);
	}
	catch(Derror) {
		cout << "Please don't divide by 0";
	}
	catch(...)
	{
		cout << "Other error occured\n";
	}
	
}