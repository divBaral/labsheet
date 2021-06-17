#include <iostream>
#include <iomanip>
using namespace std;

inline double inc(double sal,int per)
{
	return sal+per/100*sal;
}

int main()
{
	double ceo=35000,io=25000,sa=24000,pgr=18000;
	ceo=inc(ceo,9);
	io=inc(io,10);
	sa=inc(sa,12);
	pgr=inc(pgr,12);
	cout << "Net Payment\n"<<endl;
	cout<<"Chief executive officer:"<<setw(8)<<"Rs "<<ceo<<endl;
	cout<<"Information officer:"<<setw(8)<<"Rs "<<io<<endl;
	cout<<"System analyst:"<<setw(8)<<"Rs "<<sa<<endl;
	cout<<"Programmer:"<<setw(8)<<"Rs "<<pgr<<endl;

	return 0;
}
