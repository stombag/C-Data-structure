#include <iostream>
#include "CircularLinkedList.h"
#include "RadixSort.h"

using namespace std;

// ������ 


CircularLinkedList::CircularLinkedList()
{
    dummyHead = new Node();         // ���� ��� ����
    // ������忡 ���ο� ��带 �ֱ� 
    dummyHead->next = dummyHead;    // ���� ����
    // ������忡 ���� ��带 ���� �������� �ֱ� 
    count = 0;
}

// �Ҹ���
CircularLinkedList::~CircularLinkedList() {
    Node* current = dummyHead->next;
    // ��������� ���� ����� �̸��� current�� ���ϱ�
    while (current != dummyHead) {
        // current�� ������尡 �ƴҶ����� �����Ѵ�
        Node* temp = current; // curret�� temp�� ���Ѵ�.
        current = current->next; // current�� ���� ��带 current�� �ִ´�.
        delete temp; // temp�� �ִ� �ش� �ּҰ��� �����Ѵ�.

        // tem�� current�� �ּҰ��� �ְ� �����ٿ� current�� ���� ���� �̵���Ų��.
        // tem�� current�� ���� ������ �־��� �ּҰ��� ������ �־� �װ� �����Ѵ�.
        // �̰����� �ݺ��ؼ� ��带 �� �����ϰ� current�� ������尡 �ɶ� ���ฦ �����Ѵ�
    }
    delete dummyHead;  // ���� ��� ����
}

void CircularLinkedList::Push(int value)
{
    // ���� ���� 
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
    // ���� �ε����� ���̳ʽ� �̸� ������ ���� �ʰ� �ϰ�
    //  index�� count���� ���� ��� ���� ������� �ʴ´�.
    Node* newNode = new Node();


    newNode->data = value;

    Node* current = dummyHead->next;

    while (index-- > 0)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;

    count++;
}

void CircularLinkedList::remove(int index)
{
    if (index < 0 || index >= count) return;
    // �ε����� 0���� �����ϹǷ� ���� ������ �ִ� �ε����� 1�̴�.
    //���� index == count�� ���� �������� �ʴ� ����̹Ƿ� �����ϸ� �ȵȴ�.
    if (count == 0) {
        cout << "����Ʈ�� ����ִ�" << endl;
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
        cout << "�ٽ� �Է����ּ���" << endl;
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
        cout << "��� �ֽ��ϴ�." << endl;
        return;
    }

    cout << "����Ʈ ����: ";

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
