#pragma once
#include "Piece.h"

using namespace std;
class  Pawn : public Piece
{
	bool enPassant;
public:
	vector<string> PossibleMoves(bool hasmoved, string finalpos) override;
};