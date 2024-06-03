#include <iostream>
using namespace std;

struct BirthDate
{
	int day;
	int month;
	int year;
};

struct Location
{
	string city;
	string country;
};

class Student
{
	string name;
	string surname;
	string lastname;
	BirthDate birthDate;
	string phoneNumber;
	Location studentLocation;
	string nameEducationalPlace;
	Location educationalPlaceLocation;
	int groupNumber;
public:
	void Initialize()
	{
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
		birthDate.day = 0;
		birthDate.month = 0;
		birthDate.year = 0;
		phoneNumber = "no number";
		studentLocation.city = "no city";
		studentLocation.country = "no country";
		nameEducationalPlace = "no place name";
		educationalPlaceLocation.city = "no city";
		educationalPlaceLocation.country = "no country";
		groupNumber = 0;
	}
	void InitStudent()
	{
		cout << "====================================== Init Student =====================================" << endl;
		cout << "Enter student name : "; cin >> name;
		cout << "Enter student surname : "; cin >> surname;
		cout << "Enter student lastname : "; cin >> lastname;
		cout << "Enter student birth date day : "; cin >> birthDate.day;
		cout << "Enter student birth date month : "; cin >> birthDate.month;
		cout << "Enter student birth date year : "; cin >> birthDate.year;
		cout << "Enter student phone number : "; cin >> phoneNumber;
		cout << "Enter student location city : "; cin >> studentLocation.city;
		cout << "Enter student location country : "; cin >> studentLocation.country;
		cout << "Enter student education place name : "; cin >> nameEducationalPlace;
		cout << "Enter education place location city : "; cin >> educationalPlaceLocation.city;
		cout << "Enter education place location country : "; cin >> educationalPlaceLocation.country;
		cout << "Enter student group number : "; cin >> groupNumber;
	}
	void ShowStudent()
	{
		cout << "======================================== Student ========================================" << endl;
		cout << "Student fullname : " << name << ' ' << surname << ' ' << lastname << endl;
		cout << "Student birth date : " << birthDate.day << '.' << birthDate.month << '.' << birthDate.year << endl;
		cout << "Student phone number : " << phoneNumber << endl;
		cout << "Student location : city -> " << studentLocation.city << " , country -> " << studentLocation.country << endl;
		cout << "Student education place name : " << nameEducationalPlace << endl;
		cout << "Student education place location : place city -> " << educationalPlaceLocation.city << " , place country -> " << educationalPlaceLocation.country << endl;
		cout << "Student group number : " << groupNumber << endl;
	}
	void SetName(char name[50]) { this->name = name; }
	void SetSurname(char surname[50]) { this->surname = surname; }
	void SetLastname(char lastname[50]) { this->lastname = lastname; }
	void SetBirthDay(int birthDay) { birthDate.day = birthDay; }
	void SetBirthMonth(int birthMonth) { birthDate.month = birthMonth; }
	void SetBirthYear(int birthYear) { birthDate.year = birthYear; }
	void SetPhoneNumber(char phoneNumber[50]) { this->phoneNumber = phoneNumber; }
	void SetStudentCity(char studentCity[50]) { studentLocation.city = studentCity; }
	void SetStudentCountry(char studentCountry[50]) { studentLocation.country = studentCountry; }
	void SetPlaceName(char nameEducationalPlace[50]) { this->nameEducationalPlace = nameEducationalPlace; }
	void SetPlaceCity(char educationPlaceCity[50]) { educationalPlaceLocation.city = educationPlaceCity; }
	void SetPlaceCountry(char educationPlaceCountry[50]) { educationalPlaceLocation.country = educationPlaceCountry; }
	void SetGroupNumber(int groupNumber) { this->groupNumber = groupNumber; }

	string GetName() { return name; }
	string GetSurname() { return surname; }
	string GetLastname() { return lastname; }
	int GetBirthDay() { return birthDate.day; }
	int GetBirthMonth() { return birthDate.month; }
	int GetBirthYear() { return birthDate.year; }
	string GetPhoneNumber() { return phoneNumber; }
	string GetStudentCity() { return studentLocation.city; }
	string GetStudentCountry() { return studentLocation.country; }
	string GetPlaceName() { return nameEducationalPlace; }
	string GetPlaceCity() { return educationalPlaceLocation.city; }
	string GetPlaceCountry() { return educationalPlaceLocation.country; }
	int GetGroupNumber() { return groupNumber; }
};




int GetMenu()
{
	int choice = 0;
	while (choice < 1 || choice > 13)
	{
		cout << "========== Get Menu ==========" << endl;
		cout << "1 - get student name" << endl;
		cout << "2 - get student surname" << endl;
		cout << "3 - get student lastname" << endl;
		cout << "4 - get student birth day" << endl;
		cout << "5 - get student birth month" << endl;
		cout << "6 - get student birth year" << endl;
		cout << "7 - get student phone number" << endl;
		cout << "8 - get student location city" << endl;
		cout << "9 - get student location country" << endl;
		cout << "10 - get student education place name" << endl;
		cout << "11 - get education place location city" << endl;
		cout << "12 - get education place location country" << endl;
		cout << "13 - get student group number" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}

int SetMenu()
{
	int choice = 0;
	while (choice < 1 || choice > 13)
	{
		cout << "========== Set Menu ==========" << endl;
		cout << "1 - set student name" << endl;
		cout << "2 - set student surname" << endl;
		cout << "3 - set student lastname" << endl;
		cout << "4 - set student birth day" << endl;
		cout << "5 - set student birth month" << endl;
		cout << "6 - set student birth year" << endl;
		cout << "7 - set student phone number" << endl;
		cout << "8 - set student location city" << endl;
		cout << "9 - set student location country" << endl;
		cout << "10 - set student education place name" << endl;
		cout << "11 - set education place location city" << endl;
		cout << "12 - set education place location country" << endl;
		cout << "13 - set student group number" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}




enum GETSETMENU { NAME = 1, SURNAME, LASTNAME, BIRTHDAY, BIRTHMONTH, BIRTHYEAR, PHONE, CITY, COUNTRY, PLACENAME, PLACECITY, PLACECOUNTRY, GROUP };

void SetName(Student& st) { char name[50];		cin.getline(name, 50);		st.SetName(name); }
void SetSurname(Student& st) { char surname[50];		cin.getline(surname, 50);	st.SetSurname(surname); }
void SetLastname(Student& st) { char lastname[50];	cin.getline(lastname, 50);	st.SetLastname(lastname); }
void SetBirthDay(Student& st) { int day;				cin >> day;					st.SetBirthDay(day); }
void SetBirthMonth(Student& st) { int month;			cin >> month;				st.SetBirthMonth(month); }
void SetBirthYear(Student& st) { int year;				cin >> year;				st.SetBirthYear(year); }
void SetPhoneNumber(Student& st) { char phone[50];		cin.getline(phone, 50);		st.SetPhoneNumber(phone); }
void SetStudentCity(Student& st) { char city[50];		cin.getline(city, 50);		st.SetStudentCity(city); }
void SetStudentCountry(Student& st) { char country[50];		cin.getline(country, 50);	st.SetStudentCountry(country); }
void SetPlaceName(Student& st) { char name[50];		cin.getline(name, 50);		st.SetPlaceName(name); }
void SetPlaceCity(Student& st) { char city[50];		cin.getline(city, 50);		st.SetPlaceCity(city); }
void SetPlaceCountry(Student& st) { char country[50];		cin.getline(country, 50);	st.SetPlaceCountry(country); }
void SetGroupNumber(Student& st) { int groupNumber;		cin >> groupNumber;			st.SetGroupNumber(groupNumber); }

void SetValue(Student& st)
{
	switch (SetMenu())
	{
	case GETSETMENU::NAME:			cout << "Enter new student name to change : ";				SetName(st); break;
	case GETSETMENU::SURNAME:		cout << "Enter new student surname to change : ";			SetSurname(st); break;
	case GETSETMENU::LASTNAME:		cout << "Enter new student lastname to change : ";			SetLastname(st); break;
	case GETSETMENU::BIRTHDAY:		cout << "Enter new student birth day to change : ";			SetBirthDay(st); break;
	case GETSETMENU::BIRTHMONTH:	cout << "Enter new student birth month to change : ";		SetBirthMonth(st); break;
	case GETSETMENU::BIRTHYEAR:		cout << "Enter new student birth year to change : ";		SetBirthYear(st); break;
	case GETSETMENU::PHONE:			cout << "Enter new student phone number to change : ";		SetPhoneNumber(st); break;
	case GETSETMENU::CITY:			cout << "Enter new student city to change : ";				SetStudentCity(st); break;
	case GETSETMENU::COUNTRY:		cout << "Enter new student country to change : ";			SetStudentCountry(st); break;
	case GETSETMENU::PLACENAME:		cout << "Enter new educational place name to change : ";	SetPlaceName(st); break;
	case GETSETMENU::PLACECITY:		cout << "Enter new educational place city to change : ";	SetPlaceCity(st); break;
	case GETSETMENU::PLACECOUNTRY:	cout << "Enter new educational place country to change : "; SetPlaceCountry(st); break;
	case GETSETMENU::GROUP:			cout << "Enter new student group number to change : ";		SetGroupNumber(st);
	}
	cout << "Value changed." << endl;
}

void GetValue(Student st)
{
	switch (GetMenu())
	{
	case GETSETMENU::NAME: cout << st.GetName() << endl; break;
	case GETSETMENU::SURNAME: cout << st.GetSurname() << endl; break;
	case GETSETMENU::LASTNAME: cout << st.GetLastname() << endl; break;
	case GETSETMENU::BIRTHDAY: cout << st.GetBirthDay() << endl; break;
	case GETSETMENU::BIRTHMONTH: cout << st.GetBirthMonth() << endl; break;
	case GETSETMENU::BIRTHYEAR: cout << st.GetBirthYear() << endl; break;
	case GETSETMENU::PHONE: cout << st.GetPhoneNumber() << endl; break;
	case GETSETMENU::CITY: cout << st.GetStudentCity() << endl; break;
	case GETSETMENU::COUNTRY: cout << st.GetStudentCountry() << endl; break;
	case GETSETMENU::PLACENAME: cout << st.GetPlaceName() << endl; break;
	case GETSETMENU::PLACECITY: cout << st.GetPlaceCity() << endl; break;
	case GETSETMENU::PLACECOUNTRY: cout << st.GetPlaceCountry() << endl; break;
	case GETSETMENU::GROUP: cout << st.GetGroupNumber() << endl;
	}
}




int Menu()
{
	int choice = 0;
	while (choice < 1 || choice > 5)
	{
		cout << "============ Menu ============" << endl;
		cout << "1 - Show student" << endl;
		cout << "2 - Init student" << endl;
		cout << "3 - Get student value" << endl;
		cout << "4 - Set student value" << endl;
		cout << "5 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}

enum MENU { SHOW = 1, INIT, GETV, SETV, EXIT };

int main()
{
	Student student;
	student.Initialize();
	bool isExit = false;
	while (!isExit)
	{
		cout << endl;
		switch (Menu())
		{
		case MENU::SHOW: student.ShowStudent(); break;
		case MENU::INIT: student.InitStudent(); break;
		case MENU::GETV: GetValue(student); break;
		case MENU::SETV: SetValue(student); break;
		case MENU::EXIT: isExit = true;
		}
		cout << endl;
	}
	cout << "Good bye!" << endl;
}