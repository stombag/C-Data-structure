#pragma once

class CountingSort {
private:
	int* arr;
	int size;

	int value;
public:
	CountingSort(int size);
	~CountingSort();

	void push(int input);
	void sort();
	void print(); 

};
