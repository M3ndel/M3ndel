#include "Record.h"

void Record::setTconst(istream & infile)
{
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
		infile >> startYear;
}

void Record::setRunTimeMintes(istream & infile)
{
	char character;
	infile.ignore(); // to ignore the tab spacing
	infile.get(character);
	
	if (character == 92) { // 92 in ascii is "\", to check if the year is available
		runtimeMintes = -1;
		infile.ignore(); // to ignore the character "N"
	}
	else {
		infile.unget(); // to go back to the starting position of year
		infile >> runtimeMintes;
	}
}

void Record::setGenres(istream & infile)
{
	string str;
	infile >> str;
	if (str[0] != 34) {
		genres[0] = str;
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
	}
}

void Record::setRecord(istream& infile)
{
	setTconst(infile);
	setTitleType(infile);
	setPrimaryTitle(infile);
	setStartYear(infile);
	setRunTimeMintes(infile);
	setGenres(infile);
}

void Record::printRecord()
{
	cout << tconst << "\t" << titleType << "\t" << primaryTitle 
		<< "\t" << startYear << "\t" << runtimeMintes << "\t";

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
