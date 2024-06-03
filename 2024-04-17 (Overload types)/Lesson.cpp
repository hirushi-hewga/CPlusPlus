//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x;
//	int y;
//public:
//	Point() : x(0), y(0) {}
//	Point(int x, int y) : x(x), y(x) {}
//	void Print()
//	{
//		cout << "X : " << x << " ,  Y : " << y << endl;
//	}
//#pragma region Increment/Decrement
//	Point operator ++ () // Increment postfix form
//	{
//		++this->x;
//		++this->y;
//		return *this;
//	}
//	Point operator -- () // Decrement postfix form
//	{
//		--this->x;
//		--this->y;
//		return *this;
//	}
//	Point operator ++ () // Increment prefix form
//	{
//		this->x++;
//		this->y++;
//		return *this;
//	}
//	Point operator -- () // Decrement prefix form
//	{
//		this->x--;
//		this->y--;
//		return *this;
//	}
//#pragma endregion
//	int GetX() const
//	{
//		return x;
//	}
//	int GetY() const
//	{
//		return y;
//	}
//	void SetX(int x)
//	{
//		this->x = x;
//	}
//	void SetY(int y)
//	{
//		this->y = y;
//	}
//	//friend Point operator ++ (Point & other);
//};
//
//
//
//bool operator < (const Point & left, const Point & right)
//{
//	return (left.GetX() + left.GetY()) < (right.GetX() + right.GetY());
//}

//Point operator ++ (Point & other)
//{
//	other.x++;
//	other.y++;
//	//other.SetX(other.GetX() + 1);
//	//other.SetY(other.GetY() + 1);
//	return other;
//}



//int main()
//{
	//Point p1(3, 8);
	//Point p2(2, 5);
	//int a = 5, b = 3, c = 8;
	//p1.operator++();
	//a++; // postfix
	//++a; // prefix
	//cout << "P1 : "; p1.Print();
	//++p1;
	//cout << "P1 : "; p1.Print();
	//--p1;
	//cout << "P1 : "; p1.Print();
	//p1++;
	//cout << "P1 : "; p1.Print();
	//p1--;
	//cout << "P1 : "; p1.Print();
	//p1 < p2 ? p1.Print() : p2.Print();
//}