#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};
class Train
{
	int number;
	Time departure_time;
	string station_of_destination;
public:
	Train(int number, Time t, string station) : number(number), departure_time(t), station_of_destination(station) {}
	Train(const Train& other)
	{
		this->number = other.number;
		this->departure_time.hours = other.departure_time.hours;
		this->departure_time.minutes = other.departure_time.minutes;
		this->departure_time.seconds = other.departure_time.seconds;
		this->station_of_destination = other.station_of_destination;
	}

	int GetNumber()const { return number; }
	void SetTime(int h, int m, int s)
	{
		departure_time.hours = h;
		departure_time.minutes = m;
		departure_time.seconds = s;
	}
	Time GetTime()const
	{
		return departure_time;
	}
	string GetStation()const
	{
		return station_of_destination;
	}
	void Show()const
	{
		cout << "Train number : " << left << setw(3) << number << " | Departure time : ";
		if (departure_time.hours < 10) cout << '0';
		cout << departure_time.hours << ':';
		if (departure_time.minutes < 10) cout << '0';
		cout << departure_time.minutes << ':';
		if (departure_time.seconds < 10) cout << '0';
		cout << departure_time.seconds << " | Station of destination : " << station_of_destination << endl;
	}

	friend ofstream& operator <<(ofstream& out, const Train& other);
	friend ifstream& operator >>(ifstream& in, const Train& other);
};
ofstream& operator <<(ofstream& out, const Train& other)
{
	out << other.number << ':' << other.departure_time.hours << ':' << other.departure_time.minutes << ':' << other.departure_time.seconds << ':' << other.station_of_destination << '|' << endl;
	return out;
}
bool CompareByTime(const Train& train1, const Train& train2)
{
	Time t1 = train1.GetTime();
	Time t2 = train2.GetTime();
	return t1.hours * 10000 + t1.minutes * 100 + t1.seconds < t2.hours * 10000 + t2.minutes * 100 + t2.seconds;
}


class Railway
{
	vector<Train> system_;
public:
	void AddTrainToSystem(Time t, string st)
	{
		Train train(system_.size() + 1, t, st);
		system_.push_back(train);
	}
	void ShowTrains()const
	{
		try
		{
			if (system_.size() == 0) throw exception("Not found trains");
			for (int i = 0; i < system_.size(); i++)
			{
				system_[i].Show();
			}
		}
		catch (exception ex)
		{
			cout << "Error! " << ex.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown exception" << endl;
		}
	}
	void ShowTrainByNumber(int num)const
	{
		try
		{
			bool isFound = false;
			for (int i = 0; i < system_.size(); i++)
			{
				if (system_[i].GetNumber() == num)
				{
					system_[i].Show();
					isFound = true;
					break;
				}
			}
			if (!isFound) throw exception("Not found train by number");
		}
		catch (exception ex)
		{
			cout << "Error! " << ex.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown exception" << endl;
		}
	}
	void SetTimeByNumber(int num)
	{
		try
		{
			bool isFound = false;
			for (int i = 0; i < system_.size(); i++)
			{
				if (system_[i].GetNumber() == num)
				{
					system_[i].Show();
					isFound = true;
					int h, m, s;
					cout << "Enter hours : "; cin >> h;
					cout << "Enter minutes : "; cin >> m;
					cout << "Enter seconds : "; cin >> s;
					system_[i].SetTime(h, m, s);
					break;
				}
			}
			if (!isFound) throw exception("Not found train by number");
		}
		catch (exception ex)
		{
			cout << "Error! " << ex.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown exception" << endl;
		}
	}
	void SortByTime()
	{
		sort(system_.begin(), system_.end(), CompareByTime);
	}
	void ShowByStation(string station)const
	{
		for (int i = 0; i < system_.size(); i++)
		{
			if (system_[i].GetStation() == station)
				system_[i].Show();
		}
		cout << endl;
	}
	void Save()const
	{
		ofstream out("Trains.txt", ios_base::out);
		for (int i = 0; i < system_.size(); i++)
		{
			out << system_[i];
		}
		out.close();
	}
	void Load()
	{
		system_.clear();
		ifstream in("Trains.txt", ios_base::in);
		char buffnumber[250], buffhours[250], buffminutes[250], buffseconds[250], buffstation[250];
		while (!in.eof())
		{
			in.getline(buffnumber, 250, ':');
			if (in.eof()) break;
			in.getline(buffhours, 250, ':');
			in.getline(buffminutes, 250, ':');
			in.getline(buffseconds, 250, ':');
			in.getline(buffstation, 250, '|');
			Train train(Train{ atoi(buffnumber), {atoi(buffhours), atoi(buffminutes), atoi(buffseconds)}, buffstation });
			system_.push_back(train);
		}
		in.close();
	}
};

int main()
{
	Railway railway;
	railway.AddTrainToSystem(Time{ 2, 36, 52 }, "Kyiv");
	railway.AddTrainToSystem(Time{ 5, 12, 31 }, "Lviv");
	railway.AddTrainToSystem(Time{ 23, 59, 59 }, "Rivne");
	railway.AddTrainToSystem(Time{ 0, 31, 55 }, "Harkiv");
	railway.AddTrainToSystem(Time{ 14, 28, 15 }, "Odesa");
	railway.AddTrainToSystem(Time{ 11, 11, 48 }, "Zdolbuniv");
	railway.AddTrainToSystem(Time{ 8, 47, 38 }, "Kyrovohrad");
	railway.AddTrainToSystem(Time{ 7, 40, 53 }, "Herson");
	railway.AddTrainToSystem(Time{ 16, 44, 43 }, "Poltava");
	railway.AddTrainToSystem(Time{ 12, 42, 36 }, "Mariupol");
	railway.AddTrainToSystem(Time{ 13, 19, 47 }, "Zaporizzhya");
	railway.AddTrainToSystem(Time{ 10, 43, 53 }, "Sumy");
	railway.AddTrainToSystem(Time{ 10, 42, 11 }, "Kryviy rih");
	railway.AddTrainToSystem(Time{ 16, 6, 5 }, "Hmelnytsk");
	railway.AddTrainToSystem(Time{ 8, 1, 10 }, "Zarichne");
	railway.AddTrainToSystem(Time{ 2, 46, 52 }, "Dnipropetrovsk");
	railway.AddTrainToSystem(Time{ 23, 31, 12 }, "Ivanofrankivsk");
	railway.AddTrainToSystem(Time{ 2, 11, 30 }, "Zhytomyr");
	railway.AddTrainToSystem(Time{ 9, 6, 37 }, "Ternopil");
	railway.AddTrainToSystem(Time{ 16, 27, 49 }, "Cherkasy");
	railway.AddTrainToSystem(Time{ 17, 14, 51 }, "Luhansk");
	railway.AddTrainToSystem(Time{ 16, 32, 9 }, "Donetsk");
	railway.AddTrainToSystem(Time{ 11, 40, 12 }, "Poltava");
	railway.AddTrainToSystem(Time{ 10, 8, 27 }, "Lutsk");
	railway.AddTrainToSystem(Time{ 7, 13, 49 }, "Uzhorod");
	railway.AddTrainToSystem(Time{ 21, 53, 57 }, "Chernivtsi");
	railway.AddTrainToSystem(Time{ 4, 52, 40 }, "Luboml");
	railway.AddTrainToSystem(Time{ 6, 30, 58 }, "Kovel");
	railway.AddTrainToSystem(Time{ 14, 9, 51 }, "Kamin-Kashyrskiy");
	railway.AddTrainToSystem(Time{ 18, 56, 28 }, "Dubrovytsia");
	railway.AddTrainToSystem(Time{ 11, 34, 13 }, "Berezne");
	railway.AddTrainToSystem(Time{ 2, 0, 34 }, "Kostopil");
	railway.AddTrainToSystem(Time{ 7, 47, 45 }, "Dubno");
	railway.AddTrainToSystem(Time{ 11, 48, 50 }, "Ostroh");
	railway.AddTrainToSystem(Time{ 1, 44, 24 }, "Horodok");
	railway.AddTrainToSystem(Time{ 21, 38, 58 }, "Yavoriv");
	railway.AddTrainToSystem(Time{ 21, 19, 38 }, "Kremenchuk");
	railway.AddTrainToSystem(Time{ 16, 28, 31 }, "Pochaiv");
	railway.AddTrainToSystem(Time{ 20, 46, 46 }, "Zbarazh");
	railway.AddTrainToSystem(Time{ 7, 19, 20 }, "Chortkiv");
	railway.AddTrainToSystem(Time{ 1, 39, 58 }, "Borschiv");
	railway.AddTrainToSystem(Time{ 4, 41, 2 }, "Hotyn");
	railway.AddTrainToSystem(Time{ 18, 55, 58 }, "Sokyriany");
	railway.AddTrainToSystem(Time{ 16, 32, 41 }, "Novohrad-volynskiy");
	railway.AddTrainToSystem(Time{ 18, 54, 30 }, "Nobel");
	railway.AddTrainToSystem(Time{ 1, 46, 7 }, "Kuhcha");
	railway.AddTrainToSystem(Time{ 21, 53, 41 }, "Mlynok");
	railway.AddTrainToSystem(Time{ 10, 18, 35 }, "Bilska volia");
	railway.AddTrainToSystem(Time{ 16, 8, 58 }, "Volodymyrets");
	railway.AddTrainToSystem(Time{ 7, 54, 50 }, "Kuznetsovsk");
	railway.AddTrainToSystem(Time{ 15, 44, 17 }, "Rafalivka");
	railway.AddTrainToSystem(Time{ 13, 1, 8 }, "Zelene");
	railway.AddTrainToSystem(Time{ 15, 12, 14 }, "Berezhnytsia");
	railway.AddTrainToSystem(Time{ 19, 26, 34 }, "Svarytsevychi");
	railway.AddTrainToSystem(Time{ 18, 16, 5 }, "Horodysche");
	railway.AddTrainToSystem(Time{ 0, 51, 39 }, "Udrytsk");
	railway.AddTrainToSystem(Time{ 22, 21, 9 }, "Velyki ozera");
	railway.AddTrainToSystem(Time{ 18, 39, 11 }, "Liubykovychi");
	railway.AddTrainToSystem(Time{ 21, 47, 10 }, "Klesiv");
	railway.AddTrainToSystem(Time{ 11, 21, 42 }, "Tomashhorod");
	railway.AddTrainToSystem(Time{ 19, 59, 51 }, "Rokytne");
	railway.AddTrainToSystem(Time{ 23, 19, 3 }, "Blazhove");
	railway.AddTrainToSystem(Time{ 22, 16, 50 }, "Berehove");
	railway.AddTrainToSystem(Time{ 16, 49, 48 }, "Stepan");
	railway.AddTrainToSystem(Time{ 4, 4, 59 }, "Tynne");
	railway.AddTrainToSystem(Time{ 20, 26, 0 }, "Kysorychi");
	railway.AddTrainToSystem(Time{ 13, 16, 48 }, "Borove");
	railway.AddTrainToSystem(Time{ 4, 45, 37 }, "Yarynivka");
	railway.AddTrainToSystem(Time{ 17, 49, 38 }, "Yapolot");
	railway.AddTrainToSystem(Time{ 15, 52, 7 }, "Mokvyn");
	railway.AddTrainToSystem(Time{ 16, 45, 49 }, "Berestovets");
	railway.AddTrainToSystem(Time{ 5, 6, 11 }, "Bystrychi");
	railway.AddTrainToSystem(Time{ 8, 26, 49 }, "Sosnove");
	railway.AddTrainToSystem(Time{ 1, 56, 43 }, "Olesandria");
	railway.AddTrainToSystem(Time{ 0, 46, 51 }, "Orzhiv");
	railway.AddTrainToSystem(Time{ 13, 2, 48 }, "Tuchyn");
	railway.AddTrainToSystem(Time{ 15, 23, 40 }, "Storozhi");
	railway.AddTrainToSystem(Time{ 12, 52, 28 }, "Korets");
	railway.AddTrainToSystem(Time{ 9, 10, 8 }, "Klevan");
	railway.AddTrainToSystem(Time{ 2, 32, 16 }, "Hoscha");
	railway.AddTrainToSystem(Time{ 19, 5, 33 }, "Kvasyliv");
	railway.AddTrainToSystem(Time{ 15, 10, 6 }, "Ozenyn");
	railway.AddTrainToSystem(Time{ 0, 1, 54 }, "Ostroh");
	railway.AddTrainToSystem(Time{ 23, 32, 22 }, "Satyiv");
	railway.AddTrainToSystem(Time{ 3, 42, 42 }, "Mizoch");
	railway.AddTrainToSystem(Time{ 0, 46, 38 }, "Buscha");
	railway.AddTrainToSystem(Time{ 14, 57, 27 }, "Smyha");
	railway.AddTrainToSystem(Time{ 0, 12, 13 }, "Novoukrainka");
	railway.AddTrainToSystem(Time{ 1, 8, 27 }, "Mlyniv");
	railway.AddTrainToSystem(Time{ 15, 29, 36 }, "Boremel");
	railway.AddTrainToSystem(Time{ 3, 23, 35 }, "Demydivka");
	railway.AddTrainToSystem(Time{ 10, 55, 46 }, "Ptycha");
	railway.AddTrainToSystem(Time{ 21, 31, 29 }, "Tesluhiv");
	railway.AddTrainToSystem(Time{ 7, 17, 36 }, "Radyvyliv");
	railway.AddTrainToSystem(Time{ 15, 27, 31 }, "Olyk");
	railway.AddTrainToSystem(Time{ 16, 55, 25 }, "Tsuman");
	railway.AddTrainToSystem(Time{ 18, 24, 8 }, "Kiverti");
	railway.AddTrainToSystem(Time{ 21, 59, 34 }, "Trostianets");
	railway.AddTrainToSystem(Time{ 15, 18, 1 }, "Kolky");
	railway.AddTrainToSystem(Time{ 10, 16, 13 }, "Naviz");
	railway.AddTrainToSystem(Time{ 5, 57, 20 }, "Rozhysche");
	railway.AddTrainToSystem(Time{ 12, 39, 58 }, "Holoby");
	railway.AddTrainToSystem(Time{ 20, 9, 1 }, "Rokyni");
	railway.AddTrainToSystem(Time{ 22, 25, 3 }, "Torchyn");
	railway.AddTrainToSystem(Time{ 9, 33, 35 }, "Charukiv");
	railway.AddTrainToSystem(Time{ 19, 4, 12 }, "Senkevychivka");
	railway.AddTrainToSystem(Time{ 8, 22, 32 }, "Marianivka");
	railway.AddTrainToSystem(Time{ 3, 52, 51 }, "Berestechko");
	railway.AddTrainToSystem(Time{ 20, 30, 25 }, "Horohiv");
	railway.AddTrainToSystem(Time{ 0, 38, 24 }, "Pryvitne");
	railway.AddTrainToSystem(Time{ 11, 6, 15 }, "Turiysk");
	railway.AddTrainToSystem(Time{ 5, 21, 28 }, "Perespa");
	railway.AddTrainToSystem(Time{ 6, 31, 23 }, "Zaturtsi");
	railway.AddTrainToSystem(Time{ 10, 11, 42 }, "Novovolynsk");
	railway.AddTrainToSystem(Time{ 8, 12, 28 }, "Zhovtneve");
	railway.AddTrainToSystem(Time{ 3, 44, 39 }, "Ivanychi");
	railway.AddTrainToSystem(Time{ 0, 15, 38 }, "Yhovetsk");
	railway.AddTrainToSystem(Time{ 20, 9, 37 }, "Verba");
	railway.AddTrainToSystem(Time{ 14, 41, 35 }, "Ustyluh");
	railway.AddTrainToSystem(Time{ 20, 15, 57 }, "Lublynets");
	railway.AddTrainToSystem(Time{ 2, 3, 28 }, "Olesk");
	railway.AddTrainToSystem(Time{ 10, 6, 13 }, "Pischa");
	railway.AddTrainToSystem(Time{ 21, 37, 56 }, "Shatsk");
	railway.AddTrainToSystem(Time{ 12, 52, 37 }, "Holovne");
	railway.AddTrainToSystem(Time{ 15, 48, 13 }, "Lukiv");
	railway.AddTrainToSystem(Time{ 0, 18, 18 }, "Zabolottia");
	railway.AddTrainToSystem(Time{ 20, 41, 3 }, "Krymne");
	/*railway.AddTrainToSystem(Time{ 16, 59, 35 }, "Stara vyzhivka");
	railway.AddTrainToSystem(Time{ 3, 32, 19 }, "Domanove");
	railway.AddTrainToSystem(Time{ 13, 22, 33 }, "Hirnyky");
	railway.AddTrainToSystem(Time{ 12, 35, 24 }, "Radne");
	railway.AddTrainToSystem(Time{ 22, 52, 43 }, "Butsyn");
	railway.AddTrainToSystem(Time{ 8, 32, 57 }, "Soshychne");
	railway.AddTrainToSystem(Time{ 20, 18, 40 }, "Olenyne");
	railway.AddTrainToSystem(Time{ 7, 1, 27 }, "Manevychi");*/
	railway.AddTrainToSystem(Time{ 9, 53, 2 }, "Prylisne");
	railway.AddTrainToSystem(Time{ 11, 8, 26 }, "Vuterta");
	railway.AddTrainToSystem(Time{ 6, 14, 1 }, "Selysche");
	railway.AddTrainToSystem(Time{ 0, 0, 29 }, "Birky");
	railway.AddTrainToSystem(Time{ 6, 16, 25 }, "Lubeshiv");
	railway.AddTrainToSystem(Time{ 8, 2, 14 }, "Selysche");
	/*cout << "=====================================================================" << endl; railway.ShowTrains();
	cout << "=====================================================================" << endl; railway.ShowTrainByNumber(3);
	railway.SetTimeByNumber(2);
	cout << "=====================================================================" << endl; railway.ShowTrains();
	railway.SortByTime();
	cout << "=====================================================================" << endl; railway.ShowTrains();
	cout << "=====================================================================" << endl; railway.ShowByStation("Selysche");*/
	//railway.Save();
	/*railway.Load();
	railway.ShowTrains();*/
}