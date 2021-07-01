#include <iostream>
#include <cmath>
using namespace std;

class Circle {
public:
	void read()
	{
		std::cout << "Enter Radius of Circle:";
		std::cin >> r;
	}
	void show()
	{
		std::cout << "Circle(r=" << r << ')' << std::endl;
	}
	float peri()
	{
		return 2*pi*r;
	}
	float area() 
	{
		return pi*r*r;
	}
	
private:
	static constexpr float pi = 3.14f;
	float r;
};
class Rectangle {
public:
	void read()
	{
		std::cout << "Enter Rectangle length and breadth:";
		std::cin >> l >> b;
	}
	void show()
	{
		std::cout << "Rectangle(l="<< l << ",b=" << b << ')' << std::endl;
	}

	float peri()
	{
		return 2*(l+b);
	}
	float area() { return l*b;}
private:
	float l,b;

};
class Triangle {
public:
	void read()
	{
		float aa,bb,cc;
		std::cout << "Enter sides of triangle:";
		std::cin >> aa >> bb >> cc;
		bool i = (aa + bb) > cc;
		bool j = (aa + cc) > bb;
		bool k = (bb + cc) > aa;
		if( i && j && k) {
			a = aa, b = bb, c = cc;
		}
		else
			perror("Triangle invalid sides");
	}
	void show()
	{
		std::cout << "Triangle(a="<< a << ",b=" << b << ",c=" << c << ')'<< std::endl;
	}

	float area()
	{
		float s = (a + b + c) / 2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	float peri() { return (a + b + c);}
private:
	float a,b,c;
	

};
int main()
{
	Circle c;
	Rectangle r;
	Triangle t;

	c.read();
	r.read();
	t.read();

	t.show();
	cout << "Perimeter:" << t.peri() << endl;
	cout << "Area:" << t.area() << endl << endl;

	r.show();
	cout << "Perimeter:" << r.peri() << endl;
	cout << "Area:" << r.area() << endl << endl;

	c.show();
	cout << "Circumference:" << c.peri() << endl;
	cout << "Area:" << c.area() << endl << endl;


}