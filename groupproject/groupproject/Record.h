#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Record {
public:
	
	long tconst;
	string titleType; //short, movie, tvMovie, tvShort, tvMiniSeries
	string primaryTitle = "";
	int startYear = -1;
	int runtimeMinutes = -1;
	/*
	Documentary, Short, Animation, Comedy, Romance, Sport, News, Drama, Fantasy, Horror,
	Biography, Music, War, Crime, Western, Family, Adventure, History, Sci-Fi,
	Action, Mystery, \N, Thriller, Musical, Film-Noir, Game-Show, Talk-Show, Reality-TV
	*/
	string* genres = new string[3];

	int depth;
	Record* next;
	Record* parent;
	Record* left;
	Record* rigth;

public:
	Record();
	~Record();
	void setRecord(istream&);
	void printRecord();
	
private:
	// original building block of setRecord(istream&)
	void setTconst(istream&);
	void setTitleType(istream&);
	void setPrimaryTitle(istream&);
	void setStartYear(istream&);
	void setRunTimeMinutes(istream&);
	void setGenres(istream&);
};

#endif // !RECORD_H

