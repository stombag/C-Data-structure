#pragma once

class ArrayGraph {
private:
	int** adjMatrix; //2���� �迭�� ���� ���
	// �������� ũ���� �׷����� ����� ���ؼ� 2�� �����͸� �����ߴ�.
	// �������� �����ϸ� Ŭ������ ��� ������ �ٷ�� ����.
	int numVertices; // ���� ���� 

	void DFSUtil(int vertex, bool* visited);
public:
	ArrayGraph(int vertices); 
	~ArrayGraph();

	void addEdge(int i, int j); // ���� �߰�
	void removeEdge(int i, int j);// ���� ����
	bool isConnected(int i, int j); //���� ���� ���� Ȯ�� 
	void display(); // ������� ��� 

	void DFS(int startVertex);
};
