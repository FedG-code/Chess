#include "Pawn.h"
#include "Board.h"

Pawn::Pawn()
{

}

vector<string> Pawn::PossibleMoves(string finalpos)
{
	vector<string> moves;
	string startpos = pos.GetCoordinatesNotation();
	
	int startY = TranslateYFromNotation(startpos[1]);
	if (startY == 0 || startY == 7)
	{
		return moves;
	}
	string whoAmI = GetIdentity();

	char currentColour = whoAmI[0];
	
	bool hasMoved = GetHasMoved();
	//note these two seem inverted but it's due to the coordinate fix
	//if the square(s) in front are empty, you can move forward otherwise, move diagonal only if
	//enemy is in diagonal tiles
	if (currentColour == black)
	{
		if (!m_blocked1)
		{
			pos.Bump(Up);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		if (!m_blocked2 && !hasMoved)
		{
			pos.Bump(Up);
			moves.push_back(pos.GetCoordinatesNotation());
		}

		pos.SetPosition(startpos);
		//check diagonal tiles
		if (m_canEatLaterally)
		{
			bool eat1 = pos.Bump(Up);
			bool eat2 = pos.Bump(Right);

			if (eat1 && eat2)
			{
				moves.push_back(pos.GetCoordinatesNotation());
				
			}
			pos.SetPosition(startpos);

			bool eat3 = pos.Bump(Up);
			bool eat4 = pos.Bump(Left);
			if (eat3 && eat4)
			{
				moves.push_back(pos.GetCoordinatesNotation());
			}
			pos.SetPosition(startpos);
		}

	}
	else if (currentColour == white)
	{
		if (!m_blocked1)
		{
			pos.Bump(Down);
			moves.push_back(pos.GetCoordinatesNotation());
		}
		if (!m_blocked2 && !hasMoved)
		{
			pos.Bump(Down);
			moves.push_back(pos.GetCoordinatesNotation());
		}

		pos.SetPosition(startpos);
		//check diagonal tiles
		if (m_canEatLaterally)
		{
			bool eat1 = pos.Bump(Down);
			bool eat2 = pos.Bump(Right);

			if (eat1 && eat2)
			{
				moves.push_back(pos.GetCoordinatesNotation());

			}
			pos.SetPosition(startpos);

			bool eat3 = pos.Bump(Down);
			bool eat4 = pos.Bump(Left);
			if (eat3 && eat4)
			{
				moves.push_back(pos.GetCoordinatesNotation());
			}
			pos.SetPosition(startpos);
		}
	}
	return moves;
}


bool Pawn::CheckMoveAllowed(string endpos)
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

void Pawn::SetBlocked1(bool set)
{
	m_blocked1 = set;
}

void Pawn::SetBlocked2(bool set)
{
	m_blocked2 = set;
}

void Pawn::SetCanEatLaterally(bool set)
{
	m_canEatLaterally = set;
}