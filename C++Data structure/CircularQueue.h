#pragma once
#include <iostream>
using namespace std;

class CircularQueue {
private:
    struct Node {
        int data; // 들어갈 데이터
        Node* next; // 다음 노드를 가리키는 주소값을 저장하는곳
        Node(int value) : data(value), next(nullptr) {} // 초기화
    };

    Node* rear; // 마지막 노드 (rear->next가 front)
    int size;  // 사이즈를 확인할 수 있게 한다.

public:
    CircularQueue();
    ~CircularQueue();

    void push(int value);         // rear에 삽입
    int remove();                 // front에서 삭제
    void insert(int index, int value); // index 위치에 삽입 (학습용)
    int count() const;           // 노드 수 반환
    void print() const;          // 큐 내용 출력
};
