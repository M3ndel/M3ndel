#include <iostream>
#include <fstream>
#include <string>
#include "Record.h"
#include <ctime>
using namespace std;

string chooseDataset();

int main() {
	ifstream infile(chooseDataset());

	if (infile.good())
		cout << "file successfully opened" << endl;
	else
		cout << "can't open the choosen file" << endl;

	clock_t start = clock();

	Record record[5000];
	int b = time(NULL);
	for (int i = 0; i < 5000; i++) {
		record[i].setRecord(infile);
	}

	cout << clock() - start << endl;

	system("pause");
	return 0;
}

string chooseDataset() {
	cout << "Choose a dataset:" << endl
		<< "1. DataSet1_1000.txt" << endl
		<< "2. DataSet2_2000.txt" << endl
		<< "3. DataSet3_5000.txt" << endl;
	
	int chooser = 0;
	string filename;

	cin >> chooser;
	switch (chooser) {
		case 1:
		filename = "DataSet_Required/DataSet1_1000.txt";
			return filename;
		case 2:
			filename = "DataSet_Required/DataSet2_2000.txt";
			return filename;
		case 3:
			filename = "DataSet_Required/DataSet3_5000.txt";
			return filename;
	
		default:
			cout << "choose between 1 to 3" << endl;
			chooseDataset();
	}
}