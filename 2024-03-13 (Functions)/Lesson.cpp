//#include <iostream>
//using namespace std;
//
//void Hello()
//{
//	cout << "Hello world!" << endl;
//}
//
//void Star(int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		cout << '*' << ' ';
//	}
//}
//
//void AnyLine(char symbol, int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		cout << symbol << ' ';
//	}
//	cout << endl;
//}
//
//int Pow(int num, int pow)
//{
//	int res = 1;
//	for (int i = 0; i < pow; i++)
//	{
//		res *= num;
//	}
//	return res;
//}
//
//int Max(int a, int b)
//{
//	return (a > b) ? a : b;
//}
//
//int Min(int a, int b)
//{
//	return (a < b) ? a : b;
//}
//
//void Second()
//{
//	cout << "Second function" << endl;
//}
//
//void First()
//{
//	cout << "Begin first function" << endl;
//	Second();
//	cout << "End first function" << endl;
//}
//
//void Change(int a, int b)
//{
//	cout << "One in main before change = " << a << " Two in main after change = " << b << endl;
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "One in main before change = " << a << " Two in main after change = " << b << endl;
//}
//
//
//
//
//
//void InitArray(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 100 + 1;
//	}
//}
//
//void ShowArray(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//}
//
//int Summa(int arr[], int size)
//{
//	int Summa = 0;
//	for (int i = 0; i < size; i++)
//	{
//		Summa += arr[i];
//	}
//	return Summa;
//}
//
//void InitMatrix(int arr[][7], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			arr[i][j] = rand() % 50 + 1;
//		}
//	}
//}
//
//void ShowMatrix(int arr[][7], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cout << arr[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//int SummaMatrix(int arr[][7], int row, int col)
//{
//	int summa = 0;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			summa += arr[i][j];
//		}
//	}
//	return summa;
//}
//
//
//int main()
//{
//	srand(time(NULL));
//	/*Hello();
//	Hello();
//	Star(3);
//	AnyLine('*', 8);
//	int res = Pow(2, 5);
//	cout << "Res pow = " << res << endl;
//	cout << "Pow 2*5 = " << Pow(2, 5) << endl;
//	cout << "Max (10, 55) = " << Max(10, 55) << endl;
//	cout << "Max (77, 4) = " << Max(77, 4) << endl;
//	cout << "Max (22, 21) = " << Max(22, 21) << endl;
//	cout << "Min (10, 55) = " << Min(10, 55) << endl;
//	cout << "Min (77, 4) = " << Min(77, 4) << endl;
//	cout << "Min (22, 21) = " << Min(22, 21) << endl;
//	First();
//	int a = 5, b = 7;
//	cout << "One in main before change = " << a << " Two in main after change = " << b << endl;
//	Change(a, b)
//	cout << "One in main before change = " << a << " Two in main after change = " << b << endl;*/
//
//	/*const int size = 10;
//	int arr[size];
//	InitArray(arr, size);
//	ShowArray(arr, size);
//	cout << "Summa = " << Summa(arr, size);*/
//
//	/*const int row = 5;
//	const int col = 7;
//	int matrix[row][col];
//	InitMatrix(matrix, row, col);
//	ShowMatrix(matrix, row, col);
//	cout << "Summa = " << SummaMatrix(matrix, row, col);*/
//}