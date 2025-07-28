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

// ������

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

// ��������

void merge(int arr[], int left, int mid, int right) { // ������ �迭, ���� �κ� �迭,������ �κ� �迭 �̹� ���� �Ǿ� ���� 
    int n1 = mid - left + 1;  // �ӽù迭 ����� ���� �κй迭�� ���� 
    // +1�� �ϴ� ������ left~mid ������ �� �� �����̱� �����̴� 
    int n2 = right - mid;  // ������ �κй迭�� ���� 

    int* L = new int[n1]; // ���� �迭�� ��� �ӽ� ���� 
    int* R = new int[n2]; // ������ �迭�� ��� �ӽ� ���� 

    for (int i = 0; i < n1; ++i) 
        L[i] = arr[left + i]; // �ӽ� ������ ���� �迭 ��ġ
    
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i]; //�ӽ� ������ ������ �迭 ��ġ 

    int i = 0, j = 0, k = left; 
    // i: L[]�ε���
    // j: R[]�ε���
    // k: ���� ����� arr[]�� ������ ��ġ

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) // ���� �ε����� ������ �ε������� ���� ��� 
            arr[k++] = L[i++]; // ���ʺ��� �ְ� 
        else
            arr[k++] = R[j++]; // ������ ������� �����ʸ� ������.

    }
    while (i < n1)
        arr[k++] = L[i++]; // ���� ���� �״�� arr[] ����
    while (j < n2)
        arr[k++] = R[j++];
// ����� ���� LR�� �����Ѵ�. 
    delete[] L;
    delete[]R;


}

void mergeSortInternal(int arr[], int left, int right) { // �迭�� �����ϴ� ����Լ��̴�
    // copy, 0, size-1 == ���� �ε���(left), �� �ε���(right)�� �迭�� ������ �����ѵ� �ٽ� �����Ѵ�.
    if (left < right) { // �迭�� �� �� �̻��϶� �� ������ �����Ѵ�.
        int mid = (left + right) / 2; // �迭�� ���� ����, ������ �������� ������ ���� �������̴�
        mergeSortInternal(arr, left, mid); // ���� ���� ��� ����
        mergeSortInternal(arr, mid + 1, right); // ������ ���� ��� ���� +1�� �ϴ� ������ �迭�� ��Ȯ�� ��ġ�� �ʰ� �������� �����ϱ� ���ؼ��̴�. 
        // ������� ���ʰ� �������� ���ĵ� �����̴�.
        merge(arr, left, mid, right); // ���� left�� right�� �����ؼ� ���ĵ� �迭�� �����.
    }
}


void Heap::mergeSort()
{
    int* copy = new int[size]; // ������ ������ ���� �ʰ� �ϱ� ���� ���纻�� ����� ũ��� ������ ������� ���� �Ѵ�.

    for (int i = 0; i < size; ++i) // ++�� for������ ������ ������ ���̰� ���� ���� ��� �����θ� ����ϱ� �����̴�. ���� ������� �ʰ� ������ �ϱ� �����̴�.

        copy[i] = heap[i]; // ������ ������ ��ŭ ���纻�� ���� �ִ´�.

    mergeSortInternal(copy, 0, size - 1);// ���纻, ����, ������ 

    cout << "���� ���� ��� :" << endl;
    for (int i = 0; i < size; ++i)
        cout << copy[i] << " ";
    cout << endl;

    delete[] copy;

}

// �o ��Ʈ 

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // �ǵ� ����
    int i = low - 1;// ������ �ε���, ���� �ƹ����� ��� low-1�� �ʱ�ȭ�Ѵ�.

    for (int j = low; j < high; ++j) { //j�� low���� high - 1���� privot�� ������ ��ҵ��� ��ȸ�Ѵ�
        if (arr[j] < pivot) { // ���� ���� privot���� �۴ٸ� �������� ������ �Ѵ�.
            i++;
            swap(arr[i], arr[j]);
           // ���� ���� �߰ߵǸ� ��ȯ�Ͽ� ���� ���� �������� ������.
           
        }
    } 
    swap(arr[i + 1], arr[high]);
    // �� �ٿ��� pivot�� �ڱ⺸�� ���� ���� ��(i+1) �ڸ��� �̵����Ѽ� pivot�� ���� ���� ��ġ�� Ȯ���Ѵ�.
    return i + 1;
    // pivot�� ��ġ�� �ε����� ��ȯ �Ѵ�.
}

void quickSortInternal(int arr[], int low, int high) {
    if (low < high) {
        // ������ ������ ���Ұ� 2�� �̻��� ���� �����Ѵ�.
        int pi = partition(arr, low, high);// ���ذ��� �� �׷����� ������ 
        quickSortInternal(arr, low, pi - 1); // ���� �׷쿡 ���� �W ������ �ٽ� �����Ѵ�.
        quickSortInternal(arr, pi + 1, high); // ������ �׷쿡 ���� �� ������ �ٽ� �����Ѵ�.
    }
}



void Heap::quicksort()
{
    cout << " ������" << endl;
    int* copy = new int[size]; 
    //ī���� �迭 ũ�⸦ ���� ũ���� �迭�� ���� �����Ҵ��Ѵ�.     
    for (int i = 0; i < size; ++i)
        copy[i] = heap[i];
    // ���� ���ʴ�� ī�Ǻ��� �迭�� ������ �� �����͸� �־� �����Ѵ�.

    quickSortInternal(copy, 0, size - 1);
    cout << "";

    for (int i = 0; i < size; ++i)
        cout << copy[i] << " ";
    cout << endl;

    delete[] copy;

}

