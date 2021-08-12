/*Write a base class that asks the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally, make a third class that is a friend of derived and calculate the difference of the base complex number and its own complex number.*/
#include <iostream>
using namespace std;

class complexSub;

class complex{

public:
	float a;
	float b;

	void getData(){
		cout << "Enter a complex number(a b): ";
		cin >> a >> b;
	}

	void showData(){
		cout << a << " + " << "(" << b << ")" << "j";
	}
};

class complexAdd: public complex{
public:
	void getData(){
		complex::getData();
	}
	complex operator + (const complex c1){
		complex temp;
		temp.a = a + c1.a;
		temp.b = b + c1.b;
		return temp;
	}
	friend class complexSub;
};

class complexSub{
public: 
	static void getData(complexAdd& c1){

		c1.getData();
	}
	static complex subtract(complexAdd c1, complex c2){
		complex temp;
		temp.a = c1.a - c2.a;
		temp.b = c1.b - c2.b;
		return temp;
	}
};

int main(){
	complex num1;
	num1.getData();
	complexAdd num2;
	num2.getData();

	cout << endl;
	num2.showData(); cout << " + "; num1.showData();
	cout << " = "; (num2 + num1).showData();

	cout << endl;
	num2.showData(); cout << " - "; num1.showData();
	cout << " = "; complexSub::subtract(num2, num1).showData();

	cout << endl;
	return 0;
}