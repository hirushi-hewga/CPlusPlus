#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
protected:
	string model;
	int speed;
	float volume;
	float run;
	int year;
public:
	Car() :model("no model"), speed(0), volume(0), run(0), year(0) {}
	Car(string m, float v, float r, int y) :model(m), speed(0), volume(v), run(r), year(y) {}


	void Drive()const
	{
		cout << "I`am a Car! I can drive with speed " << speed << " km/h" << endl;
	}
	void Print()const
	{
		cout << "---------------- Car ----------------" << endl;
		cout << "Model : " << model << endl;
		cout << "Speed : " << speed << endl;
		cout << "Volume : " << volume << endl;
		cout << "Run : " << run << endl;
		cout << "Year : " << year << endl;
	}
	void SetSpeed(int speed)
	{
		if (speed > 0)
			this->speed = speed;
	}
};

//public car , private car , protected car
class PoliceCar : public Car
{
	int soundVolume;
public:
	PoliceCar() :soundVolume(0), Car() {}
	PoliceCar(string m, float v, float r, int y, int s) :soundVolume(s), Car(m, v, r, y) {}


	void Drive()const
	{
		cout << "I`am a Police Car! I can drive with speed " << speed << " km/h" << endl;
	}
	void Print()const
	{
		Car::Print();
		cout << "Sound volume : " << soundVolume << " km/h" << endl;
	}
};

class SportCar : public Car
{
	int turbo;
public:
	SportCar() :turbo(0), Car() {}
	SportCar(string m, float v, float r, int y, int t) :turbo(t), Car(m, v, r, y) {}


	void Drive()const
	{
		cout << "I`am a Police Car! I can drive with speed " << speed << " km/h" << endl;
	}
	void Print()const
	{
		Car::Print();
		cout << "Turbo speed : " << turbo << " km/h" << endl;
	}
	void Nitro()
	{
		speed += turbo;
		cout << "New speed : " << speed << " km/h" << endl;
	}
};



void TestDrive(Car& car)
{
	car.SetSpeed(70);
	car.Drive();
}

//int main()
//{
	/*Car car("BMW", 2.0, 50000, 2024);
	car.SetSpeed(350);
	car.Drive();
	car.Print();

	PoliceCar police("Toyota", 1.5, 200000, 2000, 500);
	police.SetSpeed(100);
	police.Drive();
	police.Print();

	TestDrive(car);
	TestDrive(police);



	SportCar sport("Ford", 3.0, 2000, 2024, 50);
	sport.SetSpeed(250);
	sport.Drive();
	sport.Nitro();
	sport.Print();
	cout << endl << endl;
	TestDrive(car);
	TestDrive(police);
	TestDrive(sport); */

	//}