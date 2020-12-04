#include "Game.h"

using namespace std;

Game::Game()
{
	bool currentPlayer = White;
}

void Game::SetUpGame()
{
	ChessBoard.SetUpBoard();
	ChessBoard.DrawBoard();
}

void Game::GameLoop()
{
	while (!isGameOver)
	{
		//Who's turn is it? Make a member variable 

		if (currentPlayer == White)
		{
			cout << "White, it's your turn. " << endl;
		}
		else if (currentPlayer == Black)
		{
			cout << "Black, it's your turn. " << endl;
		}

		PlayTurn();
		//give player vector which stores eaten pieces


		//switch turn

		//currentPlayer bool which is switch at the very end of the loop

		if (currentPlayer == White)
		{
			currentPlayer = Black;
		}
		else if (currentPlayer == Black)
		{
			currentPlayer = White;
		}
		ChessBoard.DrawBoard();
	}
}

void Game::PlayTurn()
{

	//to make a move choose the piece you want to move and it's end destination

	//check validity of chosen square first and then of destination
	string pieceSelectionAttempt;

	string pieceMoveAttempt;

	do
	{
		cout << "Please enter the tile of the piece you want to move: ";

		cin >> pieceSelectionAttempt;


		//string pieceIdentity = ChessBoard.GetTileIdentity(pieceSelectionAttempt);
		bool pieceSelectionSucess = ChessBoard.CheckGetPieceValid(currentPlayer, pieceSelectionAttempt);

		while (!pieceSelectionSucess)
		{
			cout << "That is not a piece you can move, try again: ";
			cin >> pieceSelectionAttempt;
			pieceSelectionSucess = ChessBoard.CheckGetPieceValid(currentPlayer, pieceSelectionAttempt);
		}

		//should return the type of piece it is (for debugging the whole string) and highlight it

		cout << *ChessBoard.GetTilePointer(pieceSelectionAttempt) << endl;


		cout << "Please enter the tile you want to move to, or back to change piece: ";

		cin >> pieceMoveAttempt;


		bool pieceMoveSuccess;

		pieceMoveSuccess = ChessBoard.CanPieceMove(pieceSelectionAttempt, pieceMoveAttempt);

		while (!pieceMoveSuccess)
		{
			cout << "You cannot move the selected piece to that square." << endl;
			cout << "Please select a legal square or write back to pick a new piece: ";
			cin >> pieceMoveAttempt;

			pieceMoveSuccess = ChessBoard.CanPieceMove(pieceSelectionAttempt, pieceMoveAttempt);
		}

	} while (pieceMoveAttempt == "back");

	ChessBoard.MovePiece(pieceSelectionAttempt, pieceMoveAttempt);
}