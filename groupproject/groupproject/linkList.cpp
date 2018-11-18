#include "LinkList.h"
#include "binary.h"
#include <ctime>
using namespace std;

LinkList::LinkList()
{
	Record* emptyNode = new Record();
	head = emptyNode;
	cList_h = NULL;
	tile = NULL;
}


LinkList::~LinkList()
{

}

void LinkList::insert2heap(ifstream & infile)
{
	Record* record = new Record();
	record->setRecord(infile);

	if (cList_h == NULL) {
		cList_h = record;
		tile = record;
	}
	else if (cList_h->tconst > record->tconst) {
		record->next = cList_h;
		cList_h = record;
	}
	else if (tile->tconst > record->tconst) {
		Record* currNode = head;
		Record* posNode = head->next;
		for (; !(currNode->tconst < record->tconst && posNode->tconst > record->tconst); posNode = posNode->next) {
			currNode = currNode->next;
		}
		currNode->next = record;
		record->next = posNode;
	}

	if (record->tconst == 1) { // if record->tconst == 1, then it should definitly be the head of heap tree
		Record* hptr = head; // hptr point to the head, which is pointing to a dynamically allocated varible;

		record->left = hptr->left;
		record->right = hptr->right;

		head = record;
		delete hptr; // delete hptr to release memory from the old head
	}
	else {
		Record* currNode = head;
		bool dir;
		StackArr path(record->tconst); // stack of 0 and 1 to inducate what position the node will fall into
		int numstepremaind = log(record->tconst) / log(2);
		while (--numstepremaind > 0) { // loop throught the tree until it is one step away from the destination 
			dir = path.pop(); // false mean left, true mean right
			if (dir) {
				if (currNode->right) { // check if there is a node when go deeper
					currNode = currNode->right;
				}
				else { // dir lead to nullptr,
					Record* newNode = new Record(); // create a new node to
					currNode->right = newNode; // fill up the empty region of the tree
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
		
		dir = path.pop();
		if (dir) {
			if (currNode->right) { // if currNode->right is not NULL, then there is a overlap od node, the old one should be replaced and deleted
				Record* rptr = currNode->right; // rptr point to the currNode->right, which is dynamically allocated
				
				record->left = rptr->left;
				record->right = rptr->right;
				
				currNode->right = record;
				delete rptr; // delete rptr to release memory from the overlaped old node
			}
			else { // the direaction pointing to null,
				currNode->right = record; //  and every dataset is in ascending order,
				tile->next = record; // so record->tconst must be biggest of all, 
				tile = record; // so record is the last node in the list
			}
		}
		else {
			if (currNode->left) {
				Record* lptr = currNode->left;
				
				record->left = lptr->left;
				record->right = lptr->right;
				
				currNode->left = record;
				delete lptr;
			}
			else {
				currNode->left = record;
				tile->next = record;
				tile = record;
			}
		}
	}
}

void LinkList::reset(Record * Node)
{
	Record* temp = Node;
	temp->tconst = -1;
	temp->primaryTitle = "";
	temp->titleType = "";
	temp->startYear = -1;
	temp->runtimeMinutes = -1;
	temp->genres[0] = "";
	temp->genres[1] = "";
	temp->genres[2] = "";
}

/*
 c = 1, search; c = 2, delete
 n repersent attribute tconst = 1, startYear = 2, runtimeMinutes = 3
*/
void LinkList::searchANDdelsomeYearMinute(int first, int last, int c, int n) 
{
	clock_t start = clock();

	Record* currNode = cList_h;
	int i = 0;
	while (currNode)
	{
		if (c == 1) { // search by range
			if (currNode->tconst >= first && currNode->tconst <= last && n == 1) { // search tconst by range
				cout << "Searched:\t";
				currNode->printRecord();
				i++;
			}
			else if (currNode->startYear >= first && currNode->startYear <= last && n == 2) {  // search start year by range
				cout << "Searched:\t";
				currNode->printRecord();
				i++;
			}
			else if (currNode->runtimeMinutes >= first && currNode->runtimeMinutes <= last && n == 3) { // search run time minutes range
				cout << "Searched:\t";
				currNode->printRecord();
				i++;
			}
		}
		else if (c == 2)
		{
			if (currNode->tconst >= first && currNode->tconst <= last && n == 1) {
				//cout << "Deleted:\t";
				reset(currNode);
				i++;
			}
			else if (currNode->startYear >= first && currNode->startYear <= last && n == 2) {
				//cout << "Deleted:\t";
				reset(currNode);
				i++;
			}
			else if (currNode->runtimeMinutes >= first && currNode->runtimeMinutes <= last && n == 3) {
				//cout << "Deleted:\t";
				reset(currNode);
				i++;
			}
		}
		currNode = currNode->next;
	}
	if (i == 0) 
		cout << "NO record." << endl << endl;
	else 
		cout << "There have " << i << " record." << endl << endl;

	cout << "It only takes "<< (clock() - start) / (double)CLOCKS_PER_SEC << "s." << endl;
}

/*
type: attribute
intdata: tconst / startYear / runtimeMinutes
stringdata: excludsive of above
c: search / delete
*/
void LinkList::searchANDdel(string type, int intdata, string stringdata, int c)
{
	clock_t start = clock();

	Record* currNode = cList_h;
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
	{
		Record * r = search_tconst(intdata);
		if (c == 1) {
			if (r)
				cout << "NO record." << endl << endl;
			else {
				cout << "There have 1 record." << endl;
				r->printRecord();
			}
		}
		else if (c == 2) {
			if(r)
				reset(r);
		}
	}

	break;

	case 2:		//titleType
		while (currNode)
		{
			if (currNode->titleType == stringdata) {
				if (c == 1) {
					cout << "Searched:\t";
					currNode->printRecord();
					i++;
				}
				else if (c == 2)
				{
					reset(currNode);
					i++;
				}	
			}
			currNode = currNode->next;
		}
		if (i == 0)
			cout << "NO record." << endl << endl;
		else
			cout << "There have " << i << " record." << endl << endl;
		break;
	case 3:		//primaryTitle
		while (currNode)
		{
			if (currNode->primaryTitle == stringdata) {
				if (c == 1) {
					cout << "Searched:\t";
					currNode->printRecord();
					i++;
					break;
				}
				else if (c == 2)
				{
					reset(currNode);
					i++;
					break;
				}
			}
			else
				currNode = currNode->next;
		}
		if (i == 0)
			cout << "NO record." << endl << endl;
		else
			cout << "There have " << i << " record." << endl << endl;
		break;
	case 4:		//startYear
		while (currNode)
		{
			if (currNode->startYear == intdata) {
				if (c == 1) {
					cout << "Searched:\t";
					currNode->printRecord();
					i++;
				}
				else if (c == 2)
				{
					reset(currNode);
					i++;
				}
			}
			else
				currNode = currNode->next;
		}
		if (i == 0)
			cout << "NO record." << endl << endl;
		else
			cout << "There have " << i << " record." << endl << endl;
		break;
	case 5:		//genres
		while (currNode)
		{
			if (currNode->genres[0] == stringdata || currNode->genres[1] == stringdata || currNode->genres[2] == stringdata) {
				if (c == 1) {
					cout << "Searched:\t";
					currNode->printRecord();
					i++;
				}
				else if (c == 2)
				{
					reset(currNode);
					i++;
				}
			}
			else
				currNode = currNode->next;
		}
		if (i == 0)
			cout << "NO record." << endl << endl;
		else
			cout << "There have " << i << " record." << endl << endl;
		break;
	case 6:		//runtimeMinutes
		while (currNode)
		{
			if (currNode->runtimeMinutes == intdata) {
				if (c == 1) {
					cout << "Searched:\t";
					currNode->printRecord();
					i++;
				}
				else if (c == 2)
				{
					reset(currNode);
					i++;
				}
			}
			else
				currNode = currNode->next;
		}
		if (i == 0)
			cout << "NO record." << endl << endl;
		else
			cout << "There have " << i << " record." << endl << endl;
		break;
	}
	
	cout << (clock() - start) / CLOCKS_PER_SEC << "s" << endl;
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
