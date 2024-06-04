#include <iostream>
using namespace std;

class Animal
{
protected:
	string species;
	float speed;
	float weight;
	string living;
public:
	Animal() :species("no species"), speed(0), weight(0), living("no live") {}
	Animal(string species, float speed, float weight, string living) :species(species), living(living)
	{
		this->speed = speed >= 0 ? speed : 0;
		this->weight = weight >= 0 ? weight : 0;
	}


	virtual void Move()const
	{
		cout << "I move......" << endl;
	}
	void Print()const
	{
		cout << "Species : " << species << endl;
		cout << "Speed : " << speed << " km/h" << endl;
		cout << "Weight : " << weight << " kg" << endl;
		cout << "Living environment : " << living << endl;
	}
	virtual void Say()const
	{
		cout << "I say......" << endl;
	}
};

class Bird : public Animal
{
public:
	Bird() :Animal() {}
	Bird(string species, float speed, float weight, string living) :Animal(species, speed, weight, living) {}


	void Move()const override
	{
		cout << "I move in the air at a speed " << speed << " km/h and on the ground..." << endl;
	}
	void Print()const
	{
		cout << "======== Bird ========" << endl;
		Animal::Print();
		cout << endl;
	}
	void Say()const override
	{
		cout << "Tweet-tweet" << endl;
	}
};

class Reptile : public Animal
{
public:
	Reptile() :Animal() {}
	Reptile(string species, float speed, float weight, string living) :Animal(species, speed, weight, living) {}


	void Move()const override
	{
		cout << "I move in water and on land at a speed " << speed << " km/h..." << endl;
	}
	void Print()const
	{
		cout << "======== Reptile ========" << endl;
		Animal::Print();
		cout << endl;
	}
	void Say()const override
	{
		cout << "Hiss-hiss" << endl;
	}
};

class Fish : public Animal
{
public:
	Fish() :Animal() {}
	Fish(string species, float speed, float weight, string living) :Animal(species, speed, weight, living) {}


	void Move()const override
	{
		cout << "I move in water at a speed " << speed << " km/h..." << endl;
	}
	void Print()const
	{
		cout << "======== Fish ========" << endl;
		Animal::Print();
		cout << endl;
	}
	void Say()const override
	{
		cout << "Splash-splash" << endl;
	}
};



int main()
{
	Bird bird("bird", 25, 0.8, "air");
	Fish fish("fish", 15, 0.5, "water");
	Reptile reptile("reptile", 30, 50, "land");

	bird.Print();
	bird.Move();
	bird.Say();

	fish.Print();
	fish.Move();
	fish.Say();

	reptile.Print();
	reptile.Move();
	reptile.Say();
}