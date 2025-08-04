#include <iostream>
#include "ArrayGraph.h"

using namespace std;
// 인접행렬

// 생성자
ArrayGraph::ArrayGraph(int vertices) {
    // 정점,노드의 수
    numVertices = vertices;


    // 2차원 배열 동적 생성
    adjMatrix = new int*[numVertices];
    // adjMatrix는 포인터 변수들을 저장하는 배열로 만들었다. 
    // 정수형 포인터(int*)를 numVerties개 저장할 수 있는 공간을 동적으로 확보한것이다. 
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
        // 하나씩 i번 삭제 
    }
    delete[] adjMatrix;
    // 변수 자체 삭제 ;
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
