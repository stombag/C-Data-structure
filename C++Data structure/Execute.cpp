#include <iostream>

#include "LinkedList.h"
#include "DoublyCircularLinkedList.h"
#include"VariadicCircularLinkedList.h"

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


	VariadicCircularLinkedList list;
    list.push(100);              // 맨 앞에 100 추가
	list.push(200);
	list.insert(2, 111);
	list.push(300);
	list.addMultiple(3, 19, 22, 55);
    list.print(); // 출력 예: 100 -> 200 -> 10 -> 20 -> 30 -> (back to dummy)

    return 0;

}
