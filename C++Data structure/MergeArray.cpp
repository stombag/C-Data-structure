#include "MergeArray.h"
#include <iostream>
using namespace std;

MergeArray::MergeArray() {
    size = 0;
}

void MergeArray::insert(int value) {
    if (size < 100) {
        arr[size++] = value;
    }
}

void MergeArray::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MergeArray::sort() {
    mergeSort(0, size - 1);
}

void MergeArray::mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void MergeArray::merge(int left, int mid, int right) {
    int temp[100]; // �ӽ� �迭
    int i = left;
    int j = mid + 1;
    int k = left;

    // ���ʰ� ������ ���ĵ� �κ� ����
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    // ���� ��� ����
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // ���� �迭�� ����
    for (int t = left; t <= right; t++) {
        arr[t] = temp[t];
    }
}
