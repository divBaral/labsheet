#include <iostream>
#include <iomanip>
using namespace std;

inline double inc(double sal,int per)
{
	return sal+per/100.0*sal;
}

int main()
{
	double ceo=35000,io=25000,sa=24000,pgr=18000;
	ceo=inc(ceo,9);
	io=inc(io,10);
	sa=inc(sa,12);
	pgr=inc(pgr,12);
	cout<<left<<setw(30)<<"Ranks"<< "Net Payment"<<endl<<endl;
	cout<<setw(30)<<"Chief executive officer"<<":Rs."<<setw(8)<<ceo<<endl;
	cout<<setw(30)<<"Information officer"<<":Rs."<<setw(8)<<io<<endl;
	cout<<setw(30)<<"System analyst"<<":Rs."<<setw(8)<<sa<<endl;
	cout<<setw(30)<<"Programmer"<<":Rs."<<setw(8)<<pgr<<endl;

	return 0;
}
