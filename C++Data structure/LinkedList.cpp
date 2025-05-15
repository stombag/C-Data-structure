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
	node->NextNode = current->NextNode;
	current->NextNode = node;
}

/*void InsertHead(Node** current, Node* head)
{
}
*/

void Remove(Node** head, Node* remove)
{
	if (*head == remove)
	{
		*head = remove->NextNode;
	}
	else
	{
		Node* current = *head;
		while (current != nullptr && current->NextNode != remove)
			current = current->NextNode;

		if (current != nullptr)
			current->NextNode = remove->NextNode;
	}
}

Node* GetNode(Node* head, int index)
{

	Node* current = head;
	while (current != nullptr && (--index >= 0))
		current = current->NextNode;

	return current;
}

int GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;
	while (current != nullptr)
	{
		current = current->NextNode;
		count++;

			
	}
	return count;
}
