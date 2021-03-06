#ifndef LINKLIST_H
#define LINKLIST_H
#include "Record.h"
#include <iostream>
#include <fstream>
using namespace std;

class LinkList
{
public:
	Record* head; // head of heap
	Record* cList_h; // head of singlist
	Record* tile; // tile of singlist

public:
	LinkList();
	~LinkList();
	void insert2heap(ifstream&);
	void reset(Record*);
	void searchANDdelsomeYearMinute(int first, int last, int c, int n);	//c: 1->search 2->delete n: 1->tconst 2->Year 3->Minute
	void searchANDdel(string, int, string, int); //c: 1->search 2->delete	type: tconst, titleType, primaryTitle, startYear, genres, runtimeMinutes
	Record* search_tconst(long);
};


#endif
