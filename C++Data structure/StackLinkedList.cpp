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
	// 어? 의외로 간단하네
}
bool StackLinkedList::pop()
{
	if (isEmpty())
	{
		cout << "비어있음" << endl;
		return false;
	}

	Node* temp = top;
	top = top->next;
	delete temp;
	return true; // 성공적으로 실행을 했다고 할리는 신호이다.
}

int StackLinkedList::peek() const // 가장 위에 무슨 데이터가 있는지 볼 수 있게 확인하는 함수이다.
{

	if (isEmpty())
	{
		return -1;// 함수를 실패했다는걸 알리는 신호이다. 
	}

	return top->data; // 위에 있는 값 반환 
}

bool StackLinkedList::isEmpty() const
{
	return top == nullptr;// top이 NULL이면 실행한다는 의미히다. 

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
