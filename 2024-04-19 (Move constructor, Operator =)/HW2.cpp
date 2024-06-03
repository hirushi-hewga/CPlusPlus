#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	void Show(int num)
	{
		gotoxy(this->x, this->y);
		cout << "P" << num;
	}
};

class Vector
{
	int countPoints;
	Point* points;
public:
	Vector() :countPoints(0), points(nullptr) {}
	Vector(const Vector& other)
	{
		this->countPoints = other.countPoints;
		points = new Point[countPoints];
		for (int i = 0; i < countPoints; i++)
		{
			this->points[i] = other.points[i];
		}
	}
	Vector(Vector&& other)
	{
		this->countPoints = other.countPoints;
		this->points = other.points;
		other.points = nullptr;
	}
	Vector operator =(const Vector& other)
	{
		this->countPoints = other.countPoints;
		if (this->points != nullptr)
			delete[] this->points;
		for (int i = 0; i < countPoints; i++)
		{
			this->points[i] = other.points[i];
		}
		return *this;
	}


	void Add(int x, int y)
	{
		Point* temp = new Point[countPoints + 1];
		for (int i = 0; i < countPoints; i++)
		{
			temp[i] = points[i];
		}
		temp[countPoints] = Point(x, y);
		if (points != nullptr)
			delete[] points;
		points = temp;
		countPoints++;
	}
	void Print()const
	{
		for (int i = 0; i < countPoints; i++)
		{
			points[i].Show(i + 1);
		}
	}


	~Vector()
	{
		if (points != nullptr)
			delete[] points;
	}
};



int main()
{
	Vector vector;
	vector.Add(8, 4);
	vector.Add(12, 3);
	vector.Print();
}