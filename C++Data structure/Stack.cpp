#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int size) {
    capacity = size;
    arr = new int[capacity]; // �����޸� �Ҵ� 
    top = -1; // -1�� ��� �ִٴ� ������ �ǹ��Ѵ�. ���� ��ȣ�� -1�� �̿��Ѱ��̴�. 
}

Stack::~Stack() {
    delete[] arr;  // �޸� û��
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "������ ���� á���ϴ�!" << endl;
        return;
    }
    arr[++top] = value;  // �� �ڵ尡 ���� �ɶ����� top�� 1�� �����ϸ� 
    // �迭�� ��ġ�� ����ȴ�. 
}

bool Stack::pop(int& result) { // �ּҸ� �����ؼ�  ������ �ٲ۴�

    if (isEmpty()) {
        return false;  // ���� : ���� ���� ���� 
    }
    result = arr[top--]; // ������ ��ġ�� �迭�� �̵����Ѽ� ������ ���� �� ���� result�� �ִ´�. 
    return true;  // ���� : ���� ������.
}

bool Stack::peek(int& result) const {
    if (isEmpty()) {
        return false;
    }
    result = arr[top];
    return true;
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == capacity - 1;
}

void Stack::print() const {
    if (isEmpty()) {
        cout << "������ ����ֽ��ϴ�!" << endl;
        return;
    }

    cout << "���� (top �� bottom): ";
    for (int i = top; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
