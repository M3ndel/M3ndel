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
	record->setRecord(infile);

	if (head == NULL) {
		head = record;
		tile = record;
	}
	else {
		tile->next = record;
		tile = record;
	}
}

Record * LinkList::bottom_Left(Record * node)
{
	if (node->left == NULL)
		return node;
	else {
		node = node->left;
		return bottom_Left(node);
	}
}

void LinkList::swapNodePosition(Record * a, Record * b) // for heap tree rebalance
{
	if (a == head) {
		head = b;
	}
	else if (b == head) {
		head = a;
	}


	Record* temp;
	int tdepth;
	tdepth = a->depth;
	a->depth = b->depth;
	b->depth = tdepth;

	temp = a->parent;
	a->parent = b->parent;
	b->parent = temp;

	temp = a->left;
	a->left = b->left;
	b->left = temp;

	temp = a->rigth;
	a->rigth = b->rigth;
	b->rigth = temp;
}
