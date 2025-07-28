#include <iostream>
#include "StackLinkedList.h"

using namespace std;

StackLinkedList::StackLinkedList()
{
	top = nullptr;
}

StackLinkedList::~StackLinkedList()
{
	while (!isEmpty())
	{
		pop();
	}

}

void StackLinkedList::push(int value)
{
	Node* newNode = new Node(value);

	newNode->next = top;
	top = newNode;
	// ��? �ǿܷ� �����ϳ�
}
bool StackLinkedList::pop()
{
	if (isEmpty())
	{
		cout << "�������" << endl;
		return false;
	}

	Node* temp = top;
	top = top->next;
	delete temp;
	return true; // ���������� ������ �ߴٰ� �Ҹ��� ��ȣ�̴�.
}

int StackLinkedList::peek() const // ���� ���� ���� �����Ͱ� �ִ��� �� �� �ְ� Ȯ���ϴ� �Լ��̴�.
{

	if (isEmpty())
	{
		return -1;// �Լ��� �����ߴٴ°� �˸��� ��ȣ�̴�. 
	}

	return top->data; // ���� �ִ� �� ��ȯ 
}

bool StackLinkedList::isEmpty() const
{
	return top == nullptr;// top�� NULL�̸� �����Ѵٴ� �ǹ�����. 

}


void StackLinkedList::print()const
{
	Node* current = top;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;
}
