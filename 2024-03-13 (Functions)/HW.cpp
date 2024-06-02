#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	/* 1
	int N = 10, K = 7;
	cout << "Enter height: ";
	cin >> N;
	cout << "Enter width: ";
	cin >> K;
	square(N, K);
	*/




	/* 2
	int number;
	cout << "Enter number: ";
	cin >> number;
	cout << "Factorial " << number << " --> " << factorial(number) << endl;
	*/




	/* 3
	int number;
	cout << "Enter number: ";
	cin >> number;
	bool res = isPrime(number);
	res == 1 ? cout << "Number prime --> true" << endl : cout << "Number prime --> false" << endl;
	*/




	/* 4
	int number;
	cout << "Enter number: ";
	cin >> number;
	cout << "Cube of number --> " << cube(number) << endl;
	*/




	/* 5
	int number_1, number_2;
	cout << "Enter first number: ";
	cin >> number_1;
	cout << "Enter second number: ";
	cin >> number_2;
	cout << "Larger number --> " << LargerNumber(number_1, number_2) << endl;
	*/




	/* 6
	int number;
	cout << "Enter number: ";
	cin >> number;
	bool res = isPositive(number);
	res == 1 ? cout << "true" << endl : cout << "false" << endl;
	*/




	/* 7
	const int size = 8;
	int arr[size] = { 2, 7, 6, 3, 9, 8, 5, 4 };
	MinMaxArray(arr, size);
	*/




	/* 8
	const int size = 8;
	int arr[size] = { 2, 7, 6, 3, 9, 8, 5, 4 };
	ArrayReverse(arr, size);
	*/




	/* 9
	const int size = 8;
	int arr[size] = { 2, 7, 6, 3, 9, 8, 5, 4 };
	CountIsPrime(arr, size);
	*/
}

void CountIsPrime(int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (isPrime(arr[i])) count++;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << "Count prime number --> " << count << endl;
}

void ArrayReverse(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[size - i - 1] << ' ';
	}
	cout << endl;
}

void MinMaxArray(int arr[], int size)
{
	int min = arr[0], max = arr[0], min_index = 0, max_index = 0;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		if (arr[i] > max)
		{
			max = arr[i];
			max_index = i;
		}
	}
	cout << endl;
	cout << "Min number --> " << min << " ( index: " << min_index << " )" << endl;
	cout << "Max number --> " << max << " ( index: " << max_index << " )" << endl;
}

bool isPositive(int number)
{
	if (number > 0) return true;
	else if (number < 0) return false;
}

int LargerNumber(int number_1, int number_2)
{
	if (number_1 > number_2) return number_1;
	else return number_2;
}

int cube(int number)
{
	return number * number * number;
}

bool isPrime(int number)
{
	bool res = true;
	for (int i = 1; i <= number; i++)
	{
		if (i != 1 && i != number && number % i == 0)
			res = false;
	}
	return res;
}

int factorial(int number)
{
	const int count = number - 1;
	int res = number;
	for (int i = 0; i < count; i++)
	{
		number--;
		res *= number;
	}
	return res;
}

void square(int N, int K)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}