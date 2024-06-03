#include <iostream>
#include "Header.h"
using namespace std;
//int main()
//{
	/*
	int* a = new int;
	float* b = new float;
	double* c = new double;
	cout << "Enter int number: ";
	cin >> *a;
	cout << "Enter float number: ";
	cin >> *b;
	cout << "Enter double number: ";
	cin >> *c;
	cout << *a << " x " << *b << " x " << *c << " = " << (*a) * (*b) * (*c) << endl;

	delete a;
	delete b;
	delete c;
	*/




	/*
	srand(time(NULL));
	int* size = new int;
	cout << "Enter matrix size: ";
	cin >> *size;
	int choice = -1;
	bool BOOL = true;
	int* arr = CreateArr(size);
	do {
		if (choice >= 0 && choice <= 5) BOOL = true;
		if (!BOOL) cout << "Try again." << endl;
		cout << "-----------------" << endl;
		cout << "1 - Init matrix" << endl;
		cout << "2 - Show matrix" << endl;
		cout << "3 - Add element matrix" << endl;
		cout << "4 - Delete matrix element" << endl;
		cout << "5 - Delete matrix element by index" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "-----------------" << endl;

		if (choice == 1) InitArr(arr, size);

		if (choice == 2) ShowArr(arr, size);

		if (choice == 3) arr = AddElement(arr, size);

		if (choice == 4) arr = DeleteElem(arr, size);

		if (choice == 5) arr = IndexDeleteElem(arr, size);

		if (choice == 0) cout << "Good bye." << endl;

		BOOL = false;
	} while (choice != 0);
	delete[] arr;
	*/
	//}

int* IndexDeleteElem(int* arr, int* size)
{
	(*size)--;
	int* temp = new int[*size];
	int index = -1;
	bool BOOL = true;
	do {
		if (!BOOL) cout << "Try again." << endl;
		cout << "Enter index delete element (0 - " << *size << "): ";
		cin >> index;
		BOOL = false;
	} while (index < 0 || index > *size);
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(arr + i);
	}
	for (int i = index; i < *size; i++)
	{
		*(temp + i) = *(arr + i + 1);
	}
	delete[] arr;
	arr = temp;
	return arr;
}

int* DeleteElem(int* arr, int* size)
{
	(*size)--;
	int* temp = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		*(temp + i) = *(arr + i);
	}
	delete[] arr;
	arr = temp;
	return arr;
}

int* AddElement(int* arr, int* size)
{
	int index = -1, element;
	bool BOOL = true;
	do {
		if (!BOOL) cout << "Try again." << endl;
		cout << "Enter index new element (0 - " << *size << "): ";
		cin >> index;
		BOOL = false;
	} while (index < 0 || index > *size);
	cout << "Enter new element: ";
	cin >> element;
	(*size)++;
	int* temp = new int[*size];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(arr + i);
	}
	*(temp + index) = element;
	for (int i = index + 1; i < *size; i++)
	{
		*(temp + i) = *(arr + i - 1);
	}
	delete[] arr;
	arr = temp;
	return arr;
}

void InitArr(int* arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		*(arr + i) = rand() % 80 + 20;
	}
}

void ShowArr(int* arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		cout << *(arr + i) << ' ';
	}
	cout << endl;
}

int* CreateArr(int* size)
{
	int* arr = new int[*size];
	return arr;
}