#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	list.Push(10);
	list.Push(20);
	list.Push(30);
	list.print();

	list.Insert(1, 49);
	list.print();

	list.Remove(2);
	list.print();

	cout << "2" << list.Get(2) << endl;
	cout << "³ëµå ¼ö" << list.Count() << endl;
}
