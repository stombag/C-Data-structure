#include <iostream>

#include "DoublyCircularLinkedList.h"   
using namespace std;

DoublyCircularLinkedList::DoublyCircularLinkedList() {
    dummyHead = new Node(); // 리스트 만들자 
    dummyHead->next = dummyHead; // 다음 노드를 더미로
    dummyHead->prev = dummyHead; //이전 노드를 더미로
    count = 0; // 카운트 초기화
}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    clear(); // 다 지우기
    delete dummyHead; // 더미데이터 지우기 
}

void DoublyCircularLinkedList::append(int value)
{
    Node* last = dummyHead->prev;  //라스트라는 이름을  더미헤드 이전노드의 이름으로 정한다== 이전노드 마지막 노드
    Node* newNode = new Node(value); // 새로운 노드에 값을 넣고 만든다.

    newNode->next = dummyHead; // 새노드의 다음 노드를 더미헤드로 넣는다
    newNode->prev = last; // 이전를 가리키는 걸 마지막 노드로 해서 연결한다
    last->next = newNode; // 마지막 노드의 다음 노드를 원래는 더미헤드였는데 새로운노드로 정한다
    dummyHead->prev = newNode; // 마지막으로 더미헤드의 이전 노드를 새로만든 노드로 넣어서 연결시킨다.

    count++; // 추가할때마다 카운트를 올린다.
}

void DoublyCircularLinkedList::insert(int index, int value) {
    if (index < 0 || index > count) return; // 만약 넣고 싶은 위치가 마이너스이면 안된게한다. 또한  넣고 싶은 위치가 만든 리스트보다 클 경우에도 함수를 종료한다.

    Node* current = dummyHead; // 현재라는 이름에 노드의주소값 저장한는 곳애 더미헤드를 넣는다.  더미헤드 부터 시작해야하기 때문이다
    for (int i = 0; i < index; ++i) // 넣고 싶은 위치까지 현재노드를 이동 시킨다. 
        current = current->next;

    Node* newNode = new Node(value);// 새노드 만들기 
    Node* nextNode = current->next;// 이동시킨 현재의 다음을 다음노드에 넣는다.

    newNode->next = nextNode;  // 새로만든 노드의 다음을 다음노드에 넣는다
    newNode->prev = current; // 새로 만든 노드의 이전를 현재에 연결 시킨다.
    current->next = newNode; // 현재노드의 다음 노드를 새노드에 연결 시킨다.
    nextNode->prev = newNode; // 다음 노드의 이전를 새로 만든 노드에 연결 시킨다

    // 삽입한 노드를 이전하고 다음 노드를 연결 시킨다.
    count++;
}

void DoublyCircularLinkedList::remove(int index) {
    if (index < 0 || index >= count) return; //없애야하는 자리숫자가 0보다 작거나 리스트보다 큰 숫자를 입력할경우 종료한다.

    Node* current = dummyHead->next; // 더미헤드의 다음를 current로 이름 붙인다.
    for (int i = 0; i < index; ++i) //current를 이동시킨다. index의 숫자 만큼
        current = current->next;

    Node* prevNode = current->prev; // current의 이전를 가리키는 노드를 이전노드
    Node* nextNode = current->next; // current의 다음를 가리키는 노드를 다음노드

    prevNode->next = nextNode; //이전노드의 다음을 다음노드로 연결 시킨다.
    nextNode->prev = prevNode; // 다음노드의 이전를 이전노드로 연결 시킨다.
    //current 이전과 다음 노드를 연결 시켜서 current의 없애도 리스트가 끝어지지않게 한다.

    delete current; // current의 자리에 있는 노드 삭제 
    count--; // 카운트 -1 
}

int DoublyCircularLinkedList::get(int index) const {
    if (index < 0 || index >= count) return -1; // 넣은 숫자가 마이너스 이거나 

    Node* current = dummyHead->next; // 더미헤드의 다음 노드를 current라는 이름으로 정한다.
    for (int i = 0; i < index; ++i) // current의 위치를 이동 시킨다. 
        current = current->next;

    return current->data;
}

void DoublyCircularLinkedList::print() const {
    Node* current = dummyHead->next;
    cout << "List: ";
    for (int i = 0; i < count; ++i) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyCircularLinkedList::clear() {
    while (count > 0)
        remove(0);
}

int DoublyCircularLinkedList::size() const {
    return count;
}
