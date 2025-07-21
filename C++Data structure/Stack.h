#pragma once
class Stack
{
private:
	int* arr;// 스택 배열 
	int capacity; // 최대 크기
	int top;// top 인덱스

public:
	Stack(int size = 100); // 생성자 
	~Stack(); // 소멸자
	void push(int value);// 값을 넣기
	bool pop(int&result);// 값을 꺼내고 지우기
	bool peek(int& result) const;// 맨위의 값을 보기
	bool isEmpty() const;// 비어있는지 확인
	bool isFull()const; // 꽉 찼는지 확인 
	void print() const;// 스택 출력 

};
