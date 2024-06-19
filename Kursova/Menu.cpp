#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <list>
#include <string>
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
	void Show()const
	{
		cout << ". ======== Ticket : " << ticket_number << " ========" << endl;
		cout << "   Date mail sent : " << date_mail_sent << endl;
		cout << "   Order address : " << order_address << endl;
		cout << "   Mail weight : " << mail_weight << endl;
		cout << "   Cost of service : " << cost_of_service << endl;
	}
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

	int size()const
	{
		return ticket_of_mail.size();
	}
	bool empty()const
	{
		return ticket_of_mail.size() == 0;
	}
	void PopTicket(int index)
	{
		auto it = ticket_of_mail.begin();
		advance(it, index);
		ticket_of_mail.erase(it);
	}
	Ticket& GetTicket(int index)
	{
		auto it = ticket_of_mail.begin();
		advance(it, index);
		return (*it);
	}
	void AddTicket(string ticket_number, Date date_mail_sent, string sender_address, string service, int mail_weight, int cost_of_service, bool isDelivered = false)
	{
		ticket_of_mail.push_back(Ticket{ ticket_number, date_mail_sent, sender_address, service, mail_weight, cost_of_service, isDelivered });
	}
	bool ShowTickets()const
	{
		if (!ticket_of_mail.empty())
		{
			cout << "======== " << name << ' ' << surname << " ========" << endl;
			int i = 0;
			for (Ticket ticket : ticket_of_mail)
			{
				cout << ++i;
				ticket.Show();
				cout << endl;
			}
			cout << endl;
			return true;
		}
		return false;
	}
	void ShowClient()const
	{
		cout << " - " << name << ' ' << surname << " | Tickets : " << ticket_of_mail.size() << endl;
	}
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
	out << '|' << endl;
	return out;
}

class NovaPoshta
{
	string department_name;
	list<string> services;
	vector<Client> database_of_ordered_services;
	vector<Client> database_of_performed_services;
public:
	NovaPoshta() = delete;
	NovaPoshta(string department_name) : department_name(department_name)
	{
		services.push_back("Courier delivery");
	}

	void ShowServices()const
	{
		system("cls");
		if (!services.empty())
		{
			for (string service : services)
			{
				cout << " - " << service << endl;
			}
		}
		else
		{
			cout << "Not found services" << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void ChangeService()
	{
		system("cls");
		if (!services.empty())
		{
			bool isValidData = true;
			int choice = 0;
			int i;
			while (choice < 1 || choice > services.size())
			{
				i = 0;
				for (string service : services)
				{
					cout << ++i << " - " << service << endl;
				}
				cout << endl;
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "Choice a service to change : ";
				cin >> choice;
			}
			system("cls");
			string service_;
			cout << "Enter new service to change : ";
			cin >> service_;
			i = 0;
			for (string& service : services)
			{
				if (++i == choice)
				{
					service = service_;
				}
			}
			cout << endl;
			cout << "The service has been successfully changed" << endl;
		}
		else cout << "Not found services" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddService()
	{
		system("cls");
		string newService;
		cout << "Enter new service to add : ";
		cin >> newService;
		services.push_back(newService);
		cout << endl;
		cout << "The service has been successfully added" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void DeleteService()
	{
		system("cls");
		if (!services.empty())
		{
			bool isValidData = true;
			int choice = 0;
			int i;
			while (choice < 1 || choice > services.size())
			{
				i = 0;
				for (string service : services)
				{
					cout << ++i << " - " << service << endl;
				}
				cout << endl;
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "Choice a service to delete : ";
				cin >> choice;
			}
			auto it = services.begin();
			advance(it, choice - 1);
			services.erase(it);
			cout << endl;
			cout << "The service has been successfully deleted" << endl;
		}
		else cout << "Not found services" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddClient()
	{
		system("cls");
		string name, surname;
		cout << "Enter client name : ";
		cin >> name;
		cout << "Enter client surname : ";
		cin >> surname;
		database_of_ordered_services.push_back(Client(name, surname));
		database_of_performed_services.push_back(Client(name, surname));
		cout << endl;
		cout << "Client added" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void ShowClients()const
	{
		system("cls");
		if (!database_of_ordered_services.empty())
		{
			for (Client client : database_of_ordered_services)
			{
				client.ShowClient();
			}
		}
		else cout << "Clients not found" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddTicket()
	{
		system("cls");
		if (!services.empty() && !database_of_ordered_services.empty())
		{
			string ticket_number, sender_address, service;
			int years, months, days, hours, minutes;
			int mail_weight, cost_of_service;

			int client = 0;
			bool isValidData = true;
			while (client < 1 || client > database_of_ordered_services.size())
			{
				int i = 0;
				for (Client client_ : database_of_ordered_services)
				{
					cout << ++i;
					client_.ShowClient();
				}
				cout << "Choice client : ";
				cin >> client;
			}
			auto it = database_of_ordered_services.begin();
			advance(it, client - 1);

			cout << "Enter ticket number : ";
			cin >> ticket_number;

			cout << "Enter sender address : ";
			cin >> sender_address;

			int choice = 0;
			isValidData = true;
			while (choice < 1 || choice > services.size())
			{
				int i = 0;
				for (string service_ : services)
				{
					cout << ++i << " - " << service_ << endl;
				}
				cout << "Choice service : ";
				cin >> choice;
			}
			auto it_ = services.begin();
			advance(it_, choice - 1);
			service = (*it_);

			cout << "Enter year mail sent : ";
			cin >> years;
			cout << "Enter months mail sent : ";
			cin >> months;
			cout << "Enter days mail sent : ";
			cin >> days;
			cout << "Enter hours mail sent : ";
			cin >> hours;
			cout << "Enter minutes mail sent : ";
			cin >> minutes;

			cout << "Enter mail weight : ";
			cin >> mail_weight;

			cout << "Enter cost of service : ";
			cin >> cost_of_service;

			(*it).AddTicket(ticket_number, Date{ years, months, days, {hours, minutes} }, sender_address, service, mail_weight, cost_of_service);

			cout << "Ticket added" << endl;
		}
		else
		{
			if (services.empty()) cout << "Services not found" << endl;
			if (database_of_ordered_services.empty()) cout << "Clients not found" << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void DeliverTheOrder()
	{
		bool isFoundTickets = false;
		for (Client client : database_of_ordered_services)
		{
			if (!client.empty())
			{
				isFoundTickets = true;
				break;
			}
		}
		if (!database_of_ordered_services.empty() && isFoundTickets)
		{
			int i;
			int choice = 0;
			vector<Client>::iterator it;
			while (true)
			{
				try
				{
					system("cls");
					while (choice < 1 || choice > database_of_ordered_services.size())
					{
						i = 0;
						for (Client client : database_of_ordered_services)
						{
							cout << ++i; client.ShowClient();
						}
						cout << endl;
						cout << "Choice client to deliver the order : ";
						cin >> choice;
					}
					it = database_of_ordered_services.begin();
					advance(it, choice - 1);
					if ((*it).empty()) throw exception("not found for this client");
					break;
				}
				catch (exception ex)
				{
					system("cls");
					cout << ex.what() << endl;
					cout << endl;
					cout << "Press any key to repeat : ";
					_getch();
				}
				catch (...)
				{
					system("cls");
					cout << "Unknown exception" << endl;
					cout << endl;
					cout << "Press any key to repeat : ";
					_getch();
				}
			}
			auto it_ = database_of_performed_services.begin();
			advance(it_, choice - 1);
			choice = 0;
			bool isValidData = true;
			system("cls");
			while (choice < 1 || choice >(*it).size())
			{
				(*it).ShowTickets();
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				cout << "Choice a ticket for delivery : ";
				cin >> choice;
			}
			Ticket& ticket = (*it).GetTicket(choice - 1);
			(*it_).AddTicket(ticket.ticket_number, ticket.date_mail_sent, ticket.order_address, ticket.service, ticket.mail_weight, ticket.cost_of_service, true);
			(*it).PopTicket(choice - 1);
			system("cls");
			cout << "The order has been delivered" << endl;
		}
		else
		{
			system("cls");
			cout << "No tickets found for undelivered orders!" << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void ShowDataBaseOfOrderedServices()const
	{
		system("cls");
		if (!database_of_ordered_services.empty())
		{
			bool isFoundTicket = false;
			for (Client customer : database_of_ordered_services)
			{
				if (customer.ShowTickets())
				{
					isFoundTicket = true;
				}
			}
			if (!isFoundTicket)
			{
				cout << "No tickets found for undelivered orders!" << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "No tickets found for undelivered orders!" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		_getch();
	}
	void ShowDataBaseOfPerformedServices()const
	{
		system("cls");
		if (!database_of_performed_services.empty())
		{
			bool isFoundTicket = false;
			for (Client customer : database_of_performed_services)
			{
				if (customer.ShowTickets())
				{
					isFoundTicket = true;
				}
			}
			if (!isFoundTicket)
			{
				cout << "No tickets found for delivered orders!" << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "No tickets found for delivered orders!" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		_getch();
	}
	void SaveDataBaseOfOrderedServicesToFile()const
	{
		ofstream ordered_out("OrderedServices.txt", ios_base::out);
		
		for (Client client : database_of_ordered_services)
		{
			ordered_out << client;
		}

		ordered_out.close();
	}
	void SaveDataBaseOfPerformedServicesToFile()const
	{
		ofstream performed_out("PerformedServices.txt", ios_base::out);

		for (Client client : database_of_performed_services)
		{
			performed_out << client;
		}

		performed_out.close();
	}
	void LoadDataBaseOfOrderedServicesFromFile()
	{
		database_of_ordered_services.clear();
		database_of_ordered_services.shrink_to_fit();
		string symbol;
		string buff_name, buff_surname, buff_ticket_number, buff_date_mail_sent_years, buff_date_mail_sent_months, buff_date_mail_sent_days, buff_date_mail_sent_hours, buff_date_mail_sent_minutes, buff_order_address, buff_service, buff_mail_weight, buff_cost_of_service;

		ifstream ordered_in("OrderedServices.txt", ios_base::in);

		while (!ordered_in.eof())
		{
			getline(ordered_in, buff_name);
			if (ordered_in.eof()) break;
			getline(ordered_in, buff_surname);
			Client client(buff_name, buff_surname);
			database_of_performed_services.push_back(client);
			getline(ordered_in, buff_ticket_number);
			while (buff_ticket_number != "|")
			{
				getline(ordered_in, buff_date_mail_sent_years);
				getline(ordered_in, buff_date_mail_sent_months);
				getline(ordered_in, buff_date_mail_sent_days);
				getline(ordered_in, buff_date_mail_sent_hours);
				getline(ordered_in, buff_date_mail_sent_minutes);
				getline(ordered_in, buff_order_address);
				getline(ordered_in, buff_service);
				getline(ordered_in, buff_mail_weight);
				getline(ordered_in, buff_cost_of_service);

				client.AddTicket(buff_ticket_number, { stoi(buff_date_mail_sent_years), stoi(buff_date_mail_sent_months), stoi(buff_date_mail_sent_days), stoi(buff_date_mail_sent_hours), stoi(buff_date_mail_sent_minutes) }, buff_order_address, buff_service, stoi(buff_mail_weight), stoi(buff_cost_of_service), false);
				database_of_ordered_services.push_back(client);

				getline(ordered_in, buff_ticket_number);
			}
		}

		ordered_in.close();
	}
	void LoadDataBaseOfPerformedServicesFromFile()
	{
		database_of_performed_services.clear();
		database_of_performed_services.shrink_to_fit();
		string symbol;
		string buff_name, buff_surname, buff_ticket_number, buff_date_mail_sent_years, buff_date_mail_sent_months, buff_date_mail_sent_days, buff_date_mail_sent_hours, buff_date_mail_sent_minutes, buff_order_address, buff_service, buff_mail_weight, buff_cost_of_service;

		ifstream performed_in("PerformedServices.txt", ios_base::in);

		while (!performed_in.eof())
		{
			getline(performed_in, buff_name);
			if (performed_in.eof()) break;
			getline(performed_in, buff_surname);
			Client client(buff_name, buff_surname);
			getline(performed_in, buff_ticket_number);
			while (buff_ticket_number != "|")
			{
				getline(performed_in, buff_date_mail_sent_years);
				getline(performed_in, buff_date_mail_sent_months);
				getline(performed_in, buff_date_mail_sent_days);
				getline(performed_in, buff_date_mail_sent_hours);
				getline(performed_in, buff_date_mail_sent_minutes);
				getline(performed_in, buff_order_address);
				getline(performed_in, buff_service);
				getline(performed_in, buff_mail_weight);
				getline(performed_in, buff_cost_of_service);

				client.AddTicket(buff_ticket_number, { stoi(buff_date_mail_sent_years), stoi(buff_date_mail_sent_months), stoi(buff_date_mail_sent_days), stoi(buff_date_mail_sent_hours), stoi(buff_date_mail_sent_minutes) }, buff_order_address, buff_service, stoi(buff_mail_weight), stoi(buff_cost_of_service), true);
				database_of_performed_services.push_back(client);

				getline(performed_in, buff_ticket_number);
			}
		}

		performed_in.close();
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 15)
	{
		system("cls");
		cout << " 1 - Show services" << endl;
		cout << " 2 - Change service" << endl;
		cout << " 3 - Add service" << endl;
		cout << " 4 - Delete service" << endl;
		cout << " 5 - Add client" << endl;
		cout << " 6 - Show clients" << endl;
		cout << " 7 - Add ticket" << endl;
		cout << " 8 - Deliver the order" << endl;
		cout << " 9 - show ordered services" << endl;
		cout << "10 - show performed services" << endl;
		cout << "11 - Save ordered services to file" << endl;
		cout << "12 - Save performed services to file" << endl;
		cout << "13 - Load ordered services from file" << endl;
		cout << "14 - Load performed services from file" << endl;
		cout << "15 - Exit" << endl;
		if (!isValidData)
		{
			cout << "\nError choice! Try again.\n";
		}
		else isValidData = false;
		cout << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW_SERVICES = 1, CHANGE_SERVICE, ADD_SERVICE, DELETE_SERVICE, ADD_CLIENT, SHOW_CLIENTS, ADD_TICKET, DELIVER_THE_ORDER, SHOW_ORDERED_SERVICES, SHOW_PERFORMED_SERVICES, SAVE_ORDERED_SERVICES, SAVE_PERFORMED_SERVICES, LOAD_ORDERED_SERVICES, LOAD_PERFORMED_SERVICES, EXIT };
int main()
{
	NovaPoshta nova_poshta("Nova Poshta");
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case SHOW_SERVICES: nova_poshta.ShowServices(); break;
		case CHANGE_SERVICE: nova_poshta.ChangeService(); break;
		case ADD_SERVICE: nova_poshta.AddService(); break;
		case DELETE_SERVICE: nova_poshta.DeleteService(); break;
		case ADD_CLIENT: nova_poshta.AddClient(); break;
		case SHOW_CLIENTS: nova_poshta.ShowClients(); break;
		case ADD_TICKET: nova_poshta.AddTicket(); break;
		case DELIVER_THE_ORDER: nova_poshta.DeliverTheOrder(); break;
		case SHOW_ORDERED_SERVICES: nova_poshta.ShowDataBaseOfOrderedServices(); break;
		case SHOW_PERFORMED_SERVICES: nova_poshta.ShowDataBaseOfPerformedServices(); break;
		case SAVE_ORDERED_SERVICES: nova_poshta.SaveDataBaseOfOrderedServicesToFile(); break;
		case SAVE_PERFORMED_SERVICES: nova_poshta.SaveDataBaseOfPerformedServicesToFile(); break;
		case LOAD_ORDERED_SERVICES: nova_poshta.LoadDataBaseOfOrderedServicesFromFile(); break;
		case LOAD_PERFORMED_SERVICES: nova_poshta.LoadDataBaseOfPerformedServicesFromFile(); break;
		case EXIT: isExit = true;
		}
	}
	system("cls");
	cout << "Good bye." << endl;
}