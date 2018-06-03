#ifndef LINE_HEADER
#define LINE_HEADER
#include "Word.h"
#include <iostream>
class Line{
public:
	Line();
	Line(const char * line);//line takes line and breaks it into words (fill right and left end for each word)//hint could read to zero
	~Line();
	Line(const Line & other);
	Line & operator=(const char* str);
	Line & operator=(const Line & other);
	//
	unsigned getLettersCnt();
	void makeHeading();
	bool makeItalic(unsigned, unsigned);//returns false if indexes are not valid
	bool makeBold(unsigned, unsigned); //returns false if indexes are not valid
	bool makeCombine(unsigned, unsigned); //returns false if indexes are not valid
	void writeMd(std::ostream &);
private:
	//
	void breakIntoWords(const char *);
	void moveWordsBy(unsigned ,unsigned);//move words after @param with @param positions
	void addStarBefore(unsigned);//@param word index
	void addStarAfter(unsigned);//@param word index
	
	char * letters;
	int * modified;// indexes of already modified words 0-none 1-bold 2-italic 3- bold and italic
	Word * words;
	unsigned countWords;
	unsigned countLetters;
	int headed;

};





#endif