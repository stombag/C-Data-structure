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
    //root부터 탐색시작 
    // 실제 탐색 로직은 밑에 있는 함수이다. 
}

bool BinarySearchTree::search(Node* node, int value) {
    if (!node) return false;
    // 현재 노드가 nullptr이라면 트리의 끝까지 갔는데도 못찾았다는 의미다 
    if (value == node->data) return true;
    // 현재 노드에 저장된 값이 찾고 있는 값과 같다면 탐색에 성공했다는 의미이다. 
    if (value < node->data) return search(node->left, value);
    // 찾고 있는 값이 현재 노드의 값보다 작으면 왼쪽 서브 트리로 이동하여 탐색을 계속한다는 의미이다.
    else return search(node->right, value);
    //만약 왼쪽이 아니면 오른쪽 서브트리로 이동하여 탐색을 계속한다. 
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
        // 삭제할 노드 찾음
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

// 전위 순회
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

// 후위 순회
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

