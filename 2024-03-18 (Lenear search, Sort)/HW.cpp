#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	/*
	srand(time(NULL));
	const int size = 10;
	int arr[size]{};
	InitArray(arr, size);
	ShowArray(arr, size);
	int choice;
	cout << "1 - sortuvannya za zrostannyam" << endl;
	cout << "2 - sortuvannya za spadannyam" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	InsertSort(arr, size, choice - 1);
	ShowArray(arr, size);
	*/




	/*
	srand(time(NULL));
	const int size = 20;
	int arr[size]{};
	InitArray2(arr, size);
	ShowArray(arr, size);
	int minIndex, maxIndex;
	for (minIndex = 0; minIndex < size; minIndex++) if (arr[minIndex] < 0) break;
	for (maxIndex = size - 1; maxIndex > 0; maxIndex--) if (arr[maxIndex] < 0) break;
	InsertSortRange(arr, minIndex + 1, maxIndex - 1);
	ShowArray(arr, size);
	*/




	/*
	srand(time(NULL));
	const int size = 20;
	int arr[size]{};
	InitArray3(arr, size);
	ShowArray(arr, size);
	ScatterElements(arr, size);
	ShowArray(arr, size);
	int number;
	cout << "Enter number in range (1-20): ";
	cin >> number;
	cout << "Number " << number << " is at index " << FindNumberIndex(arr, size, number) << endl;
	*/




	/*
	int number, pow;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter power of number: ";
	cin >> pow;
	cout << "Power of number " << number << " --> " << PowerOfNumber(number, pow) << endl;
	*/




	/*
	int N;
	cout << "Enter count of stars: ";
	cin >> N;
	PrintStars(N, 1);
	*/




	/*
	int a, b;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	Summa(a, b);
	*/




	/*
	const int size = 100;
	int arr[size]{};
	for (int i = 0; i < size; i++) arr[i] = rand() % 999 + 1;
	ShowArray(arr, size);
	cout << "---------------------" << endl;
	cout << "Min summa in index " << MinSummaIndex(arr, size - 9) << endl;
	*/
}

int MinSummaIndex(int arr[], int size)
{
	int res = -1;
	int summaRes;
	for (int i = 0; i < size; i++)
	{
		int summa = 0;
		for (int j = i; j < i + 10; j++)
		{
			summa += arr[j];
		}
		if (res == -1) summaRes = summa, res = i;
		else if (summaRes > summa) summaRes = summa, res = i;
	}
	return res;
}

void Summa(int a, int b)
{
	int summa = a;
	cout << "--------------------------" << endl;
	cout << a;
	for (int i = a + 1; i <= b; i++)
	{
		summa += i;
		cout << " + " << i;
	}
	cout << " = " << summa << endl;
}

void PrintStars(int count, int counter)
{
	cout << '*';
	if (counter < count) PrintStars(count, counter + 1);
}

int FindNumberIndex(int arr[], int size, int number)
{
	for (int i = 0; i < size; i++) if (arr[i] == number) return i;
}

void ScatterElements(int arr[], int size)
{
	int counter = 0, temp;
	while (counter <= 100) {
		int firstElement = 0, secondElement = 0;
		counter++;
		while (firstElement == secondElement) firstElement = rand() % size, secondElement = rand() % size;
		temp = arr[firstElement], arr[firstElement] = arr[secondElement], arr[secondElement] = temp;
	}
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
		*(parr + i) = rand() % 90 + 10;
	}
}

void InitArray2(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = rand() % 41 - 20;
	}
}

void InitArray3(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = i + 1;
	}
}

void InsertSort(int arr[], int size, int value)
{
	if (value != 1 && value != 0) value = 1;
	if (value == 0)
	{
		int temp;
		int j;
		for (int i = 0; i < size; i++)
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
	else if (value == 1)
	{
		int temp;
		int j;
		for (int i = 0; i < size; i++)
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] < temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

void InsertSortRange(int arr[], int start, int end)
{
	int temp;
	int j;
	for (int i = start + 1; i <= end; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= start && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int PowerOfNumber(int number, int pow)
{
	pow--;
	if (pow == 0) return number;
	return number * PowerOfNumber(number, pow);
}