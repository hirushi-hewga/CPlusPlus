#include <iostream>
using namespace std;
int main() {

    /*int choice;
    enum times{past = 1, present, future};
    do{
        cout << "Choose the tense in which to display the word \"learn\":" << endl;
        cout << past << " - past" << endl;
        cout << present << " - present" << endl;
        cout << future << " - future" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case past:
            cout << "Learned.\n------------------\n" << endl;
            break;
        case present:
            cout << "Learn.\n------------------\n" << endl;
            break;
        case future:
            cout << "Will learn\n------------------\n" << endl;
            break;
        case 0:
            cout << "Good bye.";
            break;
        default:
            cout << "Invalid choice! Try again:\n------------------\n" << endl;
        }
    }while(choice!=0);*/





    /*int grade1, grade2, grade3, grade, exit = 0;
    enum grades{bad = 2, so_so, good, excelent};
    do{
        cout << "\nEnter three grades." << endl;
        cout << "First grade: ";
        cin >> grade1;
        cout << "Second grade: ";
        cin >> grade2;
        cout << "Third grade: ";
        cin >> grade3;
        grade = (grade1 + grade2 + grade3)/3;
        cout << "------------------" << endl;
        switch (grade){
        case bad:
            cout << grade << " - BAD.\n" << endl;
            break;
        case so_so:
            cout << grade << " - SO-SO.\n" << endl;
            break;
        case good:
            cout << grade << " - GOOD.\n" << endl;
            break;
        case excelent:
            cout << grade << " - EXCELENT.\n" << endl;
            break;
        default:
            cout << "Invalid choice! Try again:" << endl;
        }
        do{
            cout << "Do you want to exit?\n1 - no.\n2 - yes.\nEnter your choice: ";
            cin >> exit;
        }while(exit!=1&&exit!=2);
        exit--;
        cout << "==================\n" << endl;
        if (exit==1)
            cout << "Good bye." << endl;
    }while(exit==0);*/





    /*int choice;
    float centimeters, res;
    enum values{meter = 100, decimeter = 10, millimeter = 10};
    do{
        cout << "Enter centimeters: ";
        cin >> centimeters;
        cout << "1 - centimeters to meters" << endl;
        cout << "2 - centimeters to decimeters" << endl;
        cout << "3 - centimeters to millimeters" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            res = centimeters / meter;
            break;
        case 2:
            res = centimeters / decimeter;
            break;
        case 3:
            res = centimeters * millimeter;
            break;
        case 0:
            cout << "Good bye.";
            break;
        default:
            cout << "Invalid choice! Try again:" << endl;
        }
        cout << "==================\nRes: " << res << "\n==================\n" << endl;
    }while(choice!=0);*/





    /*const int count = 100;
    int value = 0;
    while(value<count)
        cout << ++value << ' ' << endl;*/





        /*const int count = 200;
        int value = 0;
        while(value<count){
            value++;
            if (value%2==0)
                cout << value << endl;
        }*/





        /*int value = 0, count, sum = 0;
        cout << "Enter count numbers (N>0): ";
        cin >> count;
        while(value<count){
            cout << ++value << ' ' << endl;
            if (value%2==0)
                sum+=value;
        }
        cout << "Sum of even numbers --> " << sum << endl;*/





        /*int sum = 0, value = 0, number, count = 10;
        while(value<count){
            value++;
            cout << "Enter " << value << " number: ";
            cin >> number;
            sum+=number;
        }
        cout << "Suma --> " << sum << "\nSerednye aryfmetychne --> " << sum/count << endl;*/





        /*int count, value = 0, number = 0;
        while (true){
            cout << "Enter count odd numbers (1..): ";
            cin >> count;
            if (count>=1) break;
            cout << "A number less than one. Try again." << endl;
        }
        cout << "\nSquares of " << count << " numbers:" << endl;
        do{
            if (number%2!=0) cout << ++value << ". " << number << "^2 = " << number*number << endl;
            number++;
        }while (value<count);*/




        /*const int count = 100;

        int number = 100, value = 0;
        do{
            value++;
            cout << number-- << endl;
        }while (value<count);*/





        /*const int count = 7;
        int sum = 0, number, value = 0;
        do{
            cout << "\nEnter " << ++value << " number: ";
            cin >> number;
            sum+=number;
        }while (value<count);
        cout << "------------------\nSumma = " << sum << endl;*/





        /*const int count = 123;
        int number = 0;
        while (number<count){
            number++;
            if (number>=14) cout << number << endl;
        }*/





        /*const int count = 100;
        int number = 0;
        while (number<count){
            if (number%2!=0) cout << number << endl;
            number++;
        }*/
}