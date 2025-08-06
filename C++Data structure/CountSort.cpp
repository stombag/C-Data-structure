#include "CountSort.h"
#include <iostream>
using namespace std;

CountingSort::CountingSort(int size)
{
	value = 0;

	this->size = size;
	this->arr = new int[size];

}



CountingSort::~CountingSort()
{
	delete[] arr;
}

void CountingSort::push(int input)
{
	arr[value] = input;

	value++;
}

void CountingSort::sort()
{
	 // 1. 최댓값과 최솟값 구하기
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < value; ++i) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;

    // 2. 카운팅 배열 생성
    int* count = new int[range];
    for (int i = 0; i < range; ++i) count[i] = 0;

    // 3. 등장 횟수 카운팅
    for (int i = 0; i < size; ++i) {
        count[arr[i] - min]++;
    }

    // 4. 누적합 구하기
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // 5. 결과 배열 만들기 (안정 정렬)
    int* output = new int[size];
    for (int i = size - 1; i >= 0; --i) {
        int index = arr[i] - min;
        output[--count[index]] = arr[i];
    }

    // 6. 결과 복사
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }

    // 7. 메모리 해제
    delete[] count;
    delete[] output;
}

void CountingSort::print() {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
    
}
