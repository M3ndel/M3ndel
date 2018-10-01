#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	cout << "Choose a dataset:" << endl
		<< "1. DataSet1_1000.txt" << endl
		<< "2. DataSet2_2000.txt" << endl
		<< "3. DataSet3_5000.txt" << endl;
	int chooser = 0;
	string filename;
	while (chooser != 1 && chooser != 2 && chooser != 3) {
		cin >> chooser;

		switch (chooser) {
			case 1:
				filename = "DataSet_Required/DataSet1_1000.txt";
				break;
			case 2:
				filename = "DataSet_Required/DataSet2_2000.txt";
				break;
			case 3:
				filename = "DataSet_Required/DataSet3_5000.txt";
				break;
			
			default:
				cout << "choose 1-3" << endl;
		}
	}

	ifstream infile(filename);

	if (infile.good()) {
		cout << "file successfully opened";
	}
	else
		cout << "can't open the choosen file";


	system("pause");
	return 0;
}