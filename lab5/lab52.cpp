 /*
 Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).
 */

#include <iostream>

using namespace std;


class Point {
public:
    Point(float p_x = 0.0f, float p_y = 0.0f, float p_z = 0.0f)
    :
    x{p_x}, y{p_y}, z{p_z}
    {}
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator-(const Point& p1, const Point& p2);
    
    void show()
    {
        std::cout << '(' << x << ',' << y << ',' << z << ')' << std::endl;
    }
private:
    float x, y, z;
};

Point operator+(const Point& p1, const Point& p2)
{

    return Point(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}
Point operator-(const Point& p1, const Point& p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}

int main()
{
    Point p1(3, 2, 3.4);
    Point p2(1, 2, 3.5);
    Point p3 = p1 + p2;
    Point p4 = p1 - p2;

    p1.show();
    p2.show();
    cout << "\nAfter adding \n";
    p3.show();
    cout << "\nAfter subtracting \n";
    p4.show();
    


}