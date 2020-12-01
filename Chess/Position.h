#pragma once
#include "NotationManipulation.h"
using namespace std;

/***********************************
*   A B C D E F G H 
*  8				8
*  7				7
*  6				6
*  5				5
*  4				4
*  3				3
*  2				2
*  1w				1
*   A B C D E F G H 
* 
* **********************************/

enum Direction
{
	Up = 0,
	Down,
	Left,
	Right
};

class Position
{
	int m_Xpos;
	int m_Ypos;
	string m_Notation;
	string isUpOrDown(string finalpos);
	bool isUpRight(string finalpos);
	bool isDownRight(string finalpos);
	bool isDownLeft(string finalpos);
	string isLeftOrRight(string finalpos);
	bool isUpLeft(string finalpos);
	void SetJustNotation(string notation);

public:
	
	//int TranslateXFromNotation(char letter);
	//char TranslateXToNotation(int number);
	//int TranslateYFromNotation(int notationY);
	//int TranslateYToNotation(int y);
	void SetPosition(string coordinates);
	string GetCoordinatesNotation();
	string CompareNotation(string finalpos);

	int GetX();
	int GetY();
	bool Bump(Direction dir);
	bool BumpYUp();
	bool BumpXUp();
	bool BumpYDown();
	bool BumpXDown();
};
