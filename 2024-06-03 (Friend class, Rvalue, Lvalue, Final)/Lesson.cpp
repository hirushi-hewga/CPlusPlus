#include <iostream>
#include <string>
using namespace std;

class FriendClass
{

};

class SomeClass
{
	friend FriendClass;
};
class Rectangle;
class Point
{
	int x;
	int y;
public:
	Point() = default; // default = {}
	Point(int x, int y) : x(x), y(y) {}

	int SetX(int x) { this->x = x; }
	int SetY(int y) { this->y = y; }
	int GetX()const { return x; }
	int GetY()const { return y; }
	void Show()const
	{
		cout << "X : " << x << " | Y : " << y << endl;
	}
	friend Rectangle;
};

class Rectangle
{
	Point leftUpCorner;
	Point rightDownCorner;
public:
	Rectangle() = default;
	Rectangle(const Point& leftUpCorner, int sideA, int sideB) : leftUpCorner(leftUpCorner),
		rightDownCorner{ leftUpCorner.x + sideA, leftUpCorner.y + sideB } {}

	int GetSideA()const
	{
		return rightDownCorner.x - leftUpCorner.x;
	}
	int GetSideB()const
	{
		return rightDownCorner.y - leftUpCorner.y;
	}
};


class Image
{
public:
	class Pixel
	{
		int r;
		int g;
		int b;
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		string GetInfo()const
		{
			return "Pixel : r = " + to_string(r) + " | g = " + to_string(g) + " | b = " + to_string(b);
		}
	};


private:
	static const int LENGTH = 5;
	Pixel pixels[LENGTH]
	{
		Pixel(10, 155, 15),
		Pixel(255, 100, 144),
		Pixel(20, 144, 45),
		Pixel(155, 200, 45),
		Pixel(155, 255, 255)
	};
public:
	void GetImageInfo()const
	{
		for (int i = 0; i < LENGTH; i++)
		{
			cout << pixels[i].GetInfo() << endl;
		}
	}
};

class A
{
public:
	virtual string GetName()const { return "A"; }
};
class B final : public A
{
public:
	virtual string GetName()const override final { return "B"; }
};
//class C : public B
//{
//public:
//	virtual string GetName()const override { return "C"; }
//};

int& foo()
{
	int a = 2;
	return a;
}



int main()
{

	/*// l-value r-value
	//foo() = 100;
	int var;
	var = 4;
	4 = var;
	(var + 1) = 4; // (5) = 4
	(var += 1) = 4;

	int a = 1; // | a - l-value | 1 - r-value |
	int b = 3; // | b - l-value | 3 - r-value |
	int c = a + b; // | c - l-value | a + b - r-value |

	// constructor cannot be virtual*/


	/*A a;
	cout << a.GetName() << endl;
	B b;
	cout << b.GetName() << endl;
	C c;
	cout << c.GetName() << endl;*/


	/*Image image;
	image.GetImageInfo();
	Image::Pixel p(255, 255, 255);
	cout << p.GetInfo() << endl;*/


	/*Point point;
	point.Show();
	int a = 5;
	cout << a << endl;
	int b(3);
	cout << b << endl;
	int c{ 57 };
	cout << c << endl;*/
}