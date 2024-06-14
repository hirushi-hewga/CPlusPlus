#include "Customer.h"

int Client::size() const
{
    return ticket_of_mail.size();
}

bool Client::empty() const
{
    return ticket_of_mail.size() == 0;
}

void Client::PopTicket(int index)
{
    auto it = ticket_of_mail.begin();
    advance(it, index);
    ticket_of_mail.erase(it);
}

Ticket& Client::GetTicket(int index)
{
    auto it = ticket_of_mail.begin();
    advance(it, index);
    return (*it);
}

void Client::AddTicket(string ticket_number, Date date_mail_sent, string sender_address, string service, int mail_weight, int cost_of_service, bool isDelivered)
{
    ticket_of_mail.push_back(Ticket{ ticket_number, date_mail_sent, sender_address, service, mail_weight, cost_of_service, isDelivered });
}

bool Client::ShowTickets() const
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

void Client::ShowClient() const
{
	cout << " - " << name << ' ' << surname << " | Tickets : " << ticket_of_mail.size() << endl;
}

void Ticket::Show() const
{
	cout << ". ======== Ticket : " << ticket_number << " ========" << endl;
	cout << "   Date mail sent : " << date_mail_sent << endl;
	cout << "   Order address : " << order_address << endl;
	cout << "   Mail weight : " << mail_weight << endl;
	cout << "   Cost of service : " << cost_of_service << endl;
}
