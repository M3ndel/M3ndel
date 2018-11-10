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
	transform(tt.begin(), tt.end(), tt.begin(), ::tolower);
	return tt;
}

string searchGenre() {
	string g;
	cout << "Type in the genre: ";
	cin >> g;
	transform(g.begin(), g.end(), g.begin(), ::tolower);
	return g;
}

int DeleteOption() {
	int chooser;
	//tconst, titleType, primaryTitle, startYear, genres, runtimeMinutes
	cout << "\nDelete by" << endl
		<< "1. tconst" << endl
		<< "2. title type" << endl
		<< "3. primaryTitle" << endl
		<< "4. startYear" << endl
		<< "5. genres" << endl
		<< "6. runtimeMinutes" << endl
		<< "Choose: ";
	cin >> chooser;
	return chooser;
}


int searchANDdelTconst() {
	int id;
	cout << "Type in the tconst: ";
	cin >> id;
	return id;
}

string searchANDdelTitleType() {
	string tt;
	cout << "Type in the title type: ";
	cin.ignore();
	getline(cin, tt);
	//cin >> tt;
	//transform(tt.begin(), tt.end(), tt.begin(), ::tolower);
	return tt;
}

string searchANDdelPrimaryTitle() {
	string pt;
	cout << "Type in the primary type: ";
	cin.ignore();
	getline(cin, pt);
	return pt;
}

int searchANDdelStartYear() {
	int Year;
	cout << "Type in the start Year: ";
	cin >> Year;
	return Year;
}

string searchANDdelGenre() {
	string g;
	cout << "Type in the genre: ";
	cin.ignore();
	getline(cin, g);
	//cin >> g;
	//transform(g.begin(), g.end(), g.begin(), ::tolower);
	return g;
}

int searchANDdelRunTime() {
	int time;
	cout << "Type in the run time minutes: ";
	cin >> time;
	return time;
}

int searchANDdelrange(int enter) {
	string ans;
	int chooser;
	if (enter == 2)
	{
		cout << "Do you want to search by range? (yes/no)\n";
		cin >> ans;
		if (ans == "yes")
		{
			cout << "\nSearch by" << endl
				<< "1. tconst" << endl
				<< "2. startYear" << endl
				<< "3. runtimeMinutes" << endl
				<< "Choose: ";
			cin >> chooser;
			return chooser;
		}
	}
	else if (enter == 4)
	{
		cout << "Do you want to search by range? (yes/no)\n";
		cin >> ans;
		if (ans == "yes")
		{
			cout << "\nDelete by" << endl
				<< "1. tconst" << endl
				<< "2. startYear" << endl
				<< "3. runtimeMinutes" << endl
				<< "Choose: ";
			cin >> chooser;
			return chooser;
		}
	}
	else
		return -1;
}
#endif // !USERPANEL_H
