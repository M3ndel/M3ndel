#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Record {
private:
	string tconst;
	string titleType;
	string primaryTitle = "";
	int startYear = -1;
	int runtimeMintes = -1;
	string genres[3] = { "", "", ""};

public:
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

