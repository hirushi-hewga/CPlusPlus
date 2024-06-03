#include "Book.h"

Book::Book()
{
	title = "no title";
	year = 1;
	author = "no author";
	pages = 0;
	genre = NONE;
}

void Book::ShowInfo()const
{
	cout << "Title : " << title << endl;
	cout << "Year : " << year << endl;
	cout << "Author : " << author << endl;
	cout << "Pages : " << pages << endl;
	cout << "Genge : ";
	switch (genre)
	{
	case NONE:				cout << "None" << endl;				break;
	case HISTORY:			cout << "History" << endl;			break;
	case FANTASY:			cout << "Fantasy" << endl;			break;
	case DRAMA:				cout << "Drama" << endl;			break;
	case ROMAN:				cout << "Roman" << endl;			break;
	case COMEDY:			cout << "Comedy" << endl;			break;
	case PROGRAMMING:		cout << "Programming" << endl;		break;
	case POLITICAL:			cout << "Political" << endl;		break;
	case SCIENCE_FICTION:	cout << "Science fiction" << endl;
	}
}