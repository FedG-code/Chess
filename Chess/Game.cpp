#include "Game.h"

using namespace std;

Game::Game()
{

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

		if (currentPlayer == White && !isGameOver)
		{
			currentPlayer = Black;
		}
		else if (currentPlayer == Black && !isGameOver)
		{
			currentPlayer = White;
		}
		ChessBoard.DrawBoard();
	}
	GameOver(currentPlayer);
}

void Game::PlayTurn()
{

	//to make a move choose the piece you want to move and it's end destination

	//check validity of chosen square first and then of destination
	string pieceSelectionAttempt;

	string pieceMoveAttempt;

	bool CheckKingAttackedEndTurn = false;
	do
	{
		isGameOver = ChessBoard.isCheckMate(currentPlayer);

		if (isGameOver)
		{
			return;
		}


		do
		{
			bool kingIsChecked = ChessBoard.isKingInCheck(currentPlayer);
			if (kingIsChecked)
			{
				cout << "Careful, your king is in check" << endl;
			}

			cout << "Please enter the tile of the piece you want to move or ff if you surrender: ";

			cin >> pieceSelectionAttempt;

			if (pieceSelectionAttempt == "ff")
			{
				isGameOver = true;
				return;
			}
			//string pieceIdentity = ChessBoard.GetTileIdentity(pieceSelectionAttempt);
			bool pieceSelectionSucess = ChessBoard.CheckGetPieceValid(currentPlayer, pieceSelectionAttempt);

			while (!pieceSelectionSucess)
			{
				cout << "That is not a piece you can move, try again: ";
				cin >> pieceSelectionAttempt;
				pieceSelectionSucess = ChessBoard.CheckGetPieceValid(currentPlayer, pieceSelectionAttempt);

				if (pieceSelectionAttempt == "ff")
				{
					isGameOver = true;
					return;
				}
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

			//needs something that checks where the king would be in check by the end of the turn 
			//check all cardinal directions, stop looking first piece you run into / when you reach board limit

		} while (pieceMoveAttempt == "back");
		
		CheckKingAttackedEndTurn = ChessBoard.wouldKingBeInCheck(currentPlayer, pieceSelectionAttempt, pieceMoveAttempt);


	
	} while (CheckKingAttackedEndTurn);
	ChessBoard.MovePiece(pieceSelectionAttempt, pieceMoveAttempt);

	//write a simple function that stores the identity of the location being moved to, makes the moves on the board, checks for check
	//and then returns pieces where they are
}

void Game::GameOver(bool currentPlayer)
{
	if (!currentPlayer)
	{
		cout << "White wins! Here are the pieces white ate this game:" << endl;
		vector<string> eatenPieces = ChessBoard.WhitePlayer.ReturnEatenPieces();

		for (int i = 0; i < eatenPieces.size(); i++)
		{
			cout << eatenPieces[i] << endl;
		}
	}
	else
	{
		cout << "Black wins! Here are the pieces black ate this game:" << endl;
		vector<string> eatenPieces = ChessBoard.BlackPlayer.ReturnEatenPieces();

		for (int i = 0; i < eatenPieces.size(); i++)
		{
			cout << eatenPieces[i] << endl;
		}
	}
}