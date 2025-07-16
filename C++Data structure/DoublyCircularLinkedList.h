#pragma once
#include <iostream>

class DoublyCircularLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int d = 0) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* dummyHead;
    int count;

public:
    DoublyCircularLinkedList();

    ~DoublyCircularLinkedList();

    void append(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index) const;
    
    void print() const;
    void clear();
    int size() const;
};
