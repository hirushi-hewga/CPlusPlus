#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <list>
using namespace std;

struct Time
{
	int hours;
	int minutes;
};

struct Date
{
	int years;
	int months;
	int days;
	Time time;
	friend ostream& operator <<(ostream& out, const Date& other);
};
ostream& operator <<(ostream& out, const Date& other)
{
	out << other.days << '.' << other.months << '.' << other.years << " | " << other.time.hours << ':' << other.time.minutes << endl;
	return out;
}

struct Ticket
{
	string ticket_number;
	Date date_mail_sent;
	string order_address;
	string service;
	int mail_weight;
	int cost_of_service;
	bool isDelivered;
	void Show()const;
};
ofstream& operator <<(ofstream& out, const Ticket& other)
{
	out << other.ticket_number << endl;
	out << other.date_mail_sent.years << endl;
	out << other.date_mail_sent.months << endl;
	out << other.date_mail_sent.days << endl;
	out << other.date_mail_sent.time.hours << endl;
	out << other.date_mail_sent.time.minutes << endl;
	out << other.order_address << endl;
	out << other.service << endl;
	out << other.mail_weight << endl;
	out << other.cost_of_service << endl;
	return out;
}

class Client
{
	string name;
	string surname;
	list<Ticket> ticket_of_mail;
public:
	Client() = delete;
	Client(string name, string surname) : name(name), surname(surname) {}

	int size()const;
	bool empty()const;
	void PopTicket(int index);
	Ticket& GetTicket(int index);
	void AddTicket(string ticket_number, Date date_mail_sent, string sender_address, string service, int mail_weight, int cost_of_service, bool isDelivered = false);
	bool ShowTickets()const;
	void ShowClient()const;
	friend ofstream& operator <<(ofstream& out, const Client& other);
};
ofstream& operator <<(ofstream& out, const Client& other)
{
	out << other.name << endl;
	out << other.surname << endl;
	for (Ticket ticket : other.ticket_of_mail)
	{
		out << ticket;
	}
	out << endl;
	return out;
}