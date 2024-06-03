#include <iostream>
using namespace std;

class Time
{
	int h;
	int m;
	int s;
public:
	Time() :h(0), m(0), s(0) {}
	Time(int h, int m, int s)
	{
		this->s = s % 60;
		this->m = m + s / 60 % 60;
		this->h = h + s / 3600;
		if (this->m >= 60)
		{
			this->h = this->h + this->m / 60;
			this->m = this->m % 60;
		}
	}
	Time(int s)
	{
		this->h = s / 3600;
		this->m = s / 60 % 60;
		this->s = s % 60;
	}


	void Show()const
	{
		if (h < 10) cout << '0' << h << ':'; else cout << h << ':';
		if (m < 10) cout << '0' << m << ':'; else cout << m << ':';
		if (s < 10) cout << '0' << s << endl; else cout << s << endl;
	}
	void Add()
	{
		s++;
		if (s == 60)
		{
			s = 0;
			m++;
			if (m == 60)
			{
				m = 0;
				h++;
			}
		}
	}


#pragma region Overload operators
	Time operator +(const Time& other)const
	{
		int seconds = s + other.s + m * 60 + other.m * 60 + h * 3600 + other.h * 3600;
		return Time(seconds);
	}
	Time operator -(const Time& other)const
	{
		int s1 = s + m * 60 + h * 3600;
		int s2 = other.s + other.m * 60 + other.h * 3600;
		return Time(s1 - s2);
	}
	Time operator *(int number)const
	{
		int seconds = s + m * 60 + h * 3600;
		return Time(seconds * number);
	}
	Time operator /(int number)const
	{
		int seconds = s + m * 60 + h * 3600;
		return Time(seconds / number);
	}
	bool operator >(const Time& other)const
	{
		int s1 = s + m * 60 + h * 3600;
		int s2 = other.s + other.m * 60 + other.h * 3600;
		return s1 > s2;
	}
	bool operator <(const Time& other)const
	{
		int s1 = s + m * 60 + h * 3600;
		int s2 = other.s + other.m * 60 + other.h * 3600;
		return s1 < s2;
	}
	bool operator >=(const Time& other)const
	{
		return !(*this < other);
	}
	bool operator <=(const Time& other)const
	{
		return !(*this > other);
	}
	bool operator ==(const Time& other)const
	{
		return !(*this < other && *this > other);
	}
	bool operator !=(const Time& other)const
	{
		return !(*this == other);
	}
#pragma endregion
};



int main()
{
	Time t1(12, 59, 59);
	cout << "T1 : "; t1.Show();
	t1.Add();
	cout << "T1 : "; t1.Show();
	t1.Add();
	cout << "T1 : "; t1.Show();
	cout << "----------------" << endl;
	Time t2(10, 59, 59);
	cout << "T1 : "; t1.Show();
	cout << "T2 : "; t2.Show();
	Time newTime = t1 + t2;
	cout << "T1 + T2 : "; newTime.Show();
	newTime = t1 - t2;
	cout << "T1 - T2 : "; newTime.Show();
	newTime = t1 * 2;
	cout << "T1 * 2 : "; newTime.Show();
	newTime = t2 * 2;
	cout << "T2 * 2 : "; newTime.Show();
	newTime = t1 / 2;
	cout << "T1 / 2 : "; newTime.Show();
	newTime = t2 / 2;
	cout << "T2 / 2 : "; newTime.Show();
	cout << "----------------" << endl;
	//============== > ===============

	if (t1 > t2)
		cout << "T1 is > T2" << endl;
	else
		cout << "T1 is < T2" << endl;
	cout << "----------------" << endl;

	//============== < ===============

	if (t1 < t2)
		cout << "T1 is < T2" << endl;
	else
		cout << "T1 is > T2" << endl;
	cout << "----------------" << endl;

	//============== >= ==============

	if (t1 >= t2)
		cout << "T1 is >= T2" << endl;
	else
		cout << "T1 is < T2" << endl;
	cout << "----------------" << endl;

	//============== <= ==============

	if (t1 <= t2)
		cout << "T1 is <= T2" << endl;
	else
		cout << "T1 is > T2" << endl;
	cout << "----------------" << endl;

	//============== == ==============

	if (t1 == t2)
		cout << "T1 == T2" << endl;
	else
		cout << "T1 != T2" << endl;
	cout << "----------------" << endl;

	//============== != ==============

	if (t1 != t2)
		cout << "T1 != T2" << endl;
	else
		cout << "T1 == T2" << endl;
	cout << "----------------" << endl;
}