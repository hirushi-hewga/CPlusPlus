#include <iostream>
using namespace std;

//struct Player // all field is public
//{
//	string name; // char name[50];
//	int age;
//	int games;
//	int goals;
//};

//void PrintPlayer(Player& pl)
//{
//	cout << "Name : " << pl.name << endl;
//	cout << "Age : " << pl.age << endl;
//	cout << "Games : " << pl.games << endl;
//	cout << "Goals : " << pl.goals << endl;
//}

//void InitPlayer(Player& pl)
//{
//	cout << "Name : "; cin >> pl.name;
//	cout << "Age : "; cin >> pl.age;
//	pl.games = 0;
//	pl.goals = 0;
//}

//void AddGameToPlayer(Player& pl, int goals = 0)
//{
//	pl.games++;
//	pl.goals += goals;
//}

class Player
{
private: // (default)
	string name;
	int age;
	int games;
	int goals;
public:
	void PrintPlayer()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Games : " << games << endl;
		cout << "Goals : " << goals << endl;
	}
	void Initialize()
	{
		name = "No name";
		age = 0;
		games = 0;
		goals = 0;
	}
	void InitPlayer()
	{
		cout << "Name : "; cin >> name;
		cout << "Age : "; cin >> age;
	}
	bool IsValidateGoals(int goals) { return goals >= 0; }
	void AddGameToPlayer(int goals = 0)
	{
		games++;
		if (IsValidateGoals(goals))
			this->goals += goals;
	}
};

class Student
{
public:
	string name;
	string surname;
	int marks[3];
	double GetAverage()
	{
		double sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += marks[i];
		}
		return sum / 3.0;
	}
};

//int main()
//{
	/*
	Student student;//object
	Student student1;//object
	Student student2;//object
	student.name = "Valera";
	student.surname = "Kyluk";
	student.marks[0] = 10;
	cout << "Name : " << student.name << " Surname : " << student.surname << " Marks : " << student.marks[0] << endl;
	*/



	/*
	Player pl;
	pl.Initialize();
	pl.InitPlayer();
	pl.PrintPlayer();

	pl.AddGameToPlayer();
	pl.PrintPlayer();

	pl.AddGameToPlayer(1);
	pl.PrintPlayer();

	pl.AddGameToPlayer(5);
	pl.PrintPlayer();
	*/




	/*
	Player pl;
	InitPlayer(pl);
	PrintPlayer(pl);
	AddGameToPlayer(pl);
	PrintPlayer(pl);
	AddGameToPlayer(pl, 1);
	PrintPlayer(pl);
	AddGameToPlayer(pl, 5);
	PrintPlayer(pl);
	*/
	//}