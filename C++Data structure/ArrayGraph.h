#pragma once

class ArrayGraph {
private:
	int** adjMatrix; //2���� �迭�� ���� ���
	int numVertices; // ���� ���� 
public:
	ArrayGraph(int vertices); 
	~ArrayGraph();

	void addEdge(int i, int j); // ���� �߰�
	void removeEdge(int i, int j);// ���� ����
	bool isConnected(int i, int j); //���� ���� ���� Ȯ�� 
	void display(); // ������� ��� 
};
