#pragma once

class BubbleArray {
private:
    int arr[100];
    int size;

public:
    BubbleArray();
    void insert(int value);
    void sort();    // ���� ����
    void print();
};

