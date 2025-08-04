#include "listGraph.h"

using namespace std;
// ���� ����Ʈ
// ������
listGraph::listGraph(int vertices) {
    numVertices = vertices;
    adjList = new Node*[numVertices];
// ��� ũ�� �����Ҵ����� �Ҵ� �ϱ� 
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr; // �ʱ�ȭ
        // �Ҵ� ���� list�� �ʱ�ȭ �Ѵ�. 
    }
}
// �����ڿ��� ������ ���� �� ����� �ִ´�. 

// �Ҹ���
listGraph::~listGraph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjList[i];
        // ���� ��带 �ϳ��� �ִ´�. 
        while (current) { // ���� ��尡 ���� �Ҷ� ����ȴ�.
            Node* temp = current;
            // ������ �ּҰ��� temp�� �־ ���߿� �����Ѵ�. 
            current = current->next;
            // ���縦 �̵���Ų��. 
            delete temp;
        }
    }
    // ��带 �� �����ϸ� ����Ʈ�� �����Ѵ�. 
    delete[] adjList;
}

// ���� �߰� (������ �׷���)
// �������� �����߰� 
void listGraph::addEdge(int src, int dest) {
    Node* newNode = new Node(dest);
    //dest���� ���� newNode�� ����� 
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;

    // ���� ����Ű�� �Ѵ�. 
} 

// ���� ����
void listGraph::removeEdge(int src, int dest) {
    Node** current = &adjList[src];
    // adjList[src]�� ���� src�� ���� ����Ʈ ���� ���
    // �� ������ �ּҸ� current�� �����Ѵ�. 
    //**current�� �׷�  �� ��带 ����Ų��. 
    while (*current) {
        // current�� ����Ű�� �ּҰ� ������ ��� �Ѵ�. 
        // dest���� 
        if ((*current)->vertex == dest) {

            Node* temp = *current;
            *current = (*current)->next;
            // *current �ڸ� ���� �ּҷ� �ű�� 
            delete temp;
            // �ӽ� ��� ���ְ� while���� ���� ��Ų��. 
            break;
        }
        current = &((*current)->next);
        // ���� ���� �̵� 
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
