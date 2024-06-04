#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int value;
	Node* next;
	Node(Node* prev, int value, Node* next) :prev(prev), value(value), next(next) {}
};

class List
{
	Node* head;
	Node* tail;
public:
	List() :head(nullptr), tail(nullptr) {}


	bool IsEmpty()
	{
		return head == nullptr;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(nullptr, value, head);
		if (IsEmpty())
			head = tail = newNode;
		head->prev = newNode;
		head = newNode;
	}
	void Print()const
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
	}
	void AddToTail(int value)
	{
		Node* newNode = new Node(tail, value, nullptr);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr) return;
		else if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	int GetElemByPos(int pos)
	{
		Node* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (pos == ++i) return current->value;
			current = current->next;
		}
		return 0;
	}


	~List()
	{
		Node* current = nullptr;
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
	List list;
	list.AddToHead(10);
	list.AddToHead(20);
	list.AddToHead(30);
	list.AddToHead(40);
	list.Print();

	list.AddToTail(100);
	list.AddToTail(200);
	list.AddToTail(300);
	list.Print();

	list.DeleteFromTail();
	list.Print();
	list.DeleteFromTail();
	list.Print();
	list.DeleteFromTail();
	list.Print();
	*/
	//}