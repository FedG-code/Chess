#include "King.h"

vector<string> King::PossibleMoves(bool hasmoved, string finalpos)
{
	vector<string> moves;
	string startpos = pos.GetCoordinatesNotation();
	//Up
	pos.Bump(Up);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);
	
	//Up right
	pos.Bump(Up);
	pos.Bump(Right);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);

	//Right
	pos.Bump(Right);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);
	
	//Bottom right
	pos.Bump(Down);
	pos.Bump(Right);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);

	//Down
	pos.Bump(Down);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);

	//Down left
	pos.Bump(Down);
	pos.Bump(Left);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);

	//Left
	pos.Bump(Left);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);

	//Up left
	pos.Bump(Up);
	pos.Bump(Left);
	moves.push_back(pos.GetCoordinatesNotation());
	pos.SetPosition(startpos);

	return moves;
}

bool King::PossibleMoves(vector<string>& possiblemoves, bool hasmoved, string finalpos)
{
	return false;
}