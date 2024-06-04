#include <iostream>
using namespace std;

class StackFullException : public exception
{
public:
	StackFullException(const char* ex) : exception(ex) {}
};

template<typename T>
class Stack
{
	enum { EMPTY = -1 };
	int size;
	int top;
	T* arr;
public:
	Stack() = delete;
	Stack(int size)
	{
		if (size < 0) throw invalid_argument("Error argument! Size must be less that 0");
		top = EMPTY;
		arr = new T[size];
	}
	Stack(const initializer_list<int> list)
	{
		top = EMPTY;
		this->size = list.size();
		arr = new T[size];
		for (T value : list)
		{
			arr[++top] = value;
		}
	}


	bool IsFull()const
	{
		return top == size - 1;
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	T Push(T value)
	{
		if (IsFull())
			throw StackFullException("Stack is full.");
		arr[++top] = value;
		return value;
	}
	T Pop()
	{
		if (IsEmpty())
			throw exception("Stack is empty.");
		top--;
		return arr[top + 1];
	}
	T Peek()const
	{
		if (IsEmpty())
			throw exception("Stack is empty.");
		return arr[top];
	}
	T GetCount()const
	{
		return top + 1;
	}
	void Clear()
	{
		top = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}


	~Stack()
	{
		delete[] arr;
	}
};



//int main()
//{
	/*Stack<int> st({ 1, 56, 43, 84, 25, 58, 2, 8, 53, 97, 3 });
	try
	{
		st.Print();
		cout << "Last element : " << st.Peek() << endl;
		cout << "Count elements : " << st.GetCount() << endl;
		cout << "Pop : " << st.Pop() << endl;
		cout << "Pop : " << st.Pop() << endl;
		cout << "Push : " << st.Push(47) << endl;
		st.Print();
		cout << "Last element : " << st.Peek() << endl;
		cout << "Count elements : " << st.GetCount() << endl;
	}
	catch (StackFullException ex)
	{
		cout << "Exception : " << ex.what() << endl;
	}
	catch (invalid_argument ex)
	{
		cout << "Exception : " << ex.what() << endl;
	}
	catch (exception ex)
	{
		cout << "Exception : " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}*/
	//}