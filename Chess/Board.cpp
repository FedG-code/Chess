#include "Board.h"
#include <Windows.h>

using namespace std;

Board::Board()
{
	m_PieceEatenCB = Player::PieceEaten;
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
		SetConsoleTextAttribute(console, kRegularColour);
		cout << " " << abs(7-i)+1 << endl;
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

	
	//should be it's own function called check viable coordinate
	bool notationValidity = CheckNotationValid(location);
	if (!notationValidity)
	{
		return false;
	}
	string identity = *GetTilePointer(location);

	if (identity == " ")
	{
		cout << "that's an empty tile" << endl;
		return false;
	}

	Player* selectedTilePlayer = GetPlayer(identity);
	Piece* piece = selectedTilePlayer->GetPiece(identity);
	bool isAlive = piece->GetIsAlive();

	if (!isAlive)
	{
		cout << "that piece has been eaten, how'd you even select it?" << endl;
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
		SetPiece(white_queen_0, MakeNotation(kQueenStartPos, row));
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
		SetPiece(black_queen_0, MakeNotation(kQueenStartPos, row));
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
	
	bool notationValidity = CheckNotationValid(endpos);
	if (!notationValidity)
	{
		return false;
	}
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
			moves = SortPawnOut(startpos, endpos);
		}

		else if(startIdentity[1] == king)
		{
			string castling = DoesKingWantToCastle(startpos, endpos);
			if (castling.size() == 0)
			{
				moves = piece->PossibleMoves(endpos);
			}
			else
			{
				bool castleValid = CanKingCastle(startpos, endpos);
				if (castleValid)
				{
					return true;
				}
				else
				{
					cout << "you can't castle like that now" << endl;
					return false;
				}
			}
		}
		else
		{
			moves = piece->PossibleMoves(endpos);
		}
		//check possible should be moved to inside the different piece classes so it can account for stuff like pawns
		bool possible = CheckPossible(moves, endpos);
		//bool possible = piece->CheckMoveAllowed(extraInfo, endpos)


		if (!possible)
		{
			cout << "The piece you selected can't move there" << endl;
			return false;
		}

		bool clearpath;

		if (startIdentity[1] == knight || startIdentity[1] == pawn || startIdentity[1] == king)
		{
			clearpath = true;
		}
		else
		{
			clearpath = CheckClearPath(moves, endpos);
		}



		if (!clearpath)
		{
			cout << "There's a piece in the way!" << endl;
			return false;
		}
		else
		{
			return true;
		}
		//probably add is checked logic here
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
	
	string castling = DoesKingWantToCastle(startpos, endpos);
	if (castling.size() != 0)
	{
		startPiece->pos.SetPosition(endpos);
		startPiece->HasIndeedMoved();
		SetTile(startIdentity, endpos);
		ClearTile(startpos);
		Piece* rook = startPlayer->GetPiece(castling);
		
		string rookStart = rook->pos.GetCoordinatesNotation();
		if (endpos == "c1")
		{
			SetTile(castling, "d1");
			rook->pos.SetPosition("d1");
		}
		else if (endpos == "g1")
		{
			SetTile(castling, "f1");
			rook->pos.SetPosition("f1");
		}
		else if (endpos == "c8")
		{
			SetTile(castling, "d8");
			rook->pos.SetPosition("d8");
		}
		else if (endpos == "g8")
		{
			SetTile(castling, "f8");
			rook->pos.SetPosition("f8");
		}
		else
		{
			//CASTLE ERROR
		}
		rook->HasIndeedMoved();
		ClearTile(rookStart);

		return;
	}

	
	if (endIdentity != " ")
	{
		Player* endPlayer = GetPlayer(endIdentity);
		Piece* endPiece = endPlayer->GetPiece(endIdentity);
		startPlayer->EatPiece(endPiece);
		(*m_PieceEatenCB)(startPlayer, startPiece, endPlayer, endPiece);
	}

	startPiece->pos.SetPosition(endpos);
	if (startPiece->GetHasMoved() == false)
	{
		startPiece->HasIndeedMoved();
	}
	SetTile(startIdentity, endpos);
	ClearTile(startpos);


	char playerColour = startPlayer->GetPlayerColour();
	int currentRow = CharToInt(endpos[1]);
	if (startIdentity[1] == pawn && playerColour == white && currentRow == 8)
	{
		Promotion(startPlayer, endpos);
	}
	else if (startIdentity[1] == pawn && playerColour == black && currentRow == 1)
	{
		Promotion(startPlayer, endpos);
	}
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

//should likely be boolian argument
bool Board::CanKingMove(bool currentPlayer)
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

	string location = player->King.pos.GetCoordinatesNotation();
	int startX = TranslateXFromNotation(location[0]);
	int startY = TranslateYFromNotation(location[1]);
	char kingColour = player->GetPlayerColour();
	//note that any string needs to be passed even if it isn't used
	vector<string> moves = player->King.PossibleMoves(location);
	vector<string> attackedInfo;
	
	int blockedCounter = 0;
	int numberOfPossibleMoves = moves.size();
	for (int i = 0; i < moves.size(); i++)
	{
		string currentTile = moves[i];
		string currentTileIdentity = *GetTilePointer(currentTile);
		char currentTileColour = currentTileIdentity[0];
		
		vector < string > tileAttackedVector = IsTileAttacked(currentPlayer, currentTile, attacked);

		bool isCurrentTileAttacked;
		

		if (tileAttackedVector.size() != 0)
		{
			isCurrentTileAttacked = true;
		}
		else
		{
			isCurrentTileAttacked = false;
		}

		bool isKingChecked = wouldKingBeInCheck(currentPlayer, location, moves[i]);

		if (currentTileIdentity == " " || currentTileColour != kingColour)
		{
			//if (isCurrentTileAttacked)
			//{
			//	blockedCounter++;
			//}
			//else 
			if(isKingChecked)
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
	
		vector < string > tileAttackedVector = IsTileAttacked(currentPlayer, kingLocation, attacked);

	if (tileAttackedVector.size() != 0)
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
	Piece* piece = GetPieceFromLocation(startpos);

	SetTile(" ", startpos);
	SetTile(startIdentity, endpos);
	piece->pos.SetPosition(endpos);
	bool doesThisScrewKing = isKingInCheck(currentPlayer);
	SetTile(startIdentity, startpos);
	SetTile(endIdentity, endpos);
	piece->pos.SetPosition(startpos);

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
	string kingPos = player->King.pos.GetCoordinatesNotation();

	bool kingChecked = isKingInCheck(currentPlayer);
	bool canKingMove = true;
	
	//need to return what piece is attacking, if kingChecked
	//need to check whether the attack path can be blocked and whether that 
	
	//for the canAttackBeBlocked I need to have all the tiles in between the attack
	//however when I then get what those tiles are I need to know what's attacking those very tiles
	//then perform a test to see if those pieces can be blocked

	//I need a function that 

	vector<string> attackInfo = IsTileAttacked(currentPlayer, kingPos, attacked);

	int attackNumber = NumberOfAttacks(attackInfo);

	if (kingChecked)
	{
		canKingMove = CanKingMove(currentPlayer);
		if (canKingMove)
		{
			return false;
		}
		else
		{
			//if attacked twice then true
			if (attackNumber >= 2)
			{
				return true;
			}
			else
			{	
				if (GetMeOneAttackerID(attackInfo) == knight)
				{
					string attackerPos = GetMeOneAttackerPos(attackInfo);
					bool killAttempt = CanIKill(currentPlayer, attackerPos);

					if (killAttempt)
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				//else check if the final piece can be killed or blocked
				//if not it's a win for the other team
				string attackerPos = GetMeOneAttackerPos(attackInfo);
				bool killAttempt = CanIKill(currentPlayer, attackerPos);
			
				if (killAttempt)
				{
					return false;
				}
					
				bool blockAttempt = CanIBlock(currentPlayer, attackInfo);

				if (blockAttempt)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	//canAttackBeBlocked
	//canAttackBeKilled
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

vector<string> Board::IsTileAttacked(bool currentPlayer, string position, bool attackedOrBlockable)
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
	//set out in all cardinal directions and find whether there's any pieces
	//you can stop the second a piece is there, check the colour, check the identity, determine whether attacking
	//add knight moves as well
	char playerColour = player->GetPlayerColour();

	int startX = TranslateXFromNotation(position[0]);
	int startY = TranslateYFromNotation(position[1]);
	//make versions of above and below that include pawn position checks
	//pass a boolean through here called attacked or blocked

	//I need a counter of how many attacks are coming in

	vector<string> attackInfo;

	vector<string> above;
	if (attackedOrBlockable == attacked)
	{
		above = isAttackedAbove(startX, startY, playerColour);
	}
	else
	{
		above = isBlockableAbove(startX, startY, playerColour);
	}

	attackInfo.insert(attackInfo.end(), above.begin(), above.end());
	//isBlockable needs 
	vector<string> below;

	if (attackedOrBlockable == attacked)
	{
		below = isAttackedBelow(startX, startY, playerColour);
	}
	else
	{
		below = isBlockableBelow(startX, startY, playerColour);
	}

	attackInfo.insert(attackInfo.end(), below.begin(), below.end());

	//make a blockable variant for each of these
	vector<string> left = isAttackedLeft(startX, startY, playerColour, attackedOrBlockable);
	attackInfo.insert(attackInfo.end(), left.begin(), left.end());

	vector<string> right = isAttackedRight(startX, startY, playerColour, attackedOrBlockable);
	attackInfo.insert(attackInfo.end(), right.begin(), right.end());

	vector<string> upright = isAttackedUpRight(startX, startY, playerColour, attackedOrBlockable);
	attackInfo.insert(attackInfo.end(), upright.begin(), upright.end());

	vector<string> upleft = isAttackedUpLeft(startX, startY, playerColour, attackedOrBlockable);
	attackInfo.insert(attackInfo.end(), upleft.begin(), upleft.end());

	//here
	vector<string> downright = isAttackedDownRight(startX, startY, playerColour, attackedOrBlockable);
	attackInfo.insert(attackInfo.end(), downright.begin(), downright.end());

	vector<string> downleft = isAttackedDownLeft(startX, startY, playerColour, attackedOrBlockable);
	attackInfo.insert(attackInfo.end(), downleft.begin(), downleft.end());

	vector<string> knight = isAttackedByKnight(position, playerColour);
	attackInfo.insert(attackInfo.end(), knight.begin(), knight.end());
	
	return attackInfo;
}

int Board::NumberOfAttacks(vector<string> attackInfo)
{

	int number = 0;
	for (int i = 0; i < attackInfo.size(); i++)
	{
		string currentString = attackInfo[i];
		if (currentString.size() == 3)
		{
			number++;
		}
		else if (currentString.size() == 2)
		{
			if (currentString[1] == king)
			{
				number++;
			}
		}
	}

	return number;
}

char Board::GetMeOneAttackerID(vector<string> attackInfo)
{
	char attacker = ' ';

	for (int i = 0; i < attackInfo.size(); i++)
	{
		string currentString = attackInfo[i];
		if (currentString.size() == 3)
		{
			attacker = currentString[1];
		}
		else if (currentString.size() == 2)
		{
			if (currentString[1] == king)
			{
				attacker = currentString[1];
			}
		}
	}

	return attacker;
}

string Board::GetMeOneAttackerPos(vector<string> attackInfo)
{
	int stringSize = attackInfo.size();
	int attackerLocation = stringSize - 2;

	return attackInfo[attackerLocation];
}

vector<string> Board::GetMeAllAttackerPos(vector<string> attackInfo)
{
	vector<string> posList;
	for (int i = 0; i < attackInfo.size(); i++)
	{
		string currentString = attackInfo[i];
		if (currentString.size() == 3)
		{
			//this is the where the location of the attacking piece is
			int posIndex = i - 1;
			posList.push_back(attackInfo[posIndex]);
		}
	}

	return posList;
}

vector<string> Board::GetMePathToBlock(vector<string> attackInfo)
{
	vector<string> posList;
	//exclude the last two strings from block path as they're the position of the attacking piece
	//and the attacking piece
	for (int i = 0; i < attackInfo.size() - 2; i++)
	{
		string currentString = attackInfo[i];
		if (currentString.size() == 2)
		{
			
			posList.push_back(attackInfo[i]);
		}
	}

	return posList;
}

bool Board::CanIKill(bool currentPlayer, string attackerPos)

{
	vector<string> killAttempt = IsTileAttacked(!currentPlayer, attackerPos, attacked);

	if (killAttempt.size() == 0)
	{
		return false;
	}
	else
	{
		vector<string> unitsThatCanKillPos = GetMeAllAttackerPos(killAttempt);
		for (int i = 0; i < unitsThatCanKillPos.size(); i++)
		{
			bool failure = wouldKingBeInCheck(currentPlayer, unitsThatCanKillPos[i], attackerPos);
			if (!failure)
			{
				return true;
			}
		}
	}

	return false;  
}

bool Board::CanIBlock(bool currentPlayer, vector<string> attackerInfo)
{
	vector<string> pathToBlock = GetMePathToBlock(attackerInfo);

	for (int i = 0; i < pathToBlock.size(); i++)
	{
		vector<string> isTileBlockable = IsTileAttacked(!currentPlayer, pathToBlock[i], blockable);
		if (isTileBlockable.size() != 0)
		{
			vector<string> myBlockers = GetMeAllAttackerPos(isTileBlockable);
			for (int j = 0; j < myBlockers.size(); j++)
			{
				bool failure = wouldKingBeInCheck(currentPlayer, myBlockers[j], pathToBlock[i]);
				if (!failure)
				{
					return true;
				}
			}
		}
	}

	return false;
}


void Board::Promotion(Player* player, string location)
{
	Piece* piece = GetPieceFromLocation(location);
	piece->SetEaten();
	SetTile(" ", location);
	player->MakeQueen(location);
	int index = player->Queens.size() - 1;
	string id = player->Queens[index].GetIdentity();
	SetTile(id, location);  
}

string Board::DoesKingWantToCastle(string startpos, string endpos)
{
	Piece* piece = GetPieceFromLocation(startpos);
	string id = piece->GetIdentity();
	char colour = id[0];
	
	
	if (colour == white)
	{
		if (endpos == "c1") 
		{
			return "wr0";
		}
		else if (endpos == "g1")
		{
			return "wr1";
		}
	}
	else
	{
		if (endpos == "c8")
		{
			return "br0";
		}
		else if (endpos == "g8")
		{
			return "br1";
		}
	}
	return "";
}

bool Board::AreCastlingSquaresEmpty(string startpos, string endpos)
{
	string square1;
	string square2;
	string square3 = " ";
	if (startpos == "e1" && endpos == "c1")
	{
		square1 = GetTileIdentity("d1");
		square2 = GetTileIdentity(endpos);
		square3 = GetTileIdentity("b1");
		if (square1 != " " || square2 != " " || square3 != " ")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (startpos == "e1" && endpos == "g1")
	{
		square1 = GetTileIdentity("f1");
		square2 = GetTileIdentity(endpos);
		if (square1 != " " || square2 != " " || square3 != " ")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (startpos == "e8" && endpos == "c8")
	{
		square1 = GetTileIdentity("d8");
		square2 = GetTileIdentity(endpos);
		square3 = GetTileIdentity("b8");
		if (square1 != " " || square2 != " " || square3 != " ")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (startpos == "e8" && endpos == "g8")
	{
		square1 = GetTileIdentity("f8");
		square2 = GetTileIdentity(endpos);
		if (square1 != " " || square2 != " ")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
bool Board::CanKingCastle(string startpos, string endpos)
{
	Piece* king = GetPieceFromLocation(startpos);
	string id = king->GetIdentity();
	Player* player = GetPlayer(id);
	bool currentPlayer;
	char colour = player->GetPlayerColour();
	if (colour == white)
	{
		currentPlayer = true;
	}
	else
	{
		currentPlayer = false;
	}
	bool clearPath = AreCastlingSquaresEmpty(startpos, endpos);
	if (!clearPath)
	{
		return false;
	}
	bool check = isKingInCheck(currentPlayer);
	if (check)
	{
		return false;
	}
	bool kingMoved = king->GetHasMoved();
	if (kingMoved)
	{
		return false;
	}
	char castleDirection = endpos[0];
	string middleSquare;
	Piece* rook;

	if (castleDirection == 'c')
	{
		if (colour == white)
		{
			rook = player->GetPiece("wr0");
			middleSquare = "d1";
		}
		else
		{
			rook = player->GetPiece("br0");
			middleSquare = "d8";
		}
	}
	else if (castleDirection == 'g')
	{
		if (colour == white)
		{
			rook = player->GetPiece("wr1");
			middleSquare = "f1"; 
		}
		else
		{
			rook = player->GetPiece("br1");
			middleSquare = "f8";
		}
	}
	else
	{
		//CASTLE ERROR
		rook = nullptr;
	}

	bool rookMoved = rook->GetHasMoved();
	if (rookMoved)
	{
		return false;
	}

	vector <string> middleAttacked = IsTileAttacked(currentPlayer, middleSquare, attacked);
	if (middleAttacked.size() != 0)
	{
		return false;
	}

	vector <string> endAttacked = IsTileAttacked(currentPlayer, endpos, attacked);
	if (endAttacked.size() != 0)
	{
		return false;
	}

	return true;
}




















vector<string> Board::isAttackedBelow(int startX, int startY, char playerColour)
{
	vector<string> attackInfo;
	for (int y = startY + 1; y < m_rows; y++)
	{
		string currentNotation = MakeNotation(startX, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);
		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (y == startY + 1 && currentIdentity[1] == king)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else
			{
				if (currentIdentity[1] == rook || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
	}
	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isBlockableBelow(int startX, int startY, char playerColour)
{
	vector<string> attackInfo;
	for (int y = startY + 1; y < m_rows; y++)
	{
		string currentNotation = MakeNotation(startX, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);
		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (playerColour == black && currentIdentity[1] == pawn)
			{
				if (y == startY + 1)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else if (y == startY + 2 && y == 7)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
			}
			else
			{
				if (currentIdentity[1] == rook || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
	}

	attackInfo.clear();
	return attackInfo;
	//attackInfo.clear();
	//return attackInfo;
}

vector<string> Board::isAttackedAbove(int startX, int startY, char playerColour)
{
	vector<string> attackInfo;
	for (int y = startY - 1; y >= 0; y--)
	{
		string currentNotation = MakeNotation(startX, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);

		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (y == startY - 1 && currentIdentity[1] == king)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else
			{
				if (currentIdentity[1] == rook || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
	}
	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isBlockableAbove(int startX, int startY, char playerColour)
{
	vector<string> attackInfo;
	for (int y = startY - 1; y >= 0; y--)
	{
		string currentNotation = MakeNotation(startX, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);
		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (playerColour == white && currentIdentity[1] == pawn)
			{
				if (y == startY - 1)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else if (y == startY - 2 && y == 1)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
			}
			else
			{
				if (currentIdentity[1] == rook || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
	}

	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isAttackedRight(int startX, int startY, char playerColour, bool attackedOrBlocked)
{
	vector<string> attackInfo;
	for (int x = startX + 1; x < m_columns; x++)
	{
		string currentNotation = MakeNotation(x, startY);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);
		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (x == startX + 1 && currentIdentity[1] == king && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else
			{
				if (currentIdentity[1] == rook || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
	}
	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isAttackedLeft(int startX, int startY, char playerColour, bool attackedOrBlocked)
{
	vector<string> attackInfo;
	for (int x = startX - 1; x >= 0; x--)
	{
		string currentNotation = MakeNotation(x, startY);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);

		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (x == startX - 1 && currentIdentity[1] == king  && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else
			{
				if (currentIdentity[1] == rook || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
	}

	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isAttackedUpLeft(int startX, int startY, char playerColour, bool attackedOrBlocked)
{
	int x = startX - 1;
	int y = startY - 1;
	vector<string> attackInfo;
	while (y >= 0 && x >= 0)
	{	
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);

		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (y == startY - 1 && x == startX - 1 && playerColour == white && currentIdentity[1] == pawn && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else if (y == startY - 1 && x == startX - 1 && currentIdentity[1] == king && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
		x--;
		y--;

	}

	attackInfo.clear();
	return attackInfo;
}


vector<string> Board::isAttackedUpRight(int startX, int startY, char playerColour, bool attackedOrBlocked)
{
	int x = startX + 1;
	int y = startY - 1;
	vector<string> attackInfo;
	while (y >= 0 && x < m_columns)
	{
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);

		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (y == startY - 1 && x == startX + 1 && playerColour == white && currentIdentity[1] == pawn && attackedOrBlocked == attacked)
			{

				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else if(y == startY - 1 && x == startX + 1 && currentIdentity[1] == king && attackedOrBlocked == attacked)
			{
						attackInfo.push_back(currentIdentity);
						return attackInfo;
			}	
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
		x++;
		y--;

	}

	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isAttackedDownRight(int startX, int startY, char playerColour, bool attackedOrBlocked)
{
	int x = startX + 1;
	int y = startY + 1;
	vector<string> attackInfo;
	while (x < m_columns && y < m_rows)
	{
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);


		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (y == startY + 1 && x == startX + 1 && playerColour == black && currentIdentity[1] == pawn && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
		
			}
			else if (y == startY + 1 && x == startX + 1 && currentIdentity[1] == king && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;			
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
		x++;
		y++;

	}

	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isAttackedDownLeft(int startX, int startY, char playerColour, bool attackedOrBlocked)
{
	int x = startX - 1;
	int y = startY + 1;
	vector<string> attackInfo;

	while (x >= 0 && y < m_rows)
	{
		string currentNotation = MakeNotation(x, y);
		string currentIdentity = *GetTilePointer(currentNotation);
		attackInfo.push_back(currentNotation);

		if (currentIdentity != " ")
		{
			if (currentIdentity[0] == playerColour)
			{
				attackInfo.clear();
				return attackInfo;
			}
			else if (y == startY + 1 && x == startX - 1 && playerColour == black && currentIdentity[1] == pawn && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else if (y == startY + 1 && x == startX - 1 && currentIdentity[1] == king && attackedOrBlocked == attacked)
			{
				attackInfo.push_back(currentIdentity);
				return attackInfo;
			}
			else
			{
				if (currentIdentity[1] == bishop || currentIdentity[1] == queen)
				{
					attackInfo.push_back(currentIdentity);
					return attackInfo;
				}
				else
				{
					attackInfo.clear();
					return attackInfo;
				}
			}
		}
		x--;
		y++;

	}
	
	attackInfo.clear();
	return attackInfo;
}

vector<string> Board::isAttackedByKnight(string position, char playerColour)
{
	//okay this is really cheeky but I'm going to just grab a knight and convince it that it's sitting
	//where the king is and then the possible moves will tell me where to look for a knight
	string resetKnightPos = WhitePlayer.Knights[0].pos.GetCoordinatesNotation();
	WhitePlayer.Knights[0].pos.SetPosition(position);
	vector<string> moves = WhitePlayer.Knights[0].PossibleMoves(position);
	WhitePlayer.Knights[0].pos.SetPosition(resetKnightPos);

	vector<string> attackInfo;
	for (int i = 0; i < moves.size(); i++)
	{
		string currentIdentity = *GetTilePointer(moves[i]);
		if (currentIdentity[0] != playerColour && currentIdentity[1] == knight)
		{
			attackInfo.push_back(moves[i]);
			attackInfo.push_back(currentIdentity);
		}
	}
	return attackInfo;
}

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
		
		char diag1Colour = ' ';
		if (pawnDiag1X >= 0 && pawnDiag1X <= 7)
		{
			string diag1Identity = GetTileIdentity(diag1Notation);
			diag1Colour = diag1Identity[0];
		}

		char diag2Colour = ' ';
		if (pawnDiag2X >= 0 && pawnDiag2X <= 7)
		{
			string diag2Identity = GetTileIdentity(diag2Notation);
			diag2Colour = diag2Identity[0];
		}
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
		
		char diag1Colour = ' '; 
		if (pawnDiag1X >= 0 && pawnDiag1X <= 7)
		{
		string diag1Identity = GetTileIdentity(diag1Notation);
		diag1Colour	= diag1Identity[0];
		}
	
		char diag2Colour = ' ';
		if (pawnDiag2X >= 0 && pawnDiag2X <= 7)
		{
			string diag2Identity = GetTileIdentity(diag2Notation);
			diag2Colour = diag2Identity[0];
		}
		
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