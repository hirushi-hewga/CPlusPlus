#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;


int main()
{
    /*
    const int size = 8;
    int arr[size] = {1, 3, 5, 2, 7, 4, 9, 6};
    cout << "Serednye aryfmetychne --> " << SerednyeAryfmetychne(arr, size) << endl;
    */




    /*
    const int size = 4;
    int int_arr[size] = {1, 3, 5, 2};
    float float_arr[size] = {7.1f, 4.2f, 9.3f, 6.4f};
    double double_arr[size] = {7.01, 4.02, 9.03, 6.04};
    long long_arr[size] = {6, 9, 4, 7};
    PrintArray(int_arr, float_arr, size);
    PrintArray(double_arr, long_arr, size);
    */




    /*
    const int size = 8;
    int arr[size] = {1, 3, 5, 2, 7, 4, 9, 6};
    cout << "Max element --> " << MaxElement(arr, size) << endl;
    */




    /*
    srand(time(NULL));
    const int size = 8;
    int arr[size][size];
    for (int i = 0; i < size; i++){ for (int j = 0; j < size; j++){
            arr[i][j] = rand()%99+1;
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    cout << "Max element --> " << MaxElem(arr, size) << endl;
    */




    /*
    int a = 10;
    int b = 11;
    float c = 10.5f;
    float d = 11.5f;
    cout << "Min element --> " << MinElem(a, c) << endl;
    cout << "Max element --> " << MaxElem2(b, d) << endl;
    cout << "Max element --> " << MinElem(a, b, c) << endl;
    cout << "Max element --> " << MaxElem2(b, c, d) << endl;
    */




    /*
    const int size = 16;
    int arr[size] = {1, 3, 5, 2, 7, 0, 4, 9, 6, -1, -2, -3, -4, -5, -6, -7};
    Quantity(arr, size);
    */




    /*
    srand(time(NULL));
    const int size = 8;
    int arr[size][size];
    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { arr[i][j] = 0; } }
    int choice;
    do {
        cout << "........" << endl;
        cout << "1 - Init Array" << endl;
        cout << "2 - Print Array" << endl;
        cout << "3 - Print The Max And Min Element On The Main Diagonal" << endl;
        cout << "4 - Sorting Elements By Ascending Order Separately For Of Each Row Of The Matrix." << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice < 0 || choice > 4)
        {
            cout << "Invalid Choice! Try again." << endl;
            cout << "........" << endl;
            cout << "1 - Init Array" << endl;
            cout << "2 - Print Array" << endl;
            cout << "3 - Print The Max And Min Element On The Main Diagonal" << endl;
            cout << "4 - Sorting Elements By Ascending Order Separately For Of Each Row Of The Matrix." << endl;
            cout << "0 - Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }
        if (choice == 0) break;
        if (choice == 1) arr[size][size] = InitArray(arr, size);
        if (choice == 2) PrintArray(arr, size);
        if (choice == 3) MinMaxElemMainDiag(arr, size);
        if (choice == 4) arr[size][size] = SortArray(arr, size);
    } while (choice!=0);
    */




    /*
    int arrDate1[3]{};
    int arrDate2[3]{};
    bool BOOL = true;
    do {
        if (BOOL == false) cout << "Invalid Date! Try Again." << endl;
        cout << "............................" << endl;
        BOOL = true;

        cout << "Enter the year of the first date: ";
        cin >> arrDate1[0];

        if (arrDate1[0] <= 0) BOOL = false;

        cout << "Enter the month of the first date (1-12): ";
        cin >> arrDate1[1];

        if (arrDate1[1] < 1 || arrDate1[1] > 12) BOOL = false;

        cout << "Enter the day of the first date: ";
        cin >> arrDate1[2];

        if (BOOL == true) if (!ValidateDay(arrDate1[0], arrDate1[1], arrDate1[2])) BOOL = false;

    } while (BOOL == false);
    cout << "............................" << endl;

    do {
        if (BOOL == false) cout << "Invalid Date! Try Again." << endl;
        cout << "............................" << endl;
        BOOL = true;

        cout << "Enter the year of the second date: ";
        cin >> arrDate2[0];

        if (arrDate2[0] <= 0) BOOL = false;

        cout << "Enter the month of the second date (1-12): ";
        cin >> arrDate2[1];

        if (arrDate2[1] < 1 || arrDate2[1] > 12) BOOL = false;

        cout << "Enter the day of the second date: ";
        cin >> arrDate2[2];

        if (BOOL == true) if (!ValidateDay(arrDate2[0], arrDate2[1], arrDate2[2])) BOOL = false;

    } while (BOOL == false);
    cout << "............................" << endl;

    int days = DateDifference(arrDate1[0], arrDate2[0], arrDate1[1], arrDate2[1], arrDate1[2], arrDate2[2]);

    cout << "Difference in days --> " << days << endl;
    */
}



int DateDifference(int year_1, int year_2, int month_1, int month_2, int day_1, int day_2)
{
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days_1 = (year_1 / 4) + (year_1 * 365) + day_1;
    if (year_1 % 4 == 0) days_1--;
    for (int i = 0; i < month_1 - 1; i++) days_1 += months[i];
    if ((year_1 % 4 == 0 && month_1 > 2) || (year_1 % 4 == 0 && month_1 == 2 && day_1 == 28)) days_1++;


    int days_2 = (year_2 / 4) + (year_2 * 365) + day_2;
    if (year_2 % 4 == 0) days_2--;
    for (int i = 0; i < month_2 - 1; i++) days_2 += months[i];
    if ((year_2 % 4 == 0 && month_2 > 2) || (year_2 % 4 == 0 && month_2 == 2 && day_2 == 28)) days_2++;


    if (days_1 > days_2) return days_1 - days_2;
    return days_2 - days_1;
}

bool ValidateDay(int year, int month, int day)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if (day < 1 || day > 31)
            return false;
        return true;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if (day < 1 || day > 30)
            return false;
        return true;
    }
    case 2:
    {
        if (year % 4 == 0)
        {
            if (day < 1 || day > 29)
                return false;
            return true;
        }
        else
        {
            if (day < 1 || day > 28)
                return false;
            return true;
        }
    }
    }
}

int QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int element = arr[high], i = low - 1, temp;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < element)
            {
                i++;
                temp = arr[i], arr[i] = arr[j], arr[j] = temp;
            }
        }
        temp = arr[i + 1], arr[i + 1] = arr[high], arr[high] = temp;
        int index = i + 1;
        QuickSort(arr, low, index - 1);
        QuickSort(arr, index + 1, high);
    }
    return *arr;
}

int SortArray(int arr[][8], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i][size] = QuickSort(arr[i], 0, size - 1);
    }
    cout << "Array Is Sorted." << endl;
    return **arr;
}

int InitArray(int arr[][8], int size)
{
    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { arr[i][j] = rand() % 90 + 10; } }
    cout << "Array Is Initialized." << endl;
    return **arr;
}

void MinMaxElemMainDiag(int arr[][8], int size)
{
    int min = arr[0][0], max = arr[0][0];
    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { if (min > arr[i][j] && i == j) min = arr[i][j]; } }
    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { if (max < arr[i][j] && i == j) max = arr[i][j]; } }
    cout << "Min Element On The Main Diagonal --> " << min << endl;
    cout << "Max Element On The Main Diagonal --> " << max << endl;
}

void PrintArray(int arr[][8], int size)
{
    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { cout << setw(2) << arr[i][j] << ' '; } cout << endl; }
}

int SerednyeAryfmetychne(int arr[], int size)
{
    int serednye_aryfmetychne = 0;
    for (int i = 0; i < size; i++)
    {
        serednye_aryfmetychne += arr[i];
    }
    return serednye_aryfmetychne / size;
}

template<typename T1, typename T2>
void PrintArray(T1 arr1[], T2 arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << endl;
}

int MaxElement(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int MaxElem1(int arr[][8], int size)
{
    int max = arr[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }
    return max;
}

template<typename T1, typename T2>
float MaxElem2(T1 a, T2 b)
{
    return a > b ? a : b;
}
template<typename T1, typename T2, typename T3>
float MaxElem2(T1 a, T2 b, T3 c)
{
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    if (c > a && c > b) return c;
}

template<typename T1, typename T2>
float MinElem(T1 a, T2 b)
{
    return a < b ? a : b;
}
template<typename T1, typename T2, typename T3>
float MinElem(T1 a, T2 b, T3 c)
{
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    if (c < a && c < b) return c;
}

void Quantity(int arr[], int size)
{
    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0) negative++;
        else if (arr[i] > 0) positive++;
        else zero++;
    }
    cout << "Positive --> " << positive << endl;
    cout << "Negative --> " << negative << endl;
    cout << "Zero --> " << zero << endl;
}

int InitArr(int arr[][8], int size)
{
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) arr[i][j] = rand() % 99 + 1;
    return 1;
}
double InitArr(double arr[][8], int size)
{
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) arr[i][j] = rand() % 99 + 1;
    return 1;
}
char InitArr(char arr[][8], int size)
{
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) arr[i][j] = rand() % 99 + 1;
    return '-';
}