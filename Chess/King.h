#pragma once
#include "Piece.h"

using namespace std;
class King : public Piece
{
public:
	//needs a bool isAttacked
	vector<string> PossibleMoves(string finalpos);
	bool CheckMoveAllowed(string endpos) override;
};