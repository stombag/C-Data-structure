#include <iostream>

#include "LinkedList.h"
#include "DoublyCircularLinkedList.h"
#include"VariadicCircularLinkedList.h"
#include "Stack.h"
#include "StackLinkedList.h"
#include "ArrayQueue.h"
#include "CircularQueue.h"
#include "Heap.h"
using namespace std;

int main()
{
	//LinkedList list;
	//list.Push(10);
	//list.Push(20);
	//list.Push(30);
	//list.print();

	//list.Insert(1, 49);
	//list.print();

	//list.Remove(2);
	//list.print();

	//cout << "2" << list.Get(2) << endl;
	//cout << "노드 수" << list.Count() << endl;


	//DoublyCircularLinkedList list;

	//list.append(10);
	//list.append(20);
	//list.print();
	//cout<< list.get(1) <<endl;
	//
	//list.size();
	//list.clear();
	//list.print();


	//VariadicCircularLinkedList list;
 //   list.push(100);              // 맨 앞에 100 추가
	//list.push(200);
	//list.insert(2, 111);
	//list.push(300);
	//list.addMultiple(5,12,22, 10, 22, 55);
 //   list.print(); // 출력 예: 100 -> 200 -> 10 -> 20 -> 30 -> (back to dummy)

	//list.addMultiple(5,12,22, 10, 22, 55);
 //   list.print(); // 출력 예: 100 -> 200 -> 10 -> 20 -> 30 -> (back to dummy)
 //   return 0;
   
	//Stack s(5);

 //   s.push(10);
 //   s.push(20);
 //   s.push(30);
 //   s.print();  // 30 20 10

 //   int value;

 //   if (s.pop(value))
 //       cout << "pop된 값: " << value << endl;

 //   if (s.pop(value))
 //       cout << "pop된 값: " << value << endl;

 //   s.print();  // 남은 값 출력
 //   return 0;


	//StackLinkedList sl;
	//sl.push(100);
	//sl.push(200);
	//sl.push(300);
	//sl.print();

	//sl.pop();
	//sl.print();

	//cout << sl.peek() << endl;
	//

	//return 0;


	//ArrayQueue queue(5);  // 크기 5인 큐 생성

	//// 값 추가
	//queue.push(10);
	//queue.push(20);
	//queue.push(30);
	//cout << "큐 상태: ";
	//queue.print(); // 10 20 30

	//// 중간에 삽입
	//queue.insert(1, 15); // 10 15 20 30
	//cout << "삽입 후: ";
	//queue.print();

	//// 제거
	//int removed = queue.remove(); // 10 제거
	//cout << "제거된 값: " << removed << endl;
	//cout << "제거 후 큐: ";
	//queue.print();

	//// 큐가 가득 찼는지 확인
	//queue.push(40);
	//queue.push(50);
	//queue.push(60); // 가득 참
	//cout << "최종 큐: ";
	//queue.print();

	//cout << "현재 큐의 개수: " << queue.count() << endl;
	//cout << "큐가 비어있는가? " << (queue.isEmpty() ? "예" : "아니오") << endl;
	//cout << "큐가 가득 찼는가? " << (queue.isFull() ? "예" : "아니오") << endl;

	//return 0;



	//CircularQueue queue(5);  // 크기가 5인 원형 큐 생성

	//// 값 추가
	//queue.push(10);
	//queue.push(20);
	//queue.push(30);
	//queue.print(); // 10 20 30

	//// 값 제거
	//cout << "제거된 값: " << queue.remove() << endl; // 10
	//queue.print(); // 20 30

	//// 값 추가 계속
	//queue.push(40);
	//queue.push(50);
	//queue.push(60); // 큐가 가득 참
	//queue.print(); // 20 30 40 50 60

	//// 더 넣으면 실패
	//queue.push(70); // 큐가 가득 찼습니다.

	//// 하나 제거 후 다시 추가
	//queue.remove();
	//queue.push(70);
	//queue.print(); // 30 40 50 60 70

	//// 큐 상태
	//cout << "현재 큐의 개수: " << queue.count() << endl;
	//cout << "큐가 비었나요? " << (queue.isEmpty() ? "예" : "아니오") << endl;
	//cout << "큐가 가득 찼나요? " << (queue.isFull() ? "예" : "아니오") << endl;

	//return 0;




	//Heap heap(10);

	//heap.insert(30);
	//heap.insert(10);
	//heap.insert(50);
	//heap.insert(40);
	//heap.insert(60);

	//heap.print(); // 출력: 60 40 50 10 30

	//cout << "최댓값(top): " << heap.top() << endl;

	//cout << "삭제된 값: " << heap.pop() << endl;
	//heap.print(); // 가장 큰 값 삭제 후 출력

	//cout << "최댓값(top): " << heap.top() << endl;

	//return 0;


}
