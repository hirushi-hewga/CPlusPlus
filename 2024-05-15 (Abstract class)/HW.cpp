/*#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gotoxy(int p) {
	COORD coord;
	coord.X = p;
	coord.Y = p;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



class Animal
{
	string name;
	float weight;
	string place;
	int age;
public:
	Animal() :name("no name"), weight(0), place("no place"), age(0) {}
	Animal(string name, float weight, string place, int age) :name(name), place(place)
	{
		this->weight = weight > 0 ? weight : 0;
		this->age = age > 0 ? age : 0;
	}
	Animal(const Animal& other)
	{
		this->name = other.name;
		this->weight = other.weight;
		this->place = other.place;
		this->age = other.age;
	}
	void ShowInfo()const
	{
		cout << "Name:" << name << " | Weight:" << weight << " | Place:" << place << " | Age:" << age << endl;
	}
	int GetAge()const { return age; }
	void AppAge() { age++; }
};



class Fox : public Animal
{
public:
	Fox() : Animal() {}
	Fox(string name, float weight, string place, int age) : Animal(name, weight, place, age) {}
	Fox(const Fox& other) : Animal(other) {}
};



class Rabbit : public Animal
{
public:
	Rabbit() :Animal() {}
	Rabbit(string name, float weight, string place, int age) :Animal(name, weight, place, age) {}
	Rabbit(const Rabbit& other) : Animal(other) {}
};





class Plant
{
	string place;
public:
	Plant() : place("no place") {}
	Plant(string place) : place(place) {}
	Plant(const Plant& other)
	{
		this->place = other.place;
	}
	void ShowInfo()const
	{
		cout << "Place : " << place << endl;
	}
};



class Grass : public Plant
{
public:
	Grass() :Plant() {}
	Grass(string place) :Plant(place) {}
	Grass(const Grass& other) : Plant(other) {}
};





class Live
{
	Fox* fox;
	int foxCount;
	Rabbit* rabbit;
	int rabbitCount;
	Grass* grass;
	int grassCount;
public:
	Live() :fox(nullptr), rabbit(nullptr), grass(nullptr) {}


	void ReadChangesFromFile()const
	{
		system("cls");
		gotoxy(0);
		ifstream in("Changes.txt", ios_base::in);
		char change[50];
		while (!in.eof())
		{
			in.getline(change, 50, '|');
			if (in.eof()) break;
			cout << "- ";
			for (int i = 0; change[i] != '\0'; i++)
				cout << change[i];
			cout << endl;


			//char buffname[250], buffsurname[250], buffage[250];
			//in.getline(buffname, 250, ':');
			//if (in.eof())break;
			//in.getline(buffsurname, 250, ':');
			//in.getline(buffage, 250, '|');
			//int age = atoi(buffage);
			//Human readHuman;
			//readHuman.FillFromFile(buffname, buffsurname, age);
			//size++;
			//Human* temp = new Human[size];//1
			//for (int i = 0; i < size - 1; i++)
			//{
			//	temp[i].Copy(h[i]);
			//}
			//temp[size - 1] = readHuman;
			//delete h;
			//h = temp;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
	void SaveChangesToFile(const char* change)const
	{
		ofstream out("Changes.txt", ios_base::app);
		out << change;
		out << '|';
		out.close();
	}
	void ShowFox()const
	{
		system("cls");
		gotoxy(0);
		cout << "== Fox [ " << foxCount << " ] ==" << endl;
		for (int i = 0; i < foxCount; i++)
		{
			cout << "Fox_" << i + 1 << ": ";
			fox[i].ShowInfo();
		}
	}
	void IndexDeleteRabbit()
	{
		if (rabbit != nullptr)
		{
			int index = 0;
			bool isValidData = true;
			while (index < 1 || index > rabbitCount)
			{
				ShowFox();
				if (!isValidData)
				{
					cout << endl;
					cout << "Error choice! Try again." << endl;
				}
				else isValidData = false;
				cout << endl;
				cout << "Choice rabbit to delete ( 1";
				if (rabbitCount == 1) cout << " ) : ";
				else cout << "-" << rabbitCount << " ) : ";
				cin >> index;
			}
			DeleteRabbitByIndex(index);
			SaveChangesToFile("Deleted_rabbit");
		}
	}
	void ShowRabbit()const
	{
		system("cls");
		gotoxy(0);
		cout << "== Rabbit [ " << rabbitCount << " ] ==" << endl;
		for (int i = 0; i < rabbitCount; i++)
		{
			cout << "Rabbit_" << i + 1 << ": ";
			rabbit[i].ShowInfo();
		}
	}
	void DeleteFox()
	{
		if (fox != nullptr)
		{
			int index = 0;
			bool isValidData = true;
			while (index < 1 || index > foxCount)
			{
				ShowFox();
				if (!isValidData)
				{
					cout << endl;
					cout << "Error choice! Try again." << endl;
				}
				else isValidData = false;
				cout << endl;
				cout << "Choice fox to delete ( 1";
				if (foxCount == 1) cout << " ) : ";
				else cout << "-" << foxCount << " ) : ";
				cin >> index;
			}
			if (foxCount == 1)
			{
				delete[] fox;
				fox = nullptr;
				foxCount = 0;
			}
			else
			{
				Fox* temp = new Fox[--foxCount];
				for (int i = 0; i < index - 1; i++)
				{
					temp[i] = Fox(fox[i]);
				}
				for (int i = index - 1; i < foxCount; i++)
				{
					temp[i] = Fox(fox[i + 1]);
				}
				delete[] fox;
				fox = temp;
			}
			SaveChangesToFile("Deleted_fox");
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Fox not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void DeleteRabbit()
	{
		if (rabbit != nullptr)
		{
			if (rabbitCount == 1)
			{
				delete[] rabbit;
				rabbit = nullptr;
				rabbitCount = 0;
			}
			else
			{
				Rabbit* temp = new Rabbit[--rabbitCount];
				for (int i = 0; i < rabbitCount; i++)
				{
					temp[i] = Rabbit(rabbit[i]);
				}
				delete[] rabbit;
				rabbit = temp;
			}
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Rabbit not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void DeleteFoxByIndex(int index)
	{
		if (fox != nullptr)
		{
			if (foxCount == 1)
			{
				delete[] fox;
				fox = nullptr;
				foxCount = 0;
			}
			else
			{
				Fox* temp = new Fox[--foxCount];
				for (int i = 0; i < index; i++)
				{
					temp[i] = Fox(fox[i]);
				}
				for (int i = index; i < foxCount; i++)
				{
					temp[i] = Fox(fox[i + 1]);
				}
				delete[] fox;
				fox = temp;
			}
		}
	}
	void DeleteRabbitByIndex(int index)
	{
		if (rabbit != nullptr)
		{
			if (rabbitCount == 1)
			{
				delete[] rabbit;
				rabbit = nullptr;
				rabbitCount = 0;
			}
			else
			{
				Rabbit* temp = new Rabbit[--rabbitCount];
				for (int i = 0; i < index; i++)
				{
					temp[i] = Rabbit(rabbit[i]);
				}
				for (int i = index; i < rabbitCount; i++)
				{
					temp[i] = Rabbit(rabbit[i + 1]);
				}
				delete[] rabbit;
				rabbit = temp;
			}
		}
	}
	void Rules()
	{
		for (int i = 0; i < foxCount; i++)
		{
			fox[i].AppAge();
			if (fox[i].GetAge() > 8)
			{
				DeleteFoxByIndex(i);
				SaveChangesToFile("Death_of_fox");
			}
		}
		for (int i = 0; i < rabbitCount; i++)
		{
			rabbit[i].AppAge();
			if (rabbit[i].GetAge() > 8)
			{
				DeleteRabbitByIndex(i);
				SaveChangesToFile("Death_of_rabbit");
			}
		}
		if (grassCount > rabbitCount)
		{
			grassCount -= rabbitCount;
			Grass* temp = new Grass[grassCount];
			for (int i = 0; i < grassCount; i++)
			{
				temp[i] = Grass(grass[i]);
			}
			delete[] grass;
			grass = temp;
			if (rabbitCount != 0) SaveChangesToFile("Some_of_the_grass_is_eaten");
		}
		else if (grassCount != 0)
		{
			delete[] grass;
			grass = nullptr;
			grassCount = 0;
			SaveChangesToFile("All_the_grass_is_eaten");
		}
		if (rabbitCount < foxCount && rabbitCount != 0)
		{
			DeleteRabbit();
			SaveChangesToFile("Fox_ate_the_rabbit");
		}
	}
	void AddFox()
	{
		if (foxCount < 5)
		{
			Fox* temp = new Fox[foxCount + 1];
			for (int i = 0; i < foxCount; i++)
			{
				temp[i] = Fox(fox[i]);
			}
			temp[foxCount++] = Fox();
			delete[] fox;
			fox = temp;
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Fox count is max!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void AddRabbit()
	{
		Rabbit* temp = new Rabbit[rabbitCount + 1];
		for (int i = 0; i < rabbitCount; i++)
		{
			temp[i] = Rabbit(rabbit[i]);
		}
		temp[rabbitCount++] = Rabbit();
		delete[] rabbit;
		rabbit = temp;
	}
	void AddGrass()
	{
		Grass* temp = new Grass[grassCount + 1];
		for (int i = 0; i < grassCount; i++)
		{
			temp[i] = Grass(grass[i]);
		}
		temp[grassCount++] = Grass();
		delete[] grass;
		grass = temp;
	}
	void Show()const
	{
		system("cls");
		gotoxy(0);
		cout << "== Fox [ " << foxCount << " ] ==" << endl;
		for (int i = 0; i < foxCount; i++)
		{
			cout << "Fox_" << i + 1 << ": ";
			fox[i].ShowInfo();
		}
		cout << "== Rabbit [ " << rabbitCount << " ] ==" << endl;
		for (int i = 0; i < rabbitCount; i++)
		{
			cout << "Rabbit_" << i + 1 << ": ";
			rabbit[i].ShowInfo();
		}
		cout << "== Grass [ " << grassCount << " ] ==" << endl;
		for (int i = 0; i < grassCount; i++)
		{
			cout << "Grass_" << i + 1 << ": ";
			grass[i].ShowInfo();
		}
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}


	~Live()
	{
		if (fox != nullptr) delete[] fox;
		if (rabbit != nullptr) delete[] rabbit;
		if (grass != nullptr) delete[] grass;
	}
};




int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 7)
	{
		system("cls");
		gotoxy(0);
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
			cout << endl;
		}
		else isValidData = false;
		cout << "1 - Show info" << endl;
		cout << "2 - Add fox" << endl;
		cout << "3 - Add rabbit" << endl;
		cout << "4 - Add grass" << endl;
		cout << "5 - Delete fox" << endl;
		cout << "6 - Delete rabbit" << endl;
		cout << "7 - Show changes" << endl;
		cout << "8 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW = 1, ADD_FOX, ADD_RABBIT, ADD_GRASS, DELETE_FOX, DELETE_RABBIT, SHOW_CHANGES, EXIT };
*/
//int main()
//{
	/*
	remove("Changes.txt");
	Live live;
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::SHOW:
			live.Show();
			live.SaveChangesToFile("Reviewed_info");
			break;
		case MENU::ADD_FOX:
			live.AddFox();
			live.SaveChangesToFile("Added_fox");
			break;
		case MENU::ADD_RABBIT:
			live.AddRabbit();
			live.SaveChangesToFile("Added_rabbit");
			break;
		case MENU::ADD_GRASS:
			live.AddGrass();
			live.SaveChangesToFile("Added_grass");
			break;
		case MENU::DELETE_FOX: live.DeleteFox(); break;
		case MENU::DELETE_RABBIT: live.IndexDeleteRabbit(); break;
		case MENU::SHOW_CHANGES: live.ReadChangesFromFile(); break;
		case MENU::EXIT: isExit = true;
		}
		live.Rules();
	}
	system("cls");
	gotoxy(0);
	cout << "Good bye." << endl;
	*/
	//}