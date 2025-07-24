#pragma once

#include<iostream> 

using namespace std;

class ArrayQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    ArrayQueue(int size = 100);
    ~ArrayQueue();

    void push(int value);              // ť�� �� �߰�
    int remove();                      // ť���� �� ����
    void insert(int index, int value); // ť �߰��� �� ���� (��ǥ��)
    int count() const;                // ť�� �ִ� ������ ����
    void print() const;               // ť ���� ���

    bool isEmpty() const;
    bool isFull() const;;
};
