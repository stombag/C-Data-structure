#include"RadixSort.h"

RadixSort::RadixSort(int size)
{
	this->size = size;
	this->value = 0;
	arr = new int[size];

}

RadixSort::~RadixSort()
{
	delete[] arr;

}

void RadixSort::push(int input) {
    if (value < size) {
        arr[value++] = input;
    }
}

int RadixSort::getMax() {
    // �迭���� �ִ밪�� ã�°� �ݺ��Ѵ�. 
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void RadixSort::countingSort(int exp) { // �� �Լ��� ���� �ڸ����� �������� �����ϴ� �������Ѵ�
    int buckets[10][100];       

    // exp�� ���� �ڸ����� ��Ÿ���� �� �ڸ����� �ش��ϴ� ���ڸ� �������� 0 ~ 9�� ��Ŷ�� �з��ؼ� �����Ѵ�.
    // ���� ��� exp = 10�̸� ���� �ڸ� ���� 2�� 20�� buckets[2]�� 30�� buckets[3]�� ����ȴ�.
    // �� ��Ŷ ���� 100 ũ�� �迭�� �ϳ��� ���ʷ� �ִ´�. 
    int bucketCount[10] = { 0 }; // �� ��Ŷ�� �� ���� �� 
    // ��Ŷ�� �ڸ��� ���� �з��Ҷ� ���ڵ��� ��Ƶδ� �ӽ�������̴�. 

    // ��Ŷ�� �з�
    for (int i = 0; i < size; ++i) {
        int digit = (arr[i] / exp) % 10;
        buckets[digit][bucketCount[digit]++] = arr[i];
        
        // ��)
        // 170 (170/10)%10 = 7  ���� �ڸ��� 7, �� ��Ŷ buckets[7][0] = 170
        // 45 (45/10)%10 = 4 , ���� �ڸ��� 4, �� ��Ŷ buckets[4][0] = 45
        // 75 (75/10)%10 = 7, ���� �ڸ��� 7, �� ��Ŷ buckets[7][1] = 75
        // ��Ŷ 7���� 170, 75, ��Ŷ 4���� 45
        //
    }

    // ��Ŷ���� ������
    int idx = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < bucketCount[i]; ++j) {
            arr[idx++] = buckets[i][j];
        }
    }
}

void RadixSort::sort() {
    int maxVal = getMax();

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        // exe = 1 -> ���� �ڸ� 
        // exe = 10 -> ���� �ڸ� 
        // exe = 100 -> ���� �ڸ� 
        // maxval/ exp >0�� �ִ밪�� ���� �ڸ������� �۾��� �������� �ݺ��Ѵ�.
        countingSort(exp);
    }
}

void RadixSort::print() {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
