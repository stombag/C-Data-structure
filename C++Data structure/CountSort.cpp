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
	 // 1. �ִ񰪰� �ּڰ� ���ϱ�
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < value; ++i) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;

    // 2. ī���� �迭 ����
    int* count = new int[range];
    for (int i = 0; i < range; ++i) count[i] = 0;

    // 3. ���� Ƚ�� ī����
    for (int i = 0; i < size; ++i) {
        count[arr[i] - min]++;
    }

    // 4. ������ ���ϱ�
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // 5. ��� �迭 ����� (���� ����)
    int* output = new int[size];
    for (int i = size - 1; i >= 0; --i) {
        int index = arr[i] - min;
        output[--count[index]] = arr[i];
    }

    // 6. ��� ����
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }

    // 7. �޸� ����
    delete[] count;
    delete[] output;
}

void CountingSort::print() {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
    
}
