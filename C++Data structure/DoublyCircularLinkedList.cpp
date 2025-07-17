#include <iostream>

#include "DoublyCircularLinkedList.h"   
using namespace std;

DoublyCircularLinkedList::DoublyCircularLinkedList() {
    dummyHead = new Node(); // ����Ʈ ������ 
    dummyHead->next = dummyHead; // ���� ��带 ���̷�
    dummyHead->prev = dummyHead; //���� ��带 ���̷�
    count = 0; // ī��Ʈ �ʱ�ȭ
}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    clear(); // �� �����
    delete dummyHead; // ���̵����� ����� 
}

void DoublyCircularLinkedList::append(int value)
{
    Node* last = dummyHead->prev;  //��Ʈ��� �̸���  ������� ��������� �̸����� ���Ѵ�== ������� ������ ���
    Node* newNode = new Node(value); // ���ο� ��忡 ���� �ְ� �����.

    newNode->next = dummyHead; // ������� ���� ��带 �������� �ִ´�
    newNode->prev = last; // ������ ����Ű�� �� ������ ���� �ؼ� �����Ѵ�
    last->next = newNode; // ������ ����� ���� ��带 ������ ������忴�µ� ���ο���� ���Ѵ�
    dummyHead->prev = newNode; // ���������� ��������� ���� ��带 ���θ��� ���� �־ �����Ų��.

    count++; // �߰��Ҷ����� ī��Ʈ�� �ø���.
}

void DoublyCircularLinkedList::insert(int index, int value) {
    if (index < 0 || index > count) return; // ���� �ְ� ���� ��ġ�� ���̳ʽ��̸� �ȵȰ��Ѵ�. ����  �ְ� ���� ��ġ�� ���� ����Ʈ���� Ŭ ��쿡�� �Լ��� �����Ѵ�.

    Node* current = dummyHead; // ������ �̸��� ������ּҰ� �����Ѵ� ���� ������带 �ִ´�.  ������� ���� �����ؾ��ϱ� �����̴�
    for (int i = 0; i < index; ++i) // �ְ� ���� ��ġ���� �����带 �̵� ��Ų��. 
        current = current->next;

    Node* newNode = new Node(value);// ����� ����� 
    Node* nextNode = current->next;// �̵���Ų ������ ������ ������忡 �ִ´�.

    newNode->next = nextNode;  // ���θ��� ����� ������ ������忡 �ִ´�
    newNode->prev = current; // ���� ���� ����� ������ ���翡 ���� ��Ų��.
    current->next = newNode; // �������� ���� ��带 ����忡 ���� ��Ų��.
    nextNode->prev = newNode; // ���� ����� ������ ���� ���� ��忡 ���� ��Ų��

    // ������ ��带 �����ϰ� ���� ��带 ���� ��Ų��.
    count++;
}

void DoublyCircularLinkedList::remove(int index) {
    if (index < 0 || index >= count) return; //���־��ϴ� �ڸ����ڰ� 0���� �۰ų� ����Ʈ���� ū ���ڸ� �Է��Ұ�� �����Ѵ�.

    Node* current = dummyHead->next; // ��������� ������ current�� �̸� ���δ�.
    for (int i = 0; i < index; ++i) //current�� �̵���Ų��. index�� ���� ��ŭ
        current = current->next;

    Node* prevNode = current->prev; // current�� ������ ����Ű�� ��带 �������
    Node* nextNode = current->next; // current�� ������ ����Ű�� ��带 �������

    prevNode->next = nextNode; //��������� ������ �������� ���� ��Ų��.
    nextNode->prev = prevNode; // ��������� ������ �������� ���� ��Ų��.
    //current ������ ���� ��带 ���� ���Ѽ� current�� ���ֵ� ����Ʈ�� ���������ʰ� �Ѵ�.

    delete current; // current�� �ڸ��� �ִ� ��� ���� 
    count--; // ī��Ʈ -1 
}

int DoublyCircularLinkedList::get(int index) const {
    if (index < 0 || index >= count) return -1; // ���� ���ڰ� ���̳ʽ� �̰ų� 

    Node* current = dummyHead->next; // ��������� ���� ��带 current��� �̸����� ���Ѵ�.
    for (int i = 0; i < index; ++i) // current�� ��ġ�� �̵� ��Ų��. 
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
