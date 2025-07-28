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

// 힙정렬

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

// 머지정렬

void merge(int arr[], int left, int mid, int right) { // 정렬한 배열, 왼쪽 부분 배열,오른쪽 부분 배열 이미 정렬 되어 있음 
    int n1 = mid - left + 1;  // 임시배열 만들기 왼쪽 부분배열의 길이 
    // +1을 하는 이유는 left~mid 범위가 양 끝 포함이기 때문이다 
    int n2 = right - mid;  // 오른쪽 부분배열의 길이 

    int* L = new int[n1]; // 왼쪽 배열을 담는 임시 공간 
    int* R = new int[n2]; // 오른쪽 배열을 담는 임시 공간 

    for (int i = 0; i < n1; ++i) 
        L[i] = arr[left + i]; // 임시 공간에 왼쪽 배열 배치
    
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i]; //임시 공간에 오른쪽 배열 배치 

    int i = 0, j = 0, k = left; 
    // i: L[]인덱스
    // j: R[]인덱스
    // k: 병합 결과를 arr[]에 저장할 위치

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) // 왼쪽 인덱스가 오른쪽 인덱스보다 작을 경우 
            arr[k++] = L[i++]; // 왼쪽부터 넣고 
        else
            arr[k++] = R[j++]; // 그위는 차레대로 오른쪽를 넣은다.

    }
    while (i < n1)
        arr[k++] = L[i++]; // 남은 값은 그대로 arr[] 복사
    while (j < n2)
        arr[k++] = R[j++];
// 사용을 다한 LR은 삭제한다. 
    delete[] L;
    delete[]R;


}

void mergeSortInternal(int arr[], int left, int right) { // 배열을 정렬하는 재귀함수이다
    // copy, 0, size-1 == 시작 인덱스(left), 끝 인덱스(right)로 배열을 나누고 정렬한뒤 다시 병함한다.
    if (left < right) { // 배열이 두 개 이상일때 만 정렬을 수행한다.
        int mid = (left + right) / 2; // 배열을 왼쪽 절반, 오른쪽 절반으로 나누기 위한 기준점이다
        mergeSortInternal(arr, left, mid); // 왼쪽 절반 재귀 정렬
        mergeSortInternal(arr, mid + 1, right); // 오른쪽 절반 재뒤 정렬 +1를 하는 이유는 배열을 정확히 겹치지 않게 양쪽으로 분할하기 위해서이다. 
        // 여기까지 왼쪽과 오른쪽을 정렬된 상태이다.
        merge(arr, left, mid, right); // 이제 left와 right를 병합해서 정렬된 배열로 만든다.
    }
}


void Heap::mergeSort()
{
    int* copy = new int[size]; // 원본에 영향을 주지 않게 하기 위해 본사본를 만들고 크기는 원본의 사이즈와 같게 한다.

    for (int i = 0; i < size; ++i) // ++은 for문에서 전위나 후위의 차이가 거의 없고 결과 값으로만 사용하기 때문이다. 값을 사용하지 않고 증가만 하기 때문이다.

        copy[i] = heap[i]; // 원본의 사이즈 만큼 복사본에 값을 넣는다.

    mergeSortInternal(copy, 0, size - 1);// 복사본, 왼쪽, 오른쪽 

    cout << "멀지 정렬 결과 :" << endl;
    for (int i = 0; i < size; ++i)
        cout << copy[i] << " ";
    cout << endl;

    delete[] copy;

}

// 쿽 솔트 

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 맨뒤 기준
    int i = low - 1;// 마지막 인덱스, 아직 아무적도 없어서 low-1로 초기화한다.

    for (int j = low; j < high; ++j) { //j는 low부터 high - 1까지 privot을 제외한 요소들을 순회한다
        if (arr[j] < pivot) { // 현재 값이 privot보다 작다면 왼쪽으로 보내야 한다.
            i++;
            swap(arr[i], arr[j]);
           // 작은 값이 발견되면 교환하여 작은 값을 앞쪽으로 보낸다.
           
        }
    } 
    swap(arr[i + 1], arr[high]);
    // 위 줄에서 pivot을 자기보다 작은 값들 끝(i+1) 자리로 이동시켜서 pivot의 최종 정렬 위치를 확장한다.
    return i + 1;
    // pivot이 위치한 인덱스를 반환 한다.
}

void quickSortInternal(int arr[], int low, int high) {
    if (low < high) {
        // 정렬한 구간의 원소가 2개 이상일 때만 정렬한다.
        int pi = partition(arr, low, high);// 기준값을 두 그룹으놀 나눈다 
        quickSortInternal(arr, low, pi - 1); // 왼쪽 그룹에 대한 큌 정렬을 다시 실행한다.
        quickSortInternal(arr, pi + 1, high); // 오른쪽 그룹에 대한 퀵 정렬을 다시 실행한다.
    }
}



void Heap::quicksort()
{
    cout << " 퀵정렬" << endl;
    int* copy = new int[size]; 
    //카피의 배열 크기를 같은 크기의 배열로 새로 동적할당한다.     
    for (int i = 0; i < size; ++i)
        copy[i] = heap[i];
    // 이제 차례대로 카피본의 배열에 기존의 힙 데이터를 넣어 복사한다.

    quickSortInternal(copy, 0, size - 1);
    cout << "";

    for (int i = 0; i < size; ++i)
        cout << copy[i] << " ";
    cout << endl;

    delete[] copy;

}

