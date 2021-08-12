/*
Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

A. Make a particular member function of one class as a friend function of another class for addition.

B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

Make least possible classes to demonstrate all the above in a single program without conflict.

*/

#include <iostream>

class Position_Operations;
class Position;

class Position_Adder{
public:
	static Position add(const Position& p1, const Position& p2);
};

class Position {
 
	friend Position Position_Adder::add(const Position& p1, const Position& p2);
	friend class Position_Operations; 

public:
	Position(const float p_x = 0.0f, const float p_y = 0.0f)
	:x{p_x}, y{p_y}
	{

	}
	void display()
	{
		std::cout << '(' << x << ',' << y << ')' << std::endl;

	}
private:
	float x,y;
};
class Position_Operations {
public:
	
	static Position subtract(const Position& p1, const Position& p2) 
	{
		return Position{p1.x-p2.x, p1.y-p2.y};
	}

	static Position multiply(const Position& p1, const Position& p2) 
	{
		return Position{p1.x*p2.x, p1.y*p2.y};
	}
	static Position divide(const Position& p1, const Position& p2)
	{
		return Position{p1.x/p2.x, p1.y/p2.y};
	}
};



Position Position_Adder::add(const Position& p1, const Position& p2) 
{
	return Position{p1.x+p2.x, p1.y+p2.y};
}



int main()
{
	Position p1(1,2), p2(2, 3);

	Position ap,sp,mp,dp;

	ap = Position_Adder::add(p1, p2);
	sp = Position_Operations::subtract(p1, p2);
	mp = Position_Operations::multiply(p1, p2);
	dp = Position_Operations::divide(p1, p2);

	std::cout << "Given points"<< std::endl;
	p1.display();
	p2.display();


	std::cout << "\nAfter adding" << std::endl;
	ap.display();
	std::cout << "\nAfter subtracting" << std::endl;
	sp.display();
	std::cout << "\nAfter multiplying" << std::endl;
	mp.display();
	std::cout << "\nAfter dividing" << std::endl;
	dp.display();

}