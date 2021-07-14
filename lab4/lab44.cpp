/*Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).*/


#include <iostream>
using namespace std;

class Vehicle {
public:
	Vehicle(int p_num_vehicle, float p_rate, float p_hour)
	:
	num_vehicle{p_num_vehicle}, rate{p_rate}, hour{p_hour}
	{}
	Vehicle(Vehicle &v)
	{
		num_vehicle = v.num_vehicle;
		rate = v.rate;
		hour = v.hour;
		//std::cout << "Our copy constructer invoked\n";

	}
	float getCharge()
	{
		float charge = rate*hour;
		if ( num_vehicle > 10 )
			charge -= 0.1*charge;
		return charge;


	}
private:
	int num_vehicle;
	float rate, hour;
};
int main()
{
	Vehicle v1{123, 12.3, 23};
	Vehicle v2 = v1;
	cout << v1.getCharge() << " and " << v2.getCharge() << endl;

}