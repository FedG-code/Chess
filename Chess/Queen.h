#pragma once
#include "Piece.h"

using namespace std;
class Queen : public Piece
{
public:

	vector<string> PossibleMoves(bool hasmoved, string finalpos) override;
};