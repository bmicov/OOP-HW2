#ifndef WORD_HEADER
#define WORD_HEADER
struct Word{
public:
	Word();
	Word(unsigned, unsigned);
	void setLeft(unsigned);
	void setRight(unsigned);

	void incrementLeft(unsigned);
	void incrementRight(unsigned);

	unsigned getLeft();
	unsigned getRight();

private:
	unsigned left;
	unsigned right;


};





#endif