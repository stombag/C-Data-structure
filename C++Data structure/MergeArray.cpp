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
    int temp[100]; // 임시 배열
    int i = left;
    int j = mid + 1;
    int k = left;

    // 왼쪽과 오른쪽 정렬된 부분 병합
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    // 남은 요소 복사
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // 원본 배열로 복사
    for (int t = left; t <= right; t++) {
        arr[t] = temp[t];
    }
}
