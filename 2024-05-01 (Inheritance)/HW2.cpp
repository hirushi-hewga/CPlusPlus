#include <iostream>
using namespace std;

struct Fullname
{
	string name;
	string surname;
	string lastname;
	Fullname(string name, string surname, string lastname) :name(name), surname(surname), lastname(lastname) {}
};

class Passport
{
protected:
	Fullname fullname;
	string country;
public:
	Passport() = delete;
	Passport(string name, string surname, string lastname, string country) :fullname(name, surname, lastname), country(country) {}


	void Print()const
	{
		cout << "Fullname : " << fullname.surname << ' ' << fullname.name << ' ' << fullname.lastname << endl;
		cout << "Country : " << country << endl;
	}
};

class ForeignPassport : public Passport
{
	string place_of_birth;
	string visa_type;
	string passport_number;
public:
	ForeignPassport() = delete;
	ForeignPassport(string name, string surname, string lastname, string country, string place_of_birth, string visa_type, string passport_number) :place_of_birth(place_of_birth), visa_type(visa_type), passport_number(passport_number), Passport(name, surname, lastname, country) {}


	void Print()
	{
		Passport::Print();
		cout << "Place of birth : " << place_of_birth << endl;
		cout << "Visa type : " << visa_type << endl;
		cout << "Foreign passport number : " << passport_number << endl;
	}
};



//int main()
//{
	/*
	Passport pass("Bogdan", "Kurylo", "Andriyovych", "Ukraine");
	ForeignPassport foreignPass("Vladyslav", "Yanchuk", "Maksymovych", "Ukraine", "Rivne", "Biznes-visa", "AB1234567");

	cout << "============ Passport ============" << endl; pass.Print();
	cout << "======== Foreign Passport ========" << endl; foreignPass.Print();
	*/
	//}