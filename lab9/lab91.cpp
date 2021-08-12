/*Create a function called sum ( ) that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a main ( ) program that applies this function to data of various types.*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
T sum(T a, T b)
{
	return a+b;
}
int main()
{
	int ix = 2, iy = 3;
	float fx = 2.2 , fy = 3.6;
	string first_name="Saroj " , last_name= "baral";

	cout << sum(ix, iy) << endl;
	cout << sum(fx, fy) << endl;

}