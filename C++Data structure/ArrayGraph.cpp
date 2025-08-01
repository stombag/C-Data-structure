#include <iostream>
#include "ArrayGraph.h"

using namespace std;

// 생성자
ArrayGraph::ArrayGraph(int vertices) {
    numVertices = vertices;

    // 2차원 배열 동적 생성
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = 0; // 초기화
        }
    }
}

// 소멸자
ArrayGraph::~ArrayGraph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

// 간선 추가
void ArrayGraph::addEdge(int i, int j) {
    if (i >= 0 && j >= 0 && i < numVertices && j < numVertices) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // 무방향 그래프
    }
}

// 간선 제거
void ArrayGraph::removeEdge(int i, int j) {
    if (i >= 0 && j >= 0 && i < numVertices && j < numVertices) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }
}

// 연결 여부 확인
bool ArrayGraph::isConnected(int i, int j) {
    return adjMatrix[i][j] == 1;
}

// 출력
void ArrayGraph::display() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
