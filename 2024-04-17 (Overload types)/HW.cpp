#include <iostream>
using namespace std;

class Airplane
{
	string model;
	string type;
	int maxPassangersCount;
	int passangersCount;
public:
	Airplane() :model("No model"), type("None type"), maxPassangersCount(40), passangersCount(0) {}
	Airplane(string model, string type, int maxCount, int count) :Airplane()
	{
		this->model = model;
		this->type = type;
		this->maxPassangersCount = maxCount;
		if (count > maxCount) cout << "passangers will not fit";
		else this->passangersCount = count;
	}



#pragma region increment/decrement
	Airplane operator ++()
	{
		if (passangersCount >= maxPassangersCount)
		{
			cout << "Airplane is full" << endl;
			return *this;
		}
		passangersCount++;
		return *this;
	}
	Airplane operator ++(int)
	{
		if (passangersCount >= maxPassangersCount)
		{
			cout << "Airplane is full" << endl;
			return *this;
		}
		passangersCount++;
		return *this;
	}
	Airplane operator --()
	{
		if (passangersCount <= 0)
		{
			cout << "Not passangers found" << endl;
			return *this;
		}
		passangersCount--;
		return *this;
	}
	Airplane operator --(int)
	{
		if (passangersCount <= 0)
		{
			cout << "Not passangers found" << endl;
			return *this;
		}
		passangersCount--;
		return *this;
	}
#pragma endregion
#pragma region operator()
	Airplane operator ()(int value)
	{
		if (passangersCount + value > maxPassangersCount)
		{
			cout << value << " passangers will not fit" << endl;
			return *this;
		}
		passangersCount += value;
		return *this;
	}
#pragma endregion



	friend bool operator ==(const Airplane& left, const Airplane& right);
	friend bool operator >(const Airplane& left, const Airplane& right);
	friend bool operator <(const Airplane& left, const Airplane& right);
	friend ostream& operator <<(ostream& out, const Airplane& other);
};



#pragma region <<
ostream & operator <<(ostream& out, const Airplane& other)
{
	out << "======== Airplane [" << other.model << "] ========" << endl;
	out << "Type : " << other.type << endl;
	out << "Max passangers count : " << other.maxPassangersCount << endl;
	out << "Passangers count : " << other.passangersCount << endl;
	out << endl;
	return out;
}
#pragma endregion
#pragma region logic operators
bool operator ==(const Airplane& left, const Airplane& right)
{
	return left.type == right.type;
}
bool operator >(const Airplane& left, const Airplane& right)
{
	return left.maxPassangersCount > right.maxPassangersCount;
}
bool operator <(const Airplane& left, const Airplane& right)
{
	return left.maxPassangersCount < right.maxPassangersCount;
}
#pragma endregion



int main()
{
	Airplane ap1("Boeing 737 Max", "twin-engine narrow-body jet", 30, 6);
	Airplane ap2("Airbus A350 XWB", "wide-body jet", 40, 8);

	cout << ap1 << ap2;

	if (ap1 == ap2)
		cout << "AP1 == AP2" << endl;
	else
		cout << "AP1 != AP2" << endl;
	cout << endl;

	ap1++;
	ap2--;
	cout << ap1 << ap2;
	ap1--;
	ap2++;
	cout << ap1 << ap2;

	if (ap1 > ap2)
		cout << "AP1 > AP2" << endl;
	else if (ap1 < ap2)
		cout << "AP1 < AP2" << endl;
	else
		cout << "AP1 == AP2" << endl;
	cout << endl;

	ap1(8);
	ap2(8);
	cout << ap1 << ap2 << endl;
}