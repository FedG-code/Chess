#pragma once
#include "Piece.h"

using namespace std;
class King : public Piece
{
public:
	//needs a bool isAttacked
	vector<string> PossibleMoves(bool hasmoved, string finalpos);
	bool PossibleMoves(vector<string>& possiblemoves, bool hasmoved, string finalpos) override;
	//bool CheckMoveAllowed(string endpos) override;
};