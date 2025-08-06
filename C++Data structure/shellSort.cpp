#include "shellSort.h"
#include <iostream>

using namespace std;

void shellSort::push(int input) {

	arr[count] = input;
	count++;
}
shellSort::shellSort(int size)
{	count = 0;
	this->size = size;
	arr = new int[size];

}
shellSort::~shellSort()
{
	delete[] arr;
}
void shellSort::Sort()
{
	// gap은 비교할 원소들 사이의 간격을 의미한다
	for (int gap = size / 2; gap > 0; gap /= 2) {
		// gap /= 2 , gat = gap/2
		for (int i = gap; i < size; ++i) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];

			}
			arr[j] = temp;
		}
	}
}
void shellSort::printArray()
{
	for (int i = 0; i < size; i++)
		cout << arr[i]<<" ";

	cout << endl;


}
