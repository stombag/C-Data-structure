#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int size) {
    capacity = size;
    arr = new int[capacity]; // 동적메모리 할당 
    top = -1; // -1을 비어 있다는 뜻으로 의미한다. 에러 신호로 -1를 이용한것이다. 
}

Stack::~Stack() {
    delete[] arr;  // 메모리 청소
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "스택이 가득 찼습니다!" << endl;
        return;
    }
    arr[++top] = value;  // 이 코드가 실행 될때마다 top은 1씩 증가하면 
    // 배열의 위치가 변경된다. 
}

bool Stack::pop(int& result) { // 주소를 전달해서  원본을 바꾼다

    if (isEmpty()) {
        return false;  // 실패 : 꺼낼 값이 없음 
    }
    result = arr[top--]; // 맨위에 워치한 배열을 이동시켜서 연결을 끈고 그 값을 result에 넣는다. 
    return true;  // 성공 : 값을 꺼낸다.
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
        cout << "스택이 비어있습니다!" << endl;
        return;
    }

    cout << "스택 (top → bottom): ";
    for (int i = top; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
