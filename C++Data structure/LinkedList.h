#pragma once

#include<iostream>

typedef int DataType;
// 자료형 int를 DataType이라는 걸로 이름만 바꾸었다. 기능은 int와 동일하다
// 사용하는 이유 : int 말고 다른 자료형 float 같은 걸로 바꿀때 여기만 바꾸면 된다., 또한 DataType이라고 쓰면 연결리스트에만 사용하는 데이터의 타입인걸 알 수 있다.

struct Node
{
	DataType Data;
	Node* NextNode;

};
Node* Create(DataType data);
void Destroy(Node* node);

void Push(Node** Head, Node* node);
void Insert(Node* current, Node* node);
void InsertHead(Node** current, Node* head);

void Remove(Node** head, Node* remove);
Node* GetNode(Node* head, int index);
int GetNodeCount(Node* head);


