#pragma once


class SortedArray {
private:
    int arr[100];
    int size;

public:
    SortedArray();
    void insert(int value);       // ���ĵǰ� ����
    bool search(int target);      // ���� Ž��
    void print();                 // ��ü ���
};

