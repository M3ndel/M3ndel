#include "LinkList.h"
#include "binary.h"
using namespace std;

LinkList::LinkList()
{
	head = NULL;
	tile = NULL;
}


LinkList::~LinkList()
{

}

void LinkList::insert2heap(ifstream & infile)
{
	Record* record = new Record();
	record->setRecord(infile);

	StackArr path(record->tconst);

	if (head == NULL) {
		head = record;
	}
	else {
		int step = log(record->tconst) / log(2);
		Record* currNode = head;
		bool dir;
		for (dir = path.pop(); --step <= 1 && !path.isEmpty(); dir = path.pop()) {
			if (dir) {
				if (currNode->right) {
					currNode = currNode->right;
				}
				else
				{
					Record* newNode = new Record();
					currNode->right = newNode;
					currNode = currNode->right;
				}
			}
			else {
				if (currNode->left) {
					currNode = currNode->left;
				}
				else {
					Record* newNode = new Record();
					currNode->left = newNode;
					currNode = currNode->left;
				}
			}
		}
		if (dir) {
			if (currNode->right) {
				currNode = currNode->right;
				currNode->replace(record);
			}
			else
			{
				currNode->right = record;
			}
		}
		else {
			if (currNode->left) {
				currNode = currNode->left;
				currNode->replace(record);
			}
			else {
				currNode->left = record;
			}
		}
	}
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

Record * LinkList::search_tconst(long num)
{
	StackArr sa(num);
	Record* currNode = head;
	for (bool dir = sa.pop(); !sa.isEmpty(); dir = sa.pop()) {
		if (dir) {
			currNode = currNode->right;
		}
		else {
			currNode = currNode->left;
		}
	}
	if (currNode->tconst == -1) {
		cout << "Cannot Found this record." << endl;
		return nullptr;
	}
	else
	{
		return currNode;
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

	temp = a->right;
	a->right = b->right;
	b->right = temp;
}
