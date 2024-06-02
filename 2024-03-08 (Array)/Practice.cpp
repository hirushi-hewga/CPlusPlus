#include <iostream>
#include <iomanip>
using  namespace std;
int main() {
    /*cout << setw(15) << left << "Hello world!" << endl;
    cout << setw(15) << right << 12345 << endl;
    cout << setw(15) << "Hello world!" << endl;
    cout << setw(15) << left << 12345 << endl;*/






    /*const int size = 10;
    int product = 1, arr[10];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i+1 << " number: ";
        cin >> arr[i];
    }
    cout << "=======================" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(2) << i+1 << ". " << arr[i] << endl;
        product *= arr[i];
    }
    cout << "Product numbers --> " << product << endl;*/





    /*const int size = 7;
    int positive = 0, negative = 0, arr[size] = {20, -4, 35, 12, 8, 27, -10};
    for (int i = 0; i < size; i++){
        cout << i+1 << ". " << arr[i] << endl;
        if (arr[i] < 0)
            negative++;
        if (arr[i] > 0)
            positive++;
    }
    cout << "=======================" << endl;
    cout << "Positive numbers --> " << positive << endl;
    cout << "Negative numbers --> " << negative << endl;*/





    /*const int size = 7;
    long evenSum = 0, arr[size] = {-73, 42, -15, 91, -56, 30, -84};
    for (int i = 0; i < size; i++){
        cout << i+1 << ". " << setw(3) << arr[i] << endl;
        if (arr[i]%2 == 0) evenSum += arr[i];
    }
    cout << "=======================" << endl;
    cout << "Summa even numbers --> " << evenSum << endl;*/





    /*const int size = 30;
    int arr[30];
    for (int i = 0; i < size; i++){
        arr[i] = 1;
        for (int j = 0; j < i; j++){
            arr[i]*=2;
        }
    }
    for (int i = 0; i < size; i++){
        cout << setw(2) << i+1 << ". " << arr[i] << endl;
    }*/





    /*const int size = 16;
    int arr[size] = {-63, 82, -30, 55, -12, 71, -45, 93, 17, -84, 38, -50, 65, -20, 79, -7};
    for (int i = 0; i < size; i++){
        cout << setw(2) << i+1 << ". " << setw(3) << arr[i] << endl;
    }
    cout << "==========" << endl;
    for (int i = 0; i < size; i++){
        if (arr[i] < 0) arr[i] = -(arr[i]);
        cout << setw(2) << i+1 << ". " << setw(3) << arr[i] << endl;
    }*/
}