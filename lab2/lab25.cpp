#include <iostream>
using namespace std;

inline double netpay(double x)
{
	return x-.1*x;
}

int main()
{
	cout << "Enter income:" ;
	double income;
	cin >> income;
	cout<<"Your net payment by company:"<<netpay(income);
	return 0;
}