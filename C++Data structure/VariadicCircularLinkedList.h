#pragma once

class VariadicCircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d = 0); // 기본값 0 (더미 노드용)
    };

    Node* dummy; // 항상 존재하는 더미 노드 (head 역할)
    int Count;

public:
    VariadicCircularLinkedList(); // constructor
    ~VariadicCircularLinkedList();// destructor

    void push(int value);                  // 맨 끝부터 
    void insert(int index, int value);     // 특정 위치에 삽입
    void addMultiple(int count, ...);      // 가변 인자 삽입
    void print() const;                    // 전체 출력
    void clear();                          // 모든 노드 삭제
};
