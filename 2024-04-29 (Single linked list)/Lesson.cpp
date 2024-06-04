#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;

	Node(int value, Node* next) :value(value), next(next) {}
};

class List
{
	Node* head;
public:
	List() :head(nullptr) {}


	void AddToHead(int value)
	{
		Node* newNode = new Node(value, head);
		//newNode->next = head;
		//newNode->value = value;
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
		Node* newNode = new Node(value, nullptr);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr) return;
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
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
	for (int i = 0; i < 5; i++)
	{
		list.AddToHead(i);
	}
	list.Print();
	list.AddToTail(100);
	list.AddToTail(200);
	list.AddToTail(300);
	list.Print();

	cout << "Element [2] = " << list.GetElemByPos(2) << endl;
	cout << "Element [5] = " << list.GetElemByPos(5) << endl;
	cout << "Element [100] = " << list.GetElemByPos(100) << endl;

	list.DeleteFromTail();
	list.DeleteFromTail();
	list.Print();
	*/
	//}