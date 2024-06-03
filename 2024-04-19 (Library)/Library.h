#pragma once
#include "Book.h"

class Library
{
	string address; // "Rivne"
	Book* books; // 128589dfsdf
	int countBooks; // 4
public:
	Library();
	Library(string address);
	Library(const Library& other);
	Library operator =(const Library& other);
	Library(Library&& other);
	void Show()const;
	void AddBook(Book book);
	~Library();
};