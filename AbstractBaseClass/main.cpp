#include <iostream>
#include<string>
using namespace std;

class Vehicle
{
public:
	virtual void move() = 0;
};

class GroundVehicle: public Vehicle{};

class Car : public GroundVehicle
{

public:
	void move()
	{
		cout << "Машина едет на четырёх колёсах" << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "");

	Car bmw;
	bmw.move();
}