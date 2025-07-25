#pragma once

#include<iostream> 

using namespace std;

class ArrayQueue {
private:
    int* arr; // 배열 
    int front; // 앞
    int rear; // 뒤 
    int capacity; // 용량

public:
    ArrayQueue(int size = 100); // 용량을 생성자에서 정하기 
    ~ArrayQueue(); // 소멸자 

    void push(int value);              // 큐에 값 추가
    int remove();                      // 큐에서 값 제거
    void insert(int index, int value); // 큐 중간에 값 삽입 (비표준)
    int count() const;                // 큐에 있는 데이터 개수
    void print() const;               // 큐 내용 출력

    bool isEmpty() const; // 비워 있는지 확인
    bool isFull() const; // 가득 채워져있는지 확인 
};
