#include <iostream>
using namespace std;
struct date
{
	int mon,day,yr;
	
};
void show_date(struct date);
int main()
{
	struct date d;
	cout << "Enter month, day and year:";
	cin >> d.mon >> d.day >> d.yr;
	show_date(d);
}
void show_date(struct date d)
{
	cout << d.mon << '/' << d.day << '/' << d.yr;
}