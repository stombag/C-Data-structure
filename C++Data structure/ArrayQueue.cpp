#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int size) {

	capacity = size + 1;
	arr = new int[capacity];
	front = 0;
	rear = 0;

}
ArrayQueue::~ArrayQueue() {
	delete[] arr;
		
}
