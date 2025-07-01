#pragma once

#include<iostream>

typedef int DataType;
// 자료형 int를 DataType이라는 걸로 이름만 바꾸었다. 기능은 int와 동일하다
// 사용하는 이유 : int 말고 다른 자료형 float 같은 걸로 바꿀때 여기만 바꾸면 된다., 또한 DataType이라고 쓰면 연결리스트에만 사용하는 데이터의 타입인걸 알 수 있다.

class LinkedList
{
private:

	struct Node // 노드 구조체 만들기
	{
		DataType Data;
		// 노드의 데이터를 저장할 곳
		Node* NextNode;
		// 다음 노드의 주소를 저장하는 포인터
		// 현재 노드가 간리키는 주소는 다음 노드의 위치이다. 다음 노드의 주소를 저장한다.

		Node(DataType d = 0) : Data(d), NextNode(nullptr) {}// 객체에 있는 변수의 최소값을 정하는 거다

		//Node(DataType d = 0) 이건 생성자 함수. 매개변수 d를 받는데 기본값은 0입니다. 즉, 인자가 없어도 호출 된다.
		// :Data(d) 멤버 초기화 리스트. 멤버 함수 Data를 d로 초기화한다
		//NextNode(nullptr) 멤버 변수 NextNode룰 nullptr로 초기화한다
		// {} 이건 생성자본문이 비어있음 필요한 작업은 위에서 끝냄


	};
	Node* dummyHead;// 더미 노드

public:
	LinkedList() // 더미데이터를 만들어주는 역할을 한다.
	{
		dummyHead = new Node(); //호울 하면 기본 생성자를 통해 node객체가 하나 생성되고 그 주소가 더미헤드에 들어간다.
	}
	~LinkedList()
	{
		Clear();
		delete dummyHead;
	}
	void Push(DataType data); //리스트의 맨뒤에 데이터를 추가한다.

	void Insert(int index, DataType data);// 지정한 위치에 데이터를 삽입한다.

	void Remove(int index); //지정한 위치의 데이터를 삭제한다.(해당 노드를 제거하고 연결을 다시 이어준다.

	DataType Get(int index); //지정한 위치에 있는 데이터를 반환합니다.(읽기 전용, 삭제X)
	// 반환은 잠간 다른 바으로 갔다가 값을 들고 다시 돌아오는 느낌이다. 

	int Count() const; //리스트에 저장된 요소의 개수를 반환한다.

	void print() const; //리스트의 모든 데이터를 순서대로 출력한다.

	void Clear(); // 리스트의 모든 노드를 삭제하여 비운다. 
};
