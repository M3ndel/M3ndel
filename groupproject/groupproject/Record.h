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
	long getTconst(istream&);
	string getTitleType(istream&);
	string getPrimaryTitle(istream&);
	int getStartYear(istream&);
	int  getRunTimeMintes(istream&);
	string* getGenres(istream&);

	void setRecord(istream&);

	void printRecord();
};

#endif // !RECORD_H

