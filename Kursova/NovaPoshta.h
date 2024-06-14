#include "Customer.h"

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

	void ShowServices()const;
	void ChangeService();
	void AddService();
	void DeleteService();
	void AddClient();
	void ShowClients()const;
	void AddTicket();
	void DeliverTheOrder();
	void ShowDataBaseOfOrderedServices()const;
	void ShowDataBaseOfPerformedServices()const;
	void SaveDataBaseOfOrderedServicesToFile()const;
	void SaveDataBaseOfPerformedServicesToFile()const;
	void LoadDataBaseOfOrderedServicesFromFile();
	void LoadDataBaseOfPerformedServicesFromFile();
};

