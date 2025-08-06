#include"RadixSort.h"

RadixSort::RadixSort(int size)
{
	this->size = size;
	this->value = 0;
	arr = new int[size];

}

RadixSort::~RadixSort()
{
	delete[] arr;

}

void RadixSort::push(int input) {
    if (value < size) {
        arr[value++] = input;
    }
}

int RadixSort::getMax() {
    // 배열에서 최대값을 찾는걸 반복한다. 
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void RadixSort::countingSort(int exp) {
    int buckets[10][100];       // 최대 버킷 크기 100개로 가정
    int bucketCount[10] = { 0 }; // 각 버킷의 현재 길이

    // 버킷에 분류
    for (int i = 0; i < size; ++i) {
        int digit = (arr[i] / exp) % 10;
        buckets[digit][bucketCount[digit]++] = arr[i];
    }

    // 버킷에서 꺼내기
    int idx = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < bucketCount[i]; ++j) {
            arr[idx++] = buckets[i][j];
        }
    }
}

void RadixSort::sort() {
    int maxVal = getMax();

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        //
        countingSort(exp);
    }
}

void RadixSort::print() {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
