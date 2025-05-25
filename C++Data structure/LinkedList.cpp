#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::Push(DataType data)
{
	Node* newNode = new Node(data);
	Node* tail = dummyHead;
	while (tail->NextNode != nullptr)
		tail = tail->NextNode;
	tail->NextNode = newNode;

}

void LinkedList::Insert(int index, DataType data)
{
	Node* newNode = new Node(data);
	Node* current = dummyHead;

	while (index-- > 0 && current->NextNode != nullptr)
	{
		current = current->NextNode;
	}
	newNode->NextNode = current->NextNode;
	current->NextNode = newNode;

}

void LinkedList::Remove(int index)
{
	Node* current = dummyHead;
	while (index-- > 0 && current->NextNode != nullptr)
	{
		current = current->NextNode;
	}

	Node* target = current->NextNode;
	if (target != nullptr)
	{
		current->NextNode = target->NextNode;
		delete target;

	}
}

DataType LinkedList::Get(int index)
{
	Node* current = dummyHead->NextNode;
	while (index-- > 0 && current != nullptr)
	{
		current = current->NextNode;

	}
	if (current == nullptr) throw out_of_range("Index out of range");
	return current->Data;
}

int LinkedList::Count() const
{
	int count = 0;
	Node* current = dummyHead->NextNode;
	while (current != nullptr)
	{
		count++;
		current = current->NextNode;
	}

	return count;
}

void LinkedList::print() const
{
	Node* current = dummyHead->NextNode;
	while (current != nullptr)
	{
		cout << current->Data << " -> ";
		current = current->NextNode;

	}
	cout << "NULL" << endl;
}

void LinkedList::Clear()
{
	Node* current = dummyHead->NextNode;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->NextNode;
		delete temp;

	}
	dummyHead->NextNode = nullptr;
}

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
