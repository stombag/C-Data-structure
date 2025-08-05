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
	
	// ����
	// �� ���� 
	heap.heapSort();
	heap.print(); // ���: 60 40 50 10 30
	cout << endl;

	// ���� ���� 
	cout << "���� ����" << endl;
	MergeArray ma;
	ma.insert(42);
	ma.insert(3);
	ma.insert(40);
	ma.insert(29);
	ma.insert(56);
	ma.print();
	cout << "���� ";
	ma.sort();
	ma.print();
	cout << endl;

	// �� ���� 
	cout << "�� ����" << endl;
	QuickArray qa;
	qa.insert(39);
	qa.insert(10);
	qa.insert(29);
	qa.insert(54);
	qa.insert(9);
	qa.print();
	cout << "����" << endl;
	qa.sort();
	qa.print();	
	cout << endl;

	// ���� ���� 
	cout << "���� ����" << endl;
	BubbleArray ba;
	ba.insert(5);
	ba.insert(2);
	ba.insert(7);
	ba.insert(8);
	ba.insert(9);
	ba.insert(3);
	ba.insert(1);
	ba.print();
	cout << "����" << endl;
	ba.sort();
	ba.print();
	cout << endl;

	//���� ���� 
	cout << "���� ����" << endl;
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
	cout << "����" << endl;
	sar.sort();
	sar.print();
	cout << endl;

	// Ž�� 
	// ���� Ž��
	heap.linearSearch(40);
	heap.linearSearch(23);
	cout << endl;

	// ���� Ž��
	SortedArray sa;
	sa.insert(3);
	sa.insert(5);
	sa.insert(4);
	sa.insert(7);
	sa.insert(9);
	sa.print();
	sa.search(4);
	cout << endl;

	//���� Ž�� Ʈ�� 
	cout << "���� Ž�� Ʈ��" << endl;
	BinarySearchTree bst;
	bst.insert(1);
	bst.insert(3);
	bst.insert(7);
	bst.insert(6);
	bst.insert(35);
	bst.insert(9);
	bst.insert(45);

	// ������ ���� ���
	cout << "�������� ���" << endl;
	bst.inorder();
	cout << endl;
	// ���� Ž�� Ʈ��
	cout << "7 Ž�� ���: " << (bst.search(7) ? "������" : "����") << endl;
    cout << "2 Ž�� ���: " << (bst.search(2) ? "������" : "����") << endl;
   // ����
    bst.remove(3);
    cout << "3 ���� �� ���� ��ȸ: ";
    bst.inorder();


	// Ʈ�� ��ȸ 
	bst.inorder(); //����
	bst.preorder();//����
	bst.postorder();//����

	cout << endl;

	ArrayGraph AG(5);

	AG.addEdge(0, 1);
    AG.addEdge(0, 2);
    AG.addEdge(1, 3);
	AG.addEdge(0, 4);
	cout << "�׷��� ���� ���:" << endl;
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

    std::cout << "�׷��� ���� ����Ʈ:" << std::endl;
    lg.display();
	lg.BFS(4);
	lg.dijkstra(0);


	return 0;


}
