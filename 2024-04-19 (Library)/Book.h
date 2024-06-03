#pragma once
#include <iostream>
using namespace std;

enum GENRE { NONE, HISTORY, FANTASY, DRAMA, ROMAN, COMEDY, PROGRAMMING, POLITICAL, SCIENCE_FICTION };
class Book
{
	string title;
	int year;
	string author;
	int pages;
	GENRE genre;
public:
	Book();
	Book(string t, int y, string a, int p, GENRE g) :title(t), year(y), author(a), pages(p), genre(g) {}
	void ShowInfo()const;
};