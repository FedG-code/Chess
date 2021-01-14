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
	//this change is to correct the board notation. To go back
	//remove abs here, TranslateYToNotation, DrawBoard, switch pawn movement based off
	//black or white and switch the start position of the black and white pieces.
	int intY = CharToInt(notationY) - 1;

	return abs(7- intY);
}

static char TranslateYToNotation(int y)
{
	int notationY = abs(7 - y) + 1;

	return IntToChar(notationY);
}

static string MakeNotation(int x, int y)
{
	string notation;

	notation.push_back(TranslateXToNotation(x));
	notation.push_back(TranslateYToNotation(y));

	return notation;
}

static bool CheckNotationValid(string notation)
{
	if (notation.size() > 2 || notation.size() < 2)
	{
		cout << "not a valid coordinate, should only have 2 characters" << endl;
		return false;
	}
	char string0 = notation[0];
	char string1 = notation[1];
	if (string0 == 'a' || string0 == 'b' || string0 == 'c' || string0 == 'd' || string0 == 'e' || string0 == 'f' || string0 == 'g' || string0 == 'h')
	{

	}
	else if (string0 == 'A' || string0 == 'B' || string0 == 'C' || string0 == 'D' || string0 == 'E' || string0 == 'F' || string0 == 'G' || string0 == 'H')
	{

	}
	else
	{
		cout << "Your first part of the coordinate is wrong" << endl;
		return false;
	}
	
	
	if (string1 == '1' || string1 == '2' || string1 == '3' || string1 == '4' || string1 == '5' || string1 == '6' || string1 == '7' || string1 == '8')
	{
		return true;
	}
	else
	{
		cout << "your second part of the coordinate is wrong" << endl;
		return false;
	}
}





static const string white_pawn = "wp";
static const string white_pawn_0 = "wp0";
static const string white_pawn_1 = "wp1";
static const string white_pawn_2 = "wp2";
static const string white_pawn_3 = "wp3";
static const string white_pawn_4 = "wp4";
static const string white_pawn_5 = "wp5";
static const string white_pawn_6 = "wp6";
static const string white_pawn_7 = "wp7";

static const string white_knight = "wk";
static const string white_knight_0 = "wk0";
static const string white_knight_1 = "wk1";

static const string white_bishop = "wb";
static const string white_bishop_0 = "wb0";
static const string white_bishop_1 = "wb1";

static const string white_rook = "wr";
static const string white_rook_0 = "wr0";
static const string white_rook_1 = "wr1";

static const string white_queen = "wQ";
static const string white_queen_0 = "wQ0";
static const string white_king = "wK";
//static const string white_king_0 = "wK0";

static const string black_pawn = "bp";
static const string black_pawn_0 = "bp0";
static const string black_pawn_1 = "bp1";
static const string black_pawn_2 = "bp2";
static const string black_pawn_3 = "bp3";
static const string black_pawn_4 = "bp4";
static const string black_pawn_5 = "bp5";
static const string black_pawn_6 = "bp6";
static const string black_pawn_7 = "bp7";

enum class EPiece{
	King,
	Rook,
	Knight,
	Knight2,
	Bishop,
	Bishop2,
	Knight,
	Bishop,
	Queen,
	Pawn,
	Count
};

static const string black_pieces = { "bk","bk0" };
for (int i = 0; i < EPiece::Count; ++i)
{

}
black_pieces[EPiece::King]
static const string black_knight = "bk";
static const string black_knight_0 = "bk0";
static const string black_knight_1 = "bk1";

static const string black_bishop = "bb";
static const string black_bishop_0 = "bb0";
static const string black_bishop_1 = "bb1";

static const string black_rook = "br";
static const string black_rook_0 = "br0";
static const string black_rook_1 = "br1";

static const string black_queen = "bQ";
static const string black_queen_0 = "bQ0";
static const string black_king = "bK";
//static const string black_king_0 = "bK0";




static const char pawn = 'p';
static const char knight = 'k';
static const char bishop = 'b';
static const char rook = 'r';
static const char queen = 'Q';
static const char king = 'K';

static const char white = 'w';
static const char black = 'b';