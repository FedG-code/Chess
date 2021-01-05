#pragma once
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"


static const int PawnNum = 8;
static const int PieceArrayNum = 2;


class Player
{
	char m_PlayerColour;
	vector<string> m_EatenPieces;

public:
	Pawn Pawns[PawnNum];
	Knight Knights[PieceArrayNum];
	Bishop Bishops[PieceArrayNum];
	Rook Rooks[PieceArrayNum];
	vector<Queen> Queens;
	King King;

	Player(char colour);
	char GetPlayerColour();
	void SetPlayerColour(char colour);
	void TeamSetup();

	//int WhichPawnAtLocation(string location);
	//int WhichKnightAtLocation(string location);
	//int WhichBishopAtLocation(string location);
	//int WhichRookAtLocation(string location);

	Piece* GetPiece(string pieceName);

	void EatPiece(Piece* piece);
	vector<string> ReturnEatenPieces();
	void MakeQueen(string location);
	//string WhichPieceAtLocation(string location);






	//GetPawn and other get functions for all the objects.
	//Make code in Board that passes an enum identifier (look at position for reference on the enum)
	//skeptical of the logic of these comments

	static void PieceEaten(Player* attackerPlayer, Piece* attacker, Player* targetPlayer, Piece* target)
	{
		cout << "PieceEaten" << endl;
	}
};

