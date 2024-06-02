#pragma once
int SerednyeAryfmetychne(int arr[], int size);
template<typename T1, typename T2>
void PrintArray(T1 arr1[], T2 arr2[], int size);
int MaxElement(int arr[], int size);
int MaxElem1(int arr[][8], int size);
template<typename T1, typename T2>
float MaxElem2(T1 a, T2 b);
template<typename T1, typename T2, typename T3>
float MaxElem2(T1 a, T2 b, T3 c);
template<typename T1, typename T2>
float MinElem(T1 a, T2 b);
template<typename T1, typename T2, typename T3>
float MinElem(T1 a, T2 b, T3 c);
void Quantity(int arr[], int size);
int InitArr(int arr[][8], int size);
double InitArr(double arr[][8], int size);
char InitArr(char arr[][8], int size);
void PrintArray(int arr[][8], int size);
void MinMaxElemMainDiag(int arr[][8], int size);
int InitArray(int arr[][8], int size);
int SortArray(int arr[][8], int size);
int QuickSort(int arr[], int low, int high);
bool ValidateDay(int year, int month, int day);
int DateDifference(int year_1, int year_2, int month_1, int month_2, int day_1, int day_2);