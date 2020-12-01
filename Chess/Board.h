#pragma once
#include "Player.h"


constexpr int kWhiteColour = 10;
constexpr int kBlackColour = 12;
constexpr int kRegularColour = 7;

constexpr int kLeftRookStartPos = 0;
constexpr int kRightRookStartPos = 7;
constexpr int kLeftKnightStartPos = 1;
constexpr int kRightKnightStartPos = 6;
constexpr int kLeftBishopStartPos = 2;
constexpr int kRightBishopStartPos = 5;
constexpr int kQueenStartPos = 3;
constexpr int kKingStartPos = 4;

constexpr int kWhitePieceRow = 0;
constexpr int kWhitePawnRow = 1;
constexpr int kBlackPieceRow = 7;
constexpr int kBlackPawnRow = 6;

const char emptytile = ' ';

class Board
{
	static const int m_rows = 8;
	static const int m_columns = 8;

	string BoardArray[m_columns][m_rows];

public:
	Player WhitePlayer{ white };
	Player BlackPlayer{ black };

	Board();
	void DrawBoard();

	void DrawTile(string location);

	void SetTile(string identity, string location);

	void SetPiece(string identity, string location);

	bool CheckGetPieceValid(bool currentplayer, string location);
	string GetTileIdentity(string location);


	void SetUpBoard();
	void PawnRow(char colour, int row);
	void PieceRow(char colour, int row);
	void ClearTile(string position);
	void EmptyBoard();


	bool isWhite(string location);
	bool isBlack(string location);


	void SetPawn(string identity, string location);
	void SetKnight(string identity, string location);
	void SetBishop(string identity, string location);
	void SetRook(string identity, string location);
	void SetQueen(string identity, string location);
	void SetKing(string identity, string location);

	bool CanPieceMove(bool isWhite, string startpos, string endpos);
	void MovePiece(bool isWhite, string startpos, string endpos);

	bool CheckPossible(vector<string> moves, string endpos);
	bool CheckClearPath(vector<string> moves, string endpos);


	//write a getTileIdentity function
	//can you not just have all the different piece positions as pointers
	//can I write a function that takes a string and returns boardarray[x][y]
};