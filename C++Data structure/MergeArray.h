#pragma once

class MergeArray {
private:
    int arr[100];
    int size;

    void mergeSort(int left, int right);      // ���� ���� �Լ�
    void merge(int left, int mid, int right); // ����

public:
    MergeArray();
    void insert(int value);   // �迭�� �� �߰�
    void sort();              // ���� ����
    void print();             // �迭 ���
};
