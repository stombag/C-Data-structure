#pragma once

class Insertion {
private:
	int* arr;
	int size;
	int count;

public:
	Insertion(int size);
	~Insertion();

	void push(int input);

	//��������
	void sort();
	void printArray();
	

};
