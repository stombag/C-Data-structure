#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::Push(DataType data) // 연결 리스트의 끝에 새로운 노드를 추가하는 역할을 한다.
// void이므로 값을 반환하지 않습니다. 
{
	// Node* 는 Node 타입의 주소만 저장할 수 있는 변수이다. 
	// 즉 Node를 가리키는 포인터를 의미한다 .

	Node* newNode = new Node(data); 
	// 동적으로 생성하고 data값으로 갖는 노드를 하나 만들고 newNode는 만든 노드의 주소를 저장한다.
	// 새로 만들었기때문에 newNode 와 tail는 주소값이 다르다

	Node* tail = dummyHead;
	//tail 포인터를 사용해 리스트의 마지막 노드를 찾기 위한 준비를 한다.

	// new Node()는 새로운 객체를 만들고 값을 반환한다 newNode는 Node* 타입의 객체의 주소값을 저장하는거다 
	// new 는 동적할당하고 주소값을 반환한다

	while (tail->NextNode != nullptr) //NextNoder가 nullptr이 아닐 때까지 이동한다. 
		tail = tail->NextNode; // 리스트 끝으로 이동한다. 
	// 첫번째노드에서 Nextnode가 값이 잇으면 tail에 그 첫번째 노드의 NextNode를 넣으면 tail이 가리키는건 첫번째노드의 NextNode이다 
	// 그 NextNode가 값이 없으면 종료하고 있으면 두번째 노드의 NextNode를 tail에 넣는다

	//tail을 마지막 노드까지 이동시킨 뒤, 그 노드의 NextNode에 이번에 만든 노드를 연결한다.
	tail->NextNode = newNode; 

}

void LinkedList::Insert(int index, DataType data)// linkedlist 클래스 멤버함수이며 index 위치에 data 값을 data 값을 삽입한다.
{
	Node* newNode = new Node(data); // data 값을 가지고 있는 새로운 노드를 동적으로 생성한다. newNode는 새로 추가할 노드를 가리킨다. 
	Node* current = dummyHead; //삽입 위치를 찾기 위해 current 포인트를 시작점을 설정한다. 
	// 더미 헤드를 사용하면 삽입/ 삭제 시 특수한 경우 처리가 쉬워진다.

	while (index-- > 0 && current->NextNode != nullptr) // 삽입할 위치 바로 앞의 노드까지 이동한다.
	{//index --> 0: index를 1씩 줄이면서 0보다 큰 동안 반복한다.
	// 동시에 current->NextNode가 Nullptr이 아닌 동안만 반복한다.
		//결과 적으로 current는 삽입 위치 직전노드를 가리키게 된다.
		current = current->NextNode;
		// current->NextNode가 가리키는 노드를 current에 주소값을 넣는다 .
	}
	newNode->NextNode = current->NextNode;
	// 새 노드의 NextNode를 현재 노드의 다음 노드로 설정한다.
	// 즉 새 노드를 기존 리스트에 연결하는 준비를 한다. 

	current->NextNode = newNode;
	// 현재 노드의 nextNode를 새노드로 설정한다. 
	// 이로써 새 노드가 리스트에 실제로 삽입한다.
}

void LinkedList::Remove(int index) // index 위치에 있는 노드를 삭제한다.
{
	Node* current = dummyHead;//더미헤드는 리스트의 시작을 나타내는 더미헤드 노드이다 
	// 삭제할 노드 바로 앞 노드까지 이동하기 위해 current를 여기서 초기화 한다. 
	while (index-- > 0 && current->NextNode != nullptr)
	{// 삭제할 위치 바로 전 노드까지 이동하는 반복문입니다. 
		// 동시에 다음 노드가 nullptr이 아닌지 확인하여 범위 초과 방지도 합니다. 
		current = current->NextNode;
		// index가 0보다 클 때마다 curret를 한 칸씩 다음으로 이동한다.

	}

	Node* target = current->NextNode; // 실제로 삭제할 노드이다. 
	if (target != nullptr) //삭제할 노드가 존재하는지 확인한다. 
	{
		current->NextNode = target->NextNode; // current가 target을 가리키지 않고 target 다음 노드를 가리키도록 연결을 바꿉니다
		// 이렇게 하면 target 노드가 리스트에서 제거 한다
		delete target;
		// 제거한 노드의 메모리를 해제한다. 메모리 누수 방지 
	}

	// index가 1인경우 2번째 노드를 없애 버린다 .
}

DataType LinkedList::Get(int index) // 리스트에서 index위치에 있는 노드의 데이터 값을 반환한다.
// index는 0부터 시작하며, 반환 타입은 DataType이다.
{
	Node* current = dummyHead->NextNode;//리스트의 첫번째 실제 노드를 가리킨다.

	while (index-- > 0 && current != nullptr)
		//index가 0보다 클 동안, current를 계속 다음 노드로 이동시킨다.
		// 동시에 current가 nullptr이면 멈춥니다. 
	{
		current = current->NextNode;
		// 결과 : current가 index번째 노드를 가리키게 됩니다. 

	}
	if (current == nullptr) throw out_of_range("Index out of range");
	// 현재(current)가 nullptr 인 경우 즉 찾으려는 인덱스가 리스트 범위를 벗어났을때 예외를 발생한다 
	// throw out_of_range("Index out of range") 이건 문제가 발생했을때 예외로 두고 바깥 코드에서 처리하게 하는데 out of range는 예외클래스 이름이다 말그대로 범위를 벗어난경우 쓰는 예외 처리 명령어이다.
	// out of range 는 이 문제는 범위를 벗어것을 의미하는 예외 객체를 만들고 
	// throw는 그 예외 객체를 던져서 프로그램에게 문제가 생겼다고 알린다는 것다 ** 아직 이해 못함 **
	return current->Data;
}

int LinkedList::Count() const // 리스트에 들어있는 노드의 개수를 세서 정수로 반환합니다.
// const로 키워드가 있어 리스트의 내용을 변경하지 않음을 보장한다
{
	int count = 0; // 리스트 노드 개수를 셀 변수 cout를 0으로 초기화한다.
	Node* current = dummyHead->NextNode; // 더미 헤드 노드의 다음노드 부터 시작한다
	// 실제 데이터가 저장된 첫 번째 노드를 가리키는 포인터를 선언하고 초기화 한다
	while (current != nullptr) // current가 nullptr이 아닐 때 즉 리스트 끝에 도달하지 않았을 동안 반환 
		// 리스트의 끝을 nullptr로 표시하기때문에 이조건으로 반복문을 멈출 수 있다. 
	{
		count++;

		current = current->NextNode;
		//current를 다음 노드로 이동시킨다. 
		// 카운트 하고 다음으로 넘어가기 
	}

	return count;
	// 반복문이 끝나면 호출한 곳으로 카운트의 수를 보낸다 
}

void LinkedList::print() const // 화면 출력 
{
	Node* current = dummyHead->NextNode; // 첫번째 노드를 가리키는 포인터 current를 선언하고 초기화한다.
	// dummyHead는 더미 노드이고 실제 데이터는 dummyHead -> NextNode부터 시작한다. 
	while (current != nullptr) // current가 nullptr이 아닐 때 즉 리스트 끝에 도달하지 않을때 계속 반복한다.
	{
		cout << current->Data << " -> ";
		// 현재 노드에 저장된 데이터를 출력하고 뒤에 문자열도 출력해서 노드를 연결하는 모양을 보여준다. 
		current = current->NextNode;
		// current를 다음 노드로 이동시킨다. 
	}
	cout << "NULL" << endl;
	// 마지막 출력한다. 
}

void LinkedList::Clear() // 리스트에 있는 모든 노드를 메모리에서 삭제해서 리스트를 빈 상태로 만든다
{
	Node* current = dummyHead->NextNode; // 더미 헤드 다음부터가 실제 데이터가 있는 노드들이다. 
	// 그래서 거기부터 하나씩 삭제하려고 current 포인터를 거기에 맞춰 시작한다 
	while (current != nullptr)
	{
		
		Node* temp = current; // 삭제할 노드를 temp 포인터로 저장한다. 
		// 나중에 delete 하기 위해 잠깐 보관해두는 거다 
		current = current->NextNode; // current를 다음 노드로 이동시킨다. 
		delete temp;
		//temp가 가리키는 노드를 메모리에서 삭제한다. 이걸하지 않으면 메모리 누수(leak)이 발생한다
	}
	dummyHead->NextNode = nullptr;
	// 더미 헤드가 가리키는 첫 노드를 nullptr로 변경해서 이제 리스트는 완전히 빈 상태가 된다.
	// 이때 카운트는 0이 된다.
}
