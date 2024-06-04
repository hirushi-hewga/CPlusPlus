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
	Node* tail;
	Node* head;
public:
	List() :tail(nullptr), head(nullptr) {}


	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(nullptr, value, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void AddToTail(int value)
	{
		Node* newNode = new Node(nullptr, value, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void DeleteFromHead()
	{
		if (IsEmpty()) return;
		else if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
	}
	void DeleteFromTail()
	{
		if (IsEmpty()) return;
		else if (tail->prev == nullptr)
		{
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	void AddByPos(int pos, int value)
	{
		if (IsEmpty())
		{
			if (pos == 1)
			{
				Node* newNode = new Node(nullptr, value, nullptr);
				head = tail = newNode;
			}
		}
		else
		{
			Node* j = head;
			for (int i = 1; i < pos && j->next != nullptr; j = j->next, i++) {}
			Node* newNode = new Node(j->prev, value, j);
			if (j == head) AddToHead(value);
			else if (j == tail) AddToTail(value);
			else j->prev = j->prev->next = newNode;
		}
	}
	void DeleteByPos(int pos)
	{
		if (IsEmpty()) return;
		else if (head->next == nullptr)
		{
			if (pos == 1)
			{
				delete head;
				head = tail = nullptr;
			}
		}
		else
		{
			Node* j = head;
			for (int i = 1; i < pos && j->next != nullptr; j = j->next, i++) {}
			if (j == head) DeleteFromHead();
			else if (j == tail) DeleteFromTail();
			else
			{
				j->prev->next = j->next;
				j->next->prev = j->prev;
			}
			delete j;
		}
	}
	int ShowByPos(int pos)const
	{
		Node* j = head;
		for (int i = 1; i < pos && j != nullptr; j = j->next, i++) {}
		if (j == nullptr) return -1;
		return j->value;
	}


	~List()
	{
		for (Node* i = head; i != nullptr; i = i->next)
		{
			if (i->prev != nullptr)
				delete i->prev;
		}
	}
};

class Train
{
	string model;
	List carriages;
public:
	Train() = delete;
	Train(string model) :model(model) {}


	void Add()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 3)
		{
			if (!isValidData) cout << endl << "Error choice. Try again!" << endl << endl;
			isValidData = false;
			cout << "1 - Add to head" << endl;
			cout << "2 - Add to tail" << endl;
			cout << "3 - Add by pos" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		int place_count;
		cout << "Enter count places : ";
		cin >> place_count;
		switch (choice)
		{
		case 1: carriages.AddToHead(place_count); break;
		case 2: carriages.AddToTail(place_count); break;
		case 3:
			int pos;
			cout << "Enter new carriage position : ";
			cin >> pos;
			carriages.AddByPos(pos, place_count);
		}
	}
	void Delete()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 3)
		{
			if (!isValidData) cout << endl << "Error choice. Try again!" << endl << endl;
			isValidData = false;
			cout << "1 - Delete from head" << endl;
			cout << "2 - Delete from tail" << endl;
			cout << "3 - Delete by pos" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1: carriages.DeleteFromHead(); break;
		case 2: carriages.DeleteFromTail(); break;
		case 3:
			int pos;
			cout << "Enter delete position : ";
			cin >> pos;
			carriages.DeleteByPos(pos);
		}
	}
	void operator [](int pos)
	{
		cout << "Element [" << pos << "] : " << carriages.ShowByPos(pos) << endl;
	}
};



int main()
{
	Train train("Tom");
	train.Add();
	train.Add();
	train.Add();
	train.Add();
	train.Add();
	train[1];
	train[3];
	train[5];
	train[2];
	train[4];
	train.Delete();
	train.Delete();
	train[2];
	train[1];
	train[3];
}