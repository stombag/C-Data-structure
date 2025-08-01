#pragma once

class ArrayGraph {
private:
	int** adjMatrix; //2차원 배열로 인접 행렬
	int numVertices; // 정점 개수 
public:
	ArrayGraph(int vertices); 
	~ArrayGraph();

	void addEdge(int i, int j); // 간선 추가
	void removeEdge(int i, int j);// 간선 제거
	bool isConnected(int i, int j); //간선 존재 여부 확인 
	void display(); // 인접행렬 출력 
};
