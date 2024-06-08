#include <conio.h>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Dictionary
{
	string name;
	map<string, list<string>> dic;
public:
	Dictionary(string name) : name(name) {}

	void Print()const
	{
		system("cls");
		cout << "-------- Dictionary : " << name << " --------" << endl;
		for (auto pair : dic)
		{
			cout << "Word : " << pair.first << " - ";
			for (string word : pair.second)
			{
				cout << word << ", ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddTranslate()
	{
		bool isValidData = true;
		string word;
		while (dic.find(word) == dic.end())
		{
			system("cls");
			for (auto pair : dic)
			{
				cout << "- " << pair.first << endl;
			}
			if (!isValidData) cout << "\nWord not found! Try again.\n";
			isValidData = true;
			cout << endl;
			cout << "Enter word : ";
			getline(cin, word);
		}

		system("cls");
		string translate = "";
		do
		{
			cout << "Enter translate : ";
			getline(cin, translate);
			if (translate.empty())
				break;
			dic[word].push_back(translate);
		} while (true);
	}
	void AddWord()
	{
		string word, translate;
		system("cls");
		cout << "Enter new word : ";
		cin >> word;
		cout << "Enter translate : ";
		cin >> translate;
		dic.insert(make_pair(word, list<string>{translate}));
	}
	void ShowByWord()const
	{
		bool isValidData = true;
		string word;
		while (dic.find(word) == dic.end())
		{
			system("cls");
			for (auto pair : dic)
			{
				cout << "- " << pair.first << endl;
			}
			if (!isValidData) cout << "\nWord not found! Try again.\n";
			isValidData = true;
			cout << endl;
			cout << "Enter word : ";
			getline(cin, word);
		}

		system("cls");
		cout << "==== Word : " << dic.find(word)->first << "====" << endl;
		for (string word : dic.find(word)->second)
		{
			cout << "- " << word << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void DeleteWord()
	{
		bool isValidData = true;
		string word;
		while (dic.find(word) == dic.end())
		{
			system("cls");
			for (auto pair : dic)
			{
				cout << "- " << pair.first << endl;
			}
			if (!isValidData) cout << "\nWord not found! Try again.\n";
			isValidData = true;
			cout << endl;
			cout << "Enter word : ";
			getline(cin, word);
		}

		dic.erase(word);
	}
	void SaveToFile()const
	{
		ofstream out("Dictionary.txt", ios_base::out);
		out << name << endl;
		for (auto pair : dic)
		{
			out << pair.first << endl;
			for (string word : pair.second)
			{
				out << word;
				out << endl;
			}
			out << '|';
			out << endl;
		}
		out.close();
	}
	void LoadFromFile()
	{
		ifstream in("Dictionary.txt", ios_base::in);
		if (!in.is_open())
		{
			system("cls");
			cout << "Failed to open file!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			_getch();
		}
		else
		{
			dic.clear();
			getline(in, name);
			string word, translate;
			while (!in.eof())
			{
				getline(in, word);
				if (in.eof())
					break;
				getline(in, translate);
				dic.insert(make_pair(word, list<string>{translate}));
				while (true)
				{
					getline(in, translate);
					if (translate == "|")
						break;
					dic[word].push_back(translate);
				}
			}
		}
		in.close();
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 8)
	{
		system("cls");
		cout << "1 - Add word" << endl;
		cout << "2 - Find the word" << endl;
		cout << "3 - Add translation" << endl;
		cout << "4 - Delete word" << endl;
		cout << "5 - Show all words" << endl;
		cout << "6 - Save to file" << endl;
		cout << "7 - Load from file" << endl;
		cout << "8 - Exit" << endl;
		if (!isValidData) cout << "\nError choice! Try again\n";
		isValidData = false;
		cout << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { ADD_PAIR = 1, SEARCH_BY_WORD, ADD_TRANSLATE, DELETE_WORD, SHOW, SAVE, LOAD, EXIT };
int main()
{
	Dictionary dictionary("English-Ukrainian");
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case ADD_PAIR: dictionary.AddWord(); break;
		case SEARCH_BY_WORD: dictionary.ShowByWord(); break;
		case ADD_TRANSLATE: dictionary.AddTranslate(); break;
		case DELETE_WORD: dictionary.DeleteWord(); break;
		case SHOW: dictionary.Print(); break;
		case SAVE: dictionary.SaveToFile(); break;
		case LOAD: dictionary.LoadFromFile(); break;
		case EXIT: isExit = true;
		}
	}
}