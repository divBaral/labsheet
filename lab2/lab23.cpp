#include <iostream>
using namespace std;
namespace Square 
{
	int num;
	int fun(int n)
	{
		return n*n;
	}
}
namespace Cube
{
	int num;
	int fun(int n)
	{
		return n*n*n;
	}
}
int main()
{
	Square::num=5;
	Cube::num=6;
	int sq=Square::fun(Square::num);
	int cb=Cube::fun(Cube::num);
	cout << "Square:" << sq << endl;
	cout << "Cube:" << cb << endl;
	return 0;

}