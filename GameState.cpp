#include "GameState.h"

GameState::GameState()
{
	StateID = 0;
	DBColour = {15,15,15,225};
	bShouldDelete = false;
}

GameState::~GameState()
{
	for (vector<GameObject*>::iterator  GO = GameObjectStack.begin(); GO < GameObjectStack.end(); GO++)
	{
		delete* GO;
	}
	// it will clear the vector 
	vector<GameObject*>().swap(GameObjectStack);
}

void GameState::Update(float DeltaTime)
{
	for (vector<GameObject*>::iterator GO = GameObjectStack.begin(); GO < GameObjectStack.end(); GO++)
	{
		(*GO)->UpDateGameObject(DeltaTime, GameObjectStack);
	}
}

void GameState::Draw(SDL_Renderer* Renderer)
{
	SDL_SetRenderDrawColor(Renderer,DBColour.r, DBColour.g, DBColour.b, DBColour.a);

	SDL_RenderClear(Renderer);

	for (vector<GameObject*>::iterator GO = GameObjectStack.begin(); GO < GameObjectStack.end(); GO++)
	{
		(*GO)->Draw(Renderer);
	}

}

void GameState::ProcessInput(Input* UserInput)
{
	for (vector<GameObject*>::iterator GO = GameObjectStack.begin(); GO < GameObjectStack.end(); GO++)
	{
		(*GO)->ProcessInput(UserInput);
	}
}

void GameState::HandleGarbage()
{
	for (vector<GameObject*>::iterator GO = GameObjectStack.begin(); GO < GameObjectStack.end();)
	{
		if ((*GO)->ShouldDelete())
		{
			delete* GO;
			GO = GameObjectStack.erase(GO);
		}
		else
		{
			GO++;
		}

	} 
}

bool GameState::ShouldDelete()
{
	return bShouldDelete;
}

void GameState::DestroyGameState()
{
	bShouldDelete = true;
}
