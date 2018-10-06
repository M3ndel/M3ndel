#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Record {
private:
	long tconst;
	string titleType;
	string primaryTitle;
	int startYear;
	int runtimeMintes;
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

