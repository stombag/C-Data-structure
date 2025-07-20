#include "VariadicCircularLinkedList.h"
#include <iostream>
#include <cstdarg>
using namespace std;

VariadicCircularLinkedList::Node::Node(int d) : data(d), next(nullptr) {}

VariadicCircularLinkedList::VariadicCircularLinkedList() {
    dummy = new Node(); // dummy ��� ����
    dummy->next = dummy; // �ڱ� �ڽ��� ����Ŵ (���� ����)
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
    va_list args;//���� ���� ����� ó���Ҷ� ����ϴ� Ÿ��  
   // ���� ���� ���ڸ� �޾ƾ� �Ҷ� �� ������ ���ڵ��� �ϳ��� ���� �� �ְ� �ȴ�. 
   
    va_start(args, count);  
    // va_start�� ���� ���ڸ� �б� ������ �� �ֵ��� �ʱ�ȭ �մϴ�. 
    // args : �츮�� ����� ���� ��� ����
    // count : ���� ���� �� ������ ���� ���� �̸��Դϴ�. �̰� �������� �� �ں��Ͱ� ���� ���ڶ�� �����Ϸ��� �Ǵ��մϴ�.
    // �� count �ڿ� ���� ���ڵ��� va_list�� ���� �ϳ��� ������ �� �ְ� �˴ϴ�. 
    Node* tail = dummy; // creating tail and initialize to the dummy
    
    for (int i = 0; i < Count; i++)
    {
        tail = tail->next;

    }  // Isn't tail's next node the dummy node? 
      // set tail to the next node of tail
   
    for (int i = 0; i < count;i++) { 
        int value = va_arg(args, int); //Va_ �������ڿ��� �ϳ��� ���� �������� ��ũ�� �Դϴ�.
        // ���⼭ �������� ���ڴ� int Ÿ������ �����Ǿ� ������, �� �ݺ����� �ϳ��� ������ value�� ����˴ϴ�.
        Node* newNode = new Node(value); // ����� value�� newNode�� �ֱ�
      
        while(tail->next )
        tail = tail->next;
         // Isn't tail's next node the dummy node? 
      // set tai
        
        newNode->next = dummy;// newNode�� ������ dummy�� �д�
        tail->next = newNode;// tail�� ���� ��带 newNode�� �ΰ�
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
