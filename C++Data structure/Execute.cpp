#include <iostream>

#include "LinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyCircularLinkedList.h"
#include "Stack.h"
#include "StackLinkedList.h"
#include "ArrayQueue.h"
#include "CircularQueue.h"
#include "Heap.h"
#include "SortedArray.h"
#include "MergeArray.h"
#include "QuickArray.h"
#include "BubbleArray.h"
#include "SelectionArray.h"
#include"BinarySearchTree.h"
#include "ArrayGraph.h"
#include "listGraph.h"

using namespace std;

int main()
{
	cout << "링크드 리스트" << endl;
	LinkedList list;
	list.Push(10);
	list.Push(20);
	list.Push(30);
	list.print();

	list.Insert(1, 49);
	list.print();

	list.Remove(2);
	list.print();

	cout << "2" << list.Get(2) << endl;
	cout << "노드 수" << list.Count() << endl;
	cout << endl;

	cout << "원형 링크드 리스트" << endl;
	CircularLinkedList CList;

	CList.Push(19);
	CList.Push(20);
	CList.Push(49);
	CList.Print();
	
	CList.insert(1, 59);
	CList.Print();
	
	CList.remove(3);
	CList.Print();

	cout << CList.get(2) << endl;

	CList.Print();
	CList.claen();

	cout << endl;

	cout << "양방향 원형 링크드 더 리스트" << endl;
	DoublyCircularLinkedList DClist;

	DClist.append(10);
	DClist.append(20);
	DClist.append(30);

	DClist.print();
	cout<< "2번에 있는 값 "<< DClist.get(1) << endl;
	
	cout << "크기 " << DClist.size() << endl;
	DClist.clear();
	DClist.print();
	cout << endl;


	cout << "배열 스택" << endl;
	Stack sList(5);

    sList.push(10);
    sList.push(20);
    sList.push(30);
    sList.print();  // 30 20 10

    int value;

    if (sList.pop(value))
        cout << "pop된 값: " << value << endl;

    if (sList.pop(value))
        cout << "pop된 값: " << value << endl;

    sList.print();  // 남은 값 출력

	cout << endl;



	cout << "연결 리스트 스택" << endl;
	StackLinkedList SlList;
	SlList.push(100);
	SlList.push(200);
	SlList.push(300);
	SlList.print();
	cout << "삭제" << endl;
	SlList.pop();
	SlList.print();

	cout << "가장 위에 있는 것" << endl;
	cout << SlList.peek() << endl;
	cout << endl;



	cout << "배열 큐" << endl;
	ArrayQueue queue(5);  // 크기 5인 큐 생성
	// 값 추가
	queue.push(10);
	queue.push(20);
	queue.push(30);
	cout << "큐 상태: ";
	queue.print(); // 10 20 30

	// 중간에 삽입
	queue.insert(1, 15); // 10 15 20 30
	cout << "삽입 후: ";
	queue.print();

	// 제거
	int removed = queue.remove(); // 10 제거
	cout << "제거된 값: " << removed << endl;
	cout << "제거 후 큐: ";
	queue.print();

	// 큐가 가득 찼는지 확인
	queue.push(40);
	queue.push(50);
	queue.push(60); // 가득 참
	cout << "최종 큐: ";
	queue.print();

	cout << "현재 큐의 개수: " << queue.count() << endl;
	cout << "큐가 비어있는가? " << (queue.isEmpty() ? "예" : "아니오") << endl;
	cout << "큐가 가득 찼는가? " << (queue.isFull() ? "예" : "아니오") << endl;
	cout << endl;


	cout << "원형 큐" << endl;
	CircularQueue Cqueue;  
	// 값 추가
	Cqueue.push(10);
	Cqueue.push(20);
	Cqueue.push(30);
	Cqueue.print(); // 10 20 30
	
	// 값 제거
	cout << "제거된 값: " << Cqueue.remove() << endl; // 10
	Cqueue.print(); // 20 30
	
	// 값 추가 계속
	Cqueue.push(40);
	Cqueue.push(50);
	Cqueue.push(60); // 큐가 가득 참
	Cqueue.print(); // 20 30 40 50 60
	
	// 더 넣으면 실패
	Cqueue.push(70); // 큐가 가득 찼습니다.
	
	// 하나 제거 후 다시 추가
	Cqueue.remove();
	Cqueue.push(70);
	Cqueue.print(); // 30 40 50 60 70
	cout << endl;


	cout << "힙" << endl;
	Heap heap(10);

	heap.insert(50);
	heap.insert(30);
	heap.insert(10);
	heap.insert(60);
	heap.insert(40);
	heap.insert(20);
	heap.insert(199);
	cout << "최댓값(top): " << heap.top() << endl;
	cout << "삭제된 값: " << heap.pop() << endl;
	heap.print(); // 가장 큰 값 삭제 후 출력
	cout << "최댓값(top): " << heap.top() << endl;
	cout << endl;
	
	// 정렬
	// 힙 정렬 
	heap.heapSort();
	heap.print(); // 출력: 60 40 50 10 30
	cout << endl;

	// 병합 정렬 
	cout << "병합 정렬" << endl;
	MergeArray ma;
	ma.insert(42);
	ma.insert(3);
	ma.insert(40);
	ma.insert(29);
	ma.insert(56);
	ma.print();
	cout << "정렬 ";
	ma.sort();
	ma.print();
	cout << endl;

	// 퀵 정렬 
	cout << "퀵 정렬" << endl;
	QuickArray qa;
	qa.insert(39);
	qa.insert(10);
	qa.insert(29);
	qa.insert(54);
	qa.insert(9);
	qa.print();
	cout << "정렬" << endl;
	qa.sort();
	qa.print();	
	cout << endl;

	// 버블 정렬 
	cout << "버블 정렬" << endl;
	BubbleArray ba;
	ba.insert(5);
	ba.insert(2);
	ba.insert(7);
	ba.insert(8);
	ba.insert(9);
	ba.insert(3);
	ba.insert(1);
	ba.print();
	cout << "정렬" << endl;
	ba.sort();
	ba.print();
	cout << endl;

	//선택 정렬 
	cout << "선택 정렬" << endl;
	SelectionArray sar;
	sar.insert(231);
	sar.insert(223);
	sar.insert(41);
	sar.insert(23);
	sar.insert(251);
	sar.insert(64);
	sar.insert(76);
	sar.insert(235);
	sar.print();
	cout << "정렬" << endl;
	sar.sort();
	sar.print();
	cout << endl;

	// 탐색 
	// 선형 탐색
	heap.linearSearch(40);
	heap.linearSearch(23);
	cout << endl;

	// 이진 탐색
	SortedArray sa;
	sa.insert(3);
	sa.insert(5);
	sa.insert(4);
	sa.insert(7);
	sa.insert(9);
	sa.print();
	sa.search(4);
	cout << endl;

	//이진 탐색 트리 
	cout << "이진 탐색 트리" << endl;
	BinarySearchTree bst;
	bst.insert(1);
	bst.insert(3);
	bst.insert(7);
	bst.insert(6);
	bst.insert(35);
	bst.insert(9);
	bst.insert(45);

	// 오름차 정렬 출력
	cout << "오름차순 출력" << endl;
	bst.inorder();
	cout << endl;
	// 이진 탐색 트리
	cout << "7 탐색 결과: " << (bst.search(7) ? "존재함" : "없음") << endl;
    cout << "2 탐색 결과: " << (bst.search(2) ? "존재함" : "없음") << endl;
   // 삭제
    bst.remove(3);
    cout << "3 삭제 후 중위 순회: ";
    bst.inorder();


	// 트리 순회 
	bst.inorder(); //중위
	bst.preorder();//전위
	bst.postorder();//후위

	cout << endl;

	ArrayGraph AG(5);

	AG.addEdge(0, 1);
    AG.addEdge(0, 2);
    AG.addEdge(1, 3);
	AG.addEdge(0, 4);
	cout << "그래프 인접 행렬:" << endl;
    AG.display();

	AG.DFS(3);

	cout << endl;
	
	listGraph lg(5);
    lg.addEdge(0, 1,10);
	lg.addEdge(0, 4,5);
    lg.addEdge(1,2,1);
    lg.addEdge(2,3,4);
    lg.addEdge(4,1,3);
    lg.addEdge(4,2,9);
    lg.addEdge(4,3,2);

    std::cout << "그래프 인접 리스트:" << std::endl;
    lg.display();
	lg.BFS(4);
	lg.dijkstra(0);


	return 0;


}
