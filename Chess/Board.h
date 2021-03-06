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

static bool attacked = true;
static bool blockable = false;
const char emptytile = ' ';

typedef void (*OnPieceEatenCB)(Player* attackerPlayer, Piece* attacker, Player* targetPlayer, Piece* target);

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

	
	
	bool CanKingMove(bool currentPlayer);
	bool isKingInCheck(bool currentPlayer);
	bool wouldKingBeInCheck(bool currentPlayer, string startpos, string endpos);
	bool isCheckMate(bool currentPlayer);



	vector<string> IsTileAttacked(bool currentPlayer, string position, bool attackedOrBlockable);

	int NumberOfAttacks(vector<string> attackInfo);
	char GetMeOneAttackerID(vector<string> attackInfo);
	string GetMeOneAttackerPos(vector<string> attackInfo);
	vector<string> GetMeAllAttackerPos(vector<string> attackInfo);
	vector<string> GetMePathToBlock(vector<string> attackInfo);
	bool CanIKill(bool currentPlayer, string attackerPos);
	bool CanIBlock(bool currentPlayer, vector<string> attackerInfo);
	
	void Promotion(Player* player, string location);

	string DoesKingWantToCastle(string startpos, string endpos);
	bool AreCastlingSquaresEmpty(string startpos, string endpos);
	bool CanKingCastle(string startpos, string endpos);

	vector<string> isAttackedBelow(int startX, int startY, char playerColour);
	vector<string> isBlockableBelow(int startX, int startY, char playerColour);
	vector<string> isAttackedAbove(int startX, int startY, char playerColour);
	vector<string> isBlockableAbove(int startX, int startY, char playerColour);
	vector<string> isAttackedRight(int startX, int startY, char playerColour, bool attackedOrBlocked);
	vector<string> isAttackedLeft(int startX, int startY, char playerColour, bool attackedOrBlocked);
	vector<string> isAttackedUpRight(int startX, int startY, char playerColour, bool attackedOrBlocked);
	vector<string> isAttackedUpLeft(int startX, int startY, char playerColour, bool attackedOrBlocked);
	vector<string> isAttackedDownRight(int startX, int startY, char playerColour, bool attackedOrBlocked);
	vector<string> isAttackedDownLeft(int startX, int startY, char playerColour, bool attackedOrBlocked);
	vector<string> isAttackedByKnight(string position, char playerColour);

	vector<string> SortPawnOut(string startpos, string endpos);

	OnPieceEatenCB m_PieceEatenCB = nullptr;

};