#pragma once
#include <iostream>

class listGraph {
private:
    struct Node {
        int vertex; // 점선 
        Node* next; // 다음 이동할 주소값을 적용

        Node(int v) : vertex(v), next(nullptr) {}
    };

    Node** adjList; // 각 정점에 대한 연결 리스트 배열 
    int numVertices;

  // 정점은 배열 인덱스, 간선은 연결 리스트를 

public:
    listGraph(int vertices);         // 생성자
    ~listGraph();                    // 소멸자

    void addEdge(int src, int dest);    // 간선 추가
    void removeEdge(int src, int dest); // 간선 제거
    void display();                     // 그래프 출력
};
