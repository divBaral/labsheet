#include <iostream>


constexpr int days_in_months[] = {0, 30, 28, 31, 30, 31, 30,31,31, 30, 31, 30, 31};
class Date {
    int yy, mm, dd;

public:
    Date() : yy(0), mm(0), dd(0) {}
    Date(int y, int m, int d) : yy(y), mm(m), dd(d) {}


    // prefix
    Date &operator++() 
    {
        ++dd;
        if (dd > days_in_months[mm]) {
            if (mm == 2 && ((yy % 4) == 0) && ((yy % 100) != 0 || (yy % 400) == 0)) {
                if (dd > 29) {
                    ++mm;
                    dd = 1;
                }
            } else {
                dd = 1;
                ++mm;
                if (mm > 12) {
                    mm = 1;
                    ++yy;
                }
            }
        }
        return (*this);
    }

    // postfix
    Date& operator++(int) 
    {
        
        dd++;
        if (dd > days_in_months[mm]) {
            if (mm == 2 && ((yy % 4) == 0) && ((yy % 100) != 0 || (yy % 400) == 0)) {
                if (dd > 29) {
                    mm++;
                    dd = 1;
                }
            } else {
                dd = 1;
                mm++;
                if (mm > 12) {
                    mm = 1;
                    yy++;
                }
            }
        }
        return (*this);
    }


    friend std::ostream& operator<<(std::ostream &os, const Date &date) 
    {
        os << date.yy << "/" << date.mm << "/" << date.dd;
        return os;
    }
};

int main() 
{
    Date d(2020, 3, 30);
    std::cout << ++d<< std::endl;
    std::cout << d++ << std::endl;
}
