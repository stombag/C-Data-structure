#pragma once

#include <iostream> 
using namespace std;

class Heap {
private:
	int* heap; // 힙 데이터를 저장하는 동적 배열 포인터 
	int capacity; // 담을 수 있는 용량
	int size; // 현재 저장된 데이터의 수 

	void heapifyUP(int index); // 삽입 후 힙 성질을 유지 하기 위한 상향 이동 
	// 힙에 새로운 값을 삽입했을 때, 그 값이 힙의 규칙을 깨뜨릴 수 있으므로 
	// 그 값을 적절한 위치로 "위로 끝러 올려서 " 힙의 성질을 유지하는 함수 이다. 
    // 여기서 인덱스는 배열의 순서 12345를 의미한다 
	void heapifyDown(int index);// 삭제 후 성질을 유지하기 위한 하향 이동 
	// 위 두개 함수는 힙 정렬이 아니다 . 힙을 유지 하기 위한 장치인 것이다. 
public:
	Heap(int capacity = 100); // 매개변수로 용량 설정 
	~Heap();

	void insert(int value);
	int pop();
	int top() const;
	bool isEmpty() const;
	bool isFull() const;
	void print() const;
	// 힙은 완전 이진 트리의 일종으로 부모노드와 자식 노드 간의 우선 순위 조건을 만족하는 자료구조이다. 
	// 삽입 - 삭제 O(log N), 검색 루트만O(1), 그외는 O(N)
	// 배열로 구현한 이유는 힙은 완전 이진 트리이기 때문에 배열로 구현하면 매우 효율적이며, 
	// 연결 리스트로 구현하면 메모리 낭비, 느린 접근 속도, 복잡한 코드 등 여러 단점이 생기기 때문에 잘 사용하지 않는다. 


	void heapSort(); // 힙 정렬
	void mergeSort(); // 병렬 정렬
	void quicksort(); // 퀵 정렬
	void selectionSort(); // 선택 정렬
	void bubbleSort(); // 버블 정렬 
	
};