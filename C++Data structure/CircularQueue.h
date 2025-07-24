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

    void push(int value);   // 큐에 값 추가
    int remove();           // 큐에서 값 제거
    int count() const;      // 요소 개수
    void print() const;     // 큐 내용 출력

    bool isEmpty() const;
    bool isFull() const;
};
