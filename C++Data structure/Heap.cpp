#include "Heap.h"

Heap::Heap(int capacity) :capacity(capacity), size(0) { // �ʱ�ȭ ��  �Ű� ���� �� ���� 
    heap = new int[capacity]; // ���� �뷮�� �����.
}
Heap::~Heap() {
    delete[]heap; // ���� �����Ͽ� �޸� �ս��� ���ֹ�����.
}

void Heap::insert(int value) {
    if (isFull()) { // ���� ���� �Լ� ����
        return;
    }

    heap[size] = value; // ����� ��ġ�� �ε����� �����Ѵ�. 
    heapifyUP(size); // �θ�� �ڽ��� ���ؼ� �ڽ��� �� ũ�� �� ���� ����� ��ȯ�ϴ� ���̴�
    size++; // �������� ���� ���� ��Ų��. 
}

void Heap::heapifyUP(int index) {
    while (index > 0) { //�ε����� ���� 0���� Ŭ��� �ݺ��Ѵ�. 
        int parent = (index - 1) / 2; // ���� ����� �θ� �ε����� ����Ѵ�. index�� 3�̸� 2�� ������ 1�� �ȴ� index�� 4�̸� 1�̵ȴ� 5�̸� 2�� �ȴ� 
        // �� ������ �ε������� ��Ÿ���� ���� parant�̴�. 0���� 1���� 2�������� �����ϸ� �ȴ�
        if (heap[index] > heap[parent]) { // ���� ����(�θ�>=�ڽ�)�� �������� Ȯ�� 
            swap(heap[index], heap[parent]);  // �ڽ��� �� ũ�� �����ϸ� �������� �θ�� �ڽ��� ���� �����Ѵ�.
            index = parent; // �θ� ���ο� �������� �ݺ���Ų��. ó���� �ε����� 5�̸� �θ�� 2�� �ǰ� �ٽ� �����ؼ� �ε����� ���� 2���Ǹ� �θ��� ���� 0�̵ȴ� .
        } // �� �θ�� �ڽ��� ��ġ�� Ȯ���ϰ� �ڽ��� �� ���� ũ�� ���� ��ȯ�ϴ� �����ν� 
        else break;
    }
}
int Heap::pop() {
    if (isEmpty()) {
        cout << "���� ��� �ֽ��ϴ�." << endl;
        return -1; // ���� ��� ������ �Լ��� �����Ѵ�
    }

    int root = heap[0]; // ���� ���� �ִ� ��ġ�� �����´�
    heap[0] = heap[size - 1]; // ������� 1�� �� ���� 0�� �ִ´�. 
    size--; // size ���̱� 
    heapifyDown(0); // 0�� �ε������� ���� ���� 

    return root; //���� ���� �ִ� ���� ������.
}

void Heap::heapifyDown(int index) {
    while (index * 2 + 1 < size) { // ���� ����� ���� �ڽ��� ������ ������ �ݺ��Ѵ�. 
        int left = index * 2 + 1; // ���� 
        int right = index * 2 + 2; // ������ 
        // ���ʰ� �������� ���ϴ� �����̴�.
        int largest = index; // ���ʰ� �������� ���ؼ� �� ū ���� �ֱ� ���� ��� 

        if (left < size && heap[left] > heap[largest]) largest = left; // ���ʰ� �� ������� ���� ���� ���� ���� ����ū ������ Ŭ ��� largest�� left�� ������
        if (right < size && heap[right] > heap[largest]) largest = right; // �����ʰ� �� ������� ���� ���� ������ ���� ���� ū ������ Ŭ��� largest�� right�� �ִ´�.
        // ������� left�� right�� ���Ͽ� ū ���� largest�� �ִ� �����̴�.

        if (largest != index) { // index�� largest�� ���� ���� ���� ��� 
            swap(heap[index], heap[largest]);// ���� ���� �ִ� ���� largest�� �ٲ۴�.
            index = largest; // index�� ���� largest�� �����Ѵ�.
        }
        else break;
    }
}

int Heap::top() const {
    if (isEmpty()) {
        cout << "���� ��� �ֽ��ϴ�." << endl;
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
    cout << "�� ����: ";
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << endl;
}

void Heap::heapSort() {
    // ���� heap �迭�� size�� ���
    int* backup = new int[size]; // �ϴ� ����� �迭�� ũ��� size��ŭ �����
    for (int i = 0; i < size; ++i) // size��ŭ �ݺ���Ű�� ������ i���� �ٷ� 1���� �����Ѵ�
        backup[i] = heap[i]; // �ϳ��� ��� ������ �ִ´�.
    int originalSize = size; // ������ ���� ����� �� �ְ� ������ ����� �װ� �ִ´�.
    cout << "�� ���� ���: ";
    // ���� ����
    for (int i = size - 1; i >= 0; --i) { // size�� ���� ���̸鼭 �ݺ���Ų�� 0 �̸��� �ɶ� ����
        swap(heap[0], heap[i]);   // �ִ밪�� �� �ڷ� ����
        size--;                   // �� ũ�� ���̰�
        heapifyDown(0);           // ��Ʈ���� �ٽ� ����
    }

    // ���ĵ� �迭 ���
    for (int i = 0; i < originalSize; ++i)
        cout << heap[i] << " ";
    cout << endl;

    // ���� heap ����
    for (int i = 0; i < originalSize; ++i) // ���� ������ ��� �ٽ� ���� 
        heap[i] = backup[i];
    size = originalSize;

    delete[] backup;
}
