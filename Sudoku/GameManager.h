#include "Utilities.h"
#include "CommandInvoker.h"
#include "Grid.h"

#ifndef GAME_MANAGER
#define GAME_MANAGER

class GameManager
{
private:
	GameState gameState;

public:
	GameState GetGameState();
	void SetGameState(GameState gameState);
};
#endif GAME_MANAGER
