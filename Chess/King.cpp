#include "King.h"

vector<string> King::PossibleMoves(string finalpos)
{
	bool UP;
	bool DOWN;
	bool RIGHT;
	bool LEFT;
	vector<string> moves;
	string startpos = pos.GetCoordinatesNotation();
	//Up
	UP = pos.Bump(Up);
	if (UP)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);
	
	//Up right

	UP = pos.Bump(Up);
	RIGHT = pos.Bump(Right);
	if (UP && RIGHT)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//Right
	RIGHT = pos.Bump(Right);
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);
	
	//Bottom right
	DOWN = pos.Bump(Down);
	RIGHT = pos.Bump(Right);
	if (DOWN && RIGHT)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//Down
	DOWN = pos.Bump(Down);
	if (DOWN)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//Down left
	DOWN = pos.Bump(Down);
	LEFT = pos.Bump(Left);
	if (DOWN && LEFT)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//Left
	LEFT = pos.Bump(Left);
	if (LEFT)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	//Up left
	UP = pos.Bump(Up);
	LEFT = pos.Bump(Left);
	if(UP && LEFT)
	{
		moves.push_back(pos.GetCoordinatesNotation());
	}
	pos.SetPosition(startpos);

	return moves;
}

bool King::CheckMoveAllowed(string endpos)
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