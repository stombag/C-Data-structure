#include "listGraph.h"

using namespace std;

// ������
listGraph::listGraph(int vertices) {
    numVertices = vertices;
    adjList = new Node*[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr; // �ʱ�ȭ
    }
}

// �Ҹ���
listGraph::~listGraph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjList[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}

// ���� �߰� (������ �׷���)
void listGraph::addEdge(int src, int dest) {
    Node* newNode = new Node(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// ���� ����
void listGraph::removeEdge(int src, int dest) {
    Node** current = &adjList[src];
    while (*current) {
        if ((*current)->vertex == dest) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            break;
        }
        current = &((*current)->next);
    }

    current = &adjList[dest];
    while (*current) {
        if ((*current)->vertex == src) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            break;
        }
        current = &((*current)->next);
    }
}

// �׷��� ���
void listGraph::display() {
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " -> ";
        Node* temp = adjList[i];
        while (temp) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
