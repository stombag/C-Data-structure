#pragma once

#include <iostream> 
using namespace std;

class Heap {
private:
	int* heap;
	int capacity;
	int size;

	void heapifyUP(int index);
	void heapifyDown(int index);

public:
	Heap(int capacity = 100);
	~Heap();

	void insert(int value);
	int pop();
	int top() const;
	bool isEmpty() const;
	bool isFull() const;
	void print() const;

};