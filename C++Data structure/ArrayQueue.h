#pragma once

#include<iostream> 

using namespace std;

class ArrayQueue {
private:
    int* arr; // �迭 
    int front; // ��
    int rear; // �� 
    int capacity; // �뷮

public:
    ArrayQueue(int size = 100); // �뷮�� �����ڿ��� ���ϱ� 
    ~ArrayQueue(); // �Ҹ��� 

    void push(int value);              // ť�� �� �߰�
    int remove();                      // ť���� �� ����
    void insert(int index, int value); // ť �߰��� �� ���� (��ǥ��)
    int count() const;                // ť�� �ִ� ������ ����
    void print() const;               // ť ���� ���

    bool isEmpty() const; // ��� �ִ��� Ȯ��
    bool isFull() const; // ���� ä�����ִ��� Ȯ�� 
};
