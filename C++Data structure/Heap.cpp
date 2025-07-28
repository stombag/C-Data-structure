#include "Heap.h"

Heap::Heap(int capacity) :capacity(capacity), size(0) { // 초기화 및  매개 변수 값 전달 
    heap = new int[capacity]; // 정한 용량을 만든다.
}
Heap::~Heap() {
    delete[]heap; // 힙을 삭제하여 메모리 손실을 없애버린다.
}

void Heap::insert(int value) {
    if (isFull()) { // 가득 차면 함수 종료
        return;
    }

    heap[size] = value; // 사이즈에 위치한 인덱스에 접근한다. 
    heapifyUP(size); // 부모와 자식을 비교해서 자식이 더 크면 그 값을 보모랑 교환하는 식이다
    size++; // 사이즈의 값을 증가 시킨다. 
}

void Heap::heapifyUP(int index) {
    while (index > 0) { //인덱스의 값이 0보다 클경우 반복한다. 
        int parent = (index - 1) / 2; // 현재 노드의 부모 인덱스를 계산한다. index가 3이면 2로 나누어 1이 된다 index가 4이면 1이된다 5이면 2가 된다 
        // 즉 보모의 인덱스값을 나타내는 것이 parant이다. 0번층 1번층 2번층으로 생각하면 된다
        if (heap[index] > heap[parent]) { // 힙의 성질(부모>=자식)이 깨졌는지 확인 
            swap(heap[index], heap[parent]);  // 자식이 더 크면 실행하며 스왑으로 부모와 자식의 값을 변경한다.
            index = parent; // 부모를 새로운 기준으로 반복시킨다. 처음에 인덱스가 5이면 부모는 2가 되고 다시 전달해서 인덱스의 값이 2가되면 부모의 값이 0이된다 .
        } // 즉 부모와 자식의 위치를 확인하고 자식이 더 값이 크면 값을 교환하는 식으로써 
        else break;
    }
}
int Heap::pop() {
    if (isEmpty()) {
        cout << "힙이 비어 있습니다." << endl;
        return -1; // 힙이 비어 있으면 함수를 종료한다
    }

    int root = heap[0]; // 가장 위에 있는 위치를 가져온다
    heap[0] = heap[size - 1]; // 사이즈에서 1를 뺏 값을 0에 넣는다. 
    size--; // size 줄이기 
    heapifyDown(0); // 0번 인덱스부터 정렬 시작 

    return root; //가장 위에 있는 값은 보낸다.
}

void Heap::heapifyDown(int index) {
    while (index * 2 + 1 < size) { // 현재 노드의 왼쪽 자식이 존재할 까지만 반복한다. 
        int left = index * 2 + 1; // 왼쪽 
        int right = index * 2 + 2; // 오른쪽 
        // 왼쪽과 오른쪽을 정하는 과정이다.
        int largest = index; // 왼쪽과 오른쪽을 비교해서 더 큰 수를 넣기 위한 장소 

        if (left < size && heap[left] > heap[largest]) largest = left; // 왼쪽가 총 사이즈보다 작을 경우와 왼쪽 힙이 가장큰 힙보다 클 경우 largest에 left를 넣은다
        if (right < size && heap[right] > heap[largest]) largest = right; // 오른쪽가 총 사이즈보다 작을 경우와 오른쪽 힘이 가장 큰 힙보다 클경우 largest에 right를 넣는다.
        // 여기까지 left와 right를 비교하여 큰 값을 largest에 넣는 과정이다.

        if (largest != index) { // index와 largest의 값이 같지 않을 경우 
            swap(heap[index], heap[largest]);// 가장 위에 있는 값과 largest를 바꾼다.
            index = largest; // index의 값을 largest로 변경한다.
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

void Heap::heapSort() {
    // 원래 heap 배열과 size를 백업
    int* backup = new int[size]; // 일단 백업에 배열의 크기는 size만큼 만든다
    for (int i = 0; i < size; ++i) // size만큼 반복시키며 전위로 i값을 바로 1부터 시작한다
        backup[i] = heap[i]; // 하나씩 백업 변수에 넣는다.
    int originalSize = size; // 사이즈 또한 백업할 수 있게 변수를 만들고 그걸 넣는다.
    cout << "힙 정렬 결과: ";
    // 정렬 진행
    for (int i = size - 1; i >= 0; --i) { // size를 점점 줄이면서 반복시킨다 0 미만이 될때 까지
        swap(heap[0], heap[i]);   // 최대값을 맨 뒤로 보냄
        size--;                   // 힙 크기 줄이고
        heapifyDown(0);           // 루트부터 다시 정렬
    }

    // 정렬된 배열 출력
    for (int i = 0; i < originalSize; ++i)
        cout << heap[i] << " ";
    cout << endl;

    // 원래 heap 복구
    for (int i = 0; i < originalSize; ++i) // 원래 넣은거 대로 다시 정렬 
        heap[i] = backup[i];
    size = originalSize;

    delete[] backup;
}
