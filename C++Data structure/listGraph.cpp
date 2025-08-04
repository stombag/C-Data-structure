#include "listGraph.h"

using namespace std;
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
void listGraph::addEdge(int src, int dest) {
    Node* newNode = new Node(dest);
    //dest값을 갖는 newNode를 만들어 
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src);
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
