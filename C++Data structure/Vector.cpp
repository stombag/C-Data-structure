#include "Vector.h"

using namespace std;

Vector::Vector() : data(nullptr), sz(0), cap(0){}

Vector::~Vector() {
	delete[] data;
		
}

void Vector::expand() {
	int newCap = (cap == 0) ? 1 : cap * 2;
	int* newData = new int[newCap];

	for (int i = 0; i < sz; i++) {
		newData[i] = data[i];

	}
	delete[] data;
	data = newData;
	cap = newCap;

}

void Vector::push_back(int val) {
	if (sz >= cap) {
		expand();


	}
	data[sz++] = val;

}

void Vector::pop_back() {
	if (sz > 0) {
		sz--;
	}

}


int Vector::at(int index)const {
	if (index < 0 || index >= sz) {
		cout << "index out of range" << endl;
		return -1;

	}
	return data[index];
}
int& Vector::operator[](int idx) {
	return data[idx];
}
int Vector::size()	const {
	return sz;

}
int Vector::capacity() const {
	return cap;

}
void Vector::clear() {
	sz = 0;
}