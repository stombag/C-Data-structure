#pragma once
class SelectionArray {
private:
    int arr[100];
    int size;

public:
    SelectionArray();
    void insert(int value);
    void sort();    // ���� ����
    void print();
};
