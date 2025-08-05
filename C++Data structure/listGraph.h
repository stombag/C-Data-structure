#pragma once
#include <iostream>

class listGraph {
private:
    struct Node {
        int vertex; // ���� 
        int weight;
        Node* next; // ���� �̵��� �ּҰ��� ����

        Node(int v, int w ) : vertex(v),weight(w), next(nullptr) {}
    };

    Node** adjList; // �� ������ ���� ���� ����Ʈ �迭 
    int numVertices;

  // ������ �迭 �ε���, ������ ���� ����Ʈ�� 

public:
    listGraph(int vertices);         // ������
    ~listGraph();                    // �Ҹ���

    void addEdge(int src, int dest, int weight);    // ���� �߰�
    void removeEdge(int src, int dest); // ���� ����
    void display();                     // �׷��� ���

    void BFS(int startVertex);
    void dijkstra(int startVertex);
};
