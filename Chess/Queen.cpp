#include "Queen.h"
#include <iostream>

vector<string> Queen::PossibleMoves(bool hasmoved, string finalpos)
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
	
	//Up Right
	else if (direction == "UpRight")
	{
		for (startY; startY <= finalY; startY++)
		{
			pos.Bump(Right);
			pos.Bump(Up);
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

	//Down Right
	else if (direction == "DownRight")
	{
		for (startX; startX <= finalX; startX++)
		{
			pos.Bump(Right);
			pos.Bump(Down);
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

	//Down Left
	else if (direction == "DownLeft")
	{
		for (startY; startY >= finalY; startY--)
		{
			pos.Bump(Down);
			pos.Bump(Left);
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

	//Up Left
	else if (direction == "UpLeft")
	{
		for (startY; startY <= finalY; startY++)
		{
			pos.Bump(Up);
			pos.Bump(Left);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		pos.SetPosition(startpos);

		return moves;
	}
}

bool Queen::PossibleMoves(vector<string>& possiblemoves, bool hasmoved, string finalpos)
{
	return false;
}