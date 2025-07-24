#pragma once

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int capacity = 100);
    ~CircularQueue();

    void push(int value);   // ť�� �� �߰�
    int remove();           // ť���� �� ����
    int count() const;      // ��� ����
    void print() const;     // ť ���� ���

    bool isEmpty() const;
    bool isFull() const;
};
