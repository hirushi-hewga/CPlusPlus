#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}




	void SetYear(int newYear)
	{
		this->year = newYear;
	}
	int GetYear()const
	{
		return year;
	}
};


class Account
{
private:
	double sum;
	const double rate;
public:
	Account(double sum, double rate) :sum(sum), rate(rate) {}
	/*{
		this->sum = sum;
		this->rate = rate;
	}*/
	double GetRate()const
	{
		return rate;
	}
	double GetIncome()
	{
		return sum * rate / 100;
	}
	double GetIncome()const
	{
		return sum * rate / 100;
	}
	double GetSum()
	{
		return sum;
	}
	double GetSum()const
	{
		return sum;
	}
	double SetSum()
	{
		sum += GetIncome();
		return sum;
	}
};




//int main()
//{
	/*
	int r;
	cout << "Enter raate : ";
	cin >> r;
	Account ac1(2000, r);
	const Account ac2(5000, 10);

	cout << "Get Rate 1 : " << ac1.GetRate() << endl;
	cout << "Get Rate 2 : " << ac2.GetRate() << endl;

	cout << "Get Sum 1 : " << ac1.GetSum() << endl;
	cout << "Get Sum 2 : " << ac2.GetSum() << endl;

	cout << "Get Rate 1 : " << ac1.GetIncome() << endl;
	cout << "Get Rate 2 : " << ac2.GetIncome() << endl;

	cout << "Set Sum 1 : " << ac2.SetSum() << endl;
	//cout << "Set Sum 2 : " << ac2.SetSum() << endl; // error
	*/




	/*
	const int size = 10;
	const string s( "first day" );

	int* psize;
	const char* filename = "Users.txt";
	const int days[]{ 31, 31, 28 };

	const Date independencyDay( 24, 8, 1991 );
	cout << "Year : " << independencyDay.GetYear() << endl;
	//independencyDay.SetYear(2024); // error
	//independencyDay.day = 28;  // error
	//independencyDay.month = 6; // error
	*/
	//}