#pragma once

#include<iostream>

typedef int DataType;
// 자료형 int를 DataType이라는 걸로 이름만 바꾸었다. 기능은 int와 동일하다
// 사용하는 이유 : int 말고 다른 자료형 float 같은 걸로 바꿀때 여기만 바꾸면 된다., 또한 DataType이라고 쓰면 연결리스트에만 사용하는 데이터의 타입인걸 알 수 있다.

struct Node
{
// 노드 구조체 만들기 
	DataType Data;
	// 노드의 데이터를 저장할 곳
	Node* NextNode;
	// 다음 노드의 주소를 저장하는 포인터
	// 현재 노드가 간리키는 주소는 다음 노드의 위치이다. 다음 노드의 주소를 저장한다.

};
Node* Create(DataType data);
// 함수 node 구조체의 포인터를 반환함을 나타난다.
// 만든 노드를 구조체에 넣어야 한다. 기억?
// data는 나중에 구조체에 Data에 넣을 값이다. 
void Destroy(Node* node);
// void는 함수가 값을 반환하지 않을때 사용한다. 
// void는 구조체에 넣을 필요가 없다. 행동?
// Node* node는 삭제할 노드 넣는거다.
void Push(Node** Head, Node* node);
//Node**는 Node*를 가르킨다. 즉 Node** head는 Node* 타입의 포인터를 가리키"는 포인터 변수 이다.  
//연결 리스트의 헤드 포인터를 변경하려면 원래의 포인터 자체를 변경해야 한다. 이를 위해 포인터의 주소를 전달하는, 즉 포인터에 대한 포인터(**)를 사용한다.
void Insert(Node* current, Node* node);
// Node* current는 새로운 노드를 삽입할 위치의 이전 노드를 가리키는 포인터이다.
// Node* node 삽입할 새로운 노드를 가리키는 포인터이다. 

/*void InsertHead(Node** current, Node* head);
// Node** current 리스트의 헤드 포인터의 주소를 가리키는 포인터입니다.
// Node* head 리스트에 삽입할 새로운노드의 포인터이다.
*/

void Remove(Node** head, Node* remove);
// Node** head 리스트의 헤드 포인터의 주소를 가리키는 포인터이다
// Node* remove 삭제할 노드의 포인터이다.
Node* GetNode(Node* head, int index);
// Node* head 리스트의 시작 노드를 가리키는 포인터이다.
// int index 가져오고자하는 노드의 인덱스이다.
// 인덱스는 데이터의 위치를 나타내는 숫자이다. 
int GetNodeCount(Node* head);
// 이 함수는 연결리스트의 길이는 반환하는 역할이다.
// int로 선언 하면 함수가 정수 값을 반환한다는 뜻이다. 
