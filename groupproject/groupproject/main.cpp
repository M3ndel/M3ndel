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
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------WELCOME TO OUR WORLD---------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	int enter = 0;
	int chooser = 0;
	int intdata = -1;
	string stringdata = "";
	int c = 0;		//c: 1->search 2->delete
	int s = -1;
	int first;
	int last;
	LinkList list;

	ifstream infile(chooseDataset());
	if (infile.good())
		cout << "file successfully opened" << endl;
	else
		cout << "can't open the choosen file" << endl;
	int num = 1;
	clock_t start = clock();
	while (!infile.eof()) {
		list.insert2heap(infile);
	}
	cout << "It only used " << (clock() - start) / (double)CLOCKS_PER_SEC << "s.\n\n";
	system("pause");
	system("cls");

	do {
		enter = chooseOperation();
		intdata = -1;
		stringdata = "";
		c = 0;		//c: 1->search 2->delete
		s = -1;

		switch (enter) {
			// import other file into the data structure
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
			system("cls");
		}
				break;
		case 2:		//search, follow throught case 4
				//Deleting
		case 4: {
				s = searchANDdelrange(enter);
				if (s != -1)
				{
					cout << "Enter the range: ";
					cin >> first;
					cin >> last;
					list.searchANDdelsomeYearMinute(first, last, enter / 2, s);
					break;
				}
				if (enter == 2) {
					chooser = searchOption();
					c = 1;
				}
				else if (enter == 4)
				{
					chooser = DeleteOption();
					c = 2;
				}
				switch (chooser)		//tconst, titleType, primaryTitle, startYear, genres, runtime
				{
				case 1:
					intdata = searchANDdelTconst();
					list.searchANDdel("tconst", intdata, stringdata, c);
					break;
				case 2:
					stringdata = searchANDdelTitleType();
					list.searchANDdel("titleType", intdata, stringdata, c);
					break;
				case 3:
					stringdata = searchANDdelPrimaryTitle();
					list.searchANDdel("primaryTitle", intdata, stringdata, c);
					break;
				case 4:
					intdata = searchANDdelStartYear();
					list.searchANDdel("startYear", intdata, stringdata, c);
					break;
				case 5:
					stringdata = searchANDdelGenre();
					list.searchANDdel("genres", intdata, stringdata, c);
					break;
				case 6:
					intdata = searchANDdelRunTime();
					list.searchANDdel("runtime", intdata, stringdata, c);
					break;
				}
		}
			break;
			// modify the record with a corrsponding ID
		case 3: {
			Record* r = list.search_tconst(searchTconst());
			switch (modifyBy())
			{
			case 1: {
				cout << "change the title type into: ";
				cin >> r->titleType;
			}
					break;
			case 2: {
				cout << "change the primary title into: ";
				cin >> r->primaryTitle;
			}
					break;
			case 3: {
				cout << "change the start year into: ";
				cin >> r->startYear;
			}
					break;
			case 4: {
				cout << "change the Run time into: ";
				cin >> r->runtimeMinutes;
			}
					break;
			case 5: {
				int c;
				cout << "choose a genre to change(1-3): ";
				cin >> c;
				cout << "change the genre into: ";
				cin >> r->genres[c - 1];
			}
					break;
			default:		//Leave
				enter = -1;
				break;
			}
			}
		}
		} while (enter != -1);

		system("pause");
		return 0;
	}