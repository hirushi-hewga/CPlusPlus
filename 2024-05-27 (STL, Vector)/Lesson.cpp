#include <iostream>
#include <vector>
using namespace std;



//void Print(vector<int> v)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " - ";
//	}
//	cout << endl;
//}

//int main()
//{
	//vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//vector<int> v2 = { 10, 11, 12, 13, 14 };
	//for (int elem : v)
	//{
	//	cout << elem << " - ";
	//}
	//cout << endl;
	//
	//// erase - delete element by address
	//v.erase(v.begin());
	//Print(v);
	//v.erase(v.begin()+2, v.end() - 2);
	//Print(v);
	//v.erase(v.end() - 1);
	//Print(v);

	//// insert - add element by address
	//v.insert(v.begin(), { 100, 200, 300 });
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;
	//v.insert(v.begin(), 5, 77);
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;
	//v.insert(v.end(), 777);
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;
	//v.insert(v.begin(), v2.begin(), v2.end());
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;
	//v.insert(v.begin() + 5, v2.begin() + 2, v2.end() - 2);
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;
	//
	//v[0] = 100; // set
	//cout << v[0] << endl; // get
	//Print(v);
	//// add element to the end
	//v.push_back(444);
	//v.push_back(444);
	//v.push_back(444);
	//v.push_back(444);
	//Print(v);
	//// delete element at the end
	//v.pop_back();
	//Print(v);

	///*
	//Print(v);
	//Print(v2);
	//// swap
	//v.swap(v2);
	//Print(v);
	//Print(v2);
	//*/

	//cout << "First element : " << v.front() << endl;
	//cout << "Last element : " << v.back() << endl;

	//v.resize(5);
	//Print(v);
	//v.push_back(444);
	//v.push_back(444);
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;

	//v.shrink_to_fit();
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;
	//v.push_back(444);
	//v.push_back(444);
	//Print(v);
	//cout << "Size : " << v.size() << endl;
	//cout << "Capacity : " << v.capacity() << endl;

	//vector<int> numbers = { 1, 2, 7, 8, 9, 5, 4, 3 };
	//for (int i = 0; i < numbers.size(); i++)
	//{
	//	if (numbers[i] == 7)
	//	{
	//		numbers.insert(numbers.begin() + i, 7);
	//		break;
	//	}
	//}
	//Print(numbers);
//}