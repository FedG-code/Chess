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
		MakeQueen("d1");
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
		MakeQueen("d8");
		King.SetIdentity(black_king);
	}
}


//these helper functions are almost certainly useless after my switch to a string board

//int Player::WhichPawnAtLocation(string location)
//{
//	for (int i = 0; i < PawnNum; i++)
//	{
//		string pawnlocation = Pawns[i].pos.GetCoordinatesNotation();
//
//		if (pawnlocation == location)
//		{
//			return i;
//		}
//	}
//}
//
//int Player::WhichKnightAtLocation(string location)
//{
//	for (int i = 0; i < PieceArrayNum; i++)
//	{
//		string knightlocation = Knights[i].pos.GetCoordinatesNotation();
//
//		if (knightlocation == location)
//		{
//			return i;
//		}
//	}
//}
//
//int Player::WhichBishopAtLocation(string location)
//{
//	for (int i = 0; i < PieceArrayNum; i++)
//	{
//		string bishoplocation = Bishops[i].pos.GetCoordinatesNotation();
//
//		if (bishoplocation == location)
//		{
//			return i;
//		}
//	}
//}
//
//int Player::WhichRookAtLocation(string location)
//{
//	for (int i = 0; i < PieceArrayNum; i++)
//	{
//		string rooklocation = Rooks[i].pos.GetCoordinatesNotation();
//		if (rooklocation == location)
//		{
//			return i;
//		}
//	}
//}


Piece* Player::GetPiece(string pieceName)
{
	char pieceColour = pieceName[0];
	if (pieceColour != m_PlayerColour)
	{
		cout << "That piece is not your colour" << endl;

		return nullptr;
	}
	char pieceIdentity = pieceName[1];

	int pieceIndex;
	if (pieceIdentity != king)
	{
		pieceIndex = CharToInt(pieceName[2]);
	}
	
	if (pieceIdentity == pawn)
	{
		return &Pawns[pieceIndex];
	}
	else if (pieceIdentity == knight)
	{
		return &Knights[pieceIndex];
	}
	else if (pieceIdentity == bishop)
	{
		return &Bishops[pieceIndex];
	}
	else if (pieceIdentity == rook)
	{
		return &Rooks[pieceIndex];
	}
	else if (pieceIdentity == queen)
	{
		return &Queens[pieceIndex];
	}
	else if (pieceIdentity == king)
	{
		return &King;
	}
	/*	if (pieceName.compare(white_pawn_0) == 0)
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
			return &Bishops[1];
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
			return &Bishops[1];
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
	}*/

	return nullptr;
}
  

void Player::EatPiece(Piece* piece)
{
	string identity = piece->GetIdentity();
	piece->SetEaten();
	m_EatenPieces.push_back(identity);
	piece->SetIdentity(" ");
}

vector<string> Player::ReturnEatenPieces()
{
	return m_EatenPieces;
}

void Player::MakeQueen(string location)
{
	int queenIndex = Queens.size();
	char number = IntToChar(queenIndex);
	Queen newQueen;
	newQueen.pos.SetPosition(location);
	//generate queen name
	char queenColour = GetPlayerColour();
	string queenName;
	queenName.push_back(queenColour);
	queenName.push_back('Q');
	queenName.push_back(number);

	newQueen.SetIdentity(queenName);

	Queens.push_back(newQueen);
}