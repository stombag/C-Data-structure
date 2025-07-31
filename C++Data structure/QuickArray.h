#pragma once

class QuickArray {
private:
    int arr[100];
    int size;

    void quickSort(int left, int right); // �� ���� ��ü
    int partition(int left, int right);  // ���� �Լ�

public:
    QuickArray();
    void insert(int value);  // �� �߰�
    void sort();             // ���� ����
    void print();            // ���
};


