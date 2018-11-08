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

	if (head == NULL || head->tconst == -1) {
		head = record;
		tile = record;
	}
	else {
		tile->next = record;
		tile = record;

		Record* currNode = head;
		bool dir;
		StackArr path(record->tconst);
		int numstepremaind = log(record->tconst) / log(2);
		while (--numstepremaind > 0) { // loop throught the tree until it is one step away from the destination 
			dir = path.pop(); // false mean left, true mean right
			if (dir) {
				if (currNode->right) { // check is there a node when go deeper
					currNode = currNode->right;
				}
				else {
					// cout << "insert fill up node " << currNode->tconst << endl;
					// system("pause");
					Record* newNode = new Record(); // create a new node to
					currNode->right = newNode; // fill up the empty region of the tree
					newNode->parent = currNode;
					currNode = currNode->right;
				}
			}
			else {
				if (currNode->left) {
					currNode = currNode->left;
				}
				else {
					// cout << "insert fill up node" << currNode->tconst << endl;
					// system("pause");
					Record* newNode = new Record();
					currNode->left = newNode;
					newNode->parent = currNode;
					currNode = currNode->left;
				}
			}
		}
		dir = path.pop();
		if (dir) {
			if (currNode->right) { 
				Record* rptr = currNode->right;
				
				record->parent = rptr->parent;
				record->left = rptr->left;
				record->right = rptr->right;
				
				currNode->right = record;
				delete rptr;
			}
			else {
				currNode->right = record;
				record->parent = currNode;
			}
		}
		else {
			if (currNode->left) {
				Record* lptr = currNode->left;
				
				record->parent = lptr->parent;
				record->left = lptr->left;
				record->right = lptr->right;
				
				currNode->left = record;
				delete lptr;
			}
			else {
				currNode->left = record;
				record->parent = currNode;
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
	bool dir;
	while (!sa.isEmpty()) {
		dir = sa.pop();
		if (dir)
			currNode = currNode->right;
		else
			currNode = currNode->left;
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
