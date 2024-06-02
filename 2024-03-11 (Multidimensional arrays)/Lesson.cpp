#include <iostream>
#include <iomanip>
// #include <stdlib.h>
using namespace std;
int main() {
    /*
        srand(time(NULL));
        int a = rand();
        cout << a << endl;
        for (int i = 0; i < 5; i++)
        {
            a = rand()%23;
            cout << a << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            a = rand()%5 + 11;
            cout << a << endl;
        }
        //x....y --> number = rand()%(y-x) + x
    */



    /*
        const int size = 10;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand()%30;
            cout << arr[i] << ' ';
        }
        cout << endl;
    */



    /*
        const int row = 3;
        const int col = 4;
        int arr[row][col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%20;
                cout << arr[i][j] << '\t';
            }
            cout << endl;
        }
        cout << endl;


        int arr2[2][2] = {{1,2},{3,4}};
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << arr2[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;


        int arr3[2][2] = {7,8,9,10};
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << arr3[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;


        int arr4[3][3] = {};  // = {{4,5},{6,7,8}};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << arr4[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    */



    /*
        srand(time(NULL));
        const int row = 15;
        const int col = 20;
        int arr[row][col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%80 - 12;
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    */



    /*
        srand(time(NULL));
        // -12....67
        // end - start + start
        // 67 - (-12) + (-12)
        // 79 - 12
        // rand() % 79 = 0....78
        srand(time(NULL));
        const int row = 15;
        const int col = 20;
        int arr[row][col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%80 - 12;
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    */



    /*
        srand(time(NULL));
        const int row = 5;
        const int col = 8;
        int arr[row][col];
        int max_elem[row];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%80 - 40;
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 0; i < row; i++)
        {
            int max = arr[i][0];
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] > max)
                {
                    max = arr[i][j];
                    max_elem[i] = max;
                }
            }
            cout << "Max element [ " << i << " ] row = " << max << endl;
        }
        cout << endl;
    */
}