#ifndef BINARY_H
#define BINARY_H

class StackArr {
private:
	int maxTop;
	int stackTop;
	int *values;
	int size;


public:
	StackArr(long);
	//stackarr();
	~StackArr();
	bool isEmpty() const;
	bool isFull() const;
	int top() const;
	// record* top() const;
	void push(const int& x);
	int pop();
	void displayStack() const;
};

#endif