#include "Bishop.h"
#include <iostream>

vector<string> Bishop::PossibleMoves(bool hasmoved, string finalpos)
{
	string startpos = pos.GetCoordinatesNotation();
	string direction = pos.CompareNotation(finalpos);
	vector<string> moves;

	int startY = pos.GetY();
	int startX = pos.GetX();
	int finalY = TranslateYFromNotation(finalpos[1]);
	int finalX = TranslateXFromNotation(finalpos[0]);
	
	//Up Left
	if (direction == "UpLeft")
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
	//Up Right
	else if (direction == "UpRight")
	{
		for (startY; startY <= finalY; startY++)
		{
			pos.Bump(Up);
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
			pos.Bump(Down);
			pos.Bump(Right);
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
	else
	{
		//error error error
		cout << "impossible" << endl;
	}
}