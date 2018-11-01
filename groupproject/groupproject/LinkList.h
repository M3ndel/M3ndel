#ifndef LINKLIST_H
#define LINKLIST_H
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

	void push_back(ifstream&);
};

#endif
