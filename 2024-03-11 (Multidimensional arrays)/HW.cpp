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
                arr[i][j] = rand()%21 - 10;
                cout << setw(3) << arr[i][j] << ' ';
                if (arr[i][j] == 0) counter++;
            }
            cout << endl;
        }
        cout << endl;
        cout << "Count of zero elements --> " << counter;
    */
















    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i>j) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i<=j){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i<=j && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i<j) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i>=j){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i>=j && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i>j || i+j > N-1) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i<=j && i+j <= N-1){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i<=j && i+j <= N-1 && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i<j || i+j < N-1) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i>=j && i+j >= N-1){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i>=j && i+j >= N-1 && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if ((i>j && i+j < N-1) || (i<j && i+j > N-1)) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if ((i<=j && i+j <= N-1) || (i>=j && i+j >= N-1)){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (((i<=j && i+j <= N-1) || (i>=j && i+j >= N-1)) && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if ((i<j && i+j < N-1) || (i>j && i+j > N-1)) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if ((i>=j && i+j <= N-1) || (i<=j && i+j >= N-1)){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (((i>=j && i+j <= N-1) || (i<=j && i+j >= N-1)) && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i<j || i+j > N-1) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i>=j && i+j <= N-1){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i>=j && i+j <= N-1 && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i>j || i+j < N-1) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i<=j && i+j >= N-1){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i<=j && i+j >= N-1 && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i+j > N-1) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i+j <= N-1){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i+j <= N-1 && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */




    /*
        srand(time(NULL));
        const int N = 11;
        bool BOOL = false;
        int arr[N][N];
        int max_number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = rand()%97+1;
                if (i+j < N-1) arr[i][j] = 99;
                cout << setw(2) << arr[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!BOOL){
                    if (i+j >= N-1){
                        max_number = arr[i][j];
                        BOOL = true;
                    }
                    continue;
                }
                if (i+j >= N-1 && arr[i][j]>max_number) max_number = arr[i][j];
            }
        }
        cout << endl;
        cout << "Max number --> " << max_number << endl;
    */
}