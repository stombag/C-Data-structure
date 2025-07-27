#include "CircularQueue.h"

CircularQueue::CircularQueue() {
    rear = nullptr; // �������� ����Ű�� ��带 �ʱ�ȭ
    size = 0; // �ʱ�ȭ
}

CircularQueue::~CircularQueue() {
    while (size > 0) { // ����� 0�� �ɶ� ���� �ݺ��ؼ� �����Ҵ�� �޸𸮸� ��� �����. 
        remove();
    }
}

void CircularQueue::push(int value) {
    Node* newNode = new Node(value); // �Ű������� ���� �޾� �� ��带 �����ϰ� newNode��� ������ ���� �ִ´�. 
    if (!rear) { // ť�� ��� ������ �����̸� �۵��Ѵ�, rear�� nullptr�� �ƴ��� Ȯ�� �ϴ� �������� �� !rear �� real == nullptr�� ���� ���̴�. 
        rear = newNode; // ���� ���� �ʵ��� rear�� �ְ� 
        rear->next = rear; // rear�� ������带 ���� ���� �ڽŸ� ����Ű�� �Ѵ� �׷��� �ϸ� ������ �̷�� .
    } else { // real�� nullptr�� �ƴ� ��� �۵��Ѵ�.
        newNode->next = rear->next; // �� ����� ���� �ּҸ� ������ ����� �ּҷ� ���Ѵ�. 
        rear->next = newNode; // ������ ����� ���� �ּҸ� �� ���� ���Ѵ�. 
        // ��带 �� ������ �Ŀ�  ������ ��带 �ٲ۴�.
        rear = newNode; //���� ���������� ���θ��� ��尡 �Ǿ���. 
    }
    size++; // ������ ���ϱ� 
}

int CircularQueue::remove() {
    if (!rear) { // rear�� nullptr�̸� �ƹ��͵� ���� �ʴ� ���¸� �ǹ��Ѵ�
        cout << "ť�� ��� �ֽ��ϴ�." << endl;
        return -1; // int �Լ��� �ε� ��ȯ ���� ������ ��� �Ѵ�. ����Ǹ� �Լ��� �����Ѵ�
    }

    Node* front = rear->next; // ������ ����� ������ front�� �����Ѵ�.
    int value = front->data; // front�� �����͸� value�� �����Ѵ�. 

    if (rear == front) { // ��尡 �Ѱ��� ���
        delete front; //�������� ����� ���� ����� �ּҸ� ���ֹ�����.
        rear = nullptr;
        // ���� ť���� ��尡 �Ѱ� �϶� �� ��带 ����� rear==nullptr���ϸ� ������ �ʱ�ȭ�� �� ť ���°� �ȴ�.
    } else {// ��尡 �Ѱ��� �ƴ� ��� 
        rear->next = front->next; // ������ ����� ���� �ּҸ� ù��°��忡�� 2��° ���� �����Ѵ�. 
        delete front; // ���� ù��° ��带 ���� ������. 
        //ť��  ���� ���� �������� ���� ���� �� ù���� ��� ���� �����Ѵ�.
    }  

    size--; // �������� ���δ�. 
    return value; // ������ ����� �����͸� ��ȯ�Ѵ�. 
}

void CircularQueue::insert(int index, int value) {
    if (index < 0 || index > size) {
        cout << "�߸��� �ε����Դϴ�." << endl;
        return; // ������ ���� 0���� ���� ��� �Ǵ� size ���� Ŭ��� �Լ��� �����Ѵ�.
    }

    Node* newNode = new Node(value); // ���ο� ��� ����


    if (index == size) { // ������ ��忡 �ִ� ���
        push(value); // ������ ������ push�� ����
        return;
    }
// ���⼭�� rear-> next�� ù��° ��带 ����Ų��. �� ������ prev�� for������ �̵���Ų��.
    Node* prev = rear; // prev�� �ӽ�����ҷμ�, rear�� �����̴�. 
    for (int i = 0; i < index; i++) {
        prev = prev->next; // prev �̵� 
    }
    newNode->next = prev->next; // ���ο� ����� ������ �̵� ��Ų prev�� ���� �ּҷ� �����Ѵ�. 
    prev->next = newNode; // prev�� ���� �ּҸ� ���ο� ���� ��忡 ���� ��Ų��. 



    if (index == 0 && rear == nullptr) { // ���� ��带 �ƹ��͵� ������ �ʰ� ù ��带 ���鶧 
        rear = newNode; //�� ��带 rear�� �ְ� 
        rear->next = rear; // rear�� ���� ��� rear���� �ڱ� �ڽ����� ����� ���� ���¸� �����Ѵ�.
    }

    size++;
}

int CircularQueue::count() const {
    return size; 
}

void CircularQueue::print() const {
    if (!rear) {
        cout << "ť�� ��� �ֽ��ϴ�." << endl;
        return;
    }

    Node* current = rear->next;
    cout << "ť ����: ";
    for (int i = 0; i < size; i++) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
