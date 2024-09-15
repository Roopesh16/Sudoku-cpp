#include "GameManager.h"

GameState GameManager::GetGameState() { return gameState; }

void GameManager::SetGameState(GameState gameState)
{
	this->gameState = gameState;
}