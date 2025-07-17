#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

// 생성자 


CircularLinkedList::CircularLinkedList()
{
    dummyHead = new Node();         // 더미 헤드 생성
    // 더미헤드에 새로운 노드를 넣기 
    dummyHead->next = dummyHead;    // 원형 연결
    // 더미헤드에 다음 노드를 다음 더미헤드로 넣기 
    count = 0;
}

// 소멸자
CircularLinkedList::~CircularLinkedList() {
    Node* current = dummyHead->next;
    // 더미헤드의 다음 노드의 이름을 current로 정하기
    while (current != dummyHead) {
        // current가 더미헤드가 아닐때까지 실행한다
        Node* temp = current; // curret을 temp로 정한다.
        current = current->next; // current의 다음 노드를 current에 넣는다.
        delete temp; // temp에 있는 해당 주소값을 삭제한다.

        // tem에 current의 주소값을 넣고 다음줄에 current를 다음 노드로 이동시킨다.
        // tem은 current가 전에 가지고 있었던 주소값을 가지고 있어 그걸 삭제한다.
        // 이과정을 반복해서 노드를 다 제거하고 current가 더미헤드가 될때 실행를 종료한다
    }
    delete dummyHead;  // 더미 헤드 삭제
}

void CircularLinkedList::Push(int value)
{
    // 내가 만듬 
    Node* newNode = new Node();
    newNode->data = value;
    Node* tail = dummyHead;

    while (tail->next != dummyHead)
    {
        tail = tail->next;

    }
    
    tail->next = newNode;
    newNode->next = dummyHead;
    count++;
}

void CircularLinkedList::insert(int index, int value)
{
    if (index<0 || index>count)return;
    // 만약 인덱스가 마이너스 이면 실행이 되지 않게 하고
    //  index가 count보다 작을 경우 에도 실행되지 않는다.
    Node* newNode = new Node();

   
    newNode->data = value;

    Node* current = dummyHead->next;

    while (index-- > 0)
        current = current->next;

    newNode->next = current->next       ;
    current->next = newNode;

    count++; 
}

void CircularLinkedList::remove(int index)
{
    if (index<0 || index>=count) return;
    // 인덱스는 0부터 시작하므로 삭제 가능한 최대 인데스는 1이다.
    //만약 index == count일 경우는 존재하지 않는 노드이므로 삭제하면 안된다.
    if (count == 0) {
        cout << "리스트가 비어있다" << endl;
    }

    Node* current = dummyHead;
    for (int i = 0; i < index; ++i)
        current = current->next;

    Node* target = current->next;
    current->next = target->next;
   
    delete target;
    count--;
}

int CircularLinkedList::get(int index) const
{
    if (index < 0 || index >= count) {
        cout << "다시 입력해주세요" << endl;
        return -1;
    }

    Node* current = dummyHead->next;

    for (int i = 0; i < index; ++i)
        current = current->next;


    return current->data;
}

void CircularLinkedList::Print() const
{
    Node* current = dummyHead->next;

    if (current == dummyHead) {
        cout << "비어 있습니다." << endl;
        return;
    }

    cout << "리스트 내용: ";

    while (current != dummyHead)
    {
        cout << current->data << " ";
        current = current->next;

    }

    cout << endl;

}

void CircularLinkedList::claen()
{
    Node* current = dummyHead->next;

    while (current != dummyHead) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    dummyHead->next = dummyHead;
    count = 0;
}
// 장점:
// 반복 처리에 유리하다
// 양 끝 처리가 편리하다
// NULL 걱정할 필요가 없다 
// 하나의 노드에서 다른 모든 노드로의 접근이 가능하다.
// 리스트의 끝에 노드를 삽입 하는 연산이 단순 연결리스트보다 효율적이다.

// 단점:
// 끝 판단이 어렵다.
// 복잡한 구현
// 무한 루프 위험성
// 단순 용도에는 오버스팩이다.

// 사용예시
// 턴제 게임(ex. 보드게임,카드게임) - 플레이어가 반복적으로 돌아가며 턴을 가진다.
// Ai 순환 행동 루틴 - 반복적인 행동 루틴을 순서대로 돌며 처리한다. (ex. 정찰-> 수리->공격->정찰-..)
// 루프 애니매이션 - 끝없이 반복되는 몬스터 또는 배경 애니메니션
// 보스 패턴 순환 - 보스가 특정 공격 패턴을 계속 반복한다.(ex. 공격1->공격2->회피-...)


// 원형 링크더 리스트와 링크더 리스트 차이
// linkedlist는 간단하고 일반적인 구조,탐색시 끝을 nullptr로 쉽게 감지 가능 - 단순구조, 마지막 노드처리 복잡(직접관리 해야한다.)
// CircularLinkedList가 필요한 경우에 적합, 끝과 처음을 연결해 놓았기 때문에 특정 작업(무한 반복등) 유리하다 - 복잡구조, 마지막 노드처리 간단

