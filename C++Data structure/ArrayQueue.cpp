#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int size) :capacity(size), front(0), rear(0) { // ���� �ʱ�ȭ 
	// ������Ͽ��� �Է��� size���� capacity�� �ִ´�. ������ ������ �ʱ�ȭ�� �����Ѵ�. 
	arr = new int[capacity]; //capacity�� �־ �迭�� ũ�⸦ ���Ѵ�.
}
ArrayQueue::~ArrayQueue() {
	delete[] arr; // �迭�� �� ���� 

}

void ArrayQueue::push(int value) {
	if (isFull()) {
		cout << "Queue is full!" << endl;
		return; //�� ������ �Լ� ���� 
	}
	arr[rear++] = value; //  value�� �ش� �迭�� �°� �ִ´�, ���� rear�� ���ڴ� 1�� �����Ѵ�(����). �ڷ� �þ��. 

}

int ArrayQueue::remove() {
	if (isEmpty()) {
		return -1; // int�� �Լ��� �����Ϸ��� ��ȯ�� �ؾ��Ѵ� ������ �� ��� �����ߴٴ� �ǹ̷� -1�� ���� �Լ��� ���� ��Ų��. 
	}
	int removedValue = arr[front]; // removedValue��� ������ ����� �ű⿡ frout�� �ִ´�. 
	for (int i = front; i < rear - 1; ++i) { // rear ��ŭ �ݺ��ؼ� 
		arr[i] = arr[i + 1]; // arr�� ������ �����. 
	}
	rear--; // �տ� �ִ� �迭�� ���� �ڿ��ִ� ������ �ִ´� ���� �޸𸮴� �����ִ�
	return removedValue; // ���� �迭�� ���� �˷��ش�. 

}

void ArrayQueue::insert(int index, int value) {
	if (isFull()) {
		return;// ������ ����
	}
	if (index<0 || index>count()) {
		return;  // ���� ���� ���̳ʽ� �̰ų� �����迭���� ū �� �ϰ�� �����Ѵ�. 
	}
	for (int i = rear; i > front + index; --i) {  // ���� ���� front�� ���� ������ ũ�� �ݺ��Ѵ� .�Ҷ����� i�� 1�� �����Ѵ�.
		arr[i] = arr[i - 1]; // �ڷ� �����.

		//�� ������ ������ ������ Ȯ���ϱ� ���� �ڵ��̴�
	}
	arr[front + index] = value; // �����Ѵ�
	rear++; // �迭�� ���� ũ�� 1����

}

int ArrayQueue::count()const {
	return rear - front; // ũ�� 

}
void ArrayQueue::print()const {
	for (int i = front; i < rear; ++i) {
		cout << arr[i] << " ";// �迭 �ϳ��� ����Ʈ
	}
	cout << endl;
}

bool ArrayQueue::isEmpty() const {
	for (int i = front; i < rear; ++i) {
		cout << arr[i]; // �迭�� �ٵ�� �ִ��� Ȯ�� 
	}
	cout << endl;
	return true;
}

bool ArrayQueue::isFull()const {
	return rear == capacity; // �뷮�� �ڸ� ����Ű�� ���� ������ ���� ����
}