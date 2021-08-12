// careate a polymorphic class Vehicle and careate other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Vehicle{
public:
	Vehicle(string name)
	{
		m_name = name;
	}
	virtual void getInfo(){}
protected:
	string m_name;
};

class Bus: public Vehicle
{
public:
	Bus(string name): Vehicle(name){}
	

	void getInfo()
	{
		cout << "I am "<< m_name << " bus." << endl;
	}
};

class Car: public Vehicle
{
public:
	Car(string name ): Vehicle(name){}
	

	void getInfo(){
		cout << "I am "<< m_name << " car." << endl;
	}
};

class Bike: public Vehicle{
public:
	Bike(string name ): Vehicle(name){}
	void getInfo(){
		cout << "I am "<< m_name << " Bike." << endl;
	}
};

int main()
{
	Vehicle *vehicle;
	Bus bus("Night");
	Car car("Lamborgini");
	Bike bike("Bullet");

	vehicle = &bus;
	cout << typeid(*vehicle).name() << endl;
	vehicle = &car;
	cout << typeid(*vehicle).name() << endl;
	vehicle = &bike;
	cout << typeid(*vehicle).name() << endl;

	vehicle = dynamic_cast<Bus *>(&bus);
	if ( vehicle )
		vehicle->getInfo();

	vehicle = dynamic_cast<Car *>(&car);
	if ( vehicle )
		vehicle->getInfo();

	vehicle = dynamic_cast<Bike *>(&bike);
	if ( vehicle )
		vehicle->getInfo();

	cout << endl;
	return 0;
}