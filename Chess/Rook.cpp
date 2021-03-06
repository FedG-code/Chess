#include "Rook.h"

vector<string> Rook::PossibleMoves(string finalpos)
{
	string startpos = pos.GetCoordinatesNotation();
	string direction = pos.CompareNotation(finalpos);
	vector<string> moves;

	int startY = pos.GetY();
	int startX = pos.GetX();
	int finalY = TranslateYFromNotation(finalpos[1]);
	int finalX = TranslateXFromNotation(finalpos[0]);

	//Up
	if (direction == "Up")
	{
		for (startY; startY <= finalY; startY++)
		{
			pos.Bump(Up);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		pos.SetPosition(startpos);
		return moves;
	}
	//Down
	else if (direction == "Down")
	{
		for (startY; startY >= finalY; startY--)
		{
			pos.Bump(Down);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		pos.SetPosition(startpos);
		return moves;
	}
	//Right
	else if (direction == "Right")
	{
		for (startX; startX <= finalX; startX++)
		{
			pos.Bump(Right);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		pos.SetPosition(startpos);
		return moves;
	}
	//Left
	else if (direction == "Left")
	{
		for (startX; startX >= finalX; startX--)
		{
			pos.Bump(Left);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		pos.SetPosition(startpos);
		return moves;
	}
}

bool Rook::CheckMoveAllowed(string endpos)
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