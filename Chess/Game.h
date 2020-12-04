#pragma once
#include "Board.h"

static bool White = true;
static bool Black = false;

class Game
{

	Board ChessBoard{};
	bool isGameOver = false;
	bool currentPlayer;

public:

	Game();
	void SetUpGame();
	void GameLoop();
	void PlayTurn();
};