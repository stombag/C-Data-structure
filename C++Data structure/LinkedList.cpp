#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::Push(DataType data) // ���� ����Ʈ�� ���� ���ο� ��带 �߰��ϴ� ������ �Ѵ�.
// void�̹Ƿ� ���� ��ȯ���� �ʽ��ϴ�. 
{
	// Node* �� Node Ÿ���� �ּҸ� ������ �� �ִ� �����̴�. 
	// �� Node�� ����Ű�� �����͸� �ǹ��Ѵ� .

	Node* newNode = new Node(data); 
	// �������� �����ϰ� data������ ���� ��带 �ϳ� ����� newNode�� ���� ����� �ּҸ� �����Ѵ�.
	// ���� ������⶧���� newNode �� tail�� �ּҰ��� �ٸ���

	Node* tail = dummyHead;
	//tail �����͸� ����� ����Ʈ�� ������ ��带 ã�� ���� �غ� �Ѵ�.

	// new Node()�� ���ο� ��ü�� ����� ���� ��ȯ�Ѵ� newNode�� Node* Ÿ���� ��ü�� �ּҰ��� �����ϴ°Ŵ� 
	// new �� �����Ҵ��ϰ� �ּҰ��� ��ȯ�Ѵ�

	while (tail->NextNode != nullptr) //NextNoder�� nullptr�� �ƴ� ������ �̵��Ѵ�. 
		tail = tail->NextNode; // ����Ʈ ������ �̵��Ѵ�. 
	// ù��°��忡�� Nextnode�� ���� ������ tail�� �� ù��° ����� NextNode�� ������ tail�� ����Ű�°� ù��°����� NextNode�̴� 
	// �� NextNode�� ���� ������ �����ϰ� ������ �ι�° ����� NextNode�� tail�� �ִ´�

	//tail�� ������ ������ �̵���Ų ��, �� ����� NextNode�� �̹��� ���� ��带 �����Ѵ�.
	tail->NextNode = newNode; 

}

void LinkedList::Insert(int index, DataType data)// linkedlist Ŭ���� ����Լ��̸� index ��ġ�� data ���� data ���� �����Ѵ�.
{
	Node* newNode = new Node(data); // data ���� ������ �ִ� ���ο� ��带 �������� �����Ѵ�. newNode�� ���� �߰��� ��带 ����Ų��. 
	Node* current = dummyHead; //���� ��ġ�� ã�� ���� current ����Ʈ�� �������� �����Ѵ�. 
	// ���� ��带 ����ϸ� ����/ ���� �� Ư���� ��� ó���� ��������.

	while (index-- > 0 && current->NextNode != nullptr) // ������ ��ġ �ٷ� ���� ������ �̵��Ѵ�.
	{//index --> 0: index�� 1�� ���̸鼭 0���� ū ���� �ݺ��Ѵ�.
	// ���ÿ� current->NextNode�� Nullptr�� �ƴ� ���ȸ� �ݺ��Ѵ�.
		//��� ������ current�� ���� ��ġ ������带 ����Ű�� �ȴ�.
		current = current->NextNode;
		// current->NextNode�� ����Ű�� ��带 current�� �ּҰ��� �ִ´� .
	}
	newNode->NextNode = current->NextNode;
	// �� ����� NextNode�� ���� ����� ���� ���� �����Ѵ�.
	// �� �� ��带 ���� ����Ʈ�� �����ϴ� �غ� �Ѵ�. 

	current->NextNode = newNode;
	// ���� ����� nextNode�� ������ �����Ѵ�. 
	// �̷ν� �� ��尡 ����Ʈ�� ������ �����Ѵ�.
}

void LinkedList::Remove(int index) // index ��ġ�� �ִ� ��带 �����Ѵ�.
{
	Node* current = dummyHead;//�������� ����Ʈ�� ������ ��Ÿ���� ������� ����̴� 
	// ������ ��� �ٷ� �� ������ �̵��ϱ� ���� current�� ���⼭ �ʱ�ȭ �Ѵ�. 
	while (index-- > 0 && current->NextNode != nullptr)
	{// ������ ��ġ �ٷ� �� ������ �̵��ϴ� �ݺ����Դϴ�. 
		// ���ÿ� ���� ��尡 nullptr�� �ƴ��� Ȯ���Ͽ� ���� �ʰ� ������ �մϴ�. 
		current = current->NextNode;
		// index�� 0���� Ŭ ������ curret�� �� ĭ�� �������� �̵��Ѵ�.

	}

	Node* target = current->NextNode; // ������ ������ ����̴�. 
	if (target != nullptr) //������ ��尡 �����ϴ��� Ȯ���Ѵ�. 
	{
		current->NextNode = target->NextNode; // current�� target�� ����Ű�� �ʰ� target ���� ��带 ����Ű���� ������ �ٲߴϴ�
		// �̷��� �ϸ� target ��尡 ����Ʈ���� ���� �Ѵ�
		delete target;
		// ������ ����� �޸𸮸� �����Ѵ�. �޸� ���� ���� 
	}

	// index�� 1�ΰ�� 2��° ��带 ���� ������ .
}

DataType LinkedList::Get(int index) // ����Ʈ���� index��ġ�� �ִ� ����� ������ ���� ��ȯ�Ѵ�.
// index�� 0���� �����ϸ�, ��ȯ Ÿ���� DataType�̴�.
{
	Node* current = dummyHead->NextNode;//����Ʈ�� ù��° ���� ��带 ����Ų��.

	while (index-- > 0 && current != nullptr)
		//index�� 0���� Ŭ ����, current�� ��� ���� ���� �̵���Ų��.
		// ���ÿ� current�� nullptr�̸� ����ϴ�. 
	{
		current = current->NextNode;
		// ��� : current�� index��° ��带 ����Ű�� �˴ϴ�. 

	}
	if (current == nullptr) throw out_of_range("Index out of range");
	// ����(current)�� nullptr �� ��� �� ã������ �ε����� ����Ʈ ������ ������� ���ܸ� �߻��Ѵ� 
	// throw out_of_range("Index out of range") �̰� ������ �߻������� ���ܷ� �ΰ� �ٱ� �ڵ忡�� ó���ϰ� �ϴµ� out of range�� ����Ŭ���� �̸��̴� ���״�� ������ ������ ���� ���� ó�� ��ɾ��̴�.
	// out of range �� �� ������ ������ ������� �ǹ��ϴ� ���� ��ü�� ����� 
	// throw�� �� ���� ��ü�� ������ ���α׷����� ������ ����ٰ� �˸��ٴ� �ʹ� ** ���� ���� ���� **
	return current->Data;
}

int LinkedList::Count() const // ����Ʈ�� ����ִ� ����� ������ ���� ������ ��ȯ�մϴ�.
// const�� Ű���尡 �־� ����Ʈ�� ������ �������� ������ �����Ѵ�
{
	int count = 0; // ����Ʈ ��� ������ �� ���� cout�� 0���� �ʱ�ȭ�Ѵ�.
	Node* current = dummyHead->NextNode; // ���� ��� ����� ������� ���� �����Ѵ�
	// ���� �����Ͱ� ����� ù ��° ��带 ����Ű�� �����͸� �����ϰ� �ʱ�ȭ �Ѵ�
	while (current != nullptr) // current�� nullptr�� �ƴ� �� �� ����Ʈ ���� �������� �ʾ��� ���� �ݓ��Ѵ�. 
		// ����Ʈ�� ���� nullptr�� ǥ���ϱ⶧���� ���������� �ݺ����� ���� �� �ִ�. 
	{
		count++;

		current = current->NextNode;
		//current�� ���� ���� �̵���Ų��. 
		// ī��Ʈ �ϰ� �������� �Ѿ�� 
	}

	return count;
	// �ݺ����� ������ ȣ���� ������ ī��Ʈ�� ���� ������ 
}

void LinkedList::print() const // ȭ�� ��� 
{
	Node* current = dummyHead->NextNode; // ù��° ��带 ����Ű�� ������ current�� �����ϰ� �ʱ�ȭ�Ѵ�.
	// dummyHead�� ���� ����̰� ���� �����ʹ� dummyHead -> NextNode���� �����Ѵ�. 
	while (current != nullptr) // current�� nullptr�� �ƴ� �� �� ����Ʈ ���� �������� ������ ��� �ݺ��Ѵ�.
	{
		cout << current->Data << " -> ";
		// ���� ��忡 ����� �����͸� ����ϰ� �ڿ� ���ڿ��� ����ؼ� ��带 �����ϴ� ����� �����ش�. 
		current = current->NextNode;
		// current�� ���� ���� �̵���Ų��. 
	}
	cout << "NULL" << endl;
	// ������ ����Ѵ�. 
}

void LinkedList::Clear() // ����Ʈ�� �ִ� ��� ��带 �޸𸮿��� �����ؼ� ����Ʈ�� �� ���·� �����
{
	Node* current = dummyHead->NextNode; // ���� ��� �������Ͱ� ���� �����Ͱ� �ִ� �����̴�. 
	// �׷��� �ű���� �ϳ��� �����Ϸ��� current �����͸� �ű⿡ ���� �����Ѵ� 
	while (current != nullptr)
	{
		
		Node* temp = current; // ������ ��带 temp �����ͷ� �����Ѵ�. 
		// ���߿� delete �ϱ� ���� ��� �����صδ� �Ŵ� 
		current = current->NextNode; // current�� ���� ���� �̵���Ų��. 
		delete temp;
		//temp�� ����Ű�� ��带 �޸𸮿��� �����Ѵ�. �̰����� ������ �޸� ����(leak)�� �߻��Ѵ�
	}
	dummyHead->NextNode = nullptr;
	// ���� ��尡 ����Ű�� ù ��带 nullptr�� �����ؼ� ���� ����Ʈ�� ������ �� ���°� �ȴ�.
	// �̶� ī��Ʈ�� 0�� �ȴ�.
}

int main()
{
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
}
