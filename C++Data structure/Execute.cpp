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
	cout << "��ũ�� ����Ʈ" << endl;
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
	cout << "��� ��" << list.Count() << endl;
	cout << endl;

	cout << "���� ��ũ�� ����Ʈ" << endl;
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

	cout << "����� ���� ��ũ�� �� ����Ʈ" << endl;
	DoublyCircularLinkedList DClist;

	DClist.append(10);
	DClist.append(20);
	DClist.append(30);

	DClist.print();
	cout<< "2���� �ִ� �� "<< DClist.get(1) << endl;
	
	cout << "ũ�� " << DClist.size() << endl;
	DClist.clear();
	DClist.print();
	cout << endl;


	cout << "�迭 ����" << endl;
	Stack sList(5);

    sList.push(10);
    sList.push(20);
    sList.push(30);
    sList.print();  // 30 20 10

    int value;

    if (sList.pop(value))
        cout << "pop�� ��: " << value << endl;

    if (sList.pop(value))
        cout << "pop�� ��: " << value << endl;

    sList.print();  // ���� �� ���

	cout << endl;



	cout << "���� ����Ʈ ����" << endl;
	StackLinkedList SlList;
	SlList.push(100);
	SlList.push(200);
	SlList.push(300);
	SlList.print();
	cout << "����" << endl;
	SlList.pop();
	SlList.print();

	cout << "���� ���� �ִ� ��" << endl;
	cout << SlList.peek() << endl;
	cout << endl;



	cout << "�迭 ť" << endl;
	ArrayQueue queue(5);  // ũ�� 5�� ť ����
	// �� �߰�
	queue.push(10);
	queue.push(20);
	queue.push(30);
	cout << "ť ����: ";
	queue.print(); // 10 20 30

	// �߰��� ����
	queue.insert(1, 15); // 10 15 20 30
	cout << "���� ��: ";
	queue.print();

	// ����
	int removed = queue.remove(); // 10 ����
	cout << "���ŵ� ��: " << removed << endl;
	cout << "���� �� ť: ";
	queue.print();

	// ť�� ���� á���� Ȯ��
	queue.push(40);
	queue.push(50);
	queue.push(60); // ���� ��
	cout << "���� ť: ";
	queue.print();

	cout << "���� ť�� ����: " << queue.count() << endl;
	cout << "ť�� ����ִ°�? " << (queue.isEmpty() ? "��" : "�ƴϿ�") << endl;
	cout << "ť�� ���� á�°�? " << (queue.isFull() ? "��" : "�ƴϿ�") << endl;
	cout << endl;


	cout << "���� ť" << endl;
	CircularQueue Cqueue;  
	// �� �߰�
	Cqueue.push(10);
	Cqueue.push(20);
	Cqueue.push(30);
	Cqueue.print(); // 10 20 30
	
	// �� ����
	cout << "���ŵ� ��: " << Cqueue.remove() << endl; // 10
	Cqueue.print(); // 20 30
	
	// �� �߰� ���
	Cqueue.push(40);
	Cqueue.push(50);
	Cqueue.push(60); // ť�� ���� ��
	Cqueue.print(); // 20 30 40 50 60
	
	// �� ������ ����
	Cqueue.push(70); // ť�� ���� á���ϴ�.
	
	// �ϳ� ���� �� �ٽ� �߰�
	Cqueue.remove();
	Cqueue.push(70);
	Cqueue.print(); // 30 40 50 60 70
	cout << endl;


	cout << "��" << endl;
	Heap heap(10);

	heap.insert(50);
	heap.insert(30);
	heap.insert(10);
	heap.insert(60);
	heap.insert(40);
	heap.insert(20);
	heap.insert(199);


	cout << "�ִ�(top): " << heap.top() << endl;

	cout << "������ ��: " << heap.pop() << endl;
	heap.print(); // ���� ū �� ���� �� ���

	cout << "�ִ�(top): " << heap.top() << endl;

	cout << endl;
	heap.heapSort();
	heap.print(); // ���: 60 40 50 10 30
	cout << endl;
	heap.mergeSort();

	heap.print();

	cout << endl;
	heap.print();

	heap.selectionSort();
	heap.print();

	return 0;


}
