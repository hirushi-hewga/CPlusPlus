/*
#include <iostream>
#include <fstream>
using namespace std;

struct Movie
{
	int id;
	char name[50];
	char director[50];
	char genre[50];
	float rating;
	float price;
	int View;
};

void Show(Movie m)
{
	cout << "\t\tName : " << m.name << endl;
	cout << "\t\tDirector : " << m.director << endl;
	cout << "\t\tGenre : " << m.genre << endl;
	cout << "\t\tRating : " << m.rating << endl;
	cout << "\t\tPrice : " << m.price << "$" << endl;
	cout << "\t\tView : " << m.View << endl;
	cout << endl;
}
void SearchByName(Movie m[], int size, char name[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].name, name) == 0) {
			Show(m[i]);
		}
	}
}
void SearchByGenre(Movie m[], int size, char genre[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].genre, genre) == 0) {
			Show(m[i]);
		}
	}
}
void SearchByDirector(Movie m[], int size, char director[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].director, director) == 0) {
			Show(m[i]);
		}
	}
}
void MostPopularFilm(Movie m[], int size, char genre[])
{
	int max = 0;
	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].genre, genre) == 0)
		{
			if (m[i].View > max)
			{
				max = m[i].View;
				maxIndex = i;
			}
		}
	}
	Show(m[maxIndex]);
}
void ChangeInfo(Movie m[], int size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if (m[i].id == id)
		{
			Show(m[i]);
			cin.ignore();
			cout << " Name : ";
			cin.getline(m[i].name, 50);
			cout << " Genre : ";
			cin.getline(m[i].genre, 50);
			cout << " Director : ";
			cin.getline(m[i].director, 50);
			cout << " Rating : ";
			cin >> m[i].rating;
			cout << " Price : ";
			cin >> m[i].price;
			cout << " View : ";
			cin >> m[i].View;
		}
	}

}
//const char* Filename = "D://MyHumanData.txt";

struct Human//public
{
private:
	char name[50];
	char surname[50];
	int age;
public:
	void Fill()
	{
		cout << "Enter name : ";
		cin >> name;
		cout << "Enter surname : ";
		cin >> surname;
		cout << "Enter age : ";
		cin >> age;
	}
	void Show()
	{
		cout << "Name : " << name << " Surname : " << surname << " Age : " << age << endl;
	}
	void Copy(Human h)
	{
		strcpy_s(name, strlen(h.name) + 1, h.name);
		strcpy_s(surname, strlen(h.surname) + 1, h.surname);
		age = h.age;
	}
	void FillFromFile(char* nameB, char* surnameB, int ageB)
	{
		strcpy_s(name, strlen(nameB) + 1, nameB);
		strcpy_s(surname, strlen(surnameB) + 1, surnameB);
		age = ageB;
	}
	void SaveToFile()
	{
		//ofstream out(Filename, ios_base::app);
		ofstream out("Humans.txt", ios_base::app);
		out << name;
		out << ":";
		out << surname;
		out << ":";
		out << age;
		out << "|";
		out.close();
	}
};
enum Menu { ADD = 1, SHOW, READ, EXIT };
int Menu()
{
	int choice;
	cout << "1. Add person " << endl;
	cout << "2. Show all person " << endl;
	cout << "3. Read from file all person " << endl;
	cout << "4. Exit " << endl;
	cin >> choice;
	return choice;
}
void AddHuman(Human*& h, int& size)
{
	size++;
	Human* temp = new Human[size];//1
	for (int i = 0; i < size - 1; i++)
	{
		temp[i].Copy(h[i]);
	}
	temp[size - 1].Fill();
	delete h;
	h = temp;
	h[size - 1].SaveToFile();
}
void ShowAll(Human* h, int size)
{
	for (int i = 0; i < size; i++)
	{
		h[i].Show();
	}
}
void ReadFromFile(Human*& h, int& size)
{
	ifstream in("Humans.txt", ios_base::in);
	while (!in.eof())
	{
		char buffname[250], buffsurname[250], buffage[250];
		in.getline(buffname, 250, ':');
		if (in.eof())break;
		in.getline(buffsurname, 250, ':');
		in.getline(buffage, 250, '|');
		int age = atoi(buffage);
		Human readHuman;
		readHuman.FillFromFile(buffname, buffsurname, age);
		size++;
		Human* temp = new Human[size];//1
		for (int i = 0; i < size - 1; i++)
		{
			temp[i].Copy(h[i]);
		}
		temp[size - 1] = readHuman;
		delete h;
		h = temp;
	}
}
*/
//int main()
//{
	/*Human h{};
	h.Fill();
	h.Show();*/
	/*
	bool isExit = false;
	int size = 0;
	Human* humans = new Human[size];
	while (!isExit)
	{
		switch (Menu())
		{
		case Menu::ADD: AddHuman(humans, size); break;
		case Menu::SHOW: ShowAll(humans, size); break;
		case Menu::EXIT:isExit = true; break;
		case Menu::READ:ReadFromFile(humans, size); break;
		}
	}
	delete[]humans;
	*/




	/*
	const int size = 5;
	Movie movies[size]{
		{1,"Harry Potter", "Alfonso Cuaron", "Fantasy",3.72,150.49,250},
		{2,"Spider-Man", "Sam Raine", "Fantasy",4.5,100,30},
		{3,"Rambo", "Ted", "Detective",3.2,78.55,5},
		{4,"Venom", "Ruben ", "Action",4.3,170.33,145},
		{5,"The hungers games", "Gary Ross", "Fantasy",4.8,190.36,200}
	};
	int choice;
	char name[50];
	do
	{
		cout << "\t\tMenu" << endl;
		cout << "\tSearch by name             [1]" << endl;
		cout << "\tSearch by genre            [2]" << endl;
		cout << "\tSearch by director         [3]" << endl;
		cout << "\tThe most popular movie     [4]" << endl;
		cout << "\tShow all                   [5]" << endl;
		cout << "\tChange info                [6]" << endl;
		cout << "\tExit                       [0]" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			cout << "Enter name of movie : ";
			cin.getline(name,50);//cin >> name;
			SearchByName(movies, size, name);
			break;
		case 2:
			cout << "Enter genre of movie : ";
			cin.getline(name, 50);
			SearchByGenre(movies, size, name);
			break;
		case 3:
			cout << "Enter director of movie : ";
			cin.getline(name, 50);
			SearchByDirector(movies, size, name);
			break;
		case 4:
			cout << "Enter genre of movie : ";
			cin.getline(name, 50);
			MostPopularFilm(movies, size, name);
			break;
		case 5:
			for (int i = 0; i < size; i++)
			{
				Show(movies[i]);
			}
			break;
		case 6:
			int id;
			cout << "Enter id of movie : ";
			cin >> id;
			ChangeInfo(movies, size, id);
			break;
		case 0:
			cout << "Goodbye. Have a nice day!!!" << endl;break;
		default:
			cout << "Error choice " << endl;break;
		}

	} while (choice != 0);
	*/
	//}