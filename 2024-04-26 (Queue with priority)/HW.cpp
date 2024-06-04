//#include <iostream>
//using namespace std;

/*

class Queue
{
public:
	struct Document
	{
		string name;
		int priority;
	};

private:
	Document* docs;
	int size;

public:
	Queue():docs(nullptr),size(0) {}


	void Enqueue(string name, int pr)
	{
		int index = 0;
		while (index < size && docs[index].priority < pr)
		{
			index++;
		}
		Document* temp = new Document[size + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = docs[i];
		}
		temp[index] = Document{ name, pr };
		for (int i = index + 1; i <= size; i++)
		{
			temp[i] = docs[i - 1];
		}
		if (docs != nullptr)
			delete[] docs;
		docs = temp;
		size++;
	}
	bool IsEmpty()
	{
		return size == 0;
	}
	void Print()
	{
		if (!IsEmpty())
		{
			cout << "========================" << endl;
			cout << "Max priority document ( " << docs[size - 1].name << ':';
			switch (docs[size - 1].priority)
			{
			case 1: cout << "Guest )" << endl; break;
			case 2: cout << "Admin )" << endl; break;
			case 3: cout << "Manager )" << endl; break;
			case 4: cout << "Director )" << endl;
			}
			cout << "========================" << endl;
		}
	}


	~Queue()
	{
		if (docs != nullptr)
			delete[] docs;
	}
};



void AddDoc(Queue& q)
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 4)
	{
		if (!isValidData)
		{
			cout << endl;
			cout << "Error choice. Try again!" << endl;
			cout << endl;
		}
		isValidData = false;
		cout << "1 - Guest priority" << endl;
		cout << "2 - Admin priority" << endl;
		cout << "3 - Manager priority" << endl;
		cout << "4 - Director priority" << endl;
		cout << "Chioce document priority (1 - 4) : ";
		cin >> choice;
	}
	string name;
	cout << "Enter file name : ";
	cin >> name;
	q.Enqueue(name, choice);
}
int Menu()
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
		cout << "1 - Add to queue" << endl;
		cout << "2 - Print" << endl;
		cout << "3 - Exit" << endl;
		cout << "Enter your choice (1 - 3) : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { ADD = 1, PRINT, EXIT };

*/

//int main()
//{
	/*
	Queue q;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::ADD: AddDoc(q); break;
		case MENU::PRINT: q.Print(); break;
		case MENU::EXIT: isExit = true;
		}
		cout << "========================" << endl;
	}
	cout << endl;
	cout << "Good bye." << endl;
	*/
	//}