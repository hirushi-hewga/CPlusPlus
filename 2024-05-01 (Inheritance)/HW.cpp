#include <iostream>
using namespace std;

struct Fullname
{
	string name;
	string surname;
	string lastname;
	Fullname(string name, string surname, string lastname) :name(name), surname(surname), lastname(lastname) {}
};

class Student
{
protected:
	Fullname fullname;
	int age;
public:
	Student() = delete;
	Student(string name, string surname, string lastname, int age) :fullname(name, surname, lastname), age(age) {}


	void Print()const
	{
		cout << "Fullname : " << fullname.surname << ' ' << fullname.name << ' ' << fullname.lastname << endl;
		cout << "Age : " << age << endl;
	}
};

class Aspirant : public Student
{
	int sheets;
	int death_count;
public:
	Aspirant(string name, string surname, string lastname, int age, int sheets) :sheets(sheets), death_count(sheets / 8), Student(name, surname, lastname, age) {}


	void Print()
	{
		Student::Print();
		cout << "Sheets write : " << sheets << endl;
		cout << "Death count : " << death_count << endl;
	}
};



//int main()
//{
	/*
	Student st("Bogdan", "Kurylo", "Andriyovych", 17);
	Aspirant asp("Vladyslav", "Yanchuk", "Maksymovych", 17, 99);

	cout << "============ Student ============" << endl;st.Print();
	cout << "============ Aspirant ===========" << endl;asp.Print();
	*/
	//}