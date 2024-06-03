#include <iostream>
using namespace std;

class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	Array(const initializer_list<int>& list)
	{
		this->size = list.size();
		arr = new int[size];
		/*
		for (int i = 0; i < size; i++)
		{
			arr[i] = list[i];
		}
		*/
		int i = 0;
		for (int elem : list)
		{
			arr[i++] = elem;
		}
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	~Array()
	{
		delete[]arr;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void Fill(const initializer_list<int>& list)
	{
		this->size = list.size();
		if (arr != nullptr)
			delete[] arr;
		arr = new int[size];
		int i = 0;
		for (int elem : list)
		{
			arr[i++] = elem;
		}
	}
};



int main()
{
	Array arr({ 20, 21, 22, 23, 24 });
	arr.Print();
	arr.Fill({ 1, 2, 3 });
	arr.Print();



	/*
	int static_array[5] = {1, 2, 3, 4, 5};
	int* dynam_array = new int[5] { 10, 11, 12, 13, 14 };
	Array arr; // default constructor
	arr.Print();
	Array arr(10); // paramatrized constructo
	arr.Print();

	delete[] dynam_array;
	*/
}