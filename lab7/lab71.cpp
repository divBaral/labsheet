/*Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and Trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.*/

#include <iostream>
using namespace std;

class Shape 
{
public:
	virtual float area() = 0;
	virtual ~Shape(){
		cout << "Shape Destructed\n";
	}

};
class Circle : public Shape
{
	float r;

public:
	Circle( float p_r ) 
	: r (p_r)
	{}

	float area()
	{
		return 3.14*r*r;
	}
	 ~Circle()
	{
		cout << "Circle Destructed\n";
	}
};
class Trapezoid :   public Shape
{
public:
	Trapezoid( float p_l1, float p_l2, float p_h)
	:
	l1 (p_l1), l2(p_l2), h(p_h) {}
	float area()
	{
		return 0.5*(l1+l2)*h;
	}
	 ~Trapezoid()
	{
		cout << "Trapezoid Destructed\n";
	}


protected:
	float l1,  l2, h;
};
class Rectangle :   public Trapezoid
{
public:
	Rectangle(float p_l, float p_h)
	:
	Trapezoid( p_l, p_l, p_h)
	{}

	~Rectangle()
	{
		cout << "Rectangle Destructed\n";
	}


};
int main()
{
	Shape* circle, *trapezoid, *rect;
	circle = new Circle( 5 );
	trapezoid = new Trapezoid( 2, 2, 5);
	rect = new Rectangle( 4, 4);
	

	cout << "Areas" << endl;
	cout << "Circle: " << circle->area() << endl;
	cout << "Trapezoid: " << trapezoid->area() << endl;
	cout << "Rectangle: " << rect->area() << endl << endl;

	delete circle;
	delete trapezoid;
	delete rect;

}
