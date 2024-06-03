#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(x) {}
	void Show()
	{
		cout << "X : " << x << " ,  Y : " << y << endl;
	}


#pragma region Increment/Decrement
	Point operator ++ () // Increment prefix form
	{
		++this->x;
		++this->y;
		return *this;
	}
	Point operator -- () // Decrement prefix form
	{
		--this->x;
		--this->y;
		return *this;
	}
	Point operator ++ (int) // Increment postfix form
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator -- (int) // Decrement postfix form
	{
		this->x--;
		this->y--;
		return *this;
	}
#pragma endregion
#pragma region operators
	bool operator >(const Point& other)
	{
		if (((this->x - other.x) + (this->y - other.y)) > 0) return true;
		return false;
	}
	bool operator <(const Point& other)
	{
		if (((this->x - other.x) + (this->y - other.y)) < 0) return true;
		return false;
	}
	Point operator !()
	{
		this->x *= -1;
		this->y *= -1;
		return *this;
	}
#pragma endregion


	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
	void SetX(int x)
	{
		this->x = x;
	}
	void SetY(int y)
	{
		this->y = y;
	}
};



//int main()
//{
	/*
	Point p1(3, 8);
	cout << "P1 | "; p1.Show();
	p1++;
	cout << "P1 | "; p1.Show();
	p1--;
	cout << "P1 | "; p1.Show();
	!p1;
	cout << "P1 | "; p1.Show();
	Point p2(3, 8);
	cout << "P2 | "; p2.Show();

	if (p1 > p2)
		cout << "P1 is > P2";
	else if (p1 < p2)
		cout << "P1 is < P2";
	else
		cout << "P1 == P2";
	*/
	//}