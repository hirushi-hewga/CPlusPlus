#include <iostream>
using namespace std;

class Cartridge
{
public:
	enum TYPE { NONE, STANDART, L, XL };
private:
	string color;
	float volume;
	TYPE type;
public:
	Cartridge() : color("no color"), volume(0), type(NONE) {}
	Cartridge(string c, float v, TYPE t) : color(c), volume(v), type(t) {}

	void Show()const
	{
		cout << "Color : " << color << endl;
		cout << "Volume : " << volume << endl;
		cout << "Type : ";
		switch (type)
		{
		case Cartridge::NONE: cout << "None" << endl; break;
		case Cartridge::STANDART: cout << "Standart" << endl; break;
		case Cartridge::L: cout << "L" << endl; break;
		case Cartridge::XL: cout << "XL" << endl; break;
		}
		cout << endl;
	}
};

class Scanner
{
	float height, width;
	float scanResolution;
public:
	Scanner() : height(0), width(0), scanResolution(0) {}
	Scanner(float h, float w, float s) : height(h), width(w), scanResolution(s) {}

	void ShowInfo()const
	{
		cout << "Scanner with " << scanResolution << " dpi" << endl;
		cout << "Area : " << height << " mm ,  " << width << " mm" << endl;
	}
};

class Document
{
	string name;
	string format;
	int pages;
public:
	Document() : name("no name"), format("no format"), pages(0) {}
	Document(string name, string format, int pages) : name("no name"), format("no format")
	{
		this->pages = pages > 0 ? pages : 0;
	}

	void ShowInfo()const
	{
		cout << "---------------- Document : " << name << " ----------------" << endl;
		cout << "Format : " << format << endl;
		cout << "Pages : " << pages << endl;
	}
};



class Printer
{
	string model;
	int year;
	Cartridge* cartridges;
	int cartridgeCount;
	Scanner scanner;
	const Document* currentDoc;
public:
	Printer() : model("no model"), year(0), cartridges(nullptr), cartridgeCount(0), currentDoc(nullptr) {}
	Printer(string model, int year, float h, float w, float scanR) : currentDoc(nullptr)
	{
		this->model = model;
		this->year = year;

		scanner = Scanner(h, w, scanR);

		cartridgeCount = 4;
		cartridges = new Cartridge[cartridgeCount];
		cartridges[0] = Cartridge("Black", 500, Cartridge::XL);
		cartridges[1] = Cartridge("Blue", 300, Cartridge::L);
		cartridges[2] = Cartridge("Green", 200, Cartridge::L);
		cartridges[3] = Cartridge("Red", 100, Cartridge::L);
	}
	void Scan()const
	{
		cout << "Scanning..........." << endl;
		scanner.ShowInfo();
	}
	void PrintDocument()const
	{
		cout << "Printing document" << endl;
		if (currentDoc == nullptr)
		{
			cout << "No document to print" << endl;
		}
		else currentDoc->ShowInfo();
	}
	void ShowProperties()const
	{
		cout << "Printing with setting : " << endl;
		for (int i = 0; i < cartridgeCount; i++)
		{
			cartridges[i].Show();
		}
	}
	void AddToQueue(const Document& doc)
	{
		currentDoc = &doc;
	}
	void Cancel()
	{
		currentDoc = nullptr;
	}

	~Printer()
	{
		if (cartridges != nullptr)
			delete[] cartridges;
	}
};

//int main()
//{
	/*Printer printer("Cannon", 2020, 50, 50, 300);
	printer.Scan();
	printer.PrintDocument();
	printer.ShowProperties();

	Document doc1("passport.pdf", "A5", 5);
	Document doc2("C++ for beginners.pdf", "A4", 1500);

	printer.AddToQueue(doc1);
	printer.PrintDocument();

	printer.AddToQueue(doc2);
	printer.Cancel();
	printer.PrintDocument();*/
	//}