#pragma once

class ArrayGraph {
private:
	int** adjMatrix; //2차원 배열로 인접 행렬
	// 유동적인 크기의 그래프를 만들기 위해서 2중 포인터를 선언했다.
	// 동적으로 생성하면 클래스의 멤버 변수로 다루기 쉽다.
	int numVertices; // 정점 개수 

	void DFSUtil(int vertex, bool* visited);
public:
	ArrayGraph(int vertices); 
	~ArrayGraph();

	void addEdge(int i, int j); // 간선 추가
	void removeEdge(int i, int j);// 간선 제거
	bool isConnected(int i, int j); //간선 존재 여부 확인 
	void display(); // 인접행렬 출력 

	void DFS(int startVertex);
};
