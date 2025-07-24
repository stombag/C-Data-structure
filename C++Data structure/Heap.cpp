#include "Heap.h"

Heap::Heap(int capaticy) :capacity(capacity), size(0) {
	heap = new int[capacity];
}
Heap::~Heap() {
	delete[]heap;
}

void Heap::insert(int value) {
	if (isFull) {
		return;
	}

	heap[size] = value;
	heapifyUP(size);
	size++;
}

void Heap::heapifyUP(int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (heap[index] > heap[parent]) {
			swap(heap[index], heap[parent]);
			index = parent;
		}
		else break;
	}
}
int Heap::pop() {
    if (isEmpty()) {
        cout << "힙이 비어 있습니다." << endl;
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

void Heap::heapifyDown(int index) {
    while (index * 2 + 1 < size) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else break;
    }
}

int Heap::top() const {
    if (isEmpty()) {
        cout << "힙이 비어 있습니다." << endl;
        return -1;
    }
    return heap[0];
}

bool Heap::isEmpty() const {
    return size == 0;
}

bool Heap::isFull() const {
    return size == capacity;
}

void Heap::print() const {
    cout << "힙 내용: ";
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << endl;
}