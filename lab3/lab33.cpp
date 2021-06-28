#include <iostream>

class carpark{
public:
	void set(int c, int cph, float t)
	{
		carid = c;
		chph = cph;
		time = t;
	}
	void show()
	{
		std::cout << "Car ID:" << carid << std::endl;
		std::cout << "Charge per hour: Rs " << chph << std::endl;
		std::cout << "Parked time:" << time << " hrs" << std::endl;

	}
private:
	int carid;
	int chph; //charge per hour
	float time;

};

int main()
{
	carpark c;
	c.set(1232, 50, 1.5);
	c.show();
	return 0;
}