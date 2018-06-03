#include"Line.h"
#include <cstring>
#include<exception>
Line::Line()
{
	letters = new char;
	letters[0] = '\0';
	modified = nullptr;
	words = nullptr;
	countWords = 0;
	countLetters = 0;
	headed = 0;
}
Line::~Line()
{
		delete[] letters;
		delete[] modified;
		delete[] words;
}
Line::Line(const Line & other)
{
	letters = new char[other.countLetters];
	modified = new int[other.countWords];
	words = new Word[other.countWords];
	countLetters = other.countLetters;
	countWords = other.countWords;
	headed = other.headed;
	for (int i = 0; i < countLetters; i++)
	{
		letters[i] = other.letters[i];
	}
	letters[countLetters] = '\0';
	for (int i = 0; i < countWords; i++)
	{
		words[i] = other.words[i];
		modified[i] = other.modified[i];
	}
}
Line& Line::operator=(const Line& other)
{
	if (this != &other)
	{
		delete[] letters;
		delete[] modified;
		delete[] words;
		letters = new char[other.countLetters+1];
		modified = new int[other.countWords];
		words = new Word[other.countWords];
		countLetters = other.countLetters;
		countWords = other.countWords;
		headed = other.headed;
		for (int i = 0; i < countLetters; i++)
		{
			letters[i] = other.letters[i];
		}
		letters[countLetters] = '\0';
		for (int i = 0; i < countWords; i++)
		{
			words[i] = other.words[i];
			modified[i] = other.modified[i];
		}
	}
	return *this;
}
Line& Line::operator=(const char* str)
{
	if (strcmp(str, letters))
	{
		delete[] letters;
		delete[] words;
		words = nullptr;
		delete[] modified;
		countLetters = strlen(str);
		letters = new char[countLetters+1];
		for (int i = 0; i < countLetters; i++)
		{
			letters[i] = str[i];
		}
		letters[countLetters] = '\0';

		//here should be broken into words
		for (int i = 0; i <= countLetters; i++)
		{
			if (letters[i] == ' ' || letters[i] == '\0')
				countWords++;
		}

		if (words == nullptr)
		words = new Word[countWords];
		modified = new int[countWords];
		for (int i = 0; i < countWords; i++)
			modified[i] = 0;
		words[0].setLeft(0);
		int wordsIterator = 0;
		for (int i = 0; i <= countLetters; i++)
		{
			if (letters[i] == ' ')
			{
				words[wordsIterator].setRight(i - 1);
				words[wordsIterator + 1].setLeft(i + 1);
				wordsIterator++;
			}
			if (letters[i] == '\0')
			{
				words[wordsIterator].setRight(i - 1);
			}
			
		}

	}
	return *this;
}
void Line::makeHeading()
{//problems
	if (headed >= 6)return;
	char * helpLine = new char[countLetters+1];
	for (int i = 0; i < countLetters; i++)
		helpLine[i] = letters[i];
	helpLine[countLetters] = 0;
	delete[] letters;
	if (headed == 0)
	{
		letters = new char[countLetters + 3];
		letters[0] = '#';
		letters[1] = ' ';
		for (int i = 0; i < countLetters; i++)
			letters[i + 2] = helpLine[i];

		letters[countLetters + 2] = 0;
		moveWordsBy(0, 2);
		countLetters+=2;
	}
	else{
		letters = new char[countLetters + 2];
		letters[0] = '#';
		for (int i = 0; i < countLetters; i++)
			letters[i + 1] = helpLine[i];

		letters[countLetters + 1] = 0;
		moveWordsBy(0, 1);
		countLetters++;
	}
	headed++;
	delete[] helpLine;
}
bool Line::makeBold(unsigned w1, unsigned w2)
{
	if (w1 >= countWords || w2 >= countWords)
		return false;
	bool flag = false;
		for (int i = w1; i <= w2; i++)
		{
			if (i != 0 && modified[i - 1] == 2)
			{
				addStarAfter(i - 1);
				addStarBefore(i);
				addStarBefore(i);
				addStarBefore(i);
				modified[i] = 3;
				flag = true;
				
			}
			else
			if (modified[i] == 2 || modified[i]==0)
			{
				if (!flag)
				{
					addStarBefore(i);
					addStarBefore(i);
				}


				while ((modified[i] == 0 || modified[i] == 2) && i <= w2)
				{
					if (modified[i] == 2)
						modified[i] = 3;
					else modified[i] = 1;
					i++;
				}
				addStarAfter(i - 1);
				addStarAfter(i - 1);

			}
		}
		return true;
}
bool Line::makeItalic(unsigned w1, unsigned w2)
{
	if (w1 >= countWords || w2 >= countWords)
		return false;
	bool flag = false;
	for (int i = w1; i <= w2; i++)
	{
		if (i != 0 && modified[i - 1] == 1)
		{
			addStarAfter(i - 1);
			addStarAfter(i - 1);
			addStarBefore(i);
			addStarBefore(i);
			addStarBefore(i);
			modified[i] = 3;

			flag = true;
		}else
		if (modified[i] == 1 || modified[i] == 0)
		{
			if (!flag)
			addStarBefore(i);

			while ((modified[i] == 0 || modified[i] == 1) && i <= w2)
			{
				if (modified[i] == 1)
					modified[i] = 3;
				else modified[i] = 2;
				i++;
			}
			addStarAfter(i - 1);
		}
		
	}
	return true;
}
bool Line::makeCombine(unsigned w1, unsigned w2)
{
	
	return true;
}
void Line::addStarAfter(unsigned wordIndex)
{
	Word word(words[wordIndex]);
	char * helpLine = new char[countLetters + 1];
	for (int i = 0; i < countLetters; i++)
		helpLine[i] = letters[i];
	helpLine[countLetters] = 0;
	delete[] letters;
	letters = new char[countLetters + 2];
	for (int i = 0; i <= word.getRight(); i++)
		letters[i] = helpLine[i];
	letters[word.getRight() + 1] = '*';
	for (int i = word.getRight()+2; i <= countLetters; i++)
		letters[i] = helpLine[i-1];
	letters[countLetters + 1] = 0;
	moveWordsBy(wordIndex+1, 1);
	countLetters++;

	delete[] helpLine;

}
void Line::addStarBefore(unsigned wordIndex)
{
	Word word(words[wordIndex]);
	char * helpLine = new char[countLetters + 1];
	for (int i = 0; i < countLetters; i++)
		helpLine[i] = letters[i];
	helpLine[countLetters] = 0;
	delete[] letters;
	letters = new char[countLetters + 2];
	for (int i = 0; i < word.getLeft(); i++)
		letters[i] = helpLine[i];
	letters[word.getLeft()] = '*';
	for (int i = word.getLeft() + 1; i <= countLetters; i++)
		letters[i] = helpLine[i - 1];
	letters[countLetters + 1] = 0;
	moveWordsBy(wordIndex, 1);
	countLetters++;

	delete[] helpLine;

}
void Line::moveWordsBy(unsigned after,unsigned h)
{
	for (int i = after; i < countWords; i++)
	{
		words[i].incrementLeft(h);
		words[i].incrementRight(h);
	}
}
unsigned Line::getLettersCnt()
{
	return countLetters;
}
void Line::writeMd(std::ostream & ofs)
{
	ofs << letters;
	ofs << "<br />";
}