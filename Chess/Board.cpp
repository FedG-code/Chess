#include "Board.h"
#include <Windows.h>

using namespace std;

Board::Board()
{

}
   
void Board::DrawTile(string location)
{
	string currentTile = *GetTilePointer(location);
	
	if (currentTile != " ")
	{
		char currentTileIdentity = currentTile[1];
		cout << currentTileIdentity;
	}
	else
	{
		cout << " ";
	}
}

void Board::DrawBoard()
{
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			string notation = MakeNotation(j, i);
			bool WhiteCheck = isWhite(notation);
			bool BlackCheck = isBlack(notation);
			if (WhiteCheck)
			{
				SetConsoleTextAttribute(console, kWhiteColour);
				DrawTile(notation);
			}
			else if (BlackCheck)
			{
				SetConsoleTextAttribute(console, kBlackColour);
				DrawTile(notation);

			}
			else 
			{
				SetConsoleTextAttribute(console, kRegularColour);
				DrawTile(notation);
			}
		}
		cout << " " << abs(7-i)+1 << endl;

		SetConsoleTextAttribute(console, kRegularColour);

	}

	cout << 'a' << 'b' << 'c' << 'd' << 'e' << 'f' << 'g' << 'h' << endl;
}

void Board::SetTile(string identity, string location)
{
	int x = TranslateXFromNotation(location[0]);
	int y = TranslateYFromNotation(location[1]);

	BoardArray[x][y] = identity;
}

void Board::SetPiece(string identity, string location)
{
	Player* currentPlayer = GetPlayer(identity);
	Piece* piece = currentPlayer->GetPiece(identity);
	piece->pos.SetPosition(location);
	SetTile(identity, location);
	return;
}

bool Board::CheckGetPieceValid(bool currentplayer, string location)
{
	//check to see if there is a piece at the location and whether it belongs to the player

	string identity = *GetTilePointer(location);
	Player* selectedTilePlayer = GetPlayer(identity);
	Piece* piece = selectedTilePlayer->GetPiece(identity);
	bool isAlive = piece->GetIsAlive();

	if (!isAlive)
	{
		cout << "that piece has been eaten, how'd you even select it?" << endl;
		return false;
	}

	if (identity == " ")
	{
		cout << "that's an empty tile" << endl;
		return false;
	}
	else
	{
		char colour = identity[0];
		if (colour == black && !currentplayer)
		{
			return true;
		}
		else if (colour == white && currentplayer)
		{
			return true;
		}
		else
		{
			cout << "you don't own that piece" << endl;
			return false;
		}
	}
}

string Board::GetTileIdentity(string location)
{
	int startX = TranslateXFromNotation(location[0]);
	int startY = TranslateYFromNotation(location[1]);

	return BoardArray[startX][startY];
}

string* Board::GetTilePointer(string location)
{
	int startX = TranslateXFromNotation(location[0]);
	int startY = TranslateYFromNotation(location[1]);

	return &BoardArray[startX][startY];
}

Player* Board::GetPlayer(string identity)
{
	char colour = identity[0];
	if (colour == black)
	{
		return &BlackPlayer;
	}
	else if (colour == white)
	{
		return &WhitePlayer;
	}
	else if (identity == " ")
	{
		cout << "No player owns the empty square" << endl;
		return nullptr;
	}
	else
	{
		cout << "Invalid symbol input in GetPlayer" << endl;
		return nullptr;
	}
}

Piece* Board::GetPieceFromLocation(string location)
{
	string identity = *GetTilePointer(location);
	Player* currentPlayer = GetPlayer(identity);
	Piece* piece =	currentPlayer->GetPiece(identity);

	return piece;
}

void Board::SetUpBoard()
{
	EmptyBoard();

	PieceRow(white, kWhitePieceRow);
	PawnRow(white, kWhitePawnRow);
	PieceRow(black, kBlackPieceRow);
	PawnRow(black, kBlackPawnRow);

}

void Board::PawnRow(char colour, int row)
{
	if (colour == white)
	{
		for (int i = 0; i < m_rows; i++)
		{
			string currentSquare = MakeNotation(i, row);
			string currentPawn = white_pawn;
			currentPawn.push_back(IntToChar(i));

			SetPiece(currentPawn, currentSquare);
		}
	}
	else if (colour == black)
	{
		for (int i = 0; i < m_rows; i++)
		{
			string currentSquare = MakeNotation(i, row);
			string currentPawn = black_pawn;
			currentPawn.push_back(IntToChar(i));

			SetPiece(currentPawn, currentSquare);
		}
	}
}

void Board::PieceRow(char colour, int row)
{
	if (colour == white)
	{
		SetPiece(white_rook_0, MakeNotation(kLeftRookStartPos, row));
		SetPiece(white_rook_1, MakeNotation(kRightRookStartPos, row));
		SetPiece(white_knight_0, MakeNotation(kLeftKnightStartPos, row));
		SetPiece(white_knight_1, MakeNotation(kRightKnightStartPos, row));
		SetPiece(white_bishop_0, MakeNotation(kLeftBishopStartPos, row));
		SetPiece(white_bishop_1, MakeNotation(kRightBishopStartPos, row));
		SetPiece(white_queen, MakeNotation(kQueenStartPos, row));
		SetPiece(white_king, MakeNotation(kKingStartPos, row));
	}
	else if (colour == black)
	{
		SetPiece(black_rook_0, MakeNotation(kLeftRookStartPos, row));
		SetPiece(black_rook_1, MakeNotation(kRightRookStartPos, row));
		SetPiece(black_knight_0, MakeNotation(kLeftKnightStartPos, row));
		SetPiece(black_knight_1, MakeNotation(kRightKnightStartPos, row));
		SetPiece(black_bishop_0, MakeNotation(kLeftBishopStartPos, row));
		SetPiece(black_bishop_1, MakeNotation(kRightBishopStartPos, row));
		SetPiece(black_queen, MakeNotation(kQueenStartPos, row));
		SetPiece(black_king, MakeNotation(kKingStartPos, row));
	}
}

void Board::ClearTile(string position)
{
	int x = TranslateXFromNotation(position[0]);
	int y = TranslateYFromNotation(position[1]);
	BoardArray[x][y] = " ";
}

void Board::EmptyBoard()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			BoardArray[i][j] = " ";
		}
	}
}


//write a helper function that checks which piece in an array is at a location, this only needs to return the index of the array


//likely useless functions with new notation system

bool Board::isBlack(string location)
{
	string currentTile = *GetTilePointer(location);
	char colour = currentTile[0];
	if (colour == black)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::isWhite(string location)
{
	string currentTile = *GetTilePointer(location);
	char colour = currentTile[0];
	if (colour == white)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Board::CanPieceMove(string startpos, string endpos)
{
	//bit of a cheat here but because CanPieceMove is at the end of a do while loop
	//it means that it can afford to do something as incorrect as returning true
	//to what would be a meaningless string as the entire while loop repeats right after
	if (endpos == "back")
	{
		return true;
	}
	

	//we don't actually need to pass a bool into CanPieceMove because this function
	//is only called after we've confirmed the piece belongs to the player
	string startIdentity = *GetTilePointer(startpos);
	string endIdentity = *GetTilePointer(endpos);
	char endIdentityColour = endIdentity[0];

	Player* currentPlayer = GetPlayer(startIdentity);
	Piece* piece = currentPlayer->GetPiece(startIdentity);
	char currentPlayerColour = currentPlayer->GetPlayerColour();
	vector<string> moves;

	if (endIdentity != " " && endIdentityColour == currentPlayerColour)
	{
		cout << "Your own piece is there!" << endl;
		return false;
	}

	if (piece)
	{
		if (startIdentity[1] == pawn)
		{

			//make this whole thing a fn called "doPawnWell" or smth stupid like that
			//check for pieces pawn can eat, trigger a bool in pawn
			//that generate moves for diagonal eating
			moves = SortPawnOut(startpos, endpos);


		}
		else
		{
			moves = piece->PossibleMoves(endpos);
		}
		//check possible should be moved to inside the different piece classes so it can account for stuff like pawns
		bool possible = CheckPossible(moves, endpos);
		//bool possible = piece->CheckMoveAllowed(extraInfo, endpos)

		bool clearpath = true;

		if (startIdentity[1] != knight)
		{
			clearpath = CheckClearPath(moves, endpos);
		}
		if (!possible)
		{
			cout << "The piece you selected can't move there" << endl;
			return false;
		}
		else if (possible && !clearpath)
		{
			cout << "There's a piece in the way!" << endl;
			return false;
		}
		else if (possible && clearpath)
		{
			return true;
		}
		
	}
	else
	{
		return false;
	}
}

void Board::MovePiece(string startpos, string endpos)
{
	string startIdentity = *GetTilePointer(startpos);
	string endIdentity = *GetTilePointer(endpos);
	
	Player* startPlayer = GetPlayer(startIdentity);
	Piece* startPiece = startPlayer->GetPiece(startIdentity);
	

	
	if (endIdentity != " ")
	{
		Player* endPlayer = GetPlayer(endIdentity);
		Piece* endPiece = endPlayer->GetPiece(endIdentity);
		startPlayer->EatPiece(endPiece);
	}

	startPiece->pos.SetPosition(endpos);
	if (startPiece->GetHasMoved() == false)
	{
		startPiece->HasIndeedMoved();
	}
	SetTile(startIdentity, endpos);
	ClearTile(startpos);
	return;
}



bool Board::CheckPossible(vector<string> moves, string endpos)
{
	for (int i = 0; i < moves.size(); i++)
	{
		if (moves[i] == endpos)
		{
			return true;
		}
	}

	return false;
}

bool Board::CheckClearPath(vector<string> moves, string endpos)
{
	//find a way to make an exception for the knight
	for (int i = 0; i < moves.size(); i++)
	{
		if (moves[i] == endpos)
		{
			return true;
		}
		else if (moves[i] != endpos)
		{
			string currentpos = moves[i];
			int currentX = TranslateXFromNotation(currentpos[0]);
			int currentY = TranslateYFromNotation(currentpos[1]);

			if (BoardArray[currentX][currentY] != " ")
			{
				return false;
			}
		}

	}

	return true;
}


//this is the ugliest block of code I've written in ages so let me add some comments to try and explain the damn
//thing
vector<string> Board::SortPawnOut(string startpos, string endpos)
{
	//just grabbing all the info I can get on square's locations and identities
	string startIdentity = *GetTilePointer(startpos);
	string endIdentity = *GetTilePointer(endpos);

	int pieceIndex = CharToInt(startIdentity[2]);

	Player* currentPlayer = GetPlayer(startIdentity);
	Piece* piece = currentPlayer->GetPiece(startIdentity);
	char currentPlayerColour = currentPlayer->GetPlayerColour();
	vector<string> moves;
	if (currentPlayerColour == white)
	{
		//this whole section very forcefully finds the value of the squares diagonally in front of the pawn
		int pawnXStart = TranslateXFromNotation(startpos[0]);
		int pawnYStart = TranslateYFromNotation(startpos[1]);
		
		int pawnDiag1X = pawnXStart + 1;
		int pawnDiag2X = pawnXStart - 1;
		int pawnLowerY = pawnYStart - 1;

		string diag1Notation = MakeNotation(pawnDiag1X, pawnLowerY);
		string diag2Notation = MakeNotation(pawnDiag2X, pawnLowerY);
		string diag1Identity = GetTileIdentity(diag1Notation);
		char diag1Colour = diag1Identity[0];

		string diag2Identity = GetTileIdentity(diag2Notation);
		char diag2Colour = diag2Identity[0];
		if (diag1Colour == 'b' || diag2Colour == 'b')
		{
			currentPlayer->Pawns[pieceIndex].SetCanEatLaterally(true);
		}
		//this code checks if there's pieces in the way of the pawn
		string blocked1Notation = MakeNotation(pawnXStart, pawnLowerY);
		if (GetTileIdentity(blocked1Notation) != " ")
		{
			currentPlayer->Pawns[pieceIndex].SetBlocked1(true);
		}
		string blocked2Notation = MakeNotation(pawnXStart, (pawnLowerY - 1));
		if (GetTileIdentity(blocked2Notation) != " ")
		{
			currentPlayer->Pawns[pieceIndex].SetBlocked2(true);
		}
		moves = piece->PossibleMoves(endpos);
		currentPlayer->Pawns[pieceIndex].SetCanEatLaterally(false);
		currentPlayer->Pawns[pieceIndex].SetBlocked1(false);
		currentPlayer->Pawns[pieceIndex].SetBlocked2(false);
	}
	else
	{
		int pawnXStart = TranslateXFromNotation(startpos[0]);
		int pawnYStart = TranslateYFromNotation(startpos[1]);

		int pawnDiag1X = pawnXStart + 1;
		int pawnDiag2X = pawnXStart - 1;
		int pawnHigherY = pawnYStart + 1;

		string diag1Notation = MakeNotation(pawnDiag1X, pawnHigherY);
		string diag2Notation = MakeNotation(pawnDiag2X, pawnHigherY);
		string diag1Identity = GetTileIdentity(diag1Notation);
		char diag1Colour = diag1Identity[0];

		string diag2Identity = GetTileIdentity(diag2Notation);
		char diag2Colour = diag2Identity[0];
		if (diag1Colour == 'w' || diag2Colour == 'w')
		{
			currentPlayer->Pawns[pieceIndex].SetCanEatLaterally(true);
		}
		string blocked1Notation = MakeNotation(pawnXStart, pawnHigherY);
		if (GetTileIdentity(blocked1Notation) != " ")
		{
			currentPlayer->Pawns[pieceIndex].SetBlocked1(true);
		}
		string blocked2Notation = MakeNotation(pawnXStart, (pawnHigherY + 1));
		if (GetTileIdentity(blocked2Notation) != " ")
		{
			currentPlayer->Pawns[pieceIndex].SetBlocked2(true);
		}
		moves = piece->PossibleMoves(endpos);

		currentPlayer->Pawns[pieceIndex].SetCanEatLaterally(false);
		currentPlayer->Pawns[pieceIndex].SetBlocked1(false);
		currentPlayer->Pawns[pieceIndex].SetBlocked2(false);
	}

	return moves;
}

bool Board::IsTileAttacked(Player* player, string position)
{
	//set out in all cardinal directions and find whether there's any pieces
	//you can stop the second a piece is there, check the colour, check the identity, determine whether attacking
	//add knight moves as well
	char playerColour = player->GetPlayerColour();

	int startX = TranslateXFromNotation(position[0]);
	int startY = TranslateYFromNotation(position[1]);
	
	bool above = isAttackedAbove(startX, startY, playerColour);
	bool below = isAttackedBelow(startX, startY, playerColour);
	bool left = isAttackedLeft(startX, startY, playerColour);
	bool right = isAttackedRight(startX, startY, playerColour);
	bool upright = isAttackedUpRight(startX, startY, playerColour);
	bool upleft = isAttackedUpLeft(startX, startY, playerColour);
	bool downright = isAttackedDownRight(startX, startY, playerColour);
	bool downleft = isAttackedDownLeft(startX, startY, playerColour);
	bool knight = isAttackedByKnight(position, playerColour);

	//up right, up left and knight are returning true
	if (above || below || left || right || upright || upleft || downright || downleft || knight)
	{
		return true;
	}

	return false;
}

//should likely be boolian argument
bool Board::CanKingMove(Player* player)
{
	string location = player->King.pos.GetCoordinatesNotation();
	int startX = TranslateXFromNotation(location[0]);
	int startY = TranslateYFromNotation(location[1]);
	char kingColour = player->GetPlayerColour();
	//note that any string needs to be passed even if it isn't used
	vector<string> moves = player->King.PossibleMoves(location);
	
	int blockedCounter = 0;
	int numberOfPossibleMoves = moves.size();
	for (int i = 0; i < moves.size(); i++)
	{
		string currentTile = moves[i];
		string currentTileIdentity = *GetTilePointer(currentTile);
		char currentTileColour = currentTileIdentity[0];
		bool isCurrentTileAttacked = IsTileAttacked(player, currentTile);
		if (currentTileIdentity == " " || currentTileColour != kingColour)
		{
			if (isCurrentTileAttacked)
			{
				blockedCounter++;
			}
		}
		else
		{
			blockedCounter++;
		}

	}

	if (blockedCounter == numberOfPossibleMoves)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool Board::isKingInCheck(bool currentPlayer)
{
	string identity;
	if (currentPlayer)
	{
		identity = "wK";
	}
	else
	{
		identity = "bK";
	}
	Player* player = GetPlayer(identity);
	string kingLocation = player->King.pos.GetCoordinatesNotation();
	bool kingInCheck = IsTileAttacked(player, kingLocation);
	if (kingInCheck)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::wouldKingBeInCheck(bool currentPlayer, string startpos, string endpos)
{
	string startIdentity = *GetTilePointer(startpos);
	string endIdentity = *GetTilePointer(endpos);

	SetTile(" ", startpos);
	SetTile(startIdentity, endpos);
	bool doesThisScrewKing = isKingInCheck(currentPlayer);
	SetTile(startIdentity, startpos);
	SetTile(endIdentity, endpos);

	if (doesThisScrewKing)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::isCheckMate(bool currentPlayer)
{
	string identity;
	if (currentPlayer)
	{
		identity = "wK";
	}
	else
	{
		identity = "bK";
	}

	Player* player = GetPlayer(identity);

	bool kingChecked = isKingInCheck(currentPlayer);
	bool canKingMove = true;
	
	//need to return what piece is attacking, if kingChecked
	//need to check whether the attack path can be blocked and whether that 
	//

	if (kingChecked)
	{
		canKingMove = CanKingMove(player);
	}

	if (!canKingMove && kingChecked)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Board::isAttackedBelow(int startX, int startY, char playerColour)
{
	for (int y = startY; y < m_rows; y++)
	{
		string currentNotation = MakeNotation(startX, y);
		string currentIdentity = *GetTilePointer(currentNotation);

		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && y == startY + 1)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen || currentIdentity[1] == king)
			{
				return true;
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen)
			{
				return true;
			}
		}
	}

	return false;
}

bool Board::isAttackedAbove(int startX, int startY, char playerColour)
{
	for (int y = startY; y >= 0; y--)
	{
		string currentNotation = MakeNotation(startX, y);
		string currentIdentity = *GetTilePointer(currentNotation);

		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && y == startY - 1)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen || currentIdentity[1] == king)
			{
				return true;
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen)
			{
				return true;
			}
		}
	}

	return false;
}

bool Board::isAttackedRight(int startX, int startY, char playerColour)
{
	for (int x = startX; x < m_columns; x++)
	{
		string currentNotation = MakeNotation(x, startY);
		string currentIdentity = *GetTilePointer(currentNotation);

		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && x == startX + 1)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen || currentIdentity[1] == king)
			{
				return true;
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen)
			{
				return true;
			}
		}
	}

	return false;
}

bool Board::isAttackedLeft(int startX, int startY, char playerColour)
{
	for (int x = startX; x >= 0; x--)
	{
		string currentNotation = MakeNotation(x, startY);
		string currentIdentity = *GetTilePointer(currentNotation);

		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && x == startX - 1)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen || currentIdentity[1] == king)
			{
				return true;
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == rook || currentIdentity[1] == queen)
			{
				return true;
			}
		}
	}

	return false;
}

//
//
//
//
//
// all the for loops ahead are fucked, please fix them <3
// Try making a for loop with a while loop that checks both outcomes
// CHECK YOUR LOGIC IN POSITION, what happens when Bottom right hits a wall
// yeah definitely broken, luckily for you, it's the same logic so you "should" be able to fix it all in one
//
//

bool Board::isAttackedUpLeft(int startX, int startY, char playerColour)
{
	int x = startX;
	int y = startY;
	
	do
	{	
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && y == startY - 1 && x == startX - 1)
		{
			if (playerColour == white)
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king || currentIdentity[1] == pawn)
				{
					return true;
				}
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king)
				{
					return true;
				}
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
			{
				return true;
			}
		}	
		x--;
		y--;

	} while (y >= 0 && x >= 0);
	return false;
}


bool Board::isAttackedUpRight(int startX, int startY, char playerColour)
{
	int x = startX;
	int y = startY;
	do
	{
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && y == startY - 1 && x == startX + 1)
		{
			if (playerColour == white)
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king || currentIdentity[1] == pawn)
				{
					return true;
				}
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king)
				{
					return true;
				}
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
			{
				return true;
			}
		}
		x++;
		y--;
	} while (y >= 0 && x < m_columns);
	return false;
}

bool Board::isAttackedDownRight(int startX, int startY, char playerColour)
{
	int x = startX;
	int y = startY;
	do
	{
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && y == startY + 1 && x == startX + 1)
		{
			if (playerColour == black)
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king || currentIdentity[1] == pawn)
				{
					return true;
				}
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king)
				{
					return true;
				}
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
			{
				return true;
			}
		}
		x++;
		y++;
	}while (x < m_columns && y < m_rows);
	return false;
}

bool Board::isAttackedDownLeft(int startX, int startY, char playerColour)
{
	int x = startX;
	int y = startY;

	do
	{
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		if (currentIdentity[0] == playerColour && currentIdentity[1] != 'K')
		{
			return false;
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour && y == startY + 1 && x == startX - 1)
		{
			if (playerColour == black)
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king || currentIdentity[1] == pawn)
				{
					return true;
				}
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen || currentIdentity[1] == king)
				{
					return true;
				}
			}
		}
		else if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
			{
				return true;
			}
		}
		x--;
		y++;

	}while (x >= 0 && y < m_rows);
	
	return false;
}

bool Board::isAttackedByKnight(string position, char playerColour)
{
	//okay this is really cheeky but I'm going to just grab a knight and convince it that it's sitting
	//where the king is and then the possible moves will tell me where to look for a knight
	string resetKnightPos = WhitePlayer.Knights[0].pos.GetCoordinatesNotation();
	WhitePlayer.Knights[0].pos.SetPosition(position);
	vector<string> moves = WhitePlayer.Knights[0].PossibleMoves(position);

	for (int i = 0; i < moves.size(); i++)
	{
		string currentIdentity = *GetTilePointer(moves[i]);
		if (currentIdentity != " " && currentIdentity[0] != playerColour)
		{
			return true;
		}
	}
	return false;
}