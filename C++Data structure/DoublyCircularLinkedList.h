#pragma once
#include <iostream>

class DoublyCircularLinkedList {
private:
    struct Node {
        int data;
        Node* prev;//이전노드
        Node* next;// 다음노드

        Node(int d = 0) : data(d), prev(nullptr), next(nullptr) {} // 초기화 
    };

    Node* dummyHead;// 더미헤드 
    int count; //카운드 

public:
    DoublyCircularLinkedList(); //생성자

    ~DoublyCircularLinkedList();//소멸자

    void append(int value);// 넣기
    void insert(int index, int value);//삽입
    void remove(int index);//삭제
    int get(int index) const; //가져오기
    
    void print() const; // 출력
    void clear(); // 다 지우기
    int size() const; // 사이즈 확인
};
// 장점 : 
// 앞과 뒤로 자유롭게 이E할 수 있다.
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
