#include "listGraph.h"

using namespace std;

const int INF = 1e9;

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
void listGraph::addEdge(int src, int dest, int weight) {
    Node* newNode = new Node(dest, weight);
    //dest���� ���� newNode�� ����� 
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src,weight);
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
void listGraph::BFS(int startVertex) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; ++i)
        visited[i] = false;

    // ť ���� ����
    int* queue = new int[numVertices]; // ���� ũ�� ť
    int front = 0;
    int rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    cout << "BFS ���� (���� " << startVertex << "): ";

    while (front < rear) {
        int currentVertex = queue[front++];  // dequeue
        cout << currentVertex << " ";

        Node* temp = adjList[currentVertex];
        while (temp) {
            int adj = temp->vertex;
            if (!visited[adj]) {
                visited[adj] = true;
                queue[rear++] = adj;  // enqueue
            }
            temp = temp->next;
        }
    }

    cout << endl;
    delete[] visited;
    delete[] queue;
}

void listGraph::dijkstra(int startVertex)
{
    int* distance = new int[numVertices];
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; ++i)
    {
        distance[i] = INF;
        visited[i] = false;

    }
    distance[startVertex] = 0;
  for (int count = 0; count < numVertices - 1; ++count) {
        // �湮���� ���� ���� �� ���� ����� ���� ã��
        int minDistance = INF;
        int minIndex = -1;

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) break; // ���� ���� ����

        visited[minIndex] = true;

        // ���� ���� �Ÿ� ����
        Node* current = adjList[minIndex];
        while (current) {
            int neighbor = current->vertex;
            int weight = current->weight;

            if (!visited[neighbor] && distance[minIndex] + weight < distance[neighbor]) {
                distance[neighbor] = distance[minIndex] + weight;
            }

            current = current->next;
        }
    }

    // ��� ���
    cout << "[���ͽ�Ʈ��] ���� ����: " << startVertex << "\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "���� " << i << "���� �Ÿ�: ";
        if (distance[i] == INF)
            cout << "���� �Ұ�\n";
        else
            cout << distance[i] << "\n";
    }

    delete[] distance;
    delete[] visited;
}
