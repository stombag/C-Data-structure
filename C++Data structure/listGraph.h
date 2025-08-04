#pragma once
#include <iostream>

class listGraph {
private:
    struct Node {
        int vertex; // ���� 
        Node* next; // ���� �̵��� �ּҰ��� ����

        Node(int v) : vertex(v), next(nullptr) {}
    };

    Node** adjList; // �� ������ ���� ���� ����Ʈ �迭 
    int numVertices;

  // ������ �迭 �ε���, ������ ���� ����Ʈ�� 

public:
    listGraph(int vertices);         // ������
    ~listGraph();                    // �Ҹ���

    void addEdge(int src, int dest);    // ���� �߰�
    void removeEdge(int src, int dest); // ���� ����
    void display();                     // �׷��� ���
};
