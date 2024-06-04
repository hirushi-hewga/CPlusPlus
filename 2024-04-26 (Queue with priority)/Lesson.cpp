//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Queue
//{
//public:
//	struct Element
//	{
//		T value;
//		int priority;
//	};
//private:
//	Element* arr;
//	int size;
//public:
//	Queue():arr(nullptr),size(0) {}
//
//
//	void Enqueue(T value, int pr)
//	{
//		int index = 0;
//		while (index < size && arr[index].priority < pr)
//		{
//			index++;
//		}
//		Element* temp = new Element[size + 1];
//		for (int i = 0; i < index; i++)
//		{
//			temp[i] = arr[i];
//		}
//		temp[index] = Element{value, pr};
//		for (int i = index + 1; i <= size; i++)
//		{
//			temp[i] = arr[i - 1];
//		}
//		if (arr != nullptr)
//			delete[] arr;
//		arr = temp;
//		size++;
//	}
//	bool IsEmpty()const
//	{
//		return size == 0;
//	}
//	Element Dequeue()
//	{
//		if (!IsEmpty())
//		{
//			Element first = arr[0];
//			for (int i = 0; i < size; i++)
//			{
//				arr[i] = arr[i + 1];
//			}
//			size--;
//			return first;
//		}
//		return Element();
//	}
//	void Print()const
//	{
//		cout << "---------------- Queue with priority ----------------" << endl;
//		cout << "| ";
//		for (int i = 0; i < size; i++)
//		{
//			cout << arr[i].value << ':' << arr[i].priority << " | ";
//		}
//		cout << endl;
//		cout << "-----------------------------------------------------" << endl;
//	}
//
//
//	~Queue()
//	{
//		if (arr != nullptr)
//			delete[] arr;
//	}
//};
//
//
//int main()
//{
//	Queue<char> q;
//	q.Enqueue( 'A', 1 );
//	q.Enqueue( 'B', 2 );
//	q.Enqueue( 'C', 3 );
//	q.Enqueue( 'G', 7 );
//	q.Enqueue( 'K', 11 );
//	q.Enqueue( 'N', 14 );
//	q.Print();
//	q.Enqueue( 'D', 4 );
//	q.Print();
//}