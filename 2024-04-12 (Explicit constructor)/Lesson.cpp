#include <iostream>
using namespace std;

void DoSomething(long num)
{
	//some code
}
float DoSomething()
{
	return 10.0; // double ===> float
}


class Array
{
	int* arr;
	int size;
public:
	Array(int size)
	{
		this->size = size;
		arr = new int[size] {};
		/*for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}*/
	}


	int GetSize()const
	{
		return size;
	}
	int GetValue(int index)const
	{
		return arr[index];
	}
	void SetValue(int value, int index)
	{
		arr[index] = value;
	}
	void Display(int index)const
	{
		cout << arr[index] << ' ';
	}


	~Array()
	{
		delete[] arr;
	}
};

void Display(const Array& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		arr.Display(i);
	}
	cout << endl;
}

class Student
{
public:
	Student(int age)
	{

	}
};


//int main()
//{
	/*
	int size = 4;
	Array arr(size);

	for (int i = 0; i < size; i++)
	{
		arr.SetValue(size - i, i);
	}

	Display(arr);
	cout << "!!!!!" << endl;

	Array arr2 = 10; // int ===> Array
	Display(arr2);

	//implicit int ===> Array
	//Display(15);

	Student st(15); // constructor

	// int ===> Student
	Student st2 = 45;
	*/




	/*
	//explicit implicit

	//implicit
	double a(10); // int ===> double 10.0000000000000
	DoSomething(5); // int ===> long
	DoSomething(); // double ===> float
	double res = 5.0 / 4;
	*/
	//}