#include "binary.h"
#include <string>
#include <iostream>

using namespace std;

StackArr::StackArr(long n) {
	size = log(n) / log(2);
	maxTop = size + 1;
	values = new int[size + 1];
	stackTop = -1;
	int* Bin = new int[size + 1];
	for (int i = 0; i <= size; i++)
	{
		Bin[i] = n % 2;
		n = n / 2;
		if (i < size) {
			push(Bin[i]);
		}
	}
	delete[] Bin;
}

StackArr::~StackArr() {
	delete[] values;
}

bool StackArr::isEmpty() const {
	return stackTop == -1;
}

bool StackArr::isFull() const {
	return stackTop == maxTop;
}

void StackArr::push(const int& x) {
	if (isFull())
		cout << "Error! The stack is full!" << endl;
	else
		values[++stackTop] = x;
}

int StackArr::pop() {
	if (isEmpty()) {
		cout << "Error! The stack is empty!" << endl;
		return -1;
	}
	else
		return values[stackTop--];
}

int StackArr::top() const {
	if (isEmpty()) {
		cout << "Error! The stack is empty!" << endl;
		return -1;
	}
	else
		return values[stackTop];
}

void StackArr::displayStack() const {
	cout << "Top -->";
	for (int i = stackTop; i >= 0; i--)
		cout << "\t|\t" << values[i] << "\t|" << endl;
	cout << "\t|---------------|" << endl << endl;

}
