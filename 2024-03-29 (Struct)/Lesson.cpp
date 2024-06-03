#include <iostream>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
	char month_name[20];
};

struct Person
{
	char name[50];
	char surname[50];
	char lastname[50];
	float height;
	float weight;
	float footSize;
	int salary;
	char position[50];
	Date birthday;
	Date hireDate;
};

void ShowDate(Date d)
{
	cout << d.day << ' ';
	cout << d.month << ' ';
	cout << d.year << ' ';
	cout << d.month_name << endl;
}

Date CreateNewDate()
{
	Date temp;
	cout << "Enter day: ";
	cin >> temp.day;
	cout << "Enter month: ";
	cin >> temp.month;
	cout << "Enter year: ";
	cin >> temp.year;
	cout << "Enter month name: ";
	cin >> temp.month_name;
	return temp;
}

//int main()
//{
	/*
	Date test;
	test = CreateNewDate();
	Date independencyDay = { 24,8,2024,"August" };
	ShowDate(independencyDay);

	Date* ptr = nullptr;
	ptr = &independencyDay;
	cout << ptr->day << ' ';
	cout << ptr->month << ' ';
	cout << ptr->year << ' ';
	cout << ptr->month_name << endl;
	*/




	/*
	Person Nick;
	cout << "Enter name: "; cin >> Nick.name;
	cout << "Enter surname: "; cin >> Nick.surname;
	cout << "Enter lastname: "; cin >> Nick.lastname;
	cout << "Enter height: "; cin >> Nick.height;
	cout << "Enter weight: "; cin >> Nick.weight;
	cout << "Enter foot size: "; cin >> Nick.footSize;
	cout << "Enter salary: "; cin >> Nick.salary;
	cout << "Enter position: "; cin >> Nick.position;
	cout << "Enter Nick birthday day: "; cin >> Nick.birthday.day;
	cout << "Enter Nick birthday month: "; cin >> Nick.birthday.month;
	cout << "Enter Nick birthday year: "; cin >> Nick.birthday.year;
	cout << "Enter Nick birthday month name: "; cin >> Nick.birthday.month_name;
	cout << "Enter Nick hire day: "; cin >> Nick.hireDate.day;
	cout << "Enter Nick hire month: "; cin >> Nick.hireDate.month;
	cout << "Enter Nick hire year: "; cin >> Nick.hireDate.year;
	cout << "Enter Nick hire month name: "; cin >> Nick.hireDate.month_name;
	cout << "========================================" << endl;
	cout << Nick.name << ' ' << Nick.surname << ' ' << Nick.lastname << endl;
	cout << Nick.height << 'x' << Nick.weight << ' ' << Nick.footSize << endl;
	cout << "Salary" << Nick.salary << endl;
	cout << "Position" << Nick.position << endl;
	cout << "Birthday: " << Nick.birthday.day << '.' << Nick.birthday.month << '.' << Nick.birthday.year << ' ' << Nick.birthday.month_name << endl;
	cout << "Hire day: " << Nick.hireDate.day << '.' << Nick.hireDate.month << '.' << Nick.hireDate.year << ' ' << Nick.hireDate.month_name << endl;
	*/




	/*
	int dayBirthday = 15;
	int monthBirthday = 02;
	int yearBirthday = 2007;
	//int dayB[3] = { 15,02,2007,"December" }; //error
	Date myBirthday = { 15,2,2007,"December" }; //object

	cout << "============== My Birthday ==============" << endl;
	cout << "Day: " << myBirthday.day << endl;
	cout << "Month: " << myBirthday.month << endl;
	cout << "Year: " << myBirthday.year << endl;
	cout << "Month name: " << myBirthday.month_name << endl;

	cout << "========== My Friends Birthday ==========" << endl;
	Date friendBirthday;
	cout << "Enter friend birthday day: ";
	cin >> friendBirthday.day;
	cout << "Enter friend birthday month: ";
	cin >> friendBirthday.month;
	cout << "Enter friend birthday year: ";
	cin >> friendBirthday.year;
	cout << "Enter friend birthday month name: ";
	cin >> friendBirthday.month_name;

	cout << "========== My Friends Birthday ==========" << endl;
	cout << "Day: " << friendBirthday.day << endl;
	cout << "Month: " << friendBirthday.month << endl;
	cout << "Year: " << friendBirthday.year << endl;
	cout << "Month name: " << friendBirthday.month_name << endl;
	*/
	//}