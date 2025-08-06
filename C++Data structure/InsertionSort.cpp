#include "InsertionSort.h"
#include <iostream>

using namespace std;

Insertion::Insertion(int size)
{
	count = 0;
	this->size = size;
	arr = new int[size];

}

Insertion::~Insertion()
{
	delete[] arr;
}

void Insertion::push(int input) {

	arr[count] = input;
	count++;
}

void Insertion::sort()
{
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
			// �ӽð�ü key�� ����� �� ���� �ִ� �迭�� ���ؼ� �񱳴���� �� Ŭ ��� 
			// �� �� ���� ��� �ٲ۴� 
			
		}
		// �ٲٰ� �ӽð�ü�� ���� ���� �ٽ� �ִ´�. 
		arr[j + 1] = key;
	}
}
void Insertion::printArray()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;


}
