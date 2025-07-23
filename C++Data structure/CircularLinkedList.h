#pragma once

class CircularLinkedList {
private: 
    struct Node {
        // 노드 객체 만들기 
    int data; // 노드에 들어갈 데이터
    Node* next; // 다음노드 주소값 저장하기

    Node(int d = 0) : data(d), next(nullptr) {} // 초기화 

};
    Node* dummyHead; // 더미헤드 
    int count ;

public:
    CircularLinkedList(); // 생성자
    ~CircularLinkedList(); // 소멸자 
 
    void Push(int value);

    void insert(int index, int value);

    void remove(int index);

    int get(int index)const;

    void Print()const;

    void claen();

};
// 장점:
// 반복 처리에 유리하다
// 양 끝 처리가 편리하다
// NULL 걱정할 필요가 없다 
// 하나의 노드에서 다른 모든 노드로의 접근이 가능하다.
// 리스트의 끝에 노드를 삽입 하는 연산이 단순 연결리스트보다 효율적이다.

// 단점:
// 끝 판단이 어렵다.
// 복잡한 구현
// 무한 루프 위험성
// 단순 용도에는 오버스팩이다.

// 사용예시
// 턴제 게임(ex. 보드게임,카드게임) - 플레이어가 반복적으로 돌아가며 턴을 가진다.
// Ai 순환 행동 루틴 - 반복적인 행동 루틴을 순서대로 돌며 처리한다. (ex. 정찰-> 수리->공격->정찰-..)
// 루프 애니매이션 - 끝없이 반복되는 몬스터 또는 배경 애니메니션
// 보스 패턴 순환 - 보스가 특정 공격 패턴을 계속 반복한다.(ex. 공격1->공격2->회피-...)


// 원형 링크더 리스트와 링크더 리스트 차이
// linkedlist는 간단하고 일반적인 구조,탐색시 끝을 nullptr로 쉽게 감지 가능 - 단순구조, 마지막 노드처리 복잡(직접관리 해야한다.)
// CircularLinkedList가 필요한 경우에 적합, 끝과 처음을 연결해 놓았기 때문에 특정 작업(무한 반복등) 유리하다 - 복잡구조, 마지막 노드처리 간단


