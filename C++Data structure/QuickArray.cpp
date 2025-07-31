#include "QuickArray.h"
#include <iostream>
using namespace std;

QuickArray::QuickArray() {
    size = 0;
}

void QuickArray::insert(int value) {
    if (size < 100) {
        arr[size++] = value;
    }
}

void QuickArray::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void QuickArray::sort() {
    quickSort(0, size - 1);
}

void QuickArray::quickSort(int left, int right) {
    if (left < right) {
        int pivotIndex = partition(left, right);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex + 1, right);
    }

}

int QuickArray::partition(int left, int right) {
    int pivot = arr[right]; // ������ ���� �ǹ����� ����
    int i = left - 1; // �ǹ����� ���� ���� �� ����

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // �ǹ��� �ùٸ� ��ġ�� �̵�
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}
