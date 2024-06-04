#include <iostream>
using namespace std;

class Hero
{
protected:
	string name;
	int health;
	float strength;
	static const int maxHealth = 100;
public:
	Hero() :name("no name"), health(maxHealth), strength(0) {}
	Hero(string name, float st) :name(name), health(maxHealth), strength(st) {}


	void Print()const
	{
		cout << "Name : " << name << endl;
		cout << "Health : " << health << '%' << endl;
		cout << "Strength : " << strength << endl;
	}
	bool IsAlive()const
	{
		return health > 0;
	}
	void DecreaseHealth(int value)
	{
		if (health - value < 0)
			health = 0;
		else
			health -= value;
	}
};

//Inheritance
//class Child : [specificator] Parent
//[specificator] : public, private, protected
class Dragon : public Hero
{
	float fire;
public:
	Dragon() :fire(0), Hero() {}
	Dragon(string name, float s, float fire) :fire(fire), Hero(name, s) {}


	void Print()const
	{
		cout << "---------------- Dragon ----------------" << endl;
		Hero::Print();
		cout << "Fire : " << fire << endl;
	}
	void Fight(int damage)
	{
		cout << "Getting " << damage << " damage..." << endl;
		DecreaseHealth(damage - fire);
		cout << "Health after damage " << health << '%' << endl;
	}
	int Attack()const
	{
		cout << "Attacking with " << strength << endl;
		return strength;
	}
};

class Monster : public Hero
{
	float runSpeed;
public:
	Monster() :runSpeed(0), Hero() {}
	Monster(string name, float s, float run) :runSpeed(run), Hero(name, s) {}


	void Print()const
	{
		cout << "---------------- Monster ----------------" << endl;
		Hero::Print();
		cout << "Run speed : " << runSpeed << endl;
	}
	void Run()const
	{
		cout << "Running with speed : " << runSpeed << " km/h" << endl;
	}
};



//int main()
//{
	/*
	srand(time(NULL));
	Monster monster("Bob", 2, 200);
	monster.Run();
	monster.Print();
	*/


	/*
	Hero h;

	Dragon boss("Oleg", rand() % 5 + 1, rand() % 5 + 1);
	boss.Print();

	Dragon dragon("Vasia", rand() % 5 + 1, rand() % 5 + 1);
	dragon.Print();

	int i = 1;
	do {
		cout << "---------------- Round [ " << i << " ] ----------------" << endl;
		boss.Fight(dragon.Attack());
		dragon.Fight(boss.Attack());
		boss.Print();
		dragon.Print();
		i++;
		cout << endl;
	} while (boss.IsAlive() && dragon.IsAlive());
	*/
	//}