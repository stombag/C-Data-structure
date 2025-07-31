#include "SortedArray.h"
#include <iostream>
using namespace std;

SortedArray::SortedArray() {
    size = 0;
}

void SortedArray::insert(int value) {
    // 삽입 위치 찾기 (오름차순)
    int i = size - 1;
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i]; // 오른쪽으로 이동
        i--;
    }
    arr[i + 1] = value; // 삽입
    size++;
}

bool SortedArray::search(int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << "찾았습니다." << endl;
            return true;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "찾지 못했습니다." << endl;
    return false;
}

void SortedArray::print() {
    cout << "이진트리 " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
