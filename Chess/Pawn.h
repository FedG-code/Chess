#pragma once
#include "Piece.h"

using namespace std;
class  Pawn : public Piece
{
	bool m_enPassant{false};
	bool m_blocked1{false};
	bool m_blocked2{false};
	bool m_canEatLaterally{false};
public:
	
	Pawn();

	vector<string> PossibleMoves(string finalpos) override;
	bool CheckMoveAllowed(string endpos) override;

	void SetBlocked1(bool set);
	void SetBlocked2(bool set);
	void SetCanEatLaterally(bool set);
};