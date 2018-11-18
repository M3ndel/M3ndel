#include "Record.h"

Record::Record()
{
	tconst = -1;
	primaryTitle = "";
	startYear = -1;
	runtimeMinutes = -1;
	genres[0] = "";
	genres[1] = "";
	genres[2] = "";

	next = NULL;
	left = NULL;
	right = NULL;
}

Record::~Record()
{
	delete[] genres;
	delete next;
	delete left;
	delete right;
}

// original building block of setRecord(istream&)

void Record::setTconst(istream & infile)
{
	char temp;
	infile.ignore(); // to ignore 't'
	infile.ignore(); // to ignore 't'
	
	do {
		infile.get(temp);
	} while (temp == '0');

	infile.unget();
	infile >> tconst;
}

void Record::setTitleType(istream & infile)
{
	infile >> titleType;
}

void Record::setPrimaryTitle(istream & infile)
{
	char character;
	infile.ignore(); // to ignore the tab spacing
	infile.get(character); // to get the first character
	do {
		primaryTitle += character; //to constructure the title letter by letter
		infile.get(character); // place behind += operation to pervent including the last tab spacing
	} while (character != '\t');
}

void Record::setStartYear(istream & infile)
{
		char character;
	infile.get(character);
	if (character == 92) { // 92 in ascii is "\", to check if the year is available
		startYear = -1;
		infile.ignore(); // to ignore the character "N"
	}
	else {
		infile.unget();
		infile >> startYear;
	}	
}

void Record::setRunTimeMinutes(istream & infile)
{
	char character;
	infile.ignore(); // to ignore the tab spacing
	infile.get(character);
	
	if (character == 92) { // 92 in ascii is "\", to check if the year is available
		runtimeMinutes = -1;
		infile.ignore(); // to ignore the character "N"
	}
	else {
		infile.unget(); // to go back to the starting position of year
		infile >> runtimeMinutes;
	}
}

void Record::setGenres(istream & infile)
{
	string str;
	infile >> str;
	if (str[0] != '\"' && str[0] != '\\') {
		genres[0] = str;
		infile.ignore(); // to ignore "\n" AKA line feed, return key, enter.
		return;
	}
	else if (str[0] == '\\') {
		infile.ignore(); // to ignore "\n" AKA line feed, return key, enter.
		return;
	}
	else {
		int num = 0;
		for (string::iterator it = str.begin(); it != str.end(); ++it) {
			if (*it == '\"')
				continue;
			else if (*it == ',')
				num++;
			else {
				genres[num] += *it;
			}
		}
		infile.ignore(); // to ignore "\n" AKA line feed, return key, enter.
		return;
	}
}

void Record::setRecord(istream & infile)
{
	setTconst(infile);
	setTitleType(infile);
	setPrimaryTitle(infile);
	setStartYear(infile);
	setRunTimeMinutes(infile);
	setGenres(infile);
}

void Record::printRecord()
{
	cout << tconst << "\t" << titleType << "\t" << primaryTitle
		<< "\t" << startYear << "\t" << runtimeMinutes << "\t";
	if (genres[1]._Equal("")) {
		cout << genres[0] << endl;
	}
	else
	{
		cout << "\"" << genres[0] << ", " << genres[1];
		if (!genres[2]._Equal("")) {
			cout << ", " << genres[2] << "\"" << endl;
		}
		else {
			cout << "\"" << endl;
		}
	}
}
