#include <iostream>
using namespace std;

inline void Hello()
{
	cout << "Hello" << endl;
}

class Test
{
public:
	void Print();//prototype of method
};

void Test::Print()
{
	cout << "Hello" << endl;
}

class Human
{
	string name;
	int age;
	int weigth;
public:
	static int count;
	Human()//default constructor
	{
		this->name = "no name";
		this->age = 0;
		this->weigth = 0;
		this->count++;
	}
	Human(string name) :Human()
	{
		this->name = name;
		//this->age = 0;
		//this->weigth = 0;
		this->count++;
	}
	Human(string name, int age) :Human(name)
	{
		//this->name = name;
		this->age = age;
		//this->weigth = 0;
		this->count++;
	}
	Human(string name, int age, int weigth) :Human(name, age)
	{
		//this->name = name;
		//this->age = age;
		this->weigth = weigth;
		this->count++;
	}


	/*
	Human(string name, int weigth)
	{
		this->name = name;
		this->age = 0;
		this->weigth = weigth;
	}
	Human(int weigth)
	{
		this->name = "no name";
		this->age = 0;
		this->weigth = weigth;
	}
	Human(int age)
	{
		this->name = "no name";
		this->age = age;
		this->weigth = 0;
	}
	*/


	void Show()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Weigth : " << weigth << endl;
	}
};

//int main()
//{	
	/*
	Human h;
	h.Show();

	Human h2("Bob");
	h2.Show();

	Human h3("Tom", 12);
	h3.Show();

	Human h4("Olga", 18, 100);
	h4.Show();
	*/


	//Hello();
//}