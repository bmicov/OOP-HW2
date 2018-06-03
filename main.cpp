#include "Editor.h"
#include <iostream>
int digitCount(int a)
{
	if (a < 10) return 1;
	else return digitCount(a / 10) + 1;
}
void fileNameEdit(char* fileName)//remove .txt and add .md
{
	int strl = strlen(fileName);
	fileName[strl - 3] = 'm';
	fileName[strl - 2] = 'd';
	fileName[strl - 1] = 0;
}
//TODO: 
//write md file
//headed array
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "should enter file name as first arg";
		return 1;
	}


	char fileN[64];
	strcpy_s(fileN,64, argv[1]);
	Editor e(fileN);
	std::cout << "Lines and words start from 0!" << std::endl;
	std::cout << "If there isn't such file, it will be created" << std::endl;
	std::cout << ".md file is created after command 'exit'!" << std::endl;
	char cmd[1096];

do
{

	std::cin.getline(cmd, 256);
	if (cmd[0] == 'm'&&cmd[1] == 'a'&&cmd[2] == 'k'&&cmd[3] == 'e')
	{
		if (cmd[4] == 'H'&&cmd[5] == 'e'&&cmd[6] == 'a'&&cmd[7] == 'd'&&cmd[8] == 'i'&&cmd[9] == 'n'&&cmd[10] == 'g'&&cmd[11] == ' ')
		{
			unsigned a = atoi(cmd + 12);
			if (e.makeHeading(a) == false)std::cout << "No such line" << std::endl;
			else std::cout << "Done." << std::endl;
		}
		if (cmd[4] == 'I'&&cmd[5] == 't'&&cmd[6] == 'a'&&cmd[7] == 'l'&&cmd[8] == 'i'&&cmd[9] == 'c'&&cmd[10] == ' ')
		{
			unsigned a = atoi(cmd + 11);
			unsigned b = atoi(cmd + 11 + digitCount(a));
			unsigned c = atoi(cmd + (11 + digitCount(a) + digitCount(b) + 1));
			if (e.makeItalic(a, b, c) == false)std::cout << "No such line or word" << std::endl;
			else std::cout << "Done." << std::endl;

		}
		if (cmd[4] == 'B'&&cmd[5] == 'o'&&cmd[6] == 'l'&&cmd[7] == 'd'&&cmd[8] == ' ')
		{
			unsigned a = atoi(cmd + 9);
			unsigned b = atoi(cmd + 9 + digitCount(a));
			unsigned c = atoi(cmd + 9 + digitCount(a) + digitCount(b)+1);
			if (e.makeBold(a, b, c) == false)std::cout << "No such line or word" << std::endl;
			else std::cout << "Done." << std::endl;

		}
		if (cmd[4] == 'C'&&cmd[5] == 'o'&&cmd[6] == 'm'&&cmd[7] == 'b'&&cmd[8] == 'i'&&cmd[9] == 'n'&&cmd[10] == 'e' && cmd[11] == ' ')
		{
			unsigned a = atoi(cmd + 12);
			unsigned b = atoi(cmd + 12 + digitCount(a));
			unsigned c = atoi(cmd + 12 + digitCount(a) + digitCount(b)+1);
			if (e.makeCombine(a, b, c) == false)std::cout << "No such line or word" << std::endl;
			else std::cout << "Done." << std::endl;
		}

	}
	if (cmd[0] == 'r'&&cmd[1] == 'e'&&cmd[2] == 'm'&&cmd[3] == 'o'&&cmd[4] == 'v'&&cmd[5] == 'e'&&cmd[6] == ' ')
	{
		if (e.removeLine(atoi(cmd + 7)) == false)std::cout << "No such line" << std::endl;
		else std::cout << "Done." << std::endl;

	}
	if (cmd[0] == 'a'&&cmd[1] == 'd'&&cmd[2] == 'd'&&cmd[3] == 'L'&&cmd[4] == 'i'&&cmd[5] == 'n'&&cmd[6] == 'e'&&cmd[7] == ' ')
	{
		e.addLine(cmd + 8);
		std::cout << "Done." << std::endl;

	}
} while (strcmp(cmd, "exit"));

	fileNameEdit(fileN);
	e.writeToFile(fileN);
	return 0;

}