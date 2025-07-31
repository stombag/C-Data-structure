#pragma once

class QuickArray {
private:
    int arr[100];
    int size;

    void quickSort(int left, int right); // 퀵 정렬 본체
    int partition(int left, int right);  // 분할 함수

public:
    QuickArray();
    void insert(int value);  // 값 추가
    void sort();             // 정렬 실행
    void print();            // 출력
};


