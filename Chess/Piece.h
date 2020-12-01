#pragma once
#include "Position.h"
#include <vector>

static const string white_pawn = "wp";
static const string white_pawn_0 = "wp0";
static const string white_pawn_1 = "wp1";
static const string white_pawn_2 = "wp2";
static const string white_pawn_3 = "wp3";
static const string white_pawn_4 = "wp4";
static const string white_pawn_5 = "wp5";
static const string white_pawn_6 = "wp6";
static const string white_pawn_7 = "wp7";

static const string white_knight = "wk";
static const string white_knight_0 = "wk0";
static const string white_knight_1 = "wk1";

static const string white_bishop = "wb";
static const string white_bishop_0 = "wb0";
static const string white_bishop_1 = "wb1";

static const string white_rook = "wr";
static const string white_rook_0 = "wr0";
static const string white_rook_1 = "wr1";

static const string white_queen = "wQ";
//static const string white_queen_0 = "wQ0";
static const string white_king = "wK";
//static const string white_king_0 = "wK0";

static const string black_pawn = "bp";
static const string black_pawn_0 = "bp0";
static const string black_pawn_1 = "bp1";
static const string black_pawn_2 = "bp2";
static const string black_pawn_3 = "bp3";
static const string black_pawn_4 = "bp4";
static const string black_pawn_5 = "bp5";
static const string black_pawn_6 = "bp6";
static const string black_pawn_7 = "bp7";

static const string black_knight = "bk";
static const string black_knight_0 = "bk0";
static const string black_knight_1 = "bk1";

static const string black_bishop = "bb";
static const string black_bishop_0 = "bb0";
static const string black_bishop_1 = "bb1";

static const string black_rook = "br";
static const string black_rook_0 = "br0";
static const string black_rook_1 = "br1";

static const string black_queen = "bQ";
//static const string black_queen_0 = "bQ0";
static const string black_king = "bK";
//static const string black_king_0 = "bK0";

const char pawn = 'p';
const char knight = 'k';
const char bishop = 'b';
const char rook = 'r';
const char queen = 'Q';
const char king = 'K';
 
const char white = 'w';
const char black = 'b';

class Piece
{
	string m_identity;	
	bool m_hasMoved;


public:
	Position pos;
	Piece();
	virtual vector<string> PossibleMoves(bool hasmoved, string finalpos) = 0;

	string GetIdentity();
	void SetIdentity(string name);
	
	bool GetHasMoved();
	void HasIndeedMoved();

	
	void DrawPiece();
};