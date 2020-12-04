#include "Pawn.h"

vector<string> Pawn::PossibleMoves(bool hasmoved, string finalpos)
{
	vector<string> moves;
	string startpos = pos.GetCoordinatesNotation();
	
	string whoAmI = GetIdentity();

	char currentColour = whoAmI[0];
	
	//note these two seem inverted but it's due to the coordinate fix
	if (currentColour == black)
	{
		pos.Bump(Up);
		moves.push_back(pos.GetCoordinatesNotation());

		if (!hasmoved)
		{
			pos.Bump(Up);
			moves.push_back(pos.GetCoordinatesNotation());
		}

		pos.SetPosition(startpos);
		return moves;
	}
	else if (currentColour == white)
	{
		pos.Bump(Down);
		moves.push_back(pos.GetCoordinatesNotation());

		if (!hasmoved)
		{
			pos.Bump(Down);
			moves.push_back(pos.GetCoordinatesNotation());
		}

		pos.SetPosition(startpos);
		return moves;
	}
}