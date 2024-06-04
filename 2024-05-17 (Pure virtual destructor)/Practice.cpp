#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int p) {
	COORD coord;
	coord.X = p;
	coord.Y = p;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



class Food
{
	string recipe;
public:
	Food(string recipe) : recipe(recipe) {}
	virtual void Show()const
	{
		cout << "Recipe : " << recipe << endl;
		cout << endl;
	}
};



struct Node
{
	Node* prev;
	Food* food;
	Node* next;
	Node(Node* prev, Food* food, Node* next) : prev(prev), food(food), next(next) {}
};

class List
{
	Node* head;
	Node* tail;
public:
	List() : head(nullptr), tail(nullptr) {}

	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(Food* food)
	{
		if (IsEmpty())
		{
			Node* newNode = new Node(nullptr, food, nullptr);
			head = tail = newNode;
		}
		else
		{
			Node* newNode = new Node(nullptr, food, head);
			head = head->prev = newNode;
		}
	}
	void AddToTail(Food* food)
	{
		if (IsEmpty())
		{
			Node* newNode = new Node(nullptr, food, nullptr);
			head = tail = newNode;
		}
		else
		{
			Node* newNode = new Node(tail, food, nullptr);
			tail = tail->next = newNode;
		}
	}
	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			system("cls");
			gotoxy(0);
			cout << "Error! List is empty." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else if (head == tail && head != nullptr)
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
		if (IsEmpty())
		{
			system("cls");
			gotoxy(0);
			cout << "Error! List is empty." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else if (head == tail && head != nullptr)
		{
			delete tail;
			tail = head = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	void Print()const
	{
		Node* current = head;
		system("cls");
		gotoxy(0);
		while (current != nullptr)
		{
			current->food->Show();
			current = current->next;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}

	~List()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}
};





class Pizza : public Food
{
public:
	Pizza(string recipe) : Food(recipe) {}
	virtual void PreparePizza()const = 0;
};

class MilanPizza : public Pizza
{
	void PreparePizza()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Milan pizza prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	MilanPizza(string recipe) : Pizza(recipe) { PreparePizza(); }

	void Show()const override
	{
		cout << "================ Milan Pizza ================" << endl;
		Food::Show();
	}
};
class GreecePizza : public Pizza
{
	void PreparePizza()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Greece pizza prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	GreecePizza(string recipe) : Pizza(recipe) { PreparePizza(); }

	void Show()const override
	{
		cout << "================ Greece Pizza ================" << endl;
		Food::Show();
	}
};



class Souce : public Food
{
public:
	Souce(string recipe) : Food(recipe) {}
	virtual void PrepareSouce()const = 0;
};

class MilanSouce : public Souce
{
	void PrepareSouce()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Milan souce prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	MilanSouce(string recipe) : Souce(recipe) { PrepareSouce(); }

	void Show()const override
	{
		cout << "================ Milan Souce ================" << endl;
		Food::Show();
	}
};
class GreeceSouce : public Souce
{
	void PrepareSouce()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Greece souce prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	GreeceSouce(string recipe) : Souce(recipe) { PrepareSouce(); }

	void Show()const override
	{
		cout << "================ Greece Souce ================" << endl;
		Food::Show();
	}
};



class Fabric
{
public:
	virtual Pizza* PreparePizza(string recipe)const = 0;
	virtual Souce* PrepareSouce(string recipe)const = 0;
};

class FabricMilan : public Fabric
{
public:
	Pizza* PreparePizza(string recipe)const override
	{
		return new MilanPizza(recipe);
	}
	Souce* PrepareSouce(string recipe)const override
	{
		return new MilanSouce(recipe);
	}
};
class FabricGreece : public Fabric
{
public:
	Pizza* PreparePizza(string recipe)const override
	{
		return new GreecePizza(recipe);
	}
	Souce* PrepareSouce(string recipe)const override
	{
		return new GreeceSouce(recipe);
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 9)
	{
		system("cls");
		gotoxy(0);
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
			cout << endl;
		}
		cout << "1 - Prepare Milan pizza" << endl;
		cout << "2 - Prepare Milan souce" << endl;
		cout << "3 - Prepare Greece pizza" << endl;
		cout << "4 - Prepare Greece souce" << endl;
		cout << "5 - Show prepared Milan pizza" << endl;
		cout << "6 - Show prepared Milan souce" << endl;
		cout << "7 - Show prepared Greece pizza" << endl;
		cout << "8 - Show prepared Greece souce" << endl;
		cout << "9 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { MILAN_PIZZA = 1, MILAN_SOUCE, GREECE_PIZZA, GREECE_SOUCE, SHOW_MP, SHOW_MS, SHOW_GP, SHOW_GS, EXIT };
int main()
{
	FabricMilan fabricM;
	FabricGreece fabricG;
	string recipe;
	int choice = 0;
	bool isValidData = true;
	List listMP;
	List listMS;
	List listGP;
	List listGS;
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::MILAN_PIZZA:
			system("cls");
			gotoxy(0);
			while (choice < 1 || choice > 2)
			{
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "1 - Add to begin" << endl;
				cout << "2 - Add to end" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
			}
			isValidData = true;
			system("cls");
			gotoxy(0);
			cout << "Enter Milan pizza recipe : ";
			cin >> recipe;
			if (choice == 1)
				listMP.AddToHead(fabricM.PreparePizza(recipe));
			else if (choice == 2)
				listMP.AddToTail(fabricM.PreparePizza(recipe));
			choice = 0;
			break;
		case MENU::MILAN_SOUCE:
			system("cls");
			gotoxy(0);
			while (choice < 1 || choice > 2)
			{
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "1 - Add to begin" << endl;
				cout << "2 - Add to end" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
			}
			isValidData = true;
			system("cls");
			gotoxy(0);
			cout << "Enter Milan souce recipe : ";
			cin >> recipe;
			if (choice == 1)
				listMS.AddToHead(fabricM.PrepareSouce(recipe));
			else if (choice == 2)
				listMS.AddToTail(fabricM.PrepareSouce(recipe));
			choice = 0;
			break;
		case MENU::GREECE_PIZZA:
			system("cls");
			gotoxy(0);
			while (choice < 1 || choice > 2)
			{
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "1 - Add to begin" << endl;
				cout << "2 - Add to end" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
			}
			isValidData = true;
			system("cls");
			gotoxy(0);
			cout << "Enter Greece pizza recipe : ";
			cin >> recipe;
			if (choice == 1)
				listGP.AddToHead(fabricG.PreparePizza(recipe));
			else if (choice == 2)
				listGP.AddToTail(fabricG.PreparePizza(recipe));
			choice = 0;
			break;
		case MENU::GREECE_SOUCE:
			system("cls");
			gotoxy(0);
			while (choice < 1 || choice > 2)
			{
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "1 - Add to begin" << endl;
				cout << "2 - Add to end" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
			}
			isValidData = true;
			system("cls");
			gotoxy(0);
			cout << "Enter Greece souce recipe : ";
			cin >> recipe;
			if (choice == 1)
				listGS.AddToHead(fabricG.PrepareSouce(recipe));
			else if (choice == 2)
				listGS.AddToTail(fabricG.PrepareSouce(recipe));
			choice = 0;
			break;
		case MENU::SHOW_MP: listMP.Print(); break;
		case MENU::SHOW_MS: listMS.Print(); break;
		case MENU::SHOW_GP: listGP.Print(); break;
		case MENU::SHOW_GS: listGS.Print(); break;
		case MENU::EXIT: isExit = true;
		}
	}
	system("cls");
	gotoxy(0);
	cout << "Good bye." << endl;
}