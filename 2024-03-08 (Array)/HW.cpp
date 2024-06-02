#include <iostream>
#include <iomanip>
using  namespace std;
int main() {

    /*int count;
    cout << "Enter number count: ";
    cin >> count;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < count*(i+1); j++)
            cout << i+1 << ' ';
        cout << endl;
    }*/





    /*const int N = 10;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j || i + j == N - 1) cout << "0 ";
            else cout << "1 ";
        }
        cout << endl;
    }*/





    /*const int count = 10;
    int sum = 0, value = 10;
    for (int j = count; j > 0; j--){
        for (int j = 0; j < value; j++){
            cout << value << ' ';
            sum+=value;
        }
        cout << endl;
        value--;
    }
    cout << "Summa --> " << sum << endl;*/





    /*const int count = 15;
    for (int i = 0; i < count; i++){
        cout << setw(2) << i+1 << ". ";
        if ((i+1)%2 == 0) for(int j = 0; j < 8; j++) cout << i+1 << ' ';
        else for(int j = 0; j < 10; j++) cout << 1 << ' ';
        cout << endl;
    }*/





    /*const int count = 30;
    for (int i = 0; i < count; i++){
        cout << setw(2) << i+1 << ". ";
        if ((i+1)%2==0) for (int j = 0; j < 5; j++) cout << 1 << ' ';
        else for (int j = 0; j < i+1; j++) cout << j+1 << ' ';
        cout << endl;
    }*/





    /*const int count = 10;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++) cout << setw(2) << right << i+1 << " * " << setw(2) << left << j+1 << " = " << (i+1)*(j+1) << endl;
        cout << "============" << endl;
    }*/





    /*const int a = 8, b = 1060;
    int count = 0;
    for (int i = a; i < b+1; i++) if (i%12==0) count++;
    cout << "Count numbers that are divisible by 12 --> " << count << endl;*/





    /*const int size = 12;
    int arr[size], month1, month2, value = 0, maxProfit, minProfit, maxProfitMonth, minProfitMonth;

    do{
        do{
            cout << "Enter profit for " << value+1 << " month (1000-5000): ";
            cin >> arr[value];
            if (arr[value] < 1000 || arr[value] > 5000) cout << "Error value! Try again." << endl;
            if (arr[value] < 1000 || arr[value] > 5000) continue;
            value++;
            break;
        }while (value < 12);
    }while (value < 12);
    do{
        cout << "Enter first month (1-12): ";
        cin >> month1;
        if (month1 < 1 || month1 > 12) cout << "Error value! Try again." << endl;
    }while (month1 < 1 || month1 > 12);
    do{
        cout << "Enter second month (1-12): ";
        cin >> month2;
        if (month2 < 1 || month2 > 12 || month2 == month1) cout << "Error value! Try again." << endl;
    }while (month2 < 1 || month2 > 12 || month2 == month1);
    if (month1 > month2){
        int temp = month1;
        month1 = month2, month2 = temp;
    }
    maxProfit = arr[month1-1], minProfit = arr[month1-1];
    for (int i = month1; i <= month2; i++){
        if (arr[i-1]<minProfit) minProfit = arr[i-1], minProfitMonth = i;
        if (arr[i-1]>maxProfit) maxProfit = arr[i-1], maxProfitMonth = i;
    }
    cout << "Min profit in " << minProfitMonth << " month --> " << minProfit << endl;
    cout << "Max profit in " << maxProfitMonth << " month --> " << maxProfit << endl;*/
}