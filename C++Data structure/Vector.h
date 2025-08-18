#pragma once

#include <iostream>

class Vector {
private:
	int* data;
	int sz;
	int cap;

	void expand();

public:
	Vector();
	~Vector();

	void push_back(int val);
	void pop_back();
	int at(int index) const;
	int& operator[](int idx);

	int size() const;
	int capacity() const;
	  
	void clear();
};