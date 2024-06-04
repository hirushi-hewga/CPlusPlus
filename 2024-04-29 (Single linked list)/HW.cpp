#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node* next;
	Node(T value, Node* next) :value(value), next(next) {}
};

template<typename T>
class List
{
	Node<T>* head;
public:
	List() :head(nullptr) {}
	List(const List& other)
	{
		Node<T>* newNode = new Node<T>(other.head->value, nullptr);
		this->head = newNode;


		Node<T>* current_other = other.head;
		Node<T>* current_this = this->head;
		while (current_other->next != nullptr)
		{
			Node<T>* newNode = new Node<T>(current_other->next->value, nullptr);
			current_this->next = newNode;
			current_this = current_this->next;
			current_other = current_other->next;
		}
	}
	List operator =(const List& other)
	{
		this->head = other.head;
		return *this;
	}


	void AddToHead(T value)
	{
		Node<T>* newNode = new Node<T>(value, head);
		head = newNode;
	}
	void AddToTail(T value)
	{
		Node<T>* newNode = new Node<T>(value, nullptr);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node<T>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void DeleteFromHead()
	{
		Node<T>* current = head;
		head = head->next;
		delete current;
	}
	void DeleteFromTail()
	{
		if (head == nullptr) return;
		else if (head->next == nullptr)
		{
			delete head;
		}
		else
		{
			Node<T>* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
	void DeleteAll()
	{
		Node<T>* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void Show()const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
	}
	T Find(int pos)const
	{
		Node<T>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (pos == ++i) return current->value;
			current = current->next;
		}
		return 0;
	}
	void Add(int pos, T value)
	{
		if (pos == 1)
		{
			AddToHead(value);
		}
		else
		{
			Node<T>* current = head;
			int i = 0;
			while (current != nullptr)
			{
				if (pos - 1 == ++i)
				{
					Node<T>* newNode = new Node<T>(value, current->next);
					current->next = newNode;
				}
				current = current->next;
			}
		}
	}
	void Delete(int pos)
	{
		if (pos == 1)
		{
			DeleteFromHead();
		}
		else
		{
			Node<T>* current = head;
			int i = 0;
			while (current != nullptr)
			{
				if (pos - 1 == ++i)
				{
					Node<T>* next = current->next->next;
					delete current->next;
					current->next = next;
				}
				current = current->next;
			}
		}
	}


	~List()
	{
		Node<T>* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
};



//int main()
//{
	/*
	srand(time(NULL));
	List<int> list;
	list.AddToHead(888);
	cout << "list 1 : "; list.Show();
	for (int i = 0; i < 5; i++)
	{
		list.AddToHead(rand() % 9 + 1);
	}
	cout << "list 1 : "; list.Show();
	for (int i = 0; i < 5; i++)
	{
		list.AddToTail(rand() % 10 + 10);
	}
	cout << "list 1 : "; list.Show();
	list.DeleteFromHead();
	list.DeleteFromHead();
	cout << "list 1 : "; list.Show();
	list.DeleteFromTail();
	list.DeleteFromTail();
	cout << "list 1 : "; list.Show();
	cout << "Element 1 = " << list.Find(1) << endl;
	cout << "Element 3 = " << list.Find(3) << endl;
	cout << "Element 6 = " << list.Find(6) << endl;
	List<int> list2(list);
	cout << "list 2 : "; list2.Show();
	List<int> list3 = list2;
	cout << endl;
	cout << "list 1 : "; list.Show();
	cout << "list 2 : "; list2.Show();
	cout << "list 3 : "; list3.Show();

	list.Add(1, 1111);
	list2.Add(3, 1111);
	list3.Add(5, 1111);
	list.Delete(2);
	list2.Delete(4);
	list3.Delete(6);
	cout << endl;
	cout << "list 1 : "; list.Show();
	cout << "list 2 : "; list2.Show();
	cout << "list 3 : "; list3.Show();
	*/
	//}