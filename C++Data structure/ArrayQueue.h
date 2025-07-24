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

    void push(int value);              // 큐에 값 추가
    int remove();                      // 큐에서 값 제거
    void insert(int index, int value); // 큐 중간에 값 삽입 (비표준)
    int count() const;                // 큐에 있는 데이터 개수
    void print() const;               // 큐 내용 출력

    bool isEmpty() const;
    bool isFull() const;;
};
