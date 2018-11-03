#ifndef LINKLIST_H
#define LINKLIST_H
#define Heap = 1;
#include "Record.h"

#include <iostream>
#include <fstream>
using namespace std;

class LinkList
{
public:

	Record* head;
	Record* tile;

public:
	LinkList();
	~LinkList();
	void insert2heap(ifstream&);
	void push_back(ifstream&);
	Record* search_tconst(long);
	Record* bottom_Left(Record* node);
	void swapNodePosition(Record* a, Record* b);
};

#endif
