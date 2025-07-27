#include "CircularQueue.h"

CircularQueue::CircularQueue() {
    rear = nullptr; // 마지막을 가리키는 노드를 초기화
    size = 0; // 초기화
}

CircularQueue::~CircularQueue() {
    while (size > 0) { // 사이즈가 0이 될때 까지 반복해서 동적할당된 메모리를 모두 지운다. 
        remove();
    }
}

void CircularQueue::push(int value) {
    Node* newNode = new Node(value); // 매개변수의 값을 받아 새 노드를 생성하고 newNode라는 변수에 값을 넣는다. 
    if (!rear) { // 큐가 비어 있으면 상태이면 작동한다, rear이 nullptr가 아닌지 확인 하는 조건으로 즉 !rear 은 real == nullptr랑 같은 뜻이다. 
        rear = newNode; // 새로 만든 너도를 rear에 넣고 
        rear->next = rear; // rear의 다음노드를 연결 시켜 자신를 가르키게 한다 그렇게 하면 원형을 이룬다 .
    } else { // real이 nullptr가 아닐 경우 작동한다.
        newNode->next = rear->next; // 새 노드의 다음 주소를 마지막 노드의 주소로 정한다. 
        rear->next = newNode; // 마지막 노드의 다음 주소를 새 노드로 정한다. 
        // 노드를 다 변경한 후에  마지막 노드를 바꾼다.
        rear = newNode; //이제 마지막노드는 새로만든 노드가 되었다. 
    }
    size++; // 사이즈 더하기 
}

int CircularQueue::remove() {
    if (!rear) { // rear이 nullptr이면 아무것도 넣지 않는 상태를 의미한다
        cout << "큐가 비어 있습니다." << endl;
        return -1; // int 함수로 인데 반환 값을 무조건 줘야 한다. 실행되면 함수를 종료한다
    }

    Node* front = rear->next; // 마지막 노드의 다음을 front로 정의한다.
    int value = front->data; // front의 데이터를 value로 정의한다. 

    if (rear == front) { // 노드가 한개일 경우
        delete front; //마지막의 노드의 다음 노드의 주소를 없애버린다.
        rear = nullptr;
        // 원형 큐에서 노드가 한개 일때 그 노드를 지우고 rear==nullptr만하면 완전히 초기화된 빈 큐 상태가 된다.
    } else {// 노드가 한개가 아닐 경우 
        rear->next = front->next; // 마지막 노드의 다음 주소를 첫번째노드에서 2번째 노드로 변경한다. 
        delete front; // 그후 첫번째 노드를 없애 버린다. 
        //큐는  선입 선출 형식으로 가장 먼저 들어본 첫번때 노드 부터 삭제한다.
    }  

    size--; // 사이즈의 줄인다. 
    return value; // 삭제한 노드의 데이터를 반환한다. 
}

void CircularQueue::insert(int index, int value) {
    if (index < 0 || index > size) {
        cout << "잘못된 인덱스입니다." << endl;
        return; // 삽입할 곳이 0보다 작을 경우 또는 size 보다 클경우 함수를 종료한다.
    }

    Node* newNode = new Node(value); // 새로운 노드 생성


    if (index == size) { // 마지막 노드에 넣는 경우
        push(value); // 마지막 삽입은 push와 동일
        return;
    }
// 여기서는 rear-> next는 첫번째 노드를 가리킨다. 이 다음에 prev를 for문으로 이동시킨다.
    Node* prev = rear; // prev는 임시저장소로서, rear는 원본이다. 
    for (int i = 0; i < index; i++) {
        prev = prev->next; // prev 이동 
    }
    newNode->next = prev->next; // 새로운 노드의 다음을 이동 시킨 prev의 다음 주소로 변경한다. 
    prev->next = newNode; // prev의 다음 주소를 새로운 만든 노드에 연결 시킨다. 



    if (index == 0 && rear == nullptr) { // 만약 노드를 아무것도 만들지 않고 첫 노드를 만들때 
        rear = newNode; //새 노드를 rear에 넣고 
        rear->next = rear; // rear의 다음 노드 rear으로 자기 자신으로 만들어 원형 형태를 구축한다.
    }

    size++;
}

int CircularQueue::count() const {
    return size; 
}

void CircularQueue::print() const {
    if (!rear) {
        cout << "큐가 비어 있습니다." << endl;
        return;
    }

    Node* current = rear->next;
    cout << "큐 내용: ";
    for (int i = 0; i < size; i++) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
