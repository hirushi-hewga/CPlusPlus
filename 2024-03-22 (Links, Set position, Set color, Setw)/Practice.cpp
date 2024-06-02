#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;
//int main()
//{
	/*1
	int a = 6, b = 10, c = 8;
	int multi = 1;
	int serednye_aryfmetychne = 0;
	int minElement;

	Multi(a, b, c, multi);
	cout << "Multi: " << multi << endl;

	SerednyeAryfmetychne(a, b, c, serednye_aryfmetychne);
	cout << "Serednye aryfmetychne: " << serednye_aryfmetychne << endl;

	MinElement(a, b, c, minElement);
	cout << "Min element: " << minElement << endl;
	*/




	/*2
	srand(time(NULL));
	const int size = 16;
	int arr[size] = {};
	int* parr = arr;
	InitArray(parr, size);
	ShowArray(parr, size);
	ChangeArray(parr, size);
	ShowArray(parr, size);
	*/




	/*3
	int a = 4, b = 8;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	ChangeElements(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	const int size = 8;
	int arr[size]{};
	int* parr = arr;
	InitArray(parr, size);
	ShowArray(parr, size);
	ChangeElements(arr[0], arr[1]);
	ShowArray(parr, size);
	*/
	//}

void ChangeElements(int& la, int& lb)
{
	int temp;
	temp = la, la = lb, lb = temp;
}

void ChangeArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(parr + i) < 0) *(parr + i) = 0;
	}
}

void InitArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = rand() % 19 - 9;
	}
}

void ShowArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << *(parr + i) << ' ';
	}
	cout << endl;
}

void MinElement(int& la, int& lb, int& lc, int& lminElement)
{
	lminElement = la;
	if (lminElement > lb) lminElement = lb;
	if (lminElement > lc) lminElement = lc;
}

inline void SerednyeAryfmetychne(int& la, int& lb, int& lc, int& lserednye_aryfmetychne)
{
	lserednye_aryfmetychne = (la + lb + lc) / 3;
}

inline void Multi(int& la, int& lb, int& lc, int& lmulti)
{
	lmulti = la * lb * lc;
}