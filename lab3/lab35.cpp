#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
public:
	void setpara(int i, double b, float o, int y)
	{
		id = i;
		bon = b;
		ot = o;
		yr = y;
	}
	void displayreport(Employee);
private:
	int id;
	double bon;
	float ot;
	int yr;
};
void Employee::displayreport(Employee e)
{
	std::cout << "Employee with ID " << e.id << " has received Rs " << 
	e.bon << " as bonus \n and \n had worked " << e.ot << 
	" hours as a overtime in year " << e.yr << endl << endl;

}

int main()
{
	cout << "Enter no. of employees:";
	int n;
	cin >> n;
	const int size = n;
	Employee e[size];
	int id;
	double bon;
	float ot;
	int yr;
	cout << "Enter year:";
	cin >> yr;

	for (int i = 0; i < n; ++i) {
		cout << "Enter Id of " << i+1 << "employee:" ;
		cin >> id;
		cout << "Enter bonus:" ;
		cin >> bon;
		cout << "Enter overtime(in hrs):" ;
		cin >> ot;


		e[i].setpara(id,bon,ot,yr);
	}
	cout << setw(23)<<"Data" << endl << endl;
	Employee x;
	for (int i = 0; i < n; ++i)
		x.displayreport(e[i]); //qn explicitly says to pass arguments, so relunctantly writing this way.

	
}