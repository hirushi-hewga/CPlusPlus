#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct Point
{
    int x;
    int y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y) :x(x), y(y) {}
    Point(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
    }
};


class Queue
{
    Point p;
    int* arr;
    int maxSize;
    int top;
public:
    Queue() = delete;
    Queue(Point p) :maxSize(5)
    {
        this->p.x = p.x;
        this->p.y = p.y;
        arr = new int[maxSize];
        top = 0;
        for (int i = 0; i < maxSize; i++)
            arr[top++] = rand() % 9 + 1;
    }


    bool IsFull()const
    {
        return top == maxSize;
    }
    bool IsEmpty()const
    {
        return top == 0;
    }
    void Enqueue(int element)
    {
        if (!IsFull())
        {
            arr[top++] = element;
        }
    }
    void Dequeue()
    {
        if (!IsEmpty())
        {
            for (int i = 1; i < top; i++)
            {
                arr[i - 1] = arr[i];
            }
            arr[top - 1] = rand() % 9 + 1;
        }
    }
    int GetCount()const
    {
        return top;
    }
    void Clear()
    {
        top = 0;
    }
    int Peek()
    {
        if (IsEmpty())return 0;
        return arr[0];
    }
    void Print()const
    {
        Point point(this->p);
        for (int i = top - 1; i >= 0; i--)
        {
            gotoxy(point.x, point.y++);
            cout << arr[i];
        }
    }
    int GetValue()
    {
        return arr[2];
    }


    ~Queue()
    {
        delete[]arr;
    }
};



int main()
{
    srand(time(NULL));
    bool isTry = true;

    gotoxy(0, 3);
    cout << ">";
    gotoxy(8, 3);
    cout << "<";
    gotoxy(1, 0);
    cout << "-------";
    gotoxy(1, 6);
    cout << "-------";

    while (isTry)
    {
        isTry = false;
        Queue q1(Point(2, 1));
        q1.Print();
        Queue q2(Point(4, 1));
        q2.Print();
        Queue q3(Point(6, 1));
        q3.Print();
        for (int i = 0; i < 30; i++)
        {
            if (i < 10) q1.Dequeue();
            if (i < 20) q2.Dequeue();
            q3.Dequeue();
            Sleep(200);
            q1.Print();
            q2.Print();
            q3.Print();
        }
        gotoxy(0, 7);
        cout << "Res : " << q1.GetValue() << q2.GetValue() << q3.GetValue() << endl;
        gotoxy(0, 9);
        if (q1.GetValue() == q2.GetValue() && q2.GetValue() == q3.GetValue())
            cout << "You won!";
        else
            cout << "You lost";
        char symbol = 'a';
        while (symbol != 'y' && symbol != 'n')
        {
            gotoxy(0, 10);
            cout << "Try again ? y/n : "; symbol = _getch();
            if (symbol == 'y') isTry = true;
            else if (symbol == 'n')
            {
                gotoxy(0, 12);
                cout << "Good bye." << endl;
            }
        }
    }
}