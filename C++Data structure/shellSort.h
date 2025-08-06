#pragma once

class shellSort{
private:
	int* arr;
	int size;
	int count;

public:
	shellSort(int size);
	~shellSort();

	void push(int input);


	//¼ÐÁ¤·Ä
	void Sort();
	void printArray();
	

};
