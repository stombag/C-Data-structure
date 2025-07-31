#pragma once
class SelectionArray {
private:
    int arr[100];
    int size;

public:
    SelectionArray();
    void insert(int value);
    void sort();    // 선택 정렬
    void print();
};
