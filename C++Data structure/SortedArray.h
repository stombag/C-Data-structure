#pragma once


class SortedArray {
private:
    int arr[100];
    int size;

public:
    SortedArray();
    void insert(int value);       // 정렬되게 삽입
    bool search(int target);      // 이진 탐색
    void print();                 // 전체 출력
};

