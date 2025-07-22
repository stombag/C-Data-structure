#include "VariadicCircularLinkedList.h"
#include <iostream>
#include <cstdarg>
using namespace std;

VariadicCircularLinkedList::Node::Node(int d) : data(d), next(nullptr) {}

VariadicCircularLinkedList::VariadicCircularLinkedList() {
    dummy = new Node(); // dummy 노드 생성
    dummy->next = dummy; // 자기 자신을 가리킴 (원형 구조)
    Count = 0; // counting the number of nodes
}

VariadicCircularLinkedList::~VariadicCircularLinkedList() {
    clear(); // deleting nodes and memory
    delete dummy; // deleting dummyhead
}

void VariadicCircularLinkedList::push(int value) {
    Node* newNode = new Node(value); // creating a new Noode

    Node* current = dummy; // current initialize to the next node from the dummy
    for (int i = 0; i < Count; i++) // moving current
        current = current->next;

    newNode->next = dummy; // set newNode next to dummy 
    current->next = newNode; // set current next to newNode

    Count++; // add 1 to the count 
}

void VariadicCircularLinkedList::insert(int index, int value)
{
    if (index<0 || index>Count)return;

    Node* prev = dummy; // creating a prev and prev initialize to the dummy

    for (int i = 0; i <index; ++i) // Decrease the index while the next node is not the dummy node
    {
        prev = prev->next; // moving prev
    }

    Node* newNode = new Node(value); // creating a new Node 
    newNode->next = prev->next; // set newNode next to  prev next 
    prev->next = newNode; // set prev next to newNode

    Count++; // add 1 to the count 
}
void VariadicCircularLinkedList::addMultiple(int count, ...)
{
    // 조금 더 공부가 필요한거 같다.
    
    va_list args; // 가변 인자를 처리하기 위한 C 스타일 타입
    va_start(args, count); // 가변 인자 리스트를 초기화 한다
    Node* tail = dummy->next; // 마지막을 더미헤드 다음으로 초기화 한다.


    for (int i = 0; i < count; i++) { // 가변 인자 크기 만큼 반복한다.
        int value = va_arg(args, int); // 가변인자에서 int 타입의 값을 앞에서 부터 꺼낸다

    while (tail->next != dummy) // 마지막이 더미헤드가 아닐때까지 원형이라 다음 노드가 더미헤드 그게 마지막 노드다 
        tail = tail->next;

        Node* newNode = new Node(value); v// 가변인자에서 꺼낸 int 타입을 값을 넣고 새로운 노드로 넣는다. 
        tail->next = newNode;       // 현재 tail의 다음에 새 노드 연결
        tail = newNode; // 마지막노드를 새노드로 받아드린다.
        newNode->next = dummy;      // 새 노드는 dummy를 가리키도록 (원형 구조 유지)
        Count++; // 카운트 추가
    }

    va_end(args); // 이제 더이상  가변 인자 목록을 사용하지 않겠다는 의미 // @@@ 근데 한번더 호출하니깐  우연히 호출된거라고 GPT가 말함 이상해
    


}
void VariadicCircularLinkedList::print() const {
    Node* current = dummy->next; //creating a current and current initialliaze to the dummy next 
    while (current != dummy)  { // isn't  current the dummy?
        cout << current->data << endl; 
        current = current->next;// moving the current 
    }
     cout << "(back to dummy)" << endl; // end
}

void VariadicCircularLinkedList::clear() {
    Node* current = dummy->next; // creating a current and current intialliaze to the dummy next 
    while (current != dummy) { // isn't current the dummy? 
        Node* next = current->next; // creating a next and next intiallize to the curret next
        delete current; // deleting current 
        current = next; // set  current to the next 
    }
    dummy->next = dummy; // set dummy next to the dummy 
}
