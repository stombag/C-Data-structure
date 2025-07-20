#pragma once

class VariadicCircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d = 0); // �⺻�� 0 (���� ����)
    };

    Node* dummy; // �׻� �����ϴ� ���� ��� (head ����)
    int Count;

public:
    VariadicCircularLinkedList(); // constructor
    ~VariadicCircularLinkedList();// destructor

    void push(int value);                  // �� ������ 
    void insert(int index, int value);     // Ư�� ��ġ�� ����
    void addMultiple(int count, ...);      // ���� ���� ����
    void print() const;                    // ��ü ���
    void clear();                          // ��� ��� ����
};
