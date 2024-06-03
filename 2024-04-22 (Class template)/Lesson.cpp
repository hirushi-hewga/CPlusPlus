#include <iostream>
using namespace std;

template<typename T_coord>
class Point
{
private:
	T_coord x;
	T_coord y;
public:
	Point() : x(0), y(0) {}
	Point(T_coord x, T_coord y) : x(x), y(y) {}
	void SetCoords(T_coord newX, T_coord newY)
	{
		this->x = newX;
		this->y = newY;
	}
	void Print()
	{
		cout << "X : " << x << " ,  Y : " << y << endl;
	}
};

template<typename T_X, typename T_Y>
class NewPoint
{
private:
	T_X x;
	T_Y y;
public:
	NewPoint() : x(0), y(0) {}
	NewPoint(T_X x, T_Y y) : x(x), y(y) {}
	void SetCoords(T_X newX, T_Y newY)
	{
		this->x = newX;
		this->y = newY;
	}
	void Print()
	{
		cout << "X : " << x << " ,  Y : " << y << endl;
	}
};



template<typename T_coll, typename T_value>
class MyClass
{
	T_coll* collection;
	int size;
	T_value point;
public:
	MyClass()
	{
		collection = nullptr;
		size = 0;
		//point = NULL;
	}
	MyClass(T_coll* coll, T_value value) :collection(coll), point(value) {}


	void SetCollection(int* coll)
	{
		collection = coll;
	}
	void SetValue(T_value value)
	{
		point = value;
	}
	void Print()
	{
		cout << "Collection" << collection << endl;
		cout << "Value : " << point << endl;
	}


	~MyClass()
	{
		delete[] collection;
	}
};



template<typename T_arr>

T_arr GetMax(T_arr* arr, int size)
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}



//int main()
//{
	/*
	Point<float> point(4.23, 6.5);
	point.Print();
	point.SetCoords(15, 23);
	point.Print();

	NewPoint<int, double> pointNew(10, 3.33);
	pointNew.Print();
	*/



	/*
	long* long_arr = new long[4];
	for (int i = 0; i < 4; i++)
	{
		long_arr[i] = i + 1;
		cout << long_arr[i] << ' ';
	}
	cout << endl;
	char* char_arr = new char[4];
	for (int i = 0; i < 4; i++)
	{
		char_arr[i] = 'a' + i;
		cout << char_arr[i] << ' ';
	}
	cout << endl;

	MyClass<long, string> cl1(long_arr, "Class with long collection");
	MyClass<char, string> cl2(char_arr, "Class with char collection");

	cl1.Print();
	cl2.Print();


	//delete[] long_arr;
	//delete[] char_arr;
	*/



	/*
	const int size = 10;
	float numbers[size] = {5, 8, 45, 7, 96, 3, 25, 85, 96, 12};
	cout << "Max : " << GetMax(numbers, size) << endl;
	string colors[5] = { "A", "AA", "AAA", "AAAA", "W" };
	cout << "Max : " << GetMax(colors, 5) << endl;

	string names[6] = { "Ilya", "Sasha", "Nikita", "Sergiy", "Ivan", "Max" };
	cout << "Max : " << GetMax(names, 6) << endl;
	*/
	//}