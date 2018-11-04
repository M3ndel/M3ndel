#include "binary.h"
#include <iostream>
using namespace std;

int main() {
	StackArr sa(56);
	if (sa.isFull()) {
		cout << "is full" << endl;
	}
	else {
		cout << "is not full" << endl;
	}

	cout << sa.pop() << endl;
	cout << sa.pop() << endl;
	cout << sa.pop() << endl;
	cout << sa.pop() << endl;
	

	if (sa.isEmpty()) {
		cout << "is empty" << endl;
	}
	else {
		cout << "is not empty" << endl;
	}

	system("pause");
	return 0;
}