#include <iostream>
using namespace std;
int main() {
    /*int number;
    cout << "Enter number: ";
    cin >> number;
    //Ternary operator:
    (number%2==0)?cout << number << " - even" << endl:cout << number << " - odd" << endl;*/



    /*int number, count, summa;
    cout << "Enter number (1-100): ";
    cin >> number;
    if (number < 1 || number > 100){
        cout << "\nNumber out of range!";
        return 0;
    }
    else if (number==100)
        count = 3, summa = 1;
    else if (number >= 10)
        count = 2, summa = number / 10 + number % 10;
    else
        count = 1, summa = number;
    cout << "Number count --> " << count << endl;
    cout << "Digits summa --> " << summa << endl;*/



    /*float value, inch, centimeter, choice;
    cout << "Enter value: ";
    cin >> value;
    cout << "1 - inch --> centimeter\n2 - centimeter --> inch\nEnter your choice: ";
    cin >> choice;
    switch ((int)choice){
    case 1:
        inch = value;
        centimeter = inch * 2.54;
        cout << inch << " inch = " << centimeter << " centimeter" << endl;
        break;
    case 2:
        centimeter = value;
        inch = centimeter / 2.54;
        cout << centimeter << " centimeter = " << inch << " inch" << endl;
        break;
    default:
        cout << "Invalid number!" << endl;
    }*/



    /*int number_1, number_2, action;
    cout << "Enter first number: ";
    cin >> number_1;
    cout << "Enter second number: ";
    cin >> number_2;
    cout << "1 - (+)\n2 - (-)\n3 - (*)\n4 - (/)\nEnter action choice: ";
    cin >> action;
    switch (action){
    case 1:
        cout << number_1 << " + " << number_2 << " = " << number_1+number_2 << endl;
        break;
    case 2:
        cout << number_1 << " - " << number_2 << " = " << number_1-number_2 << endl;
        break;
    case 3:
        cout << number_1 << " * " << number_2 << " = " << number_1*number_2 << endl;
        break;
    case 4:
        cout << number_1 << " / " << number_2 << " = " << (float)number_1/number_2 << endl;
        break;
    default:
        cout << "Invalid action!" << endl;
    }*/
}