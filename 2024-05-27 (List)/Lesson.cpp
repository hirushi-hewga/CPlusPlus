#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

//struct Book
//{
//	string name;
//	string author;
//	int pages;
//};
//bool CompareByName(const Book& b1, const Book& b2)
//{
//	return b1.name < b2.name;
//}
//bool CompareByAuthor(const Book& b1, const Book& b2)
//{
//	return b1.author < b2.author;
//}
//bool CompareByPages(const Book& b1, const Book& b2)
//{
//	return b1.pages < b2.pages;
//}
//
//
//
//void Print(list<int> l1, list<int> l2)
//{
//	cout << "List 1 : ";
//	list<int>::iterator it;
//	for (it = l1.begin(); it != l1.end(); it++)
//	{
//		cout << *it << ' ';
//	}
//	cout << endl;
//	cout << "List 2 : ";
//	for (auto it = l2.begin(); it != l2.end(); it++)
//	{
//		cout << *it << ' ';
//	}
//	cout << endl;
//}

//int main()
//{
	/*
	list<Book> library;

	library.assign(
		{
			Book{ "Night", "Gogol", 786 },
			Book{ "Maria", "Kotliarevskuy", 400 },
			Book{ "Kobzar", "Shevchenko", 1000 }
		});


	cout << "-------- Original colection --------" << endl;
	for (Book book : library)
	{
		cout << left << setw(9) << book.name << setw(17) << book.author << setw(7) << book.pages << endl;
	}

	library.sort(CompareByName);
	cout << "-------- Sort by name --------" << endl;
	for (Book book : library)
	{
		cout << left << setw(9) << book.name << setw(17) << book.author << setw(7) << book.pages << endl;
	}

	library.sort(CompareByAuthor);
	cout << "-------- Sort by author --------" << endl;
	for (Book book : library)
	{
		cout << left << setw(9) << book.name << setw(17) << book.author << setw(7) << book.pages << endl;
	}

	library.sort(CompareByPages);
	cout << "-------- Sort by pages --------" << endl;
	for (Book book : library)
	{
		cout << left << setw(9) << book.name << setw(17) << book.author << setw(7) << book.pages << endl;
	}
	*/




	/*
	list<int> list1, list2;
	for (int i = 0; i < 6; i++)
	{
		list1.push_back(i);
		list2.push_front(i);
	}
	Print(list1, list2);

	list1.assign({ 11, 12, 13, 14, 15, 16, 17, 2, 2, 2, 2, 2 });
	Print(list1, list2);

	auto it = list1.begin();
	it++;
	it++;
	it++;
	list1.erase(it);
	list1.erase(++list1.begin());
	Print(list1, list2);

	list1.remove(2);
	Print(list1, list2);

	list1.insert(list1.begin(), 5, 1);
	Print(list1, list2);
	list1.insert(list1.begin(), 100);
	Print(list1, list2);
	list1.insert(list1.begin(), { 7, 8, 9, 10, 11 });
	Print(list1, list2);
	list1.insert(list1.begin(), list2.begin(), list2.end());
	Print(list1, list2);

	// list1.resize(30);
	list1.resize(30, 44);
	Print(list1, list2);

	list1.splice(list1.end(), list2, list2.begin());
	Print(list1, list2);

	cout << "Size : " << list1.size() << endl;

	list1.reverse();
	Print(list1, list2);

	list1.sort();
	list2.sort();
	Print(list1, list2);

	list1.merge(list2);
	Print(list1, list2);

	list1.unique();
	Print(list1, list2);

	list1.swap(list2);
	Print(list1, list2);
	*/
	//}