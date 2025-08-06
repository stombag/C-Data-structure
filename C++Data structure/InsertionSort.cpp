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
			// 임시객체 key를 만들고 그 전에 있는 배열과 비교해서 비교대상이 더 클 경우 
			// 그 비교 값과 대상를 바꾼다 
			
		}
		// 바꾸고 임시객체에 넣은 값을 다시 넣는다. 
		arr[j + 1] = key;
	}
}
void Insertion::printArray()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;


}
