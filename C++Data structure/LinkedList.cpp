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
//Node** head : �ܺο��� head�� ����Ű�� ��ġ�� ������ �� �ִ�, ���� ����Ʈ�� ���� �ּҸ� �ٲ� �� �ִ�. 
//Node* node : ����Ʈ�� �߰��� ������� �������̴�.
// *head ���� ����Ʈ ������ 
{
	if ((*head) != nullptr)
	{
		//head�� ��� �ִ� �ʴ� ���
		Node* tail = (*head);
		// tail�� ���� ����Ʈ�� ������ �����ؼ� ����Ѵ�. �� �պ��� ���

		while (tail->NextNode != nullptr)
			tail = tail->NextNode;
		// NextNode�� nullptr�� �� ������ ����Ʈ�� ������ �̵�
		tail->NextNode = node;
		// ����Ʈ�� ������ ����� next�� ���ο� ��带 �����Ѵ�. 

	}
	else
	{
		*head = node;
		// node�� ���� ���� 
	}

}

void Insert(Node* current, Node* node)
{
	//current : ������ ��ġ �ٷ� �� ���
	//node : ������ �� ��� 
	node->NextNode = current->NextNode;
	// �� ��尡 ���� ���� ��带 ����Ű�� �Ѵ�.
	current->NextNode = node;
	// ���� ����� ���� ������ �����Ѵ�. 
}

/*void InsertHead(Node** current, Node* head)
{
}
*/

void Remove(Node** head, Node* remove)
{
	//Node**head : dummyHead�� NextNode�� ����� �޸���ġ(�ּ�)�� ����Ų��.
	// Node** head �� &dummyHead->NextNode �� ����. 
	// Node*remove :������ ��带 ���� �����ϴ�. ������ targer�̴�.
	if (*head == remove)
	{
		//����Ʈ�� ù��° ��尡 ���� ����� ��� 
		*head = remove->NextNode;
		// ���� �Ͱ� dummyHead -> NextNode = remove-> NextNode;�� ����. 
		//������ ������� NextNode�� ù��° ��忴�µ� �ι�° ���� �����ϴ°Ŵ�
	}
	else
	{
		Node* current = *head;
		// current�� dummyHead->NextNode���� �����Ѵ�. 
		while (current != nullptr && current->NextNode != remove)
			current = current->NextNode;
		//remove �ٷ� ���� ��带 ã�� ���� �ݺ��� 
		// current -> NextNode == remove�� �ɶ� ���� �̵�
		// ã���� current�� ���� ��� ���� ����̴�.

		if (current != nullptr)
			current->NextNode = remove->NextNode;
		// ���� ��� ��带 ����Ʈ���� �ǳʶڴ�.
		// current�� ���� remove�� �ǳʶٰ� remove->NextNode�� ����Ų��. 
	}
}

Node* GetNode(Node* head, int index)
{
	//Node* head : ����Ʈ�� ���� ��� (�������� �����ϰ� ù ������ Ž��)
	// int index : ã�� ���� �ε��� ��ȣ

	Node* current = head;
	//head�� ����Ű�� ��带 ����Ų��.
	while (current != nullptr && (--index >= 0))
	// current != nullptr : ���� ����Ű�� ��尡 ������ ���� �̵��Ѵ�.
	// index�� �� ĭ �̵��ؾ��ϴ��� �ǹ��̸� --�� 1�� �پ���.5 4 3 2 1
	// index��° ��ġ�� �ִ� ��带 ã�� ���� ����Ʈ�� ������ �� ĭ�� �̵��Ѵ�. 

	current = current->NextNode;
	// ���� ���� �̵��Ѵ�.
		return current;
}

int GetNodeCount(Node* head)
{
	//Node* head : ����Ʈ�� ���� ���(��������� ���� ���) 
	int count = 0;
	Node* current = head;

	while (current != nullptr)
	{
		// ����Ʈ ������ ��ȸ�Ѵ�. 
		current = current->NextNode;
		count++;
		// ���� ���� �̵��ϰ� ���ڸ� 1 ���Ѵ�.

			
	}
	return count;
}


int main()
{
	Node* head = DummyHead();
	cout << "DummeyHead" << endl;
	Node* a = Create(1);
	cout << "Node a" << a->Data<< endl;
	Push(&head->NextNode, a);
	Node* b = Create(2);
	cout << "Node b" << b->Data<< endl;
	Push(&a->NextNode, b);
	Node* c = Create(3);
	cout << "Node c" << c->Data<< endl<<endl;
	Push(&b->NextNode, c);
	Node* d = Create(4);
	cout << "Node d" << d->Data<< endl<<endl;
	Push(&c->NextNode, d);

	int count = GetNodeCount(head->NextNode);
	cout << count << endl;

	Node* GGetNdoe = GetNode(head->NextNode, 1);
	cout << GGetNdoe->Data << endl;

	Remove(&head->NextNode, d);
	cout << count << endl;

	Node* E = Create(5);
	cout << "Node E" << E->Data<< endl<<endl;
	Push(&c->NextNode, E);
	
	count = GetNodeCount(head->NextNode);
	cout << count << endl;


	 // 10. ��ü ����Ʈ ���
    cout << "Step 10: Final list: ";
    Node* current = head->NextNode;
    while (current != nullptr) {
        cout << current->Data << " ";
        current = current->NextNode;
    }
    cout << endl;

    // 11. ��� ��� �޸� ����
    current = head->NextNode;
    while (current != nullptr) {
        Node* next = current->NextNode;
        Destroy(current);
        current = next;
    }
    Destroy(head);
    cout << "Step 11: All nodes destroyed." << endl;

    return 0;

}
