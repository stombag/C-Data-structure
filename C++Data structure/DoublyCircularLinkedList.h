#pragma once
#include <iostream>

class DoublyCircularLinkedList {
private:
    struct Node {
        int data;
        Node* prev;//이전노드
        Node* next;// 다음노드

        Node(int d = 0) : data(d), prev(nullptr), next(nullptr) {} // 초기화 
    };

    Node* dummyHead;// 더미헤드 
    int count; //카운드 

public:
    DoublyCircularLinkedList(); //생성자

    ~DoublyCircularLinkedList();//소멸자

    void append(int value);// 넣기
    void insert(int index, int value);//삽입
    void remove(int index);//삭제
    int get(int index) const; //가져오기
    
    void print() const; // 출력
    void clear(); // 다 지우기
    int size() const; // 사이즈 확인
};
