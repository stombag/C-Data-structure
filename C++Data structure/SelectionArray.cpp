#include "SelectionArray.h"
#include <iostream>
using namespace std;

SelectionArray::SelectionArray() {
    size = 0;
}

void SelectionArray::insert(int value) {
    if (size < 100) {
        arr[size++] = value;
    }
}

void SelectionArray::sort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void SelectionArray::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
