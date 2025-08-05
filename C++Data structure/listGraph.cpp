#include "listGraph.h"

using namespace std;

const int INF = 1e9;

// 인접 리스트
// 생성자
listGraph::listGraph(int vertices) {
    numVertices = vertices;
    adjList = new Node*[numVertices];
// 노드 크기 동적할당으로 할당 하기 
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr; // 초기화
        // 할당 받은 list를 초기화 한다. 
    }
}
// 생성자에서 정점을 먼저 다 만들어 넣는다. 

// 소멸자
listGraph::~listGraph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjList[i];
        // 현재 노드를 하나씩 넣는다. 
        while (current) { // 현재 노드가 존재 할때 실행된다.
            Node* temp = current;
            // 현재의 주소값을 temp에 넣어서 나중에 삭제한다. 
            current = current->next;
            // 현재를 이동시킨다. 
            delete temp;
        }
    }
    // 노드를 다 제거하면 리스트를 제거한다. 
    delete[] adjList;
}

// 간선 추가 (무방향 그래프)
// 정점에서 간선추가 
void listGraph::addEdge(int src, int dest, int weight) {
    Node* newNode = new Node(dest, weight);
    //dest값을 갖는 newNode를 만들어 
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src,weight);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;

    // 서로 가르키게 한다. 
} 

// 간선 제거
void listGraph::removeEdge(int src, int dest) {
    Node** current = &adjList[src];
    // adjList[src]는 정점 src의 연결 리스트 시작 노드
    // 그 포인터 주소를 current에 저장한다. 
    //**current는 그럼  그 노드를 가리킨다. 
    while (*current) {
        // current가 가리키는 주소가 있으면 계속 한다. 
        // dest부터 
        if ((*current)->vertex == dest) {

            Node* temp = *current;
            *current = (*current)->next;
            // *current 자리 다음 주소로 옮기기 
            delete temp;
            // 임시 노드 없애고 while문을 정지 시킨다. 
            break;
        }
        current = &((*current)->next);
        // 다음 노드로 이동 
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

// 그래프 출력
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

    // 큐 직접 구현
    int* queue = new int[numVertices]; // 고정 크기 큐
    int front = 0;
    int rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    cout << "BFS 시작 (정점 " << startVertex << "): ";

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
        // 방문하지 않은 정점 중 가장 가까운 정점 찾기
        int minDistance = INF;
        int minIndex = -1;

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) break; // 남은 정점 없음

        visited[minIndex] = true;

        // 인접 정점 거리 갱신
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

    // 결과 출력
    cout << "[다익스트라] 시작 정점: " << startVertex << "\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "정점 " << i << "까지 거리: ";
        if (distance[i] == INF)
            cout << "도달 불가\n";
        else
            cout << distance[i] << "\n";
    }

    delete[] distance;
    delete[] visited;
}
