#include <iostream>
#include <iomanip>
using namespace std;

void DeleteRowInTheEnd(int** arr, int& rows, int cols)
{
	int** temp = new int* [rows - 1];
}

void FillRow(int* arr, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arr[i] = rand() % 10;
	}
}

int** AddRowInTheEnd(int** arr, int& rows, int cols)
{
	rows++;
	int** temp = new int* [rows];
	for (int i = 0; i < rows - 1; i++)
	{
		temp[i] = arr[i];
	}
	temp[rows - 1] = new int[cols];
	FillRow(temp[rows - 1], cols);
	delete[] arr;
	return temp;
}

void FillArr(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void FillArr2(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 41 - 20;
		}
	}
}

//int main()
//{
	/*
	srand(time(NULL));
	int rows = 4;
	int cols = 5;
	cout << "Enter count rows: ";
	cin >> rows;
	cout << "Enter count cols: ";
	cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 41 - 20;
			cout << setw(3) << arr[i][j] << ' ';
		}
		cout << endl;
	}





	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	*/
	//}