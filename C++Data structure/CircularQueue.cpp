#include "CircularQueue.h"

CircularQueue::CircularQueue(int capacity)
    : capacity(capacity), front(0), rear(0), size(0) {
    arr = new int[capacity];
}

CircularQueue::~CircularQueue() {
    delete[] arr;
}

void CircularQueue::push(int value) {
    if (isFull()) {
        cout << "ť�� ���� á���ϴ�." << endl;
        return;
    }
    arr[rear] = value;
    rear = (rear + 1) % capacity;
    size++;
}

int CircularQueue::remove() {
    if (isEmpty()) {
        cout << "ť�� ��� �ֽ��ϴ�." << endl;
        return -1;
    }
    int value = arr[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}

int CircularQueue::count() const {
    return size;
}

void CircularQueue::print() const {
    cout << "ť ����: ";
    for (int i = 0; i < size; ++i) {
        int index = (front + i) % capacity;
        cout << arr[index] << " ";
    }
    cout << endl;
}

bool CircularQueue::isEmpty() const {
    return size == 0;
}

bool CircularQueue::isFull() const {
    return size == capacity;
}
