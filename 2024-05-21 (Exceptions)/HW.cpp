#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	Node* prev;
	float value;
	Node* next;
	Node(Node* prev, float value, Node* next) :prev(prev), value(value), next(next) {}
};

class List
{
	Node* head;
	Node* tail;
public:
	List() :head(nullptr), tail(nullptr) {}


	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(float value)
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
	void AddToTail(float value)
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
		if (IsEmpty()) throw exception("List is empty");
		else if (head == tail)
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
		if (IsEmpty()) throw exception("List is empty");
		else if (head == tail)
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
	void Show()const
	{
		if (IsEmpty()) throw exception("List is empty");
		system("cls");
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 6)
	{
		system("cls");
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
			cout << endl;
		}
		cout << "1 - Add value to head" << endl;
		cout << "2 - Add value to tail" << endl;
		cout << "3 - Delete value from head" << endl;
		cout << "4 - Delete value from tail" << endl;
		cout << "5 - Show list" << endl;
		cout << "6 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { ADD_TO_HEAD = 1, ADD_TO_TAIL, DELETE_FROM_HEAD, DELETE_FROM_TAIL, PRINT_LIST, EXIT };
//int main()
//{
	/*char s;
	List list;
	bool isExit = false;
	while (!isExit)
	{
		try
		{
			float value;
			switch (Menu())
			{
			case ADD_TO_HEAD:
				system("cls");
				cout << "Enter value : "; cin >> value;
				cout << endl;
				list.AddToHead(value);
				cout << "Value added to head" << endl;
				cout << endl;
				cout << "Press any key to continue : ";
				s = _getch();
				break;
			case ADD_TO_TAIL:
				system("cls");
				cout << "Enter value : "; cin >> value;
				cout << endl;
				list.AddToTail(value);
				cout << "Value added to tail" << endl;
				cout << endl;
				cout << "Press any key to continue : ";
				s = _getch();
				break;
			case DELETE_FROM_HEAD:
				system("cls");
				list.DeleteFromHead();
				cout << "Value deleted from head" << endl;
				cout << endl;
				cout << "Press any key to continue : ";
				s = _getch();
				break;
			case DELETE_FROM_TAIL:
				system("cls");
				list.DeleteFromTail();
				cout << "Value deleted from tail" << endl;
				cout << endl;
				cout << "Press any key to continue : ";
				s = _getch();
				break;
			case PRINT_LIST:
				list.Show();
				cout << endl;
				cout << "Press any key to continue : ";
				s = _getch();
				break;
			case EXIT: isExit = true;
			}
		}
		catch (exception ex)
		{
			system("cls");
			cout << ex.what() << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			s = _getch();
		}
		catch (...)
		{
			system("cls");
			cout << "Unknown exception" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			s = _getch();
		}
	}*/
	//}