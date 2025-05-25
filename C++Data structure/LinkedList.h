#pragma once

#include<iostream>

typedef int DataType;
// �ڷ��� int�� DataType�̶�� �ɷ� �̸��� �ٲپ���. ����� int�� �����ϴ�
// ����ϴ� ���� : int ���� �ٸ� �ڷ��� float ���� �ɷ� �ٲܶ� ���⸸ �ٲٸ� �ȴ�., ���� DataType�̶�� ���� ���Ḯ��Ʈ���� ����ϴ� �������� Ÿ���ΰ� �� �� �ִ�.

class LinkedList
{
private:

	struct Node
	{
		// ��� ����ü ����� 
		DataType Data;
		// ����� �����͸� ������ ��
		Node* NextNode;
		// ���� ����� �ּҸ� �����ϴ� ������
		// ���� ��尡 ����Ű�� �ּҴ� ���� ����� ��ġ�̴�. ���� ����� �ּҸ� �����Ѵ�.

		Node(DataType d = 0) : Data(d), NextNode(nullptr) {}

	};
	Node* dummyHead;

public:
	LinkedList()
	{
		dummyHead = new Node();
	}
	~LinkedList()
	{
		Clear();
		delete dummyHead;
	}
	void Push(DataType data);

	void Insert(int index, DataType data);

	void Remove(int index);

	DataType Get(int index);

	int Count() const;

	void print() const;

	void Clear();
};
