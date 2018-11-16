#ifndef LINKLIST_H
#define LINKLIST_H
#include "Record.h"
#include <iostream>
#include <fstream>
using namespace std;

//short = 0, movie = 1, tvMovie = 2, tvShort = 3, tvMiniSeries = 4, tvEpisode
inline int titleType2Int(string tt) {
	if (tt == "short")
		return 0;
	
	if (tt == "movie")
		return 1;

	if (tt == "tvMovie")
		return 2;

	if (tt == "tvShort")
		return 3;

	if (tt == "tvMiniSeries")
		return 4;

	if (tt == "tvEpisode")
		return 5;

	if (tt == "tvSeries")
		return 6;
}

class LinkList
{
public:

	Record* head;
	Record* tile;
	Record** firstAppearTitle = new Record*[7];
	Record** lastAppearTitle = new Record*[7];

public:
	LinkList();
	~LinkList();
	void insert2heap(ifstream&);
	void push_back(ifstream&);
	void reset(Record*);
	void searchANDdelsomeYearMinute(int first, int last, int c, int n);	//c: 1->search 2->delete n: 1->tconst 2->Year 3->Minute
	void searchANDdel(string, int, string, int); //c: 1->search 2->delete	type: tconst, titleType, primaryTitle, startYear, genres, runtimeMinutes
	Record* search_tconst(long);
};


#endif
