#pragma once
#include "Piece.h"

using namespace std;
class Bishop : public Piece
{
public:

	vector<string> PossibleMoves(bool hasmoved, string finalpos) override;
};