#include "BubbleArray.h"
#include <iostream>
using namespace std;

BubbleArray::BubbleArray() {
    size = 0;
}

void BubbleArray::insert(int value) {
    if (size < 100) {
        arr[size++] = value;
    }
}

void BubbleArray::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleArray::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
