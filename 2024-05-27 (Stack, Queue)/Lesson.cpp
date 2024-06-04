#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class User
{
	string name;
	int rating;

	friend ostream& operator <<(ostream& os, const User& user);
public:
	User(string n, int r) : name(n), rating(r) {}
	bool operator <(const User& other)const
	{
		return this->rating < other.rating;
	}
};
ostream& operator <<(ostream& os, const User& user)
{
	os << "Name : " << user.name << " | Rating : " << string(user.rating, '*');
	return os;
}



int main()
{
	// Stack

	stack<string> plates;
	plates.push("Plate 1");
	plates.push("Plate 2");
	plates.push("Plate 3");

	stack<string> articles;
	articles.push("Article 1");
	articles.push("Article 2");

	articles.swap(plates);

	while (!plates.empty())
	{
		cout << plates.top() << endl;
		plates.pop();
	}
	while (!articles.empty())
	{
		cout << articles.top() << endl;
		articles.pop();
	}


	// Queue

	queue<string> clients;
	clients.push("Vitia");
	clients.push("Kolya");
	clients.push("Sofia");
	clients.push("Oksana");
	clients.push("Petro");

	cout << "First client : " << clients.front() << endl;
	cout << "Last client : " << clients.back() << endl;

	while (!clients.empty())
	{
		cout << "Client : " << clients.front() << endl;
		clients.pop();
	}


	// Queue with priority

	priority_queue<string> workers;

	workers.push("Vitia");
	workers.push("Kolya");
	workers.push("Sofia");
	workers.push("Oksana");
	workers.push("Petro");

	cout << "First : " << workers.top() << endl;

	while (!workers.empty())
	{
		cout << "User : " << workers.top() << endl;
		workers.pop();
	}


	priority_queue<User> users;

	users.push(User("Vitia", 5));
	users.push(User("Kolya", 1));
	users.push(User("Sofia", 1));
	users.push(User("Oksana", 3));
	users.push(User("Petro", 4));

	cout << "First : " << users.top() << endl;

	while (!users.empty())
	{
		cout << "User :  " << users.top() << endl;
		users.pop();
	}


	// Dequeue

	deque<int> deck;

	deck.push_back(10);
	deck.push_back(20);
	deck.push_front(1);
	deck.push_front(2);

	while (!deck.empty())
	{
		cout << "First : " << deck.front() << endl;
		deck.pop_front();
	}
}