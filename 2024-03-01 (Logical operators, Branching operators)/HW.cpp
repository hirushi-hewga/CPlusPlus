#include <iostream>
using namespace std;
int main() {
    /*int side_1, side_2, side_3;
    cout << "Enter triangle first side: ";
    cin >> side_1;
    cout << "Enter triangle second side: ";
    cin >> side_2;
    cout << "Enter triangle third side: ";
    cin >> side_3;
    cout << "----------------------------------" << endl;
    if (side_1 == side_2 && side_2 == side_3)
        cout << "trykutnyk rivnostoronniy" << endl;
    if (side_1 == side_2 || side_2 == side_3 || side_3 == side_1)
        cout << "trykutnyk rivnobedrennyy" << endl;
    if (side_1 * side_1 == side_2 * side_2 + side_3 * side_3 || side_3 * side_3 == side_2 * side_2 + side_1 * side_1 || side_2 * side_2 == side_1 * side_1 + side_3 * side_3)
        cout << "trykutnyk pryamokutnyy" << endl;*/




        /*float brickLength, brickWidth, brickHeight, holeLength, holeWidth, holeHeight, temp, count = 0;
        cout << "Enter brick length: ";
        cin >> brickLength;
        cout << "Enter brick width: ";
        cin >> brickWidth;
        cout << "Enter brick height: ";
        cin >> brickHeight;
        cout << "Enter hole length: ";
        cin >> holeLength;
        cout << "Enter hole width: ";
        cin >> holeWidth;
        cout << "Enter hole depth: ";
        cin >> holeHeight;
        cout << "----------------------------------" << endl;
        if (brickLength > 0 && brickWidth > 0 && brickHeight > 0 && holeLength > 0 && holeWidth > 0 && holeHeight > 0){
            if (brickLength <= holeLength && brickHeight <= holeHeight && brickWidth <= holeWidth)
                count++;
            temp = brickLength, brickLength = brickWidth, brickWidth = temp;

            if (brickLength <= holeLength && brickHeight <= holeHeight && brickWidth <= holeWidth)
                count++;
            temp = brickLength, brickLength = brickHeight, brickHeight = temp;

            if (brickLength <= holeLength && brickHeight <= holeHeight && brickWidth <= holeWidth)
                count++;
            temp = brickHeight, brickHeight = brickWidth, brickWidth = temp;

            if (brickLength <= holeLength && brickHeight <= holeHeight && brickWidth <= holeWidth)
                count++;
            temp = brickWidth, brickWidth = brickLength, brickLength = temp;

            if (brickLength <= holeLength && brickHeight <= holeHeight && brickWidth <= holeWidth)
                count++;
            temp = brickLength, brickLength = brickHeight, brickHeight = temp;

            if (brickLength <= holeLength && brickHeight <= holeHeight && brickWidth <= holeWidth)
                count++;
        }
        if (count == 0)
            cout << "Error!!! It does not fit!" << endl;
        else if (count == 1)
            cout << "Fit in" << endl;
        else if (count <= 5)
            cout << "Fit in " << count << " ways" << endl;
        else
            cout << "Fits in all ways" << endl;*/




            /*int number_1, number_2, number_3;
            cout << "Enter first number: ";
            cin >> number_1;
            cout << "Enter second number: ";
            cin >> number_2;
            cout << "Enter third number: ";
            cin >> number_3;
            cout << "------------------------" << endl;
            cout << "positive numbers:" << endl;
            if (number_1 > 0)
                cout << number_1 << endl;
            if (number_2 > 0)
                cout << number_2 << endl;
            if (number_3 > 0)
                cout << number_3 << endl;
            cout << "negative numbers:" << endl;
            if (number_1 < 0)
                cout << number_1 << endl;
            if (number_2 < 0)
                cout << number_2 << endl;
            if (number_3 < 0)
                cout << number_3 << endl;*/




                /*int number;
                cout << "Enter number: ";
                cin >> number;
                cout << "------------------------" << endl;
                if (number < -1 || number > 5)
                    cout << "Number " << number << " outside the segments [2, 5] and [-1, 1]." << endl;
                else
                    cout << "Number " << number << " within the segments [2, 5] and [-1, 1]." << endl;*/




                    /*int number_1, number_2, number_3;
                    cout << "Enter first number: ";
                    cin >> number_1;
                    cout << "Enter second number: ";
                    cin >> number_2;
                    cout << "Enter third number: ";
                    cin >> number_3;
                    cout << "------------------------" << endl;
                    if (number_1 == number_2 && number_1 == number_3)
                        cout << number_1 << " == " << number_2 << " == " << number_3 << " - The numbers are equal." << endl;
                    else
                        cout << "The numbers are not equal." << endl;*/




                        /*int number_1, number_2, number_3, number;
                        cout << "Enter first number: ";
                        cin >> number_1;
                        cout << "Enter second number: ";
                        cin >> number_2;
                        cout << "Enter third number: ";
                        cin >> number_3;
                        cout << "------------------------" << endl;
                        number = number_1;
                        (number%2==0)?cout << number << " - even" << endl:cout << number << " - odd" << endl;
                        number = number_2;
                        (number%2==0)?cout << number << " - even" << endl:cout << number << " - odd" << endl;
                        number = number_3;
                        (number%2==0)?cout << number << " - even" << endl:cout << number << " - odd" << endl;*/




                        /*int number_1, number_2, temp;
                        cout << "Enter first number: ";
                        cin >> number_1;
                        cout << "Enter second number: ";
                        cin >> number_2;
                        cout << number_1 << ", " << number_2 << endl;
                        cout << "------------------------" << endl;
                        (number_1!=number_2)?cout << "The numbers are not equal" << endl:cout << "The numbers are equal:" << endl;
                        if (number_1!=number_2)
                            temp = number_1,number_1 = number_2, number_2 = temp;
                        cout << number_1 << ", " << number_2 << endl;*/



                        /*int number, count, summa, first_digit, last_digit;
                        cout << "Enter number (1-999): ";
                        cin >> number;
                        cout << "------------------------" << endl;
                        if (number < 1 || number > 999)
                            cout << "\nNumber out of range!";
                        else if (number>=100)
                            count = 3, summa = number % 10 + number / 100 + number / 10 % 10, first_digit = number/100, last_digit = number%10;
                        else if (number >= 10)
                            count = 2, summa = number / 10 + number % 10, first_digit = number/10, last_digit = number%10;
                        else
                            count = 1, summa = number, first_digit = number, last_digit = number;
                        cout << "Number count --> " << count << endl;
                        cout << "Digits summa --> " << summa << endl;
                        cout << first_digit << "  " << last_digit << endl;*/




                        /*int hours, minutes, seconds;
                        cout << "Enter hours: ";
                        cin >> hours;
                        cout << "Enter minutes: ";
                        cin >> minutes;
                        cout << "Enter seconds: ";
                        cin >> seconds;
                        cout << "------------------------" << endl;
                        if (hours < 24 && hours >= 0 && minutes < 60 && minutes >= 0 && seconds < 60 && seconds >=0)
                            cout << "The time is acceptable" << endl;
                        else
                            cout << "Time is not allowed" << endl;*/




                            /*int hours;
                            cout << "Enter hours (0-23): ";
                            cin >> hours;
                            switch (hours){
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                                cout << "Good night" << endl;
                                break;
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                            case 10:
                            case 11:
                                cout << "Good morning" << endl;
                                break;
                            case 12:
                            case 13:
                            case 14:
                            case 15:
                            case 16:
                            case 17:
                                cout << "Good day" << endl;
                                break;
                            case 18:
                            case 19:
                            case 20:
                            case 21:
                            case 22:
                            case 23:
                                cout << "Good evening" << endl;
                                break;
                            default:
                                cout << "Hour out of range!";
                            }*/




                            /*int number_1, number_2, number_3, min_number;
                            cout << "Enter first number: ";
                            cin >> number_1;
                            cout << "Enter second number: ";
                            cin >> number_2;
                            cout << "Enter third number: ";
                            cin >> number_3;
                            cout << "------------------------" << endl;
                            (number_1<number_2)?min_number = number_1:min_number = number_2;
                            (min_number<number_3)?min_number = min_number:min_number = number_3;
                            cout << "Minimum: " << min_number << endl;*/
}