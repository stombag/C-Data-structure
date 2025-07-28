#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int size) :capacity(size), front(0), rear(0) { // 변수 초기화 
	// 헤더파일에서 입력한 size값을 capacity에 넣는다. 나머지 변수는 초기화를 진행한다. 
	arr = new int[capacity]; //capacity를 넣어서 배열을 크기를 정한다.
}
ArrayQueue::~ArrayQueue() {
	delete[] arr; // 배열을 다 삭제 

}

void ArrayQueue::push(int value) {
	if (isFull()) {
		cout << "Queue is full!" << endl;
		return; //다 있으면 함수 종료 
	}
	arr[rear++] = value; //  value를 해당 배열에 맞게 넣는다, 그후 rear의 숫자는 1씩 증가한다(후위). 뒤로 늘어난다. 

}

int ArrayQueue::remove() {
	if (isEmpty()) {
		return -1; // int는 함수를 종료하려면 반환을 해야한다 하지만 이 경우 실패했다는 의미로 -1로 적어 함수를 종료 시킨다. 
	}
	int removedValue = arr[front]; // removedValue라는 변수를 만들고 거기에 frout를 넣는다. 
	for (int i = front; i < rear - 1; ++i) { // rear 만큼 반복해서 
		arr[i] = arr[i + 1]; // arr를 앞으로 땡긴다. 
	}
	rear--; // 앞에 있던 배열를 빼고 뒤에있는 스택을 넣는다 물론 메모리는 남아있다
	return removedValue; // 지운 배열의 값을 알려준다. 

}

void ArrayQueue::insert(int index, int value) {
	if (isFull()) {
		return;// 다차면 종료
	}
	if (index<0 || index>count()) {
		return;  // 넣을 곳이 마이너스 이거나 넣은배열보다 큰 수 일경우 종료한다. 
	}
	for (int i = rear; i > front + index; --i) {  // 넣을 값과 front를 더한 값보다 크면 반복한다 .할때마다 i는 1씩 감소한다.
		arr[i] = arr[i - 1]; // 뒤로 땡긴다.

		//이 과정은 삽입할 공간을 확보하기 위한 코드이다
	}
	arr[front + index] = value; // 삽입한다
	rear++; // 배열에 넣은 크기 1증가

}

int ArrayQueue::count()const {
	return rear - front; // 크기 

}
void ArrayQueue::print()const {
	for (int i = front; i < rear; ++i) {
		cout << arr[i] << " ";// 배열 하나씩 프린트
	}
	cout << endl;
}

bool ArrayQueue::isEmpty() const {
	for (int i = front; i < rear; ++i) {
		cout << arr[i]; // 배열이 다들어 있는지 확인 
	}
	cout << endl;
	return true;
}

bool ArrayQueue::isFull()const {
	return rear == capacity; // 용량과 뒤를 가리키는 값이 같은면 실행 종료
}