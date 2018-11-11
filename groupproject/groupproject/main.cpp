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
	int num = 1;
	clock_t start = clock();
	while (!infile.eof()) {
		list.insert2heap(infile);
	}
	cout << (clock() - start) / (double)CLOCKS_PER_SEC << endl;
	infile.close();
	infile.clear();
	system("pause");
	system("clean");

	switch (chooseOperation())
	{
	case 1: {
		ifstream importfile(importFrom());
		start = clock();
		while (!importfile.eof()) {
			list.insert2heap(importfile);
		}
		cout << (clock() - start) / (double)CLOCKS_PER_SEC << endl;
		importfile.close();
		importfile.clear();
		system("pause");
		system("clean");
	}
		break;

	case 2: {
		switch (searchOption())
		{
		case 1: {
			Record* r = list.search_tconst(searchTconst());
			if (r)
				r->printRecord();
		}
			break;
		case 2:

		case 4: {
			cout << "type in attribute for deletion: ";
			string attribute;
			int t;
			string type;
			cin >> attribute;
			if (attribute != "tconst") {
				t = 0;
				cout << "type in corresponding type for deletion: ";
				cin >> type;
			}
			else {
				cout << "type in ID for deletion: ";
				cin >> t;
			}
			list.searchANDdel(attribute, t, type, 2);
		}
			break;
		default:
			break;
		}
	
	}
	default:
		break;
	}
	
	

	system("pause");
	return 0;
}

