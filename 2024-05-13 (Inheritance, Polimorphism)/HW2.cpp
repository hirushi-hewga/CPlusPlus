#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
	string name;
public:
	Shape() :name("no name") {}
	Shape(string n) :name(n) {}

	virtual float GetArea()const = 0 {};
	virtual void Show()const
	{
		cout << "Name : " << name << endl;
	}
};

class Rectangle : public Shape
{
	float side_1;
	float side_2;
public:
	Rectangle() :side_1(0), side_2(0), Shape() {}
	Rectangle(string n, float s1, float s2) : Shape(n)
	{
		this->side_1 = s1 > 0 ? s1 : 0;
		this->side_2 = s2 > 0 ? s2 : 0;
	}

	float GetArea()const override
	{
		return side_1 * side_2;
	}
	void Show()const override
	{
		cout << "======== Rectangle ========" << endl;
		Shape::Show();
		cout << "Side 1 : " << side_1 << " sm" << endl;
		cout << "Side 2 : " << side_2 << " sm" << endl;
		cout << "Area : " << GetArea() << "sm ^ 2" << endl;
	}
};

class Circle : public Shape
{
	float radius;
public:
	Circle() :radius(0), Shape() {}
	Circle(string n, float r) : Shape(n)
	{
		this->radius = r > 0 ? r : 0;
	}

	float GetArea()const override
	{
		return pow(3.14 * radius, 2);
	}
	void Show()const override
	{
		cout << "======== Circle ========" << endl;
		Shape::Show();
		cout << "Radius : " << radius << " sm" << endl;
		cout << "Area : " << GetArea() << "sm ^ 2" << endl;
	}
};

class RightTriangle : public Shape
{
	float katet_1;
	float katet_2;
public:
	RightTriangle() :katet_1(0), katet_2(0), Shape() {}
	RightTriangle(string n, float k1, float k2) : Shape(n)
	{
		this->katet_1 = k1 > 0 ? k1 : 0;
		this->katet_2 = k2 > 0 ? k2 : 0;
	}

	float GetArea()const override
	{
		return (katet_1 * katet_2) / 2;
	}
	void Show()const override
	{
		cout << "======== Right Triangle ========" << endl;
		Shape::Show();
		cout << "Katet 1 : " << katet_1 << " sm" << endl;
		cout << "Katet 2 : " << katet_2 << " sm" << endl;
		cout << "Area : " << GetArea() << "sm ^ 2" << endl;
	}
};

class Triangle : public Shape
{
	float side_1;
	float side_2;
	float side_3;
public:
	Triangle() :side_1(0), side_2(0), side_3(0), Shape() {}
	Triangle(string n, float s1, float s2, float s3) : Shape(n)
	{
		this->side_1 = s1 > 0 ? s1 : 0;
		this->side_2 = s2 > 0 ? s2 : 0;
		this->side_3 = s3 > 0 ? s3 : 0;
	}

	float GetArea()const override
	{
		double p = (side_1 + side_2 + side_3) / 2;
		return sqrt(p * (p - side_1) * (p - side_2) * (p - side_3));
	}
	void Show()const override
	{
		cout << "======== Triangle ========" << endl;
		Shape::Show();
		cout << "Side 1 : " << side_1 << " sm" << endl;
		cout << "Side 2 : " << side_2 << " sm" << endl;
		cout << "Side 3 : " << side_3 << " sm" << endl;
		cout << "Area : " << GetArea() << "sm ^ 2" << endl;
	}
};

class Trapeze : public Shape
{
	float height;
	float base_1;
	float base_2;
public:
	Trapeze() :height(0), base_1(0), base_2(0), Shape() {}
	Trapeze(string n, float h, float b1, float b2) : Shape(n)
	{
		this->height = h > 0 ? h : 0;
		this->base_1 = b1 > 0 ? b1 : 0;
		this->base_2 = b2 > 0 ? b2 : 0;
	}

	float GetArea()const override
	{
		return (base_1 + base_2) * height / 2;
	}
	void Show()const override
	{
		cout << "======== Triangle ========" << endl;
		Shape::Show();
		cout << "Height : " << height << " sm" << endl;
		cout << "Base 1 : " << base_1 << " sm" << endl;
		cout << "Base 2 : " << base_2 << " sm" << endl;
		cout << "Area : " << GetArea() << "sm ^ 2" << endl;
	}
};



void TestShape(Shape& s) { s.Show(); }

int main()
{
	Rectangle rect("Rectangle", 5, 7);
	Circle circle("Circle", 7);
	RightTriangle rt("Right triangle", 5, 7);
	Triangle triangle("Triangle", 5, 7, 9);
	Trapeze trap("Trapeze", 5, 7, 9);

	TestShape(rect);
	TestShape(circle);
	TestShape(rt);
	TestShape(triangle);
	TestShape(trap);
}