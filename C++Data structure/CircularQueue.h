#pragma once
#include <iostream>
using namespace std;

class CircularQueue {
private:
    struct Node {
        int data; // �� ������
        Node* next; // ���� ��带 ����Ű�� �ּҰ��� �����ϴ°�
        Node(int value) : data(value), next(nullptr) {} // �ʱ�ȭ
    };

    Node* rear; // ������ ��� (rear->next�� front)
    int size;  // ����� Ȯ���� �� �ְ� �Ѵ�.

public:
    CircularQueue();
    ~CircularQueue();

    void push(int value);         // rear�� ����
    int remove();                 // front���� ����
    void insert(int index, int value); // index ��ġ�� ���� (�н���)
    int count() const;           // ��� �� ��ȯ
    void print() const;          // ť ���� ���
};
