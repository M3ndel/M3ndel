#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Record.h"
#include "LinkList.h"
#include "UserPanel.h"
#include <ctime>
using namespace std;

int main() {
	ifstream infile(chooseDataset());
	if (infile.good())
		cout << "file successfully opened" << endl;
	else
		cout << "can't open the choosen file" << endl;

	LinkList list;
	clock_t start = clock();
	while (!infile.eof()) {
		list.push_back(infile);
	}

	cout << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

	system("pause");
	return 0;
}

