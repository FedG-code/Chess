#pragma once
#include "Piece.h"

using namespace std;
class Knight : public Piece
{
public:

	vector<string> PossibleMoves(string finalpos) override;
	bool CheckMoveAllowed(string endpos) override;
};