#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

enum MENU { CHANGE = 1, SHOW, SEARCHA, SEARCHT, SEARCHP, SEARCHG, ADD, SAVE, LOAD };

struct Book
{
private:
	int id;
	char title[50];
	char author[50];
	char publisher[50];
	char genre[50];
	int yearOfPublication;
	int price;
public:
	void Show(Book* b, int size)
	{
		int tmax = 0, amax = 0, pmax = 0, gmax = 0;
		for (int i = 0; i < size; i++) if (strlen(b[i].title) > tmax) tmax = strlen(b[i].title);
		for (int i = 0; i < size; i++) if (strlen(b[i].author) > amax) amax = strlen(b[i].author);
		for (int i = 0; i < size; i++) if (strlen(b[i].publisher) > pmax) pmax = strlen(b[i].publisher);
		for (int i = 0; i < size; i++) if (strlen(b[i].genre) > gmax) gmax = strlen(b[i].genre);
		cout << "Id : " << left << setw(3) << id;
		cout << " ,  Title : " << left << setw(tmax) << title;
		cout << " ,  Author : " << left << setw(amax) << author;
		cout << " ,  Publisher : " << left << setw(pmax) << publisher;
		cout << " ,  Genre : " << left << setw(gmax) << genre;
		cout << " ,  Year of publication : " << yearOfPublication;
		cout << " ,  price : " << price << endl;
	}
	void Fill()
	{
		cout << "Enter id : "; cin >> id;
		cin.ignore();
		cout << "Enter title : "; cin.getline(title, 50);
		cout << "Enter author : "; cin.getline(author, 50);
		cout << "Enter publisher : "; cin.getline(publisher, 50);
		cout << "Enter genre : "; cin.getline(genre, 50);
		cout << "Enter year of publication : "; cin >> yearOfPublication;
		cout << "Enter price : "; cin >> price;
	}
	void Copy(Book b)
	{
		id = b.id;
		strcpy_s(title, strlen(b.title) + 1, b.title);
		strcpy_s(author, strlen(b.author) + 1, b.author);
		strcpy_s(publisher, strlen(b.publisher) + 1, b.publisher);
		strcpy_s(genre, strlen(b.genre) + 1, b.genre);
		yearOfPublication = b.yearOfPublication;
		price = b.price;
	}
	void FillFromFile(int idB, char* titleB, char* authorB, char* publisherB, char* genreB, int yearOfPublicationB, int priceB)
	{
		id = idB;
		strcpy_s(title, strlen(titleB) + 1, titleB);
		strcpy_s(author, strlen(authorB) + 1, authorB);
		strcpy_s(publisher, strlen(publisherB) + 1, publisherB);
		strcpy_s(genre, strlen(genreB) + 1, genreB);
		yearOfPublication = yearOfPublicationB;
		price = priceB;
	}
	void SaveToFile()
	{
		//ios_base::in		: Open file for reading.
		//ios_base::out		: Open file for writing.
		//ios_base::app		: Append to the end of the file.
		//ios_base::ate		: Set the position of the file pointer to the end of the file after opening.
		//ios_base::trunc	: Open file for writing, truncating the contents of the file to zero length.
		//ios_base::binary	: Open file in binary mode.

		//(ios_base::in | ios_base::out) : Open file for reading and writing.

		//ofstream out(Filename, ios_base::app);
		ofstream out("Library.txt", ios_base::app);
		out << id;
		out << ":";
		out << title;
		out << ":";
		out << author;
		out << ":";
		out << publisher;
		out << ":";
		out << genre;
		out << ":";
		out << yearOfPublication;
		out << ":";
		out << price;
		out << "|";
		out.close();
	}
	bool IdEqual(int id)
	{
		if (this->id == id) return true;
		return false;
	}
	bool SearchAuthor(char author[50])
	{
		if (strcmp(this->author, author) == 0) return true;
		else return false;
	}
	bool SearchTitle(char title[50])
	{
		if (strcmp(this->title, title) == 0) return true;
		else return false;
	}
	bool SearchPublisher(char publisher[50])
	{
		if (strcmp(this->publisher, publisher) == 0) return true;
		else return false;
	}
	bool SearchGenre(char genre[50])
	{
		if (strcmp(this->genre, genre) == 0) return true;
		else return false;
	}
};




int Menu()
{
	int choice;
	cout << "1 - change data" << endl;
	cout << "2 - show data" << endl;
	cout << "3 - search by author" << endl;
	cout << "4 - search by title" << endl;
	cout << "5 - search by publisher" << endl;
	cout << "6 - search by genre" << endl;
	cout << "7 - add new book" << endl;
	cout << "8 - save to file" << endl;
	cout << "9 - load from file" << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	cout << endl;
	return choice;
}

void AddBook(Book*& b, int& size)
{
	size++;
	Book* temp = new Book[size];//1
	for (int i = 0; i < size - 1; i++)
	{
		temp[i].Copy(b[i]);
	}
	temp[size - 1].Fill();
	delete b;
	b = temp;
	//b[size - 1].SaveToFile();
}

void ReadFromFile(Book*& h, int& size)
{
	ifstream in("Library.txt", ios_base::in);
	while (!in.eof())
	{
		char buffId[250], buffTitle[250], buffAuthor[250], buffPublisher[250], buffGenre[250], buffYearOfPublication[250], buffPrice[250];
		in.getline(buffId, 250, ':');
		if (in.eof())break;
		in.getline(buffTitle, 250, ':');
		in.getline(buffAuthor, 250, ':');
		in.getline(buffPublisher, 250, ':');
		in.getline(buffGenre, 250, ':');
		in.getline(buffYearOfPublication, 250, ':');
		in.getline(buffPrice, 250, '|');
		int id = atoi(buffId);
		int yearOfPublication = atoi(buffYearOfPublication);
		int price = atoi(buffPrice);
		Book readBook;
		readBook.FillFromFile(id, buffTitle, buffAuthor, buffPublisher, buffGenre, yearOfPublication, price);
		size++;
		Book* temp = new Book[size];//1
		for (int i = 0; i < size - 1; i++)
		{
			temp[i].Copy(h[i]);
		}
		temp[size - 1] = readBook;
		delete h;
		h = temp;
	}
}

void ChangeBook(Book*& b, int size)
{
	int id;
	for (int i = 0; i < size; i++) b[i].Show(b, size);
	cout << "Enter book id to change data : ";
	cin >> id;
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (b[i].IdEqual(id)) index = i; break;
	}
	Book* temp = new Book[size];
	for (int i = 0; i < index; i++)
	{
		temp[i].Copy(b[i]);
	}
	temp[index].Fill();
	for (int i = index + 1; i < size; i++)
	{
		temp[i].Copy(b[i]);
	}
	delete[] b;
	b = temp;
}

void SearchByAuthor(Book* b, int size)
{
	char author[50];
	cout << "Enter author : ";
	cin.getline(author, 50);
	for (int i = 0; i < size; i++)
	{
		if (b[i].SearchAuthor(author)) b[i].Show(b, size); break;
	}
}

void SearchByTitle(Book* b, int size)
{
	char title[50];
	cout << "Enter title : ";
	cin.getline(title, 50);
	for (int i = 0; i < size; i++)
	{
		if (b[i].SearchTitle(title)) b[i].Show(b, size); break;
	}
}

void SearchByPublisher(Book* b, int size)
{
	char publisher[50];
	cout << "Enter publisher : ";
	cin.getline(publisher, 50);
	for (int i = 0; i < size; i++)
	{
		if (b[i].SearchPublisher(publisher)) b[i].Show(b, size); break;
	}
}

void SearchByGenre(Book* b, int size)
{
	char genre[50];
	cout << "Enter genre : ";
	cin.getline(genre, 50);
	for (int i = 0; i < size; i++)
	{
		if (b[i].SearchGenre(genre)) b[i].Show(b, size); break;
	}
}




int main()// Book not found!
{
	int size = 0;
	Book* Library = new Book[size];

	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::CHANGE: ChangeBook(Library, size); break;
		case MENU::SHOW: for (int i = 0; i < size; i++) (*(Library + i)).Show(Library, size); break;
		case MENU::SEARCHA: SearchByAuthor(Library, size); break;
		case MENU::SEARCHT: SearchByTitle(Library, size); break;
		case MENU::SEARCHP: SearchByPublisher(Library, size); break;
		case MENU::SEARCHG: SearchByGenre(Library, size); break;
		case MENU::ADD: AddBook(Library, size); break;
		case MENU::SAVE: for (int i = 0; i < size; i++) (*(Library + i)).SaveToFile(); break;
		case MENU::LOAD: ReadFromFile(Library, size);
		}
		cout << endl;
	}
	cout << "Good bye" << endl;

	delete[] Library;
}