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

	
	while (!infile.eof()) {
		Record* record = new Record;
		record->setRecord(infile);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 50; j++) {
				if (record->genres[i] == type[j] || record->genres[i] == "") {
					break;
				}
				else if (type[j] == ".") {
					type[j] = record->genres[i];
					break;
				}
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