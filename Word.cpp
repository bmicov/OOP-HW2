#include"Word.h"

Word::Word() : left(0), right(0)
{};

Word::Word(unsigned l, unsigned r) : left(l), right(r)
{};

void Word::setLeft(unsigned l)
{
	left = l;
}
void Word::setRight(unsigned r)
{
	right = r;
}
void Word::incrementLeft(unsigned i)
{
	left += i;
}
void Word::incrementRight(unsigned i)
{
	right += i;
}
unsigned Word::getLeft()
{
	return left;
}
unsigned Word::getRight()
{
	return right;
}