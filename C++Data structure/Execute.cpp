#include <iostream>

#include "LinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyCircularLinkedList.h"
#include "Stack.h"
#include "StackLinkedList.h"
#include "ArrayQueue.h"
#include "CircularQueue.h"
#include "Heap.h"
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
	heap.heapSort();
	heap.print(); // 출력: 60 40 50 10 30
	cout << endl;
	heap.mergeSort();

	heap.print();

	cout << endl;
	heap.print();

	heap.selectionSort();
	heap.print();

	return 0;


}
