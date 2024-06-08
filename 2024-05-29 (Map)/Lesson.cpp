#include <Windows.h>
#include <iostream>
#include <list>
#include <map>
using namespace std;

struct ID
{
	int id;
	string name;
	ID() : id(0), name("no name") {}
	ID(int id, string name) : id(id), name(name) {}

	void Show()const
	{
		cout << "ID : " << id << " | Name : " << name << endl;
	}
	bool operator <(const ID& other)const
	{
		return this->name < other.name;
	}
};

class Dictionary
{
	string name;
	map<string, list<string>> dic;
public:
	Dictionary(string name) : name(name)
	{
		dic.insert(make_pair("word", list<string>({ "slovo" })));
		dic.insert(make_pair("mind", list<string>({ "dumka", "dusha", "spohad" })));
		dic.insert(make_pair("bad", list<string>({ "poganiy", "borg" })));
	}

	void Print()const
	{
		cout << "Dictionary name : " << name << endl;
		for (auto pair : dic)
		{
			cout << "Word : " << pair.first << " - ";
			for (string word : pair.second)
			{
				cout << word << " , ";
			}
			cout << endl;
		}
	}
};



//map<string, int>::iterator FindByValue(map<string, int>& clients, int value)
//{
//	for (map<string, int>::iterator i = clients.begin(); i != clients.end(); i++)
//	{
//		if (i->second == value)
//		{
//			return i;
//		}
//	}
//	return clients.end();
//}

//int main()
//{
	/*
	Dictionary dictionary("English-Ukrainian");
	dictionary.Print();

	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	map<string, list<string>> dic;
	string word = "run";
	list<string> meanings = { "bigty", "pochaty", "zapochatkuvaty" };

	dic.insert(make_pair(word, meanings));
	dic.insert(make_pair("word", list<string>({ "slovo" })));
	dic.insert(make_pair("mind", list<string>({ "dumka", "dusha", "spohad" })));
	dic.insert(make_pair("bad", list<string>({ "poganiy", "borg" })));

	for (auto item : dic["bad"])
	{
		cout << item << " ";
	}
	*/





	/*
	map<ID, int> m;
	ID id1(1, "Taras");
	pair<ID, int> p(id1, 15000);
	m.insert(p);

	m.insert(make_pair(ID(2, "Olga"), 25000));
	m.insert(make_pair(ID(3, "Anna"), 12000));
	m.insert(make_pair(ID(7, "Vasia"), 7350));
	m[ID(8, "Anna")] = 38000;

	for (auto i : m)
	{
		i.first.Show();
		cout << "Value : " << i.second << endl;
		cout << "_________________________________" << endl;
	}
	*/




	/*
	map<int, string> mymap;

	map<string, int> clients;

	pair<string, int> p("Olga", 5);
	clients.insert(p);

	clients.insert(pair<string, int>("Mykola", 2));

	clients.insert(make_pair("Oleg", 7));

	for (auto item : clients)
	{
		cout << "Key : " << item.first << " | Value : " << item.second << endl;
	}

	//auto res = clients.insert(make_pair("Olga", 9));
	pair<map<string, int>::iterator, bool> res = clients.insert(make_pair("Olga", 9));

	if (res.second)
	{
		cout << "Added!!!!" << endl;
	}
	else
	{
		cout << "Not Added!!!!" << endl;
	}

	cout << "-------------------------------------" << endl;

	for (auto item : clients)
	{
		cout << "Key : " << item.first << " | Value : " << item.second << endl;
	}

	cout << "Value Olga : " << clients["Olga"] << endl;
	cout << "Value Mykola : " << clients["Mykola"] << endl;


	map<string, int>::iterator it = clients.find("Oleg");
	if (it == clients.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Found !!!" << endl;
		cout << "Key : " << it->first << " | Value : " << it->second << endl;
		it->second = 1000;
		cout << "Key : " << it->first << " | Value : " << it->second << endl;
	}

	it = FindByValue(clients, 1000);
	if (it != clients.end())
	{
		cout << "Key : " << it->first << " | Value : " << it->second << endl;
	}

	if (it != clients.end())
	{
		clients.erase(it);
	}

	cout << "-------------------------------------" << endl;
	for (auto item : clients)
	{
		cout << "Key : " << item.first << " | Value : " << item.second << endl;
	}

	cout << "Value Olga : " << clients["Olga"] << endl;
	clients["Olga"] = 100500;
	clients["Muroslava"] = 55;
	for (auto item : clients)
	{
		cout << "Key : " << item.first << " | Value : " << item.second << endl;
	}
	*/
	//}