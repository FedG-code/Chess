#pragma once
#include <string>
#include <iostream>
using namespace std;


static int CharToInt(char character)
{
	char a = character;
	return a - '0';
}

static char IntToChar(int number)
{
	int a = number;
	return a + '0';
}

static int TranslateXFromNotation(char letter)
{
	switch (letter)
	{
		case 'a':
		case 'A':
		{
			return 0;
			break;
		}
		case 'b':
		case 'B':
		{
			return 1;
			break;
		}
		case 'c':
		case 'C':
		{
			return 2;
			break;
		}
		case 'd':
		case 'D':
		{
			return 3;
			break;
		}
		case 'e':
		case 'E':
		{
			return 4;
			break;
		}
		case 'f':
		case 'F':
		{
			return 5;
			break;
		}
		case 'g':
		case 'G':
		{
			return 6;
			break;
		}
		case 'h':
		case 'H':
		{
			return 7;
			break;
		}
		default:
		{
			//error error error
			cout << "invalid character for coordinate" << endl;
			return 1000;
			break;
		}
	}
}

static char TranslateXToNotation(int number)
{
	switch (number)
	{
		case 0:
		{
			return 'a';
			break;
		}
		case 1:
		{
			return 'b';
			break;
		}
		case 2:
		{
			return 'c';
			break;
		}
		case 3:
		{
			return 'd';
			break;
		}
		case 4:
		{
			return 'e';
			break;
		}
		case 5:
		{
			return 'f';
			break;
		}
		case 6:
		{
			return 'g';
			break;
		}
		case 7:
		{
			return 'h';
			break;
		}
		default:
		{
			//error error error
			cout << "invalid number for coordinate" << endl;
			return 'X';
			break;
		}
	}
}

static int TranslateYFromNotation(char notationY)
{

	int intY = CharToInt(notationY) - 1;

	return intY;
}

static char TranslateYToNotation(int y)
{
	int notationY = y + 1;

	return IntToChar(notationY);
}

static string MakeNotation(int x, int y)
{
	string notation;

	notation.push_back(TranslateXToNotation(x));
	notation.push_back(TranslateYToNotation(y));

	return notation;
}