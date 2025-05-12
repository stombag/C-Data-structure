#include <iostream>
#include "LinkedList.h"
using namespace std;

Node* Create(DataType data)
{
	Node* newNode = new Node();
	// Node*의 별명은 newnode이고 new Node의 주소값을 가리키는 건 newnode이다 
	// 포인터는 주소만 가리키는 자료형이다
	newNode->Data = data;
	// 주소값을 가리키는 newNode에 접근하면 Node가 나오는데 그것에 있는 Data에 data값을 넣는다.
	newNode->NextNode = nullptr;
	
	// NextNode를 nullptr로 비우는 이유는 다음 노드의 주소를 넣기 위해서 이다. 
	// nullptr는 아무것도 가리키지 않는 포인터 키워드이다.
	return newNode;
	// newNode가 가리키는 주소값을 반환한다 즉 그 주소값의 위치에 값을 넣는다. 
}
Node* DummyHead()
{
	Node* dummyhead = new Node();
	dummyhead->NextNode = nullptr;
	return dummyhead;
	// 기본 노드에서 내용이 비어 있는 상태의 노드를 만들고 만드는 노드 앞에 세우면 그게 더미헤드가 된다.
	// main 첫 줄에 넣기, 이렇게 따로 더미 헤드라는 함수를 만들어야한다. 
}
void Destroy(Node* node)
{
	delete node;
	// 메모리 해제 
	node = nullptr;
	// node이 가지고 있는 주소값없애기 

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
