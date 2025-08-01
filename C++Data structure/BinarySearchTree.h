#pragma once

#include <iostream>

using namespace std;

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value);
    };

    Node* root;

    void insert(Node*& node, int value);
    bool search(Node* node, int value);
    void inorder(Node* node);
    void preorder(Node* node);     // 전위 순회 추가
    void postorder(Node* node);    // 후위 순회 추가
    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    void destroyTree(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    bool search(int value); // 이진 탐색

    void inorder();
    void preorder();     // 전위 순회 함수 인터페이스
    void postorder();    // 후위 순회 함수 인터페이스
    void remove(int value);
};
