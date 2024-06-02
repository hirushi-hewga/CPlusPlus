#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    /*
        srand(time(NULL));
        const int row = 3;
        const int col = 4;
        int arr[row][col];
        int counter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%10 - 5;
                cout << setw(2) << arr[i][j] << ' ';
                if (arr[i][j] != 0) counter++;
            }
            cout << endl;
        }
        cout << endl;
        cout << "Count of non-zero elements --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 3;
        const int col = 3;
        int arr[row][col];
        int counter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%10 - 5;
                cout << setw(2) << arr[i][j] << ' ';
                if (arr[i][j] == 0) counter++;
            }
            cout << endl;
        }
        cout << endl;
        cout << "Count of zero elements --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 3;
        const int col = 7;
        int arr[row][col];
        int counter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%61 - 30;
                cout << setw(3) << arr[i][j] << ' ';
                if (arr[i][j] > -12 && arr[i][j] < 12) counter++;
            }
            cout << endl;
        }
        cout << endl;
        cout << "Count of elements whose module is less than 12 --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 4;
        const int col = 5;
        int arr[row][col];
        int counter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%81 - 40;
                cout << setw(3) << arr[i][j] << ' ';
                if (arr[i][j] > 0) counter++;
            }
            cout << endl;
        }
        cout << endl;
        cout << "Count of positive numbers --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 4;
        const int col = 5;
        int arr[row][col];
        int counter = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%21 - 10;
                cout << setw(3) << arr[i][j] << ' ';
                if (arr[i][j] > 0) counter*=arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << "Product of all positive numbers --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 4;
        const int col = 5;
        int arr[row][col];
        int counter = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%19 - 9;
                cout << setw(2) << arr[i][j] << ' ';
                if (arr[i][j] < 0) counter*=arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << "Product of all negative numbers --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 4;
        const int col = 4;
        int arr[row][col];
        int counter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%41 - 20;
                cout << setw(3) << arr[i][j] << ' ';
                if (arr[i][j]%6 == 1) counter++;
            }
            cout << endl;
        }
        cout << endl;
        cout << "Count of elements that, when divided by 6, would give a remainder of 1 --> " << counter;
    */




    /*
        srand(time(NULL));
        const int row = 5;
        const int col = 6;
        int arr[row][col];
        int min_number;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%41 - 20;
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < row; i++)
        {
            int min = arr[i][0];
            for (int j = 0; j < col; j++)
            {
                if (min > arr[i][j]) min = arr[i][j];
            }
            min_number = min;
        }
        cout << endl;
        cout << "Min number --> " << min_number;
    */




    /*
        srand(time(NULL));
        const int row = 5;
        const int col = 6;
        int arr[row][col];
        int max_number;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%41 - 20;
                cout << setw(3) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < row; i++)
        {
            int max = arr[i][0];
            for (int j = 0; j < col; j++)
            {
                if (max < arr[i][j]) max = arr[i][j];
            }
            max_number = max;
        }
        cout << endl;
        cout << "Max number --> " << max_number;
    */




    /*
        srand(time(NULL));
        const int row = 4;
        const int col = 5;
        int arr[row][col];
        int summa = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand()%41 - 20;
                cout << setw(3) << arr[i][j] << ' ';
                if (arr[i][j] < 0) summa+=arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << "Summa negative numbers --> " << summa;
    */
}