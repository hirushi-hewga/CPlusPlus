#include <iostream>
using namespace std;

class Employer
{
	int salary;
	int money;
public:
	Employer() :salary(0), money(0) {}
	Employer(int s, int m) :salary(s), money(m) {}


	virtual void Print()const
	{
		cout << "Salary : " << salary << " UAH" << endl;
		cout << "Money : " << money << " UAH" << endl;
	}
};

class President : public Employer
{
	int cortege;
public:
	President() :cortege(0), Employer() {}
	President(int s, int m, int c) :cortege(c), Employer(s, m) {}
	void Print()const override
	{
		cout << "============ President ============" << endl;
		Employer::Print();
		cout << "Cortege : " << cortege << " cars" << endl;
	}
};

class Manager : public Employer
{
	int workers;
public:
	Manager() :workers(0), Employer() {}
	Manager(int s, int m, int w) :workers(w), Employer(s, m) {}
	void Print()const override
	{
		cout << "============ Manager ============" << endl;
		Employer::Print();
		cout << "Workers : " << workers << endl;
	}
};

class Worker : public Employer
{
	int years_Expirience;
public:
	Worker() :years_Expirience(0), Employer() {}
	Worker(int s, int m, int y) :years_Expirience(y), Employer(s, m) {}
	void Print()const override
	{
		cout << "============ Worker ============" << endl;
		Employer::Print();
		cout << "Expirience : " << years_Expirience << " years" << endl;
	}
};



//int main()
//{
	/*
	President president(350000, 5000000000, 28);
	Manager manager(50000, 2500000, 8);
	Worker worker(30000, 1000000, 0);

	president.Print();
	manager.Print();
	worker.Print();
	*/
	//}