#include "LinkList.h"
#include "binary.h"
#include <stack>
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

void LinkList::reset(Record * Node)
{
	Record* temp = Node;
	Node->printRecord();
	temp->tconst = -1;
	temp->primaryTitle = "";
	temp->titleType = "";
	temp->startYear = -1;
	temp->runtimeMinutes = -1;
	temp->genres[0] = "";
	temp->genres[1] = "";
	temp->genres[2] = "";
}

void LinkList::searchANDdelsomeYearMinute(int first, int last, int c, int n)
{
	stack<Record*> tree;		//it is stack
	tree.push(head);
	int i = 0;
	while (tree.size() > 0)
	{
		Record* temp = tree.top();
		if (c == 1) {
			if (temp->tconst >= first && temp->tconst <= last && n == 1) {
				cout << "Searched:\t";
				temp->printRecord();
				i++;
			}
			else if (temp->startYear >= first && temp->startYear <= last && n == 2) {
				cout << "Searched:\t";
				temp->printRecord();
				i++;
			}
			else if (temp->runtimeMinutes >= first && temp->runtimeMinutes <= last && n == 3) {
				cout << "Searched:\t";
				temp->printRecord();
				i++;
			}
		}
		else if (c == 2)
		{
			if (temp->tconst >= first && temp->tconst <= last && n == 1) {
				cout << "Deleted:\t";
				reset(temp);
				i++;
			}
			else if (temp->startYear >= first && temp->startYear <= last && n == 2) {
				cout << "Deleted:\t";
				reset(temp);
				i++;
			}
			else if (temp->runtimeMinutes >= first && temp->runtimeMinutes <= last && n == 3) {
				cout << "Deleted:\t";
				reset(temp);
				i++;
			}
		}
		tree.pop();
		if (temp->right != NULL)
			tree.push(temp->right);
		if (temp->left != NULL)
			tree.push(temp->left);
	}
	if (i == 0) 
		cout << "NO record." << endl << endl;
	else 
		cout << "There have " << i << " record." << endl << endl;
}

void LinkList::searchANDdel(string type, int intdata, string stringdata, int c)
{
	stack<Record*> tree;		//it is stack
	tree.push(head);
	int n;
	int i = 0;
	if (type == "tconst") n = 1;
	else if (type == "titleType") n = 2;
	else if (type == "primaryTitle") n = 3;
	else if (type == "startYear") n = 4;
	else if (type == "genres") n = 5;
	else if (type == "runtime") n = 6;

	switch (n)		//n--> 1:tconst 2:titleType 3:0 4:startYear 5:genres 6:runtimeMinutes
	{
	case 1:		//tconst
		i = 0;
		while (tree.size() > 0)
		{
			Record* temp = tree.top();
			if (temp->tconst == intdata) {
				if (c == 1) {
					cout << "Searched:\t";
					temp->printRecord();
					i++;
					break;
				}
				else if (c == 2)
				{
					cout << "Deleted:\t";
					reset(temp);
					break;
				}
			}
			else
			{
				tree.pop();
				if (temp->right != NULL)
					tree.push(temp->right);
				if (temp->left != NULL)
					tree.push(temp->left);
			}
		}
		if (i == 0) cout << "NO record." << endl << endl;
		else cout << "There have " << i << " record." << endl << endl;
		break;
	case 2:		//titleType
		i = 0;
		while (tree.size() > 0)
		{
			Record* temp = tree.top();
			if (temp->titleType == stringdata) {
				if (c == 1) {
					cout << "Searched:\t";
					temp->printRecord();
					i++;
				}
				else if (c == 2)
				{
					cout << "Deleted:\t";
					reset(temp);
					i++;
				}
			}
			tree.pop();
			if (temp->right != NULL)
				tree.push(temp->right);
			if (temp->left != NULL)
				tree.push(temp->left);
		}
		if (i == 0) cout << "NO record." << endl << endl;
		else cout << "There have " << i << " record." << endl << endl;
		break;
	case 3:		//primaryTitle
		i = 0;
		while (tree.size() > 0)
		{
			Record* temp = tree.top();
			if (temp->primaryTitle == stringdata) {
				if (c == 1) {
					cout << "Searched:\t";
					temp->printRecord();
					i++;
					break;
				}
				else if (c == 2)
				{
					cout << "Deleted:\t";
					reset(temp);
					i++;
					break;
				}
			}
			else
			{
				tree.pop();
				if (temp->right != NULL)
					tree.push(temp->right);
				if (temp->left != NULL)
					tree.push(temp->left);
			}
		}
		if (i == 0) cout << "NO record." << endl << endl;
		else cout << "There have " << i << " record." << endl << endl;
		break;
	case 4:		//startYear
		i = 0;
		while (tree.size() > 0)
		{
			Record* temp = tree.top();
			if (temp->startYear == intdata) {
				if (c == 1) {
					cout << "Searched:\t";
					temp->printRecord();
					i++;
				}
				else if (c == 2)
				{
					cout << "Deleted:\t";
					reset(temp);
					i++;
				}
			}
			tree.pop();
			if (temp->right != NULL)
				tree.push(temp->right);
			if (temp->left != NULL)
				tree.push(temp->left);
		}
		if (i == 0) cout << "NO record." << endl << endl;
		else cout << "There have " << i << " record." << endl << endl;
		break;
	case 5:		//genres
		i = 0;
		while (tree.size() > 0)
		{
			Record* temp = tree.top();
			if (temp->genres[0] == stringdata || temp->genres[1] == stringdata || temp->genres[2] == stringdata) {
				if (c == 1) {
					cout << "Searched:\t";
					temp->printRecord();
					i++;
				}
				else if (c == 2)
				{
					cout << "Deleted:\t";
					reset(temp);
					i++;
				}
			}
			tree.pop();
			if (temp->right != NULL)
				tree.push(temp->right);
			if (temp->left != NULL)
				tree.push(temp->left);
		}
		if (i == 0) cout << "NO record." << endl << endl;
		else cout << "There have " << i << " record." << endl << endl;
		break;
	case 6:		//runtimeMinutes
		i = 0;
		while (tree.size() > 0)
		{
			Record* temp = tree.top();
			if (temp->runtimeMinutes == intdata) {
				if (c == 1) {
					cout << "Searched:\t";
					temp->printRecord();
					i++;
				}
				else if (c == 2)
				{
					cout << "Deleted:\t";
					reset(temp);
					i++;
				}
			}
			tree.pop();
			if (temp->right != NULL)
				tree.push(temp->right);
			if (temp->left != NULL)
				tree.push(temp->left);
		}
		if (i == 0) cout << "NO record." << endl << endl;
		else cout << "There have " << i << " record." << endl << endl;
		break;
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
