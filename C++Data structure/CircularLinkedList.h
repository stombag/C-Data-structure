#pragma once

class CircularLinkedList {
private: 
    struct Node {
        // 노드 객체 만들기 
    int data; // 노드에 들어갈 데이터
    Node* next; // 다음노드 주소값 저장하기

    Node(int d = 0) : data(d), next(nullptr) {} // 초기화 

};
    Node* dummyHead; // 더미헤드 
    int count ;

public:
    CircularLinkedList(); // 생성자
    ~CircularLinkedList(); // 소멸자 
 
    void Push(int value);

    void insert(int index, int value);

    void remove(int index);

    int get(int index)const;

    void Print()const;

    void claen();

};
