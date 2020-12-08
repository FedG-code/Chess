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

constexpr int kBlackPieceRow = 0;
constexpr int kBlackPawnRow = 1;
constexpr int kWhitePieceRow = 7;
constexpr int kWhitePawnRow = 6;

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

	string* GetTilePointer(string location);
	Player* GetPlayer(string identity);
	Piece* GetPieceFromLocation(string location);

	void SetUpBoard();
	void PawnRow(char colour, int row);
	void PieceRow(char colour, int row);
	void ClearTile(string position);
	void EmptyBoard();


	bool isWhite(string location);
	bool isBlack(string location);


	bool CanPieceMove(string startpos, string endpos);
	void MovePiece(string startpos, string endpos);

	bool CheckPossible(vector<string> moves, string endpos);
	bool CheckClearPath(vector<string> moves, string endpos);

	vector<string> SortPawnOut(string startpos, string endpos);
	bool IsTileAttacked(Player* player, string position);
	bool CanKingMove(Player* player);
	bool isKingInCheck(bool currentPlayer);
	bool wouldKingBeInCheck(bool currentPlayer, string startpos, string endpos);
	bool isCheckMate(bool currentPlayer);

	vector<string> isAttackedAbove(int startX, int startY, char playerColour);
	vector<string> isAttackedBelow(int startX, int startY, char playerColour);
	vector<string> isAttackedRight(int startX, int startY, char playerColour);
	vector<string> isAttackedLeft(int startX, int startY, char playerColour);
	vector<string> isAttackedUpRight(int startX, int startY, char playerColour);
	vector<string> isAttackedUpLeft(int startX, int startY, char playerColour);
	vector<string> isAttackedDownRight(int startX, int startY, char playerColour);
	vector<string> isAttackedDownLeft(int startX, int startY, char playerColour);
	bool isAttackedByKnight(string position, char playerColour);
};