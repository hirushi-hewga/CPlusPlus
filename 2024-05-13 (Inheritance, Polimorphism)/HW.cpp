#include <iostream>
using namespace std;

class Transport
{
	float time;
	float cost;
	float speed;
public:
	Transport() :time(0), cost(0), speed(0) {}
	Transport(float t, float c, float s) :time(t), cost(c), speed(s) {}

	virtual void Print()const
	{
		cout << "Time : " << time << " m" << endl;
		cout << "Cost : " << cost << " grn" << endl;
		cout << "Speed : " << speed << " miles" << endl;
	}
};

class Car : public Transport
{
public:
	Car() :Transport() {}
	Car(float t, float c, float s) :Transport(t, c, s) {}

	void Print()const override
	{
		cout << "======== Car ========" << endl;
		Transport::Print();
	}
};

class Bicycle : public Transport
{
public:
	Bicycle() :Transport() {}
	Bicycle(float t, float c, float s) :Transport(t, c, s) {}

	void Print()const override
	{
		cout << "======== Bicycle ========" << endl;
		Transport::Print();
	}
};

class Cart : public Transport
{
public:
	Cart() :Transport() {}
	Cart(float t, float c, float s) :Transport(t, c, s) {}

	void Print()const override
	{
		cout << "======== Cart ========" << endl;
		Transport::Print();
	}
};



//int main()
//{
	/*Car car(20, 37, 80);
	Bicycle bicycle(40, 10, 50);
	Cart cart(60, 0, 20);

	car.Print();
	bicycle.Print();
	cart.Print();*/
	//}