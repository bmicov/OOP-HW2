#include"Editor.h"
#include<fstream>
#include<iostream>
Editor::Editor()
{
	lines = nullptr;
	count = 0;
}
Editor::~Editor()
{
	delete[] lines;
}

Editor::Editor(const Editor & other)
{
	lines = new Line[other.count];
	count = other.count;
	for (int i = 0; i < count; i++)
	{
		lines[i] = other.lines[i];
	}
}
Editor& Editor::operator=(const Editor& other)
{
	
	if (this != &other)
	{
		delete[] lines;
		lines = new Line[other.count];
		count = other.count;
		for (int i = 0; i < count; i++)
		{
			lines[i] = other.lines[i];
		}
	}
	return *this;
}
Editor::Editor(const char* fileName)
{
	std::ifstream ifs(fileName);
	char buffer[1025];
	int linesCnt = 0;
	while (ifs)
	{
		ifs.getline(buffer, 1025);
		if (strcmp(buffer, ""))
		linesCnt++;
	}
	lines = new Line[linesCnt];
	count = linesCnt;
	ifs.close();
	std::ifstream ifs1(fileName);

	//ifs.seekg(0, std::ios::beg);
	linesCnt = 0;
	//ifs1.clear();
	while (ifs1)
	{
		ifs1.getline(buffer, 1025);
		if (strcmp(buffer, ""))
		{
			lines[linesCnt] = buffer;
			linesCnt++;
		}
	}
	ifs1.close();
}
bool Editor::makeHeading(unsigned line)
{
	if (line >= count) return false;
	 lines[line].makeHeading();
	 return true;
}
bool Editor::makeBold(unsigned line, unsigned w1, unsigned w2)
{
	if (line >= count)return false;
	return lines[line].makeBold(w1, w2);
	
}
bool Editor::makeItalic(unsigned line, unsigned w1, unsigned w2)
{
	if (line >= count) return false;
	return lines[line].makeItalic(w1, w2);
}
bool Editor::makeCombine(unsigned line, unsigned w1, unsigned w2)
{
	if (line >= count) return false;
	bool correct=makeBold(line, w1, w2);
	makeItalic(line, w1, w2);
	return correct;
}
bool Editor::addLine(const char * str)
{
	if (!str) return false;
	Line * help = lines;
	count++;
	lines = new Line[count];
	//Line * help = new Line[count+1];
	for (int i = 0; i < count-1; i++)
		lines[i] = help[i];
	
	

	lines[count-1] = str;
	delete[] help;
	return true;
}
bool Editor::removeLine(unsigned k)
{//problem
	if (k >= count) return false;
	Line * help = lines;
	lines = new Line[count - 1];
	for (int i = 0; i < k; i++)
	{
		lines[i] = help[i];
	}
	for (int i = k + 1; i < count; i++)
	{
		lines[i - 1] = help[i];
	}
	
	--count;
	delete[] help;
	return true;
}
void Editor::writeToFile(const char * fileName)
{
	std::ofstream ofs(fileName, std::ios::out | std::ios::trunc);
	for (int i = 0; i < count; i++)
	{
		lines[i].writeMd(ofs);
		ofs << std::endl;
	}
	ofs.close();
}