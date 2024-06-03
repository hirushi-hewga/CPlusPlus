#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(x) {}
	void Print()
	{
		cout << "X : " << x << " ,  Y : " << y << endl;
	}
	Point Plus(const Point& other)
	{
		Point point(this->x + other.x, this->y + other.y);
		/*Point point;
		point.x = this->x + other.x;
		point.y = this->y + other.y;*/
		return point;
	}
	Point Minus(const Point& other) const
	{
		Point point(this->x - other.x, this->y - other.y);
		return point;
	}
	//void operator[type]()
	Point operator+ (const Point& other)const
	{
		Point point(this->x + other.x, this->y + other.y);
		return point;
	}
	Point operator- (const Point& other)const
	{
		Point point(this->x - other.x, this->y - other.y);
		return point;
	}
	Point operator* (const Point& other)const
	{
		Point point(this->x * other.x, this->y * other.y);
		return point;
	}
	Point operator/ (const Point& other)const
	{
		Point point(this->x / other.x, this->y / other.y);
		return point;
	}
	Point operator+ (int value)const
	{
		Point point(this->x + value, this->y + value);
		return point;
	}
	Point operator +=(const Point& other)
	{
		// c = a += b;
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point operator-()const
	{
		/*Point point(this->x * -1, this->y * -1);
		return point;*/
		return Point(-x, -y);
	}
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
#pragma region Logic Operators
	bool operator > (const Point& other)const
	{
		/*if ((this->x + this->y) > (other.x + other.y))
			return true;
		else
			return false;*/
		return (this->x + this->y) > (other.x + other.y);
	}
	bool operator < (const Point& other)const
	{
		return (this->x + this->y) < (other.x + other.y);
	}
	bool operator <= (const Point& other)const
	{
		return (this->x + this->y) <= (other.x + other.y);
	}
	bool operator >= (const Point& other)const
	{
		return (this->x + this->y) >= (other.x + other.y);
	}
	bool operator == (const Point& other)const
	{
		return (this->x + other.x) == (this->y + other.y);
	}
	bool operator && (const Point& other)const
	{
		return (this->x + other.x) && (this->y + other.y);
	}
	bool operator != (const Point& other)const
	{
		return (this->x + other.x) != (this->y + other.y);
	}

#pragma endregion

};

//int main()
//{
	/*
	Point p1(3, 8);
	Point p2(2, 5);

	int a = 5, b = 3, c = 8;
	int res = a + b;
	cout << "Res = " << res << endl;
	res = a - b;
	cout << "Res = " << res << endl;


	cout << "P1 : "; p1.Print();
	cout << "P2 : "; p2.Print();

	Point newPoint = p1.Plus(p2);
	cout << "RES : "; newPoint.Print();

	newPoint = p1.Minus(p2);
	cout << "RES : "; newPoint.Print();

	newPoint = p1 + p2; // p1.operator+(p2)
	cout << "RES : "; newPoint.Print();
	newPoint = p1 - p2; // p1.operator-(p2)
	cout << "RES : "; newPoint.Print();
	newPoint = p1 * p2; // p1.operator*(p2)
	cout << "RES : "; newPoint.Print();
	newPoint = p1 / p2; // p1.operator/(p2)
	cout << "RES : "; newPoint.Print();
	newPoint = p1 + 100;
	cout << "RES : "; newPoint.Print();

	p1 += p2;
	cout << "P1 : "; p1.Print();

	newPoint = p1 += p2;
	cout << "RES : "; newPoint.Print();

	newPoint = -p1;
	cout << "RES : "; newPoint.Print();

	a = b = c;


	if (p1 > p2)
	{
		cout << "p1 is > p2" << endl;
	}
	else
	{
		cout << "p1 is < p2" << endl;
	}

	if (p1 == p2)
	{
		cout << "p1 is == p2" << endl;
	}
	else
	{
		cout << "p1 is != p2" << endl;
	}
	*/
	//}