#pragma once

class CircularLinkedList {
private: 
    struct Node {
        // ��� ��ü ����� 
    int data; // ��忡 �� ������
    Node* next; // ������� �ּҰ� �����ϱ�

    Node(int d = 0) : data(d), next(nullptr) {} // �ʱ�ȭ 

};
    Node* dummyHead; // ������� 
    int count ;

public:
    CircularLinkedList(); // ������
    ~CircularLinkedList(); // �Ҹ��� 
 
    void Push(int value);

    void insert(int index, int value);

    void remove(int index);

    int get(int index)const;

    void Print()const;

    void claen();

};
