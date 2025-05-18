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
//Node** head : 외부에서 head가 가리키는 위치를 변경할 수 있다, 연결 리스트의 시작 주소를 바꿀 수 있다. 
//Node* node : 리스트에 추가할 새노드의 포인터이다.
// *head 연결 리스트 시작점 
{
	if ((*head) != nullptr)
	{
		//head가 비어 있는 않는 경우
		Node* tail = (*head);
		// tail은 현재 리스트의 시작점 복사해서 사요한다. 맨 앞부터 출발

		while (tail->NextNode != nullptr)
			tail = tail->NextNode;
		// NextNode가 nullptr이 될 때가지 리스트의 끝까지 이동
		tail->NextNode = node;
		// 리스트의 마지막 노드의 next에 새로운 노드를 연결한다. 

	}
	else
	{
		*head = node;
		// node를 직접 연결 
	}

}

void Insert(Node* current, Node* node)
{
	//current : 삽입할 위치 바로 앞 노드
	//node : 삽입할 새 노드 
	node->NextNode = current->NextNode;
	// 새 노드가 기존 다음 노드를 가리키게 한다.
	current->NextNode = node;
	// 현재 노드의 다음 새노드로 변경한다. 
}

/*void InsertHead(Node** current, Node* head)
{
}
*/

void Remove(Node** head, Node* remove)
{
	//Node**head : dummyHead의 NextNode가 저장된 메모리위치(주소)를 가리킨다.
	// Node** head 는 &dummyHead->NextNode 와 같다. 
	// Node*remove :제거할 노드를 직접 지정하다. 제거할 targer이다.
	if (*head == remove)
	{
		//리스트의 첫번째 노드가 제거 대상일 경우 
		*head = remove->NextNode;
		// 위에 것과 dummyHead -> NextNode = remove-> NextNode;와 같다. 
		//월래는 더미헤드 NextNode가 첫번째 노드였는데 두번째 노드로 변경하는거다
	}
	else
	{
		Node* current = *head;
		// current는 dummyHead->NextNode에서 시작한다. 
		while (current != nullptr && current->NextNode != remove)
			current = current->NextNode;
		//remove 바로 이전 노드를 찾기 위한 반복문 
		// current -> NextNode == remove가 될때 까지 이동
		// 찾으면 current는 제거 대상 앞의 노드이다.

		if (current != nullptr)
			current->NextNode = remove->NextNode;
		// 제거 대상 노드를 리스트에서 건너뛴다.
		// current가 이제 remove를 건너뛰고 remove->NextNode를 가리킨다. 
	}
}

Node* GetNode(Node* head, int index)
{
	//Node* head : 리스트의 시작 노드 (더미헤드는 제외하고 첫 노드부터 탐색)
	// int index : 찾고 싶은 인덱스 번호

	Node* current = head;
	//head가 가리키는 노드를 가리킨다.
	while (current != nullptr && (--index >= 0))
	// current != nullptr : 현재 가리키는 노드가 존재할 때만 이동한다.
	// index는 몇 칸 이동해야하는지 의미이며 --로 1씩 줄어든다.5 4 3 2 1
	// index번째 위치에 있는 노드를 찾기 위해 리스트를 앞으로 한 칸씩 이동한다. 

	current = current->NextNode;
	// 다음 노드로 이동한다.
		return current;
}

int GetNodeCount(Node* head)
{
	//Node* head : 리스트의 시작 노드(더미헤드의 다음 노드) 
	int count = 0;
	Node* current = head;

	while (current != nullptr)
	{
		// 리스트 끝가지 순회한다. 
		current = current->NextNode;
		count++;
		// 다음 노드로 이동하고 숫자를 1 더한다.

			
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


	 // 10. 전체 리스트 출력
    cout << "Step 10: Final list: ";
    Node* current = head->NextNode;
    while (current != nullptr) {
        cout << current->Data << " ";
        current = current->NextNode;
    }
    cout << endl;

    // 11. 모든 노드 메모리 해제
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
