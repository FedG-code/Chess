#pragma once
#include "Piece.h"

using namespace std;
class  Pawn : public Piece
{
	bool enPassant;
public:
	vector<string> PossibleMoves(bool hasmoved, string finalpos) override;
	bool PossibleMoves(vector<string>& possiblemoves, bool hasmoved, string finalpos) override;
	//bool CheckMoveAllowed(string endpos) override;
};