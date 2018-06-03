#ifndef EDITOR_HEADER
#define EDITOR_HEADER
#include "Line.h"
class Editor{
public:
	//editor takes filename and breaks text into lines
	//
	Editor();
	Editor(const char* fileName);
	~Editor();
	Editor(const Editor & other);
	Editor & operator=(const Editor & other);

	//
	bool makeHeading(unsigned); //returns false if line is not valid
	bool makeItalic(unsigned,unsigned, unsigned);//returns false if indexes are not valid or line is not valid
	bool makeBold(unsigned,unsigned, unsigned); //returns false if indexes are not valid or line is not valid
	bool makeCombine(unsigned,unsigned, unsigned); //returns false if indexes are not valid or line is not valid 
	bool addLine(const char *);
	bool removeLine(unsigned);
	void writeToFile(const char * fileName);//todo
private:
	Line * lines;
	unsigned count;//lines count
};





#endif