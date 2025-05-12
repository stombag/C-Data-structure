#include <iostream>
#include "LinkedList.h"
using namespace std;

Node* Create(DataType data)
{
	Node* newNode = new Node();
	// Node*�� ������ newnode�̰� new Node�� �ּҰ��� ����Ű�� �� newnode�̴� 
	// �����ʹ� �ּҸ� ����Ű�� �ڷ����̴�
	newNode->Data = data;
	// �ּҰ��� ����Ű�� newNode�� �����ϸ� Node�� �����µ� �װͿ� �ִ� Data�� data���� �ִ´�.
	newNode->NextNode = nullptr;
	
	// NextNode�� nullptr�� ���� ������ ���� ����� �ּҸ� �ֱ� ���ؼ� �̴�. 
	// nullptr�� �ƹ��͵� ����Ű�� �ʴ� ������ Ű�����̴�.
	return newNode;
	// newNode�� ����Ű�� �ּҰ��� ��ȯ�Ѵ� �� �� �ּҰ��� ��ġ�� ���� �ִ´�. 
}
Node* DummyHead()
{
	Node* dummyhead = new Node();
	dummyhead->NextNode = nullptr;
	return dummyhead;
	// �⺻ ��忡�� ������ ��� �ִ� ������ ��带 ����� ����� ��� �տ� ����� �װ� ������尡 �ȴ�.
	// main ù �ٿ� �ֱ�, �̷��� ���� ���� ����� �Լ��� �������Ѵ�. 
}
void Destroy(Node* node)
{
	delete node;
	// �޸� ���� 
	node = nullptr;
	// node�� ������ �ִ� �ּҰ����ֱ� 

}
void Push(Node** head, Node* node)
{
	if ((*head) != nullptr)
	{
		Node* tail = (*head);

		while (tail->NextNode != nullptr)
			tail = tail->NextNode;

		tail->NextNode = node;

	}
	else
	{
		*head = new Node();
	}

}

void Insert(Node* current, Node* node)
{
}

/*void InsertHead(Node** current, Node* head)
{
}
*/

void Remove(Node** head, Node* remove)
{
}

Node* GetNode(Node* head, int index)
{
	return nullptr;
}

int GetNodeCount(Node* head)
{
	return 0;
}
