#pragma once
#include "Position.h"
#include <vector>



class Piece
{
	string m_identity;	
	bool m_hasMoved;
	bool m_isAlive;

public:
	Position pos;
	Piece();
	virtual vector<string> PossibleMoves(bool hasmoved, string finalpos) = 0;

	string GetIdentity();
	void SetIdentity(string name);
	
	bool GetHasMoved();
	void HasIndeedMoved();

	void DrawPiece();



	bool GetIsAlive();
	void SetEaten();

	void EatPiece(Piece* piece);
};