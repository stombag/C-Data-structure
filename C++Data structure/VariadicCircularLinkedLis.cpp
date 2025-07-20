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

void VariadicCircularLinkedList::addMultiple(int count, ...) {
    va_list args;//가변 인자 목록을 처리할때 사용하는 타입  
   // 여러 개의 인자를 받아야 할때 이 변수로 인자들을 하나씩 읽을 수 있게 된다. 
   
    va_start(args, count);  
    // va_start는 가변 인자를 읽기 시작할 수 있도록 초기화 합니다. 
    // args : 우리가 사용할 인자 목록 변수
    // count : 고정 인자 중 마지막 인자 변수 이름입니다. 이걸 기준으로 그 뒤부터가 가변 인자라고 컴파일러가 판단합니다.
    // 즉 count 뒤에 오는 인자들을 va_list를 통해 하나씩 꺼내쓸 수 있게 됩니다. 
    Node* tail = dummy; // creating tail and initialize to the dummy
    
    for (int i = 0; i < Count; i++)
    {
        tail = tail->next;

    }  // Isn't tail's next node the dummy node? 
      // set tail to the next node of tail
   
    for (int i = 0; i < count;i++) { 
        int value = va_arg(args, int); //Va_ 가변인자에서 하나씩 값을 꺼내오는 매크로 입니다.
        // 여기서 꺼내오는 인자는 int 타입으로 지정되어 있으며, 각 반복마다 하나씩 꺼내와 value에 저장됩니다.
        Node* newNode = new Node(value); // 저장된 value를 newNode에 넣기
      
        while(tail->next )
        tail = tail->next;
         // Isn't tail's next node the dummy node? 
      // set tai
        
        newNode->next = dummy;// newNode의 다음을 dummy로 둔다
        tail->next = newNode;// tail에 다음 노드를 newNode로 두고
    }

    va_end(args);}

void VariadicCircularLinkedList::print() const {
    Node* current = dummy->next; //creating a current and current initialliaze to the dummy next 
    while (current != dummy)  { // isn't  current the dummy?
        cout << current->data << endl; 
        current = current->next;// moving the current 
    }
 
    cout << Count << endl;
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
