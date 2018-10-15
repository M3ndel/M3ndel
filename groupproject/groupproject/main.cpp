#include <iostream>
#include <fstream>
#include <string>
#include "Record.h"
using namespace std;

string chooseDataset();

int main() {
	ifstream infile(chooseDataset());
	string type[50];
	for (int i = 0; i < 50; i++) {
		type[i] = ".";
	}

	if (infile.good())
		cout << "file successfully opened" << endl;
	else
		cout << "can't open the choosen file" << endl;

	Record record;
	for (int i = 0; i < 50000; i++) {
		record.setRecord(infile);
		string str = record.titleType;
		for (int y = 0; y < 50; y++) {
			if (str == type[y]) {
				break;
			}
			else if (type[y] == ".") {
				type[y] = str;
				break;
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		cout << type[i] << endl;
	}

	system("pause");
	return 0;
}

string chooseDataset() {
	cout << "Choose a dataset:" << endl
		<< "1. DataSet1_1000.txt" << endl
		<< "2. DataSet2_2000.txt" << endl
		<< "3. DataSet3_5000.txt" << endl
		<< "4. DataSet4_10000.txt" << endl
		<< "5. DataSet5_50000.txt" << endl;
	
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

		case 4:
			filename = "DataSet_Required/DataSet4_10000.txt";
			return filename;

		case 5:
			filename = "DataSet_Required/DataSet5_50000.txt";
			return filename;
	
		default:
			cout << "choose between 1 to 5" << endl;
			chooseDataset();
	}
}