#pragma once
class Stack
{
private:
	int* arr;
	int capacity;
	int top;

public:
	Stack(int size = 100);
	~Stack();

	void push(int value);
	int pop();
	int peek() const;
	bool isEmpty() const;
	bool isFull()const;
	void print() const;



};
