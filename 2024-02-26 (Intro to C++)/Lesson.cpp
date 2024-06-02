#include <iostream>
using namespace std;
int main() {
    char name[20] = "Ivan";
    int age = 16;

    cout << "Name: " << name << endl;   //cout
    cout << "Age: " << age << endl;     //endl




    const int number_1 = 2;
    int number_2 = 4;

    cout << "\nNumber 1: " << number_1 << "\nNumber 2: " << number_2 << endl;




    float floatNumber = 2.1435;
    double doubleNumber_1 = 2.1436;
    double doubleNumber_2 = 2.14e+013;      // doubleNumber_2 = 2.14*10^13 = 21400000000000
    double doubleNumber_3 = -2.14e-013;     // doubleNumber_3 = -2.14*10^-13 = -0.000000000000214

    cout << '\n' << floatNumber << '\n' << doubleNumber_1 << '\n' << doubleNumber_2 << '\n' << doubleNumber_3 << endl;




    char symbol = 'A';
    bool flag = true;       //Logic operator true = 1; false = 0;
    const char NewLine = '\n';

    cout << NewLine << symbol << NewLine << flag << endl;




    int number;
    cout << "\nEnter number: ";
    cin >> number;

    cout << "Your number: " << number << endl;
}