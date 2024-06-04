#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() :x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}
};

struct Node
{
	Point* point;
	Node* next;
	Node(Point* point, Node* next) :point(point), next(next) {}
};

class List
{
	Node* head;
public:
	List() :head(nullptr) {}


	void AddToHead(int x, int y)
	{
		Point* point = new Point(x, y);
		Node* newNode = new Node(point, head);
		head = newNode;
	}
	void AddToTail(int x, int y)
	{
		Point* point = new Point(x, y);
		Node* newNode = new Node(point, nullptr);
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
	void DeleteFromHead()
	{
		Node* current = head;
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
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
	void Add(int pos, int x, int y)
	{
		if (pos == 1)
		{
			AddToHead(x, y);
		}
		else
		{
			Point* point = new Point(x, y);
			Node* current = head;
			int i = 0;
			while (current != nullptr)
			{
				if (pos - 1 == ++i)
				{
					Node* newNode = new Node(point, current->next);
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
			Node* current = head;
			int i = 0;
			while (current != nullptr)
			{
				if (pos - 1 == ++i)
				{
					Node* next = current->next->next;
					delete current->next;
					current->next = next;
				}
				current = current->next;
			}
		}
	}
	Node* GetHead()const
	{
		return head;
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

class Vector
{
	enum { HEAD = 1, TAIL, POS };
	List points;
public:
	void Add()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 3)
		{
			if (!isValidData)
			{
				cout << endl;
				cout << "Error choice. Try again!" << endl;
				cout << endl;
			}
			isValidData = false;
			cout << "1 - Add to head" << endl;
			cout << "2 - Add to tail" << endl;
			cout << "3 - Add by pos" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		int x, y, pos;
		switch (choice)
		{
		case HEAD:
			cout << "Enter x point : ";
			cin >> x;
			cout << "Enter y point : ";
			cin >> y;
			points.AddToHead(x, y);
			break;
		case TAIL:
			cout << "Enter x point : ";
			cin >> x;
			cout << "Enter y point : ";
			cin >> y;
			points.AddToTail(x, y);
			break;
		case POS:
			cout << "Enter x point : ";
			cin >> x;
			cout << "Enter y point : ";
			cin >> y;
			cout << "Enter pos in point list : ";
			cin >> pos;
			points.Add(pos, x, y);
		}
	}
	void Delete()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 3)
		{
			if (!isValidData)
			{
				cout << endl;
				cout << "Error choice. Try again!" << endl;
				cout << endl;
			}
			isValidData = false;
			cout << "1 - Delete to head" << endl;
			cout << "2 - Delete to tail" << endl;
			cout << "3 - Delete by pos" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		switch (choice)
		{
		case HEAD:
			points.DeleteFromHead();
			break;
		case TAIL:
			points.DeleteFromTail();
			break;
		case POS:
			int pos;
			cout << "Enter pos in point list : ";
			cin >> pos;
			points.Delete(pos);
		}
	}

	friend ostream& operator <<(ostream& out, const Vector& other);
};

ostream& operator <<(ostream& out, const Vector& other)
{
	Node* current = other.points.GetHead();
	int i = 0;
	while (current != nullptr)
	{
		out << "==== Point " << ++i << " ====" << endl;
		out << "x = " << current->point->x << " ,  y = " << current->point->y << endl;
		out << endl;
		current = current->next;
	}
	return out;
}



int main()
{
	Vector v;
	v.Add();
	v.Add();
	v.Add();
	v.Add();
	v.Add();
	v.Add();
	cout << v << endl;
	v.Delete();
	v.Delete();
	cout << v << endl;
}