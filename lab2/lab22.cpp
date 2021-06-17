#include <iostream>
using namespace std;
void inchof(float&);
float inchof(float,float);
void inchof();
int main()
{
	float ft;
	cout<<"Enter feet:"<<endl;
	cin>>ft;
	float in=ft;
	inchof(in);//with one argument and reference
	cout<<"Inches in "<<ft<<"ft:"<<in<<endl;

	cin>>ft>>in;
	cout<<"Inches in "<<ft<<"ft and "<<in<<"inches:"<<inchof(ft,in)<<endl;//with 2 arguments
	
	inchof(); //with no argument
	return 0;
}
void inchof(float &x)
{
	x=x*12;
}
void inchof()
{
	float ft;
	cin>>ft;
	cout<<"Inches in "<<ft<<"ft:"<<ft*12<<endl;

}
float inchof(float f,float i)
{
	return f*12+i;
}