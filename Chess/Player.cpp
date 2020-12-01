#include "Player.h"
#include <iostream>


Player::Player(char colour)
{
	SetPlayerColour(colour);
	TeamSetup();
}

char Player::GetPlayerColour()
{
	return m_PlayerColour;
}

void Player::SetPlayerColour(char colour)
{
	if (colour == black || colour == white)
	{
		m_PlayerColour = colour;
	}
	else
	{
		cout << "invalid colour" << std::endl;
	}
}

void Player::TeamSetup()
{
	//note: this function could be expanded to also set the intial position of the pawns but I feel the board class should tackle that
	if (m_PlayerColour == white)
	{
		for (int i = 0; i < PawnNum; i++)
		{
			string whichpawn;
			whichpawn.append(white_pawn);
			whichpawn.push_back(IntToChar(i));
			Pawns[i].SetIdentity(whichpawn);
		}
		for (int i = 0; i < PieceArrayNum; i++)
		{
			string whichknight;
			whichknight.append(white_knight);
			whichknight.push_back(IntToChar(i));
			Knights[i].SetIdentity(whichknight);

			string whichbishop;
			whichbishop.append(white_bishop);
			whichbishop.push_back(IntToChar(i));
			Bishops[i].SetIdentity(whichbishop);

			string whichrook;
			whichrook.append(white_rook);
			whichrook.push_back(IntToChar(i));
			Rooks[i].SetIdentity(whichrook);
		}
		Queen.SetIdentity(white_queen);
		King.SetIdentity(white_king);
	}
	else if (m_PlayerColour == black)
	{
		for (int i = 0; i < PawnNum; i++)
		{
			string whichpawn;
			whichpawn.append(black_pawn);
			whichpawn.push_back(IntToChar(i));
			Pawns[i].SetIdentity(whichpawn);
		}
		for (int i = 0; i < PieceArrayNum; i++)
		{
			string whichknight;
			whichknight.append(black_knight);
			whichknight.push_back(IntToChar(i));
			Knights[i].SetIdentity(whichknight);

			string whichbishop;
			whichbishop.append(black_bishop);
			whichbishop.push_back(IntToChar(i));
			Bishops[i].SetIdentity(whichbishop);

			string whichrook;
			whichrook.append(black_rook);
			whichrook.push_back(IntToChar(i));
			Rooks[i].SetIdentity(whichrook);
		}
		Queen.SetIdentity(black_queen);
		King.SetIdentity(black_king);
	}
}


//these helper functions are almost certainly useless after my switch to a string board

int Player::WhichPawnAtLocation(string location)
{
	for (int i = 0; i < PawnNum; i++)
	{
		string pawnlocation = Pawns[i].pos.GetCoordinatesNotation();

		if (pawnlocation == location)
		{
			return i;
		}
	}
}

int Player::WhichKnightAtLocation(string location)
{
	for (int i = 0; i < PieceArrayNum; i++)
	{
		string knightlocation = Knights[i].pos.GetCoordinatesNotation();

		if (knightlocation == location)
		{
			return i;
		}
	}
}

int Player::WhichBishopAtLocation(string location)
{
	for (int i = 0; i < PieceArrayNum; i++)
	{
		string bishoplocation = Bishops[i].pos.GetCoordinatesNotation();

		if (bishoplocation == location)
		{
			return i;
		}
	}
}

int Player::WhichRookAtLocation(string location)
{
	for (int i = 0; i < PieceArrayNum; i++)
	{
		string rooklocation = Rooks[i].pos.GetCoordinatesNotation();
		if (rooklocation == location)
		{
			return i;
		}
	}
}


Piece* Player::GetPiece(string pieceName)
{
	if (m_PlayerColour == white)
	{
		if (pieceName.compare(white_pawn_0) == 0)
		{
			return &Pawns[0];
		}
		if (pieceName.compare(white_pawn_1) == 0)
		{
			return &Pawns[1];
		}
		if (pieceName.compare(white_pawn_2) == 0)
		{
			return &Pawns[2];
		}
		if (pieceName.compare(white_pawn_3) == 0)
		{
			return &Pawns[3];
		}
		if (pieceName.compare(white_pawn_4) == 0)
		{
			return &Pawns[4];
		}
		if (pieceName.compare(white_pawn_5) == 0)
		{
			return &Pawns[5];
		}
		if (pieceName.compare(white_pawn_6) == 0)
		{
			return &Pawns[6];
		}
		if (pieceName.compare(white_pawn_7) == 0)
		{
			return &Pawns[7];
		}
		if (pieceName.compare(white_knight_0) == 0)
		{
			return &Knights[0];
		}
		if (pieceName.compare(white_knight_1) == 0)
		{
			return &Knights[1];
		}
		if (pieceName.compare(white_bishop_0) == 0)
		{
			return &Bishops[0];
		}
		if (pieceName.compare(white_bishop_1) == 0)
		{
			return &Bishops[0];
		}
		if (pieceName.compare(white_rook_0) == 0)
		{
			return &Rooks[0];
		}
		if (pieceName.compare(white_rook_1) == 0)
		{
			return &Rooks[1];
		}
		if (pieceName.compare(white_queen) == 0)
		{
			return &Queen;
		}
		if (pieceName.compare(white_king) == 0)
		{
			return &King;
		}
	}
	else
	{
		if (pieceName.compare(black_pawn_0) == 0)
		{
			return &Pawns[0];
		}
		if (pieceName.compare(black_pawn_1) == 0)
		{
			return &Pawns[1];
		}
		if (pieceName.compare(black_pawn_2) == 0)
		{
			return &Pawns[2];
		}
		if (pieceName.compare(black_pawn_3) == 0)
		{
			return &Pawns[3];
		}
		if (pieceName.compare(black_pawn_4) == 0)
		{
			return &Pawns[4];
		}
		if (pieceName.compare(black_pawn_5) == 0)
		{
			return &Pawns[5];
		}
		if (pieceName.compare(black_pawn_6) == 0)
		{
			return &Pawns[6];
		}
		if (pieceName.compare(black_pawn_7) == 0)
		{
			return &Pawns[7];
		}
		if (pieceName.compare(black_knight_0) == 0)
		{
			return &Knights[0];
		}
		if (pieceName.compare(black_knight_1) == 0)
		{
			return &Knights[1];
		}
		if (pieceName.compare(black_bishop_0) == 0)
		{
			return &Bishops[0];
		}
		if (pieceName.compare(black_bishop_1) == 0)
		{
			return &Bishops[0];
		}
		if (pieceName.compare(black_rook_0) == 0)
		{
			return &Rooks[0];
		}
		if (pieceName.compare(black_rook_1) == 0)
		{
			return &Rooks[1];
		}
		if (pieceName.compare(black_queen) == 0)
		{
			return &Queen;
		}
		if (pieceName.compare(black_king) == 0)
		{
			return &King;
		}
	}

	return nullptr;
}


//string Player::WhichPieceAtLocation(string location)
//{
//	//check if a pawn is at location
//	for (int i = 0; i < PawnNum; i++)
//	{
//		string pawnlocation = Pawns[i].pos.GetCoordinatesNotation();
//		string whoamI = "p";
//		whoamI.push_back(i);
//		if (pawnlocation == location)
//		{
//			return whoamI;
//		}
//	}
//
//	//check knights
//	for (int i = 0; i < PieceArrayNum; i++)
//	{
//		string knightlocation = Knights[i].pos.GetCoordinatesNotation();
//		string whoamI = "k";
//		whoamI.push_back(i);
//		if (knightlocation == location)
//		{
//			return whoamI;
//		}
//	}
//
//	//check bishops
//	for (int i = 0; i < PieceArrayNum; i++)
//	{
//		string bishoplocation = Bishops[i].pos.GetCoordinatesNotation();
//		string whoamI = "b";
//		whoamI.push_back(i);
//		if (bishoplocation == location)
//		{
//			return whoamI;
//		}
//	}
//
//	//check rooks
//
//	for (int i = 0; i < PieceArrayNum; i++)
//	{
//		string rooklocation = Rooks[i].pos.GetCoordinatesNotation();
//		string whoamI = "r";
//		whoamI.push_back(i);
//		if (rooklocation == location)
//		{
//			return whoamI;
//		}
//	}
//
//	//check Queen
//
//	string queenlocation = Queen.pos.GetCoordinatesNotation();
//	if (queenlocation == location)
//	{
//		return "q";
//	}
//
//	string kinglocation = King.pos.GetCoordinatesNotation();
//	if (kinglocation == location)
//	{
//		return "K";
//	}
//}