#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinarySearchTree::insert(int value) {
    insert(root, value);
}

void BinarySearchTree::insert(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

bool BinarySearchTree::search(int value) {
    return search(root, value);
    //root���� Ž������ 
    // ���� Ž�� ������ �ؿ� �ִ� �Լ��̴�. 
}

bool BinarySearchTree::search(Node* node, int value) {
    if (!node) return false;
    // ���� ��尡 nullptr�̶�� Ʈ���� ������ ���µ��� ��ã�Ҵٴ� �ǹ̴� 
    if (value == node->data) return true;
    // ���� ��忡 ����� ���� ã�� �ִ� ���� ���ٸ� Ž���� �����ߴٴ� �ǹ��̴�. 
    if (value < node->data) return search(node->left, value);
    // ã�� �ִ� ���� ���� ����� ������ ������ ���� ���� Ʈ���� �̵��Ͽ� Ž���� ����Ѵٴ� �ǹ��̴�.
    else return search(node->right, value);
    //���� ������ �ƴϸ� ������ ����Ʈ���� �̵��Ͽ� Ž���� ����Ѵ�. 
}

void BinarySearchTree::inorder() {
    inorder(root);
    cout << endl;
}

void BinarySearchTree::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BinarySearchTree::remove(int value) {
    root = remove(root, value);
}

BinarySearchTree::Node* BinarySearchTree::remove(Node* node, int value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        // ������ ��� ã��
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// ���� ��ȸ
void BinarySearchTree::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BinarySearchTree::preorder() {
    cout << "[Preorder] ";
    preorder(root);
    cout << endl;
}

// ���� ��ȸ
void BinarySearchTree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

void BinarySearchTree::postorder() {
    cout << "[Postorder] ";
    postorder(root);
    cout << endl;
}

