#ifndef USERPANEL_H
#define USERPANEL_H
#include <iostream>
#include <algorithm>
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

int chooseOperation() {
	cout << "Choose a operation:" << endl
		<< "1. Importing" << endl
		<< "2. Searching" << endl
		<< "3. Modifying" << endl
		<< "4. Deleting" << endl;

	int chooser;
	cin >> chooser;
	return chooser;
}

string importFrom() {
	string batch;
	cout << "please type in the file name: ";
	cin >> batch;
	return batch;
}

int searchOption() {
	int chooser;

	cout << "Search by" << endl
		<< "1. tconst" << endl
		<< "2. title type" << endl
		<< "3. title type and genres" << endl;
	cin >> chooser;
	return chooser;
}

int searchTconst() {
	int id;
	cout << "Type in the tconst: ";
	cin >> id;
	return id;
}

string searchTitleType() {
	string tt;
	cout << "Type in the title type: ";
	cin >> tt;
	return tt;
}

string searchGenre() {
	string g;
	cout << "Type in the genre: ";
	cin >> g;
	transform(g.begin(), g.end(), g.begin(), ::tolower);
	g[0] -= 32;
	return g;
}
#endif // !USERPANEL_H
