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
	string identity = *GetTilePointer(startpos);
	Player* currentPlayer = GetPlayer(identity);
	Piece* piece = currentPlayer->GetPiece(identity);

	if (piece)
	{
		bool hasmoved = piece->GetHasMoved();
		vector<string> moves = piece->PossibleMoves(hasmoved, endpos);
		//check possible should be moved to inside the different piece classes so it can account for stuff like pawns
		bool possible = CheckPossible(moves, endpos);
		bool clearpath = true;

		if (identity[1] != knight)
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
