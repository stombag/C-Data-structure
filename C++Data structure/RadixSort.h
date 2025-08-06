#pragma once
#include <iostream>

class RadixSort {
private:
    int* arr;
    int size;
    int value;

    int getMax();
    void countingSort(int exp);

public:
    RadixSort(int size);
    ~RadixSort();

    void push(int input);
    void sort();
    void print();
};