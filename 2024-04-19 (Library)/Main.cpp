#include "Library.h"

Library ShowLibrary(Library& lib) // copy constructor
{
	Library temp; // default constructor
	temp = lib; // operator =
	return temp;
} // copy constructor

int main()
{
	Book b;
	Book b1("C++ for beginners", 2022, "Stiven Prata", 1500, GENRE::PROGRAMMING);
	b1.ShowInfo();

	Library lib("Rivne, Kyivska 16");
	lib.AddBook(b1);
	lib.AddBook(Book("CHarry Potter", 2018, "Rowling", 800, GENRE::FANTASY));
	lib.AddBook(Book("Maria", 1980, "Kotliarevskyi", 300, GENRE::HISTORY));
	lib.AddBook(Book("The Lord of the Rings", 2019, "Jonh Ronald", 450, GENRE::FANTASY));

	lib.Show();

	ShowLibrary(lib);


	Library copy(lib); // copy constructor
	Library newLib = copy; // operator =
	newLib = lib; // operator =
}