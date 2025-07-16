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
