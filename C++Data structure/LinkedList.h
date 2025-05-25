#pragma once

#include<iostream>

typedef int DataType;
// 자료형 int를 DataType이라는 걸로 이름만 바꾸었다. 기능은 int와 동일하다
// 사용하는 이유 : int 말고 다른 자료형 float 같은 걸로 바꿀때 여기만 바꾸면 된다., 또한 DataType이라고 쓰면 연결리스트에만 사용하는 데이터의 타입인걸 알 수 있다.

class LinkedList
{
private:

	struct Node
	{
		// 노드 구조체 만들기 
		DataType Data;
		// 노드의 데이터를 저장할 곳
		Node* NextNode;
		// 다음 노드의 주소를 저장하는 포인터
		// 현재 노드가 간리키는 주소는 다음 노드의 위치이다. 다음 노드의 주소를 저장한다.

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
