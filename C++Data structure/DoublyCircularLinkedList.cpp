#include <iostream>

#include "DoublyCircularLinkedList.h"   
using namespace std;

DoublyCircularLinkedList::DoublyCircularLinkedList() {
    dummyHead = new Node();
    dummyHead->next = dummyHead;
    dummyHead->prev = dummyHead;
    count = 0;
}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    clear();
    delete dummyHead;
}

void DoublyCircularLinkedList::append(int value)
{
    Node* last = dummyHead->prev;
    Node* newNode = new Node(value);

    newNode->next = dummyHead;
    newNode->prev = last;
    last->next = newNode;
    dummyHead->prev = newNode;

    count++;
}

void DoublyCircularLinkedList::insert(int index, int value) {
    if (index < 0 || index > count) return;

    Node* current = dummyHead;
    for (int i = 0; i < index; ++i)
        current = current->next;

    Node* newNode = new Node(value);
    Node* nextNode = current->next;

    newNode->next = nextNode;
    newNode->prev = current;
    current->next = newNode;
    nextNode->prev = newNode;

    count++;
}

void DoublyCircularLinkedList::remove(int index) {
    if (index < 0 || index >= count) return;

    Node* current = dummyHead->next;
    for (int i = 0; i < index; ++i)
        current = current->next;

    Node* prevNode = current->prev;
    Node* nextNode = current->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete current;
    count--;
}

int DoublyCircularLinkedList::get(int index) const {
    if (index < 0 || index >= count) return -1;

    Node* current = dummyHead->next;
    for (int i = 0; i < index; ++i)
        current = current->next;

    return current->data;
}

void DoublyCircularLinkedList::print() const {
    Node* current = dummyHead->next;
    cout << "List: ";
    for (int i = 0; i < count; ++i) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyCircularLinkedList::clear() {
    while (count > 0)
        remove(0);
}

int DoublyCircularLinkedList::size() const {
    return count;
}
