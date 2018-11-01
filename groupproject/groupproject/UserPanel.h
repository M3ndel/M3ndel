#ifndef USERPANEL_H
#define USERPANEL_H
#include <iostream>
#include <string>
using namespace std;

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


#endif // !USERPANEL_H
