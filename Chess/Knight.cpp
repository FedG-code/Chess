#include "Knight.h"

vector<string> Knight::PossibleMoves(string finalpos)
{
	vector<string> moves;
	string startpos = pos.GetCoordinatesNotation();

	//top right, right side
	
	bool bool1 = pos.Bump(Up);
	bool bool2 = pos.Bump(Right);
	bool bool3 = pos.Bump(Right);
	if (bool1 && bool2 && bool3)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//top right, left side
	
	bool bool4 = pos.Bump(Up);
	bool bool5 = pos.Bump(Up);
	bool bool6 = pos.Bump(Right);
	if (bool4 && bool5 && bool6)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//top left, right side

	bool bool7 = pos.Bump(Up);
	bool bool8 = pos.Bump(Up);
	bool bool9 = pos.Bump(Left);
	if (bool7 && bool8 && bool9)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//top left, left side

	bool bool10 = pos.Bump(Up);
	bool bool11 = pos.Bump(Left);
	bool bool12 = pos.Bump(Left);
	if (bool10 && bool11 && bool12)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//bottom left, left side

	bool bool13 = pos.Bump(Down);
	bool bool14 = pos.Bump(Left);
	bool bool15 = pos.Bump(Left);
	if (bool13 && bool14 && bool15)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//bottom left, right side

	bool bool16 = pos.Bump(Down);
	bool bool17 = pos.Bump(Down);
	bool bool18 = pos.Bump(Left);
	if (bool16 && bool17 && bool18)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//bottom right, left side

	bool bool19 = pos.Bump(Down);
	bool bool20 = pos.Bump(Down);
	bool bool21 = pos.Bump(Right);
	if (bool19 && bool20 && bool21)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//bottom right, right side

	bool bool22 = pos.Bump(Down);
	bool bool23 = pos.Bump(Right);
	bool bool24 = pos.Bump(Right);
	if (bool22 && bool23 && bool24)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	return moves;
}

bool Knight::CheckMoveAllowed(string endpos)
{
	vector<string> moves = PossibleMoves(endpos);

	for (int i = 0; i < moves.size(); i++)
	{
		if (moves[i] == endpos)
		{
			return true;
		}
	}

	return false;
}