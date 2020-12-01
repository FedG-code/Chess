#pragma once
#include "Piece.h"

using namespace std;
class Rook : public Piece
{
public:

	vector<string> PossibleMoves(bool hasmoved, string finalpos) override;
};