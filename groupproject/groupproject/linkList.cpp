#include "LinkList.h"



LinkList::LinkList()
{
	head = NULL;
	tile = NULL;
}


LinkList::~LinkList()
{

}

void LinkList::push_back(ifstream & infile)
{
	Record* record = new Record();
	record->SetRecord(infile);

	if (head == NULL) {
		head = record;
		tile = record;
	}
	else {
		tile->next = record;
		tile = record;
	}
}
