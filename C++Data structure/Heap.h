#pragma once

#include <iostream> 
using namespace std;

class Heap {
private:
	int* heap; // �� �����͸� �����ϴ� ���� �迭 ������ 
	int capacity; // ���� �� �ִ� �뷮
	int size; // ���� ����� �������� �� 

	void heapifyUP(int index); // ���� �� �� ������ ���� �ϱ� ���� ���� �̵� 
	// ���� ���ο� ���� �������� ��, �� ���� ���� ��Ģ�� ���߸� �� �����Ƿ� 
	// �� ���� ������ ��ġ�� "���� ���� �÷��� " ���� ������ �����ϴ� �Լ� �̴�. 
    // ���⼭ �ε����� �迭�� ���� 12345�� �ǹ��Ѵ� 
	void heapifyDown(int index);// ���� �� ������ �����ϱ� ���� ���� �̵� 
	// �� �ΰ� �Լ��� �� ������ �ƴϴ� . ���� ���� �ϱ� ���� ��ġ�� ���̴�. 
public:
	Heap(int capacity = 100); // �Ű������� �뷮 ���� 
	~Heap();

	void insert(int value);
	int pop();
	int top() const;
	bool isEmpty() const;
	bool isFull() const;
	void print() const;
	// ���� ���� ���� Ʈ���� �������� �θ���� �ڽ� ��� ���� �켱 ���� ������ �����ϴ� �ڷᱸ���̴�. 
	// ���� - ���� O(log N), �˻� ��Ʈ��O(1), �׿ܴ� O(N)
	// �迭�� ������ ������ ���� ���� ���� Ʈ���̱� ������ �迭�� �����ϸ� �ſ� ȿ�����̸�, 
	// ���� ����Ʈ�� �����ϸ� �޸� ����, ���� ���� �ӵ�, ������ �ڵ� �� ���� ������ ����� ������ �� ������� �ʴ´�. 


	void heapSort(); // �� ����
	void mergeSort(); // ���� ����
	void quicksort(); // �� ����
	void selectionSort(); // ���� ����
	void bubbleSort(); // ���� ���� 
	
};