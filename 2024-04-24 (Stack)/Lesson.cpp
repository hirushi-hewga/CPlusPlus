#include <iostream>
using namespace std;

//class Stack
//{
//	enum { EMPTY = -1, FULL = 9 };
//	int arr[FULL + 1]; // 10
//	int top;
//public:
//	Stack()
//	{
//		top = EMPTY;
//	}
//	~Stack() = default;
//	Stack(const Stack& other) = delete;
//
//
//	bool IsFull()const
//	{
//		return top == FULL;
//	}
//	bool Push(int elem)
//	{
//		if (!IsFull())
//		{
//			arr[++top] = elem;
//			return true;
//		}
//		return false;
//	}
//	bool IsEmpty()const
//	{
//		return top == EMPTY;
//	}
//	int Pop()
//	{
//		if (!IsEmpty())
//		{
//			return arr[top--];
//		}
//	}
//	int GetCount()const
//	{
//		return top + 1;
//	}
//	void Clear()
//	{
//		top = EMPTY;
//	}
//	void Print()const
//	{
//		for (int i = 0; i <= top; i++)
//		{
//			cout << arr[i] << ' ';
//		}
//		cout << endl;
//	}
//};

//class MyClass
//{
//	// default delete
//	// default constructor
//	// copy constructor
//	// destructor
//	// operator =
//};
//
//class Stack
//{
//	enum { EMPTY = -1 };
//	int size;
//	int* arr;
//	int top;
//public:
//	Stack() = delete;
//	Stack(int size):size(size)
//	{
//		top = EMPTY;
//		arr = new int[size];
//	}
//	bool IsFull()const
//	{
//		return top == size - 1;
//	}
//	bool Push(int value)
//	{
//		if (!IsFull())
//		{
//			arr[++top] = value;
//			return true;
//		}
//		return false;
//	}
//	bool IsEmpty()const
//	{
//		return top == EMPTY;
//	}
//	int Pop()
//	{
//		if (!IsEmpty())
//		{
//			return arr[top--];
//		}
//	}
//	int Peek()
//	{
//		if (!IsEmpty())
//		{
//			return arr[top];
//		}
//	}
//	int GetCount()const
//	{
//		return top + 1;
//	}
//	void Clear()
//	{
//		top = EMPTY;
//	}
//	void Print()const
//	{
//		for (int i = 0; i <= top; i++)
//		{
//			cout << arr[i] << ' ';
//		}
//		cout << endl;
//	}
//	~Stack()
//	{
//		delete[] arr;
//	}
//};
//
//bool IsValidCode(string code)
//{
//	Stack st(10);
//	for (char symbol : code)
//	{
//		if (symbol == '{')
//		{
//			st.Push(1);
//		}
//		if (symbol == '}')
//		{
//			if (st.IsEmpty()) return false;
//			st.Pop();
//		}
//	}
//	return st.IsEmpty();
//}



//int main()
//{
	/*
	Stack st;
	// Stack copy(st);

	st.Push(10);
	st.Push(7);
	st.Push(5);
	st.Push(4);
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	cout << "Element : " << st.Pop() << endl;
	cout << "Count : " << st.GetCount() << endl;
	st.Print();

	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	while (!st.IsEmpty())
	{
		cout << "Element : " << st.Pop() << endl;
	}
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	*/



	/*
	srand(time(NULL));
	Stack st(20);
	// Stack copy(st);

	while (!st.IsFull())
	{
		st.Push(rand() % 99 + 1);
	}
	// st.Push(10);
	// st.Push(7);
	// st.Push(5);
	// st.Push(4);
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	cout << "Element : " << st.Pop() << endl;
	cout << "Count : " << st.GetCount() << endl;
	st.Print();

	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	while (!st.IsEmpty())
	{
		cout << "Element : " << st.Pop() << endl;
	}
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	*/



	/*
	string code = "class Stack{ void Print(){ if (){}}};";
	if (IsValidCode(code))
		cout << "Code is valid" << endl;
	else
		cout << "Code is invalid" << endl;
	*/
	//}