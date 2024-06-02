#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	/*
	int a, b;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	int* pmax = FindMax(&a, &b);
	cout << "Max --> " << *pmax << endl;
	*/




	/*
	int a;
	int* pa = &a;

	cout << "Enter number: ";
	cin >> *pa;

	NumberSign(pa);
	*/




	/*
	int a, b, temp;
	int* pa = &a;
	int* pb = &b;

	cout << "Enter first number: ";
	cin >> *pa;
	cout << "Enter second number: ";
	cin >> *pb;

	cout << "a = " << *pa << endl;
	cout << "b = " << *pb << endl;
	cout << "---------" << endl;
	temp = *pa, * pa = *pb, * pb = temp;
	cout << "a = " << *pa << endl;
	cout << "b = " << *pb << endl;
	*/




	/*
	int a, b;
	int* pa = &a;
	int* pb = &b;
	cout << "Enter first number: ";
	cin >> *pa;
	cout << "Enter second number: ";
	cin >> *pb;
	Calculator(pa, pb);
	*/




	/*
	srand(time(NULL));
	const int size = 8;
	int arr[size];
	int* parr = arr;
	InitArray(parr, size);
	ShowArray(parr, size);
	int res = SummaArray(parr, size);
	cout << "Summa array elements: " << res << endl;
	*/
}

int SummaArray(int* parr, int size)
{
	int Summa = 0;
	for (int i = 0; i < size; i++)
	{
		Summa += *(parr + i);
	}
	return Summa;
}

void ShowArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(parr + i) << ' ';
	}
	cout << endl;
}
void InitArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = rand() % 20 + 1;
	}
}

void Divide(int* pa, int* pb)
{
	cout << *pa << " / " << *pb << " = " << (double)*pa / (double)*pb << endl;
}
void Multiply(int* pa, int* pb)
{
	cout << *pa << " * " << *pb << " = " << *pa * *pb << endl;
}
void Subtract(int* pa, int* pb)
{
	cout << *pa << " - " << *pb << " = " << *pa - *pb << endl;
}
void Add(int* pa, int* pb)
{
	cout << *pa << " + " << *pb << " = " << *pa + *pb << endl;
}

void Calculator(int* pa, int* pb)
{
	int choice;
	cout << "1 - Add numbers" << endl;
	cout << "2 - Subtract numbers" << endl;
	cout << "3 - Multiply numbers" << endl;
	cout << "4 - Divide numbers" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "======================" << endl;
	if (choice == 1) Add(pa, pb);
	else if (choice == 2) Subtract(pa, pb);
	else if (choice == 3) Multiply(pa, pb);
	else if (choice == 4) Divide(pa, pb);
	else
	{
		cout << "Try again!" << endl;
		Calculator(pa, pb);
	}
}

void NumberSign(int* a)
{
	if (*a > 0)
		cout << "Number sign --> positive" << endl;
	else if (*a < 0)
		cout << "Number sign --> negative" << endl;
	else
		cout << "Number = 0" << endl;
}

int* FindMax(int* a, int* b)
{
	if (*a > *b)
		return a;
	else
		return b;
}