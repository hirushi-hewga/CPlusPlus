#include "NovaPoshta.h"


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
		cout << " 5 - Add client to batabase" << endl;
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