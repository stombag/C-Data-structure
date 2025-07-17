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
    if (index < 0 || index >= count) return  -1; // 조건이 참이면 그자리에서 함수를 종료하고
    // 이 조건이 거짓이면 실행하지 않고 아래 코드가 실행한다.

    Node* current = dummyHead->next; // 더미헤드의 다음 노드를 current라는 이름으로 정한다.
    for (int i = 0; i < index; ++i) // current의 위치를 이동 시킨다. 
        current = current->next;
    return current->data; //이동 시킨 current에 있는 data 값을 반환한다.
}

void DoublyCircularLinkedList::print() const {
    Node* current = dummyHead->next; // 노드의 주소를 저장하는 장소를 current로 정하고 거기에 더미헤드의 다음를 가리키는 주소값을 넣는다.
    cout << "List: ";
    for (int i = 0; i < count; ++i) { // count의 숫자 만큼 반복되게 한다
        cout << current->data << " "; // current의 data값을 출력한다
        current = current->next; // current의 위치를 변경시킨다.
    }
    cout << endl;
}


void DoublyCircularLinkedList::clear() {
    while (count > 0) // count가 0이 될때까지 실행한다.
        remove(0); // 
}

int DoublyCircularLinkedList::size() const {
    cout << count << endl;
    return count; //현재 까지 있는 노드 숫자를 가져와서 반환하기
}
// 장점 : 
// 앞과 뒤로 자유롭게 이둉할 수 있다.
// 더 유연한 자료구조 구현이 가능하다
// 삽입/삭제가 효율적이다.
// 양 끝 노드 연결되서 특별 처리 줄어든다

// 단점 :
// 메모리 사용 증가: 포인터가 2개라 노드당 메모리 사용량이 단일 연결 리스트보다 크다 
// 버그 가능성 높다 : 삽입/ 삭제 시 모두 올바르게 연결해야한다. 
// 무한 루프 위험성 

// 사용 예시 : 
// 캐릭터 턴 되감기 시스템 - 플레이어가 한 턴 전/후로 이동 가능 
// 무기/ 아이템 캘리셀 - 무기를 왼쪽/ 오른쪽으로 넘기며 선택 가능, 마지막-> 처음 가능
// UI 커서 순환 - 메뉴 커서가 끝에서 다시 처음으로 또는 뒤로 이동(캐릭터 선택UI)
// 히스토리/행동 되돌리기 - 행동을 저장해 놓고 이동하며 취소/ 다시하기 구현 

// 단방향 원형 리스트와 양방향 원형 리스트의 차이
// 단방향 원형 리스트는 단순한 순환 구조로 가볍고 구현이 쉽다 하지만 뒤로 이동하는 건 불가능학 삭제시 이전 노드를 알아야 해서 불편하다
// 양방향 원형 리스트는 앞뒤로 자유롭게 탐색 가능하며, 중간 삽입/ 삭제도 편리하지만, 포인터 2개 관리로 구현이 복잡하고 메모리도 더 사용해야한다.