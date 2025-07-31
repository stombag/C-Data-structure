#include "SortedArray.h"
#include <iostream>
using namespace std;

SortedArray::SortedArray() {
    size = 0;
}

void SortedArray::insert(int value) {
    // ���� ��ġ ã�� (��������)
    int i = size - 1;
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i]; // ���������� �̵�
        i--;
    }
    arr[i + 1] = value; // ����
    size++;
}

bool SortedArray::search(int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << "ã�ҽ��ϴ�." << endl;
            return true;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "ã�� ���߽��ϴ�." << endl;
    return false;
}

void SortedArray::print() {
    cout << "����Ʈ�� " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
