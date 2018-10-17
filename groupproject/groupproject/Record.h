#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Record {
public:
	
	long tconst;
	string titleType; //enum titlekind {short, movie, tvMovie, tvShort, tvMiniSeries};
	string primaryTitle = "";
	int startYear = -1;
	int runtimeMintes = -1;
	
	/*
	Documentary, Short, Animation, Comedy, Romance, Sport, News, Drama, Fantasy, Horror,
	Biography, Music, War, Crime, Western, Family, Adventure, History, Sci-Fi,
	Action, Mystery, \N, Thriller, Musical, Film-Noir, Game-Show, Talk-Show, Reality-TV
	*/
	string* genres = new string[3];

public:
	Record();
	~Record();
	void setTconst(istream&);
	void setTitleType(istream&);
	void setPrimaryTitle(istream&);
	void setStartYear(istream&);
	void setRunTimeMintes(istream&);
	void setGenres(istream&);

	void setRecord(istream&);

	void printRecord();
};

#endif // !RECORD_H

