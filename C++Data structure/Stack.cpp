#include "Stack.h"

#include <iostream>

using namespace std;


Stack::Stack(int size)
{
	capacity = size;
	arr = new int[capacity];
	top = -1;
}

Stack::~Stack()
{
	delete[] arr;

}

void Stack::push(int value)
{

	if (isFull())
	{
		cout << " 다참 " << endl;
		return;
	}
	arr[++top] = value;
}


int Stack::pop()
{ 
	if (isEmpty())
	{
		cout << "스택이 비어있습니다." << endl;
		return -1;
	}
	return arr[top--];

			
}
int Stack::peek() const
{
	if (isEmpty())
	{
		cout << "비어 있음	" << endl;
		return -1;	
	}
	return arr[top];
	
}

bool Stack::isEmpty() const
{
	return top == -1;
}

bool Stack::isFull() const
{
	return top == capacity - 1;	
}

void Stack::print() const
{
	if (isEmpty())
	{
		cout << "비어 있는" << endl;
		return;
}
	cout << "스택 내용" << endl;
	for (int i = top; i >= 0; --i)
		cout << arr[i] << " ";
	cout << endl;
}