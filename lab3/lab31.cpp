#include <iostream>
using namespace std;

class Celsius{
	float cel;
public:
	void setcel(float x){cel=x;}
	float getcel(){return cel;}
	float toFahrenheit(){return cel*9.0/5.0 +32;}

};

class Fahrenheit{
	float fah;
public:
	void setfah(float x){fah=x;}
	float getfah(){return fah;}
	float toCelsius(){return 5.0/9.0*(fah-32);}
};
int main()
{
	Celsius c;
	float cel;
	cout<<"Enter temperature in Celsuis:"<<endl;
	cin>>cel;
	c.setcel(cel);

	Fahrenheit f;
	float fah;
	cout<<"Enter temperature in Fahrenheit:"<<endl;
	cin>>fah;
	f.setfah(fah);
	cout<<c.getcel()<<" C ="<<c.toFahrenheit()<<" F"<<endl;
	cout<<f.getfah()<<" F ="<<f.toCelsius()<<" C"<<endl;
	return 0;
}