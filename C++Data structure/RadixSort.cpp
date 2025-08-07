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
    // 배열에서 최대값을 찾는걸 반복한다. 
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void RadixSort::countingSort(int exp) { // 이 함수는 현재 자릿수를 기준으로 정렬하는 역할을한다
    int buckets[10][100];       

    // exp는 비교할 자릿수를 나타내고 그 자릿수에 해당하는 숫자를 기준으로 0 ~ 9번 버킷에 분류해서 저장한다.
    // 예를 들어 exp = 10이면 십의 자리 수가 2인 20은 buckets[2]에 30은 buckets[3]에 저장된다.
    // 각 버킷 안의 100 크기 배열에 하나씩 차례로 넣는다. 
    int bucketCount[10] = { 0 }; // 각 버킷에 들어간 원소 수 
    // 버킷은 자리수 별로 분류할때 숫자들을 담아두는 임시저장소이다. 

    // 버킷에 분류
    for (int i = 0; i < size; ++i) {
        int digit = (arr[i] / exp) % 10;
        buckets[digit][bucketCount[digit]++] = arr[i];
        
        // 예)
        // 170 (170/10)%10 = 7  십의 자리는 7, 들어갈 버킷 buckets[7][0] = 170
        // 45 (45/10)%10 = 4 , 십의 자리는 4, 들어갈 버킷 buckets[4][0] = 45
        // 75 (75/10)%10 = 7, 십의 자리는 7, 들어갈 버킷 buckets[7][1] = 75
        // 버킷 7에는 170, 75, 버킷 4에는 45
        //
    }

    // 버킷에서 꺼내기
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
        // exe = 1 -> 일의 자리 
        // exe = 10 -> 십의 자리 
        // exe = 100 -> 백의 자리 
        // maxval/ exp >0은 최대값이 현재 자릿수보다 작아질 때까지만 반복한다.
        countingSort(exp);
    }
}

void RadixSort::print() {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
