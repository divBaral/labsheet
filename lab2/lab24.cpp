#include <iostream>
using namespace std;
float& large(float& ,float& );
int main()
{
	float val,t1=23.4,t2=37.9;
	cout << "Enter value:"<<endl;
	cin >> val;
	large(t1,t2)=val;
	cout<< "t1:"<<t1<<endl;
	cout<< "t2:"<<t2<<endl;
	return 0;
}
float& large(float& x, float& y)
{
	return x>y?x:y;
}