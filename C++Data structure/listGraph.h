#pragma once
#include <iostream>

class listGraph {
private:
    struct Node {
        int vertex;
        Node* next;

        Node(int v) : vertex(v), next(nullptr) {}
    };

    Node** adjList; // 각 정점에 대한 연결 리스트 배열
    int numVertices;

public:
    listGraph(int vertices);         // 생성자
    ~listGraph();                    // 소멸자

    void addEdge(int src, int dest);    // 간선 추가
    void removeEdge(int src, int dest); // 간선 제거
    void display();                     // 그래프 출력
};
