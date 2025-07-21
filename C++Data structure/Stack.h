#pragma once
class Stack
{
private:
	int* arr;// ���� �迭 
	int capacity; // �ִ� ũ��
	int top;// top �ε���

public:
	Stack(int size = 100); // ������ 
	~Stack(); // �Ҹ���
	void push(int value);// ���� �ֱ�
	bool pop(int&result);// ���� ������ �����
	bool peek(int& result) const;// ������ ���� ����
	bool isEmpty() const;// ����ִ��� Ȯ��
	bool isFull()const; // �� á���� Ȯ�� 
	void print() const;// ���� ��� 

};
