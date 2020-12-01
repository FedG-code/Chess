#include "Game.h"

int main()
{
	Game newGame;
	newGame.SetUpGame();
	newGame.GameLoop();
}


//main problem atm, the coordinates are slightly wrong, currently it's like white and black are swapped and either
//of the axes is off



// Don't look at this just file testing

//position class test
//
// Position pos;
//pos.SetPosition("b4");
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;
//pos.Bump(Up);
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;
//pos.Bump(Up);
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;
//pos.Bump(Down);
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;
//pos.Bump(Right);
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;
//pos.Bump(Left);
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;
//pos.Bump(Right);
//cout << pos.GetCoordinatesNotation() << " " << pos.GetX() << " " << pos.GetY() << endl;

//Player Class Test
//Player WhitePlayer{ white };
//Player BlackPlayer{ black };
//WhitePlayer.TeamSetup();
//BlackPlayer.TeamSetup();
//
//for (int i = 0; i < 8; i++)
//{
//	string whitepawns = WhitePlayer.Pawns[i].GetIdentity();
//	string blackpawns = BlackPlayer.Pawns[i].GetIdentity();
//	cout << whitepawns << " " << blackpawns << endl;
//}
//
//for (int i = 0; i < 2; i++)
//{
//	string whitebishops = WhitePlayer.Bishops[i].GetIdentity();
//	string blackbishops = BlackPlayer.Bishops[i].GetIdentity();
//	cout << whitebishops << " " << blackbishops << endl;
//}
//
//for (int i = 0; i < 2; i++)
//{
//	string whiteknights = WhitePlayer.Knights[i].GetIdentity();
//	string blackknights = BlackPlayer.Knights[i].GetIdentity();
//	cout << whiteknights << " " << blackknights << endl;
//}
//
//for (int i = 0; i < 2; i++)
//{
//	string whiterooks = WhitePlayer.Rooks[i].GetIdentity();
//	string blackrooks = BlackPlayer.Rooks[i].GetIdentity();
//	cout << whiterooks << " " << blackrooks << endl;
//}
//
//string whitequeen = WhitePlayer.Queen.GetIdentity();
//string blackqueen = BlackPlayer.Queen.GetIdentity();
//
//cout << whitequeen << " " << blackqueen << endl;
//string whiteking = WhitePlayer.King.GetIdentity();
//string blackking = BlackPlayer.King.GetIdentity();
//
//cout << whiteking << " " << blackking << endl;

//Board Class Test
	//Board chessBoard;
	//chessBoard.DrawBoard();
	//chessBoard.EmptyBoard();


	//chessBoard.BoardArray[0][0] = " ";
	////cout << chessBoard.BoardArray[0][0] << endl;
	////Position pos;
	//string firstnotation = MakeNotation(0, 0);
	////cout << firstnotation << endl;
	////chessBoard.SetTile("wp0", "a1");
	////chessBoard.SetPawn(white_pawn_0, firstnotation);
	//chessBoard.PawnRow(white, kWhitePawnRow);
	//chessBoard.PawnRow(black, kBlackPawnRow);
	//chessBoard.DrawBoard();


//Game Class Tests
//Game newGame;
//
//newGame.SetUpGame();