/*Write a program to overload stream operators to read a complex number and display the complex number in a+ib format.*/
#include <iostream>
using namespace std;

class Mycomplex
{
public:
	Mycomplex(float x=0, float y=0)
	{
		a = x;
		b = y;

	}
	friend ostream& operator<<(ostream& os, Mycomplex cmp);
	friend istream& operator>>(istream& is, Mycomplex& cmp);
private:
	float a, b;
};
ostream& operator<<(ostream& os, Mycomplex cmp)
{
	os << cmp.a <<" + i " << cmp.b;
	return os;
}
istream& operator>>(istream& is, Mycomplex& cmp)
{
	is >> cmp.a >> cmp.b;
	return is;
}
int main()
{
	Mycomplex cmp;
	cin >> cmp;
	cout << cmp;
}