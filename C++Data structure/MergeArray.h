#pragma once

class MergeArray {
private:
    int arr[100];
    int size;

    void mergeSort(int left, int right);      // 내부 정렬 함수
    void merge(int left, int mid, int right); // 병합

public:
    MergeArray();
    void insert(int value);   // 배열에 값 추가
    void sort();              // 정렬 실행
    void print();             // 배열 출력
};
