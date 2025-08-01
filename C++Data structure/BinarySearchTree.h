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
    void preorder(Node* node);     // ���� ��ȸ �߰�
    void postorder(Node* node);    // ���� ��ȸ �߰�
    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    void destroyTree(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    bool search(int value); // ���� Ž��

    void inorder();
    void preorder();     // ���� ��ȸ �Լ� �������̽�
    void postorder();    // ���� ��ȸ �Լ� �������̽�
    void remove(int value);
};
