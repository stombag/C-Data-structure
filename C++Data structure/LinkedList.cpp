#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::Push(DataType data) // 연결 리스트의 끝에 새로운 노드를 추가하는 역할을 한다.
// void이므로 값을 반환하지 않습니다. 
{
	Node* newNode = new Node(data); // 동적으로 생성하고 data값으로 갖는 노드를 하나 만들고 newNode는 그 노드의 주소를 저장한다.
	Node* tail = dummyHead; //tail 포인터를 사용해 리스트의 마지막 노드를 찾기 위한 준비를 한다.
	while (tail->NextNode != nullptr) //NextNoder가 nullptr이 아닐 때까지 이동한다. 
		tail = tail->NextNode; // 리스트 끝으로 이동한다. 
	tail->NextNode = newNode; // NextNod == nullptr 인 노드를 찾으면 -> 그 노드가 현재 꼬리(tail) 노드이다.

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
	cout << "노드 수" << list.Count() << endl;
}
