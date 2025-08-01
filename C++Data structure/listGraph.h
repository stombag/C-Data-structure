#pragma once
#include <iostream>

class listGraph {
private:
    struct Node {
        int vertex;
        Node* next;

        Node(int v) : vertex(v), next(nullptr) {}
    };

    Node** adjList; // �� ������ ���� ���� ����Ʈ �迭
    int numVertices;

public:
    listGraph(int vertices);         // ������
    ~listGraph();                    // �Ҹ���

    void addEdge(int src, int dest);    // ���� �߰�
    void removeEdge(int src, int dest); // ���� ����
    void display();                     // �׷��� ���
};
