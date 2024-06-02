#include <iostream>
using namespace std;

int main()
{
    char symbol = 'f';
    cout << symbol << endl;

    char line[5] = { 'C','a','t','!','\0' };
    for (int i = 0; i < 5; i++)
    {
        cout << line[i];
    }
    //line C-style
    char mystring[] = "string";//string\0

    cout << mystring << " has " << sizeof(mystring) << " characters " << endl;
    cout << mystring << " has " << strlen(mystring) << " symbols  " << endl;

    for (int i = 0; i < sizeof(mystring); i++)
    {
        cout << static_cast<int>(mystring[i]) << " ";
    }
    cout << endl;

    //mystring = "cat";
    mystring[0] = 'S';
    /*int arr[] = { 1,2,3,4,5 };
    arr[0] = 7;*/
    cout << mystring << endl;

    char name[15] = "Max";
    cout << "My name is : " << name << endl;

    char newName[255];
    cout << "Enter name : ";
    //cin >> newName;
    cin.getline(newName, 255);
    cout << "Youe name is " << newName << endl;

    char text[] = "print this!";
    char dest[50];

    strcpy_s(dest, text);
    cout << dest << endl;

    _strupr_s(text);
    cout << text << endl;

    _strlwr_s(text);
    cout << text << endl;

    _strrev(text);
    cout << text << endl;
    _strrev(text);
    cout << text << endl;

    char arr[255] = {};
    strcpy_s(arr, text);
    cout << arr << endl;

    arr[2] = '\0';
    cout << arr << endl;

    strcat_s(arr, "..............");
    cout << arr << endl;

    cin >> dest;
    strcat_s(arr, dest);
    cout << arr << endl;

    strncat_s(arr, dest, 3);
    cout << arr << endl;

}