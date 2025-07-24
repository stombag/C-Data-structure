#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int size):capacity(size),front(0),rear(0) {

	
	arr = new int[capacity];
	

}
ArrayQueue::~ArrayQueue() {
	delete[] arr;
		
}

void ArrayQueue::push(int value) {
	if (isFull()) {
		cout << "Queue is full!" << endl;
		return;
	}
	arr[rear++] = value; // Add value to the rear

}

int ArrayQueue::remove() {
	if (isEmpty()) {
		return -1;
	}
	int removedValue = arr[front];
	for (int i = front; i < rear - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	rear--;
	return removedValue;

}

void ArrayQueue::insert(int index, int value) {
	if (isFull()) {
		return;
	}
	if (index<0 || index>count()) {
		return;
	}
	for (int i = rear; i > front + index; --i) {
		arr[i] = arr[i - 1];

	}
	arr[front + index] = value;
	rear++;

}

int ArrayQueue::count()const {
	return rear - front;

}
void ArrayQueue::print()const {
	for (int i = front; i < rear; ++i) {
		cout << arr[i] << " ";

	}
	cout << endl;
}

bool ArrayQueue::isEmpty() const {
	for (int i = front; i < rear; ++i) {
		cout << arr[i];
	}
	cout << endl;
}

bool ArrayQueue::isFull()const {
	return rear == capacity;
}