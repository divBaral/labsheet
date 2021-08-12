/*
Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.
*/


#include <iostream>


constexpr int days_in_months[] = {0, 30, 28, 31, 30, 31, 30,31,31, 30, 31, 30, 31};
class Date {
private:
    int y, m, d;

public:
    Date(int p_y = 0, int p_m = 0, int p_d =0)
    :y{p_y}, d{p_d}, m{p_m} 
    {}


    // prefix
    Date &operator++() 
    {
        ++d;
        if (d > days_in_months[m]) {
            if (m == 2 && ((y % 4) == 0) && ((y % 100) != 0 || (y % 400) == 0)) {
                ++m;
                d = 1;
            } 
            else {
                d = 1;
                ++m;
                if (m > 12) {
                    m = 1;
                    ++y;
                }
            }
        }
        return (*this);
    }

    // postfix
    Date& operator++(int) 
    {
        
        d++;
        if (d > days_in_months[m]) {
            if (m == 2 && ((y % 4) == 0) && ((y % 100) != 0 || (y % 400) == 0)) {
                m++;
                d = 1;
            } else {
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                }
            }
        }
        return (*this);
    }


    friend std::ostream& operator<<(std::ostream& os, const Date& d) 
    {
        os << d.y << "/" << d.m << "/" << d.d;
        return os;
    }
};

int main() 
{
    Date d(2021, 2, 29);
    std::cout << ++d<< std::endl;
    std::cout << d++ << std::endl;
}
