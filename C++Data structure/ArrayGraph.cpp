#include <iostream>
#include "ArrayGraph.h"

using namespace std;
// �������

// ������
ArrayGraph::ArrayGraph(int vertices) {
    // ����,����� ��
    numVertices = vertices;


    // 2���� �迭 ���� ����
    adjMatrix = new int*[numVertices];
    // adjMatrix�� ������ �������� �����ϴ� �迭�� �������. 
    // ������ ������(int*)�� numVerties�� ������ �� �ִ� ������ �������� Ȯ���Ѱ��̴�. 
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = 0; // �ʱ�ȭ
        }
    }
}

// �Ҹ���
ArrayGraph::~ArrayGraph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjMatrix[i];
        // �ϳ��� i�� ���� 
    }
    delete[] adjMatrix;
    // ���� ��ü ���� ;
}

// ���� �߰�
void ArrayGraph::addEdge(int i, int j) {
    if (i >= 0 && j >= 0 && i < numVertices && j < numVertices) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // ������ �׷���
    }
}

// ���� ����
void ArrayGraph::removeEdge(int i, int j) {
    if (i >= 0 && j >= 0 && i < numVertices && j < numVertices) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }
}

// ���� ���� Ȯ��
bool ArrayGraph::isConnected(int i, int j) {
    return adjMatrix[i][j] == 1;
}

// ���
void ArrayGraph::display() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
