#include <iostream>
using namespace std;

class Array
{
	int* arr;
	int size;
public:
	Array(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100 + 1;
		}
	}void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	int operator[](int index)
	{
		if (index < 0 || index >= size) return -1;
		else return arr[index];
	}
	void operator()(int count)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] += count;
		}
	}
	~Array()
	{
		delete[] arr;
	}
};

//int main()
//{
	/*int size = 16;
	Array arr(size);
	arr.Print();
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	arr.Print();
	arr(184);
	arr.Print();*/
	//}