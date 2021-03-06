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
	virtual vector<string> PossibleMoves(string finalpos) = 0;
	//virtual bool PossibleMoves(vector<string> &possiblemoves, bool hasmoved, string finalpos) = 0;
	virtual bool CheckMoveAllowed(string endpos) = 0;

	string GetIdentity();
	void SetIdentity(string name);
	
	bool GetHasMoved();
	void HasIndeedMoved();

	void DrawPiece();



	bool GetIsAlive();
	void SetEaten();
};