#include <iostream>
using namespace std;

void ChangeValue(int a)//copy 0 a = 0;
{
	a++;
}

void ChangeValue(int* a)
{
	(*a)++;
}
int* FindMax(int* a, int* b, int* c)
{
	if (*a > *b && *a > *c)
		return a;
	else if (*b > *c && *b > *a)
		return b;
	else
		return c;
}

void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void InitArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int* FindMax(int* arr, int size)
{
	int* max = arr;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) > *max)
		{
			max = arr + i;
		}
	}
	return arr;
}


//int main() {
	/*
	srand(time(NULL));
	const int size = 10;
	int arr[size];
	InitArray(arr, size);
	ShowArray(arr, size);
	int* Max = FindMax(arr, size);
	cout << "Max element = " << *Max << endl;
	*/


	/*
	int a = 0, b = 0, c = 0;
	cout << "Enter numbers: ";
	cin >> a >> b >> c;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	int max; // = FindMax(a, b, c);
	cout << "Max = " << max << endl;
	max++;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "Max = " << max << endl;
	int* pmax = FindMax(&a, &b, &c);
	cout << "Max = " << max << endl;
	(*pmax)++;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "Max = " << max << endl;
	*/


	/*
	int a = 0;
	cout << "a = " << a << endl;
	ChangeValue(a);
	cout << "a = " << a << endl;
	ChangeValue(&a);
	cout << "a = " << a << endl;
	*/


	/*
	int a = 10;
	int* pa = &a;
	cout << "a = " << a << endl;
	cout << "pa = " << pa << endl;
	cout << "*pa = " << *pa << endl;

	int b = 3;
	int* pb = &b;
	cout << "b = " << b << endl;
	cout << "pb = " << pb << endl;
	cout << "*pb = " << *pb << endl;

	cout << "Summa = " << a + b << endl;
	cout << "Summa = " << *pa + *pb << endl;

	pa = &b;
	cout << "*pa = " << *pa << endl;
	cout << "*pb = " << *pb << endl;
	*pa += 1;
	cout << "b = " << b << endl;
	cout << "pb = " << pb << endl;
	cout << "*pa = " << *pa << endl;
	*/


	/*
	srand(time(NULL));
	const int size = 5;
	int arr[size];
	int* parr = &arr[0];

	for (int i = 0; i < size; i++)
	{
		//arr[i] = rand() % 50;
		*(parr + i) = rand() % 50 + 1;
	}

	cout << parr << endl;
	cout << arr << endl;
	cout << *parr << endl;
	cout << *arr << endl;
	cout << (parr + 1) << endl;
	cout << (arr + 1) << endl;
	cout << *(parr + 1) << endl;
	cout << *(arr + 1) << endl;

	for (int i = 0; i < size; i++)
	{
		//cout << arr[i] << ' ';
		cout << *(parr + i) << ' ';
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		*parr = rand() % 20 + 1;
		parr++;
	}

	for (int i = 0; i < size; i++)
	{
		cout << *parr << ' ';
		parr++;
	}
	cout << endl;

	parr = arr;

	int* newp = arr;
	*newp = 0;
	newp += 3;
	*newp = 0;
	for (int i = 0; i < size; i++)
	{
		cout << *parr << ' ';
		parr++;
	}
	parr--;
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << *parr << ' ';
		parr--;
	}
	cout << endl;

	int num = 10;
	int* find = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == num)
		{
			find = arr + i;
		}
	}
	if (find != nullptr)
	{
		cout << "Address find element = " << find << endl;
		*find *= 2;
		for (int i = 0; i < size; i++)
		{
			cout << *parr << ' ';
			parr++;
		}
	}
	else
	{
		cout << "Element not find" << endl;
	}
	cout << endl;
	*/
	//}