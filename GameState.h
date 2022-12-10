#pragma once
#include "SDL.h"
#include"Input.h"
#include"GameObject.h"

class GameState
{
public:
	GameState();
	~GameState();

	virtual void Update(float DeltaTime);
	virtual void Draw(SDL_Renderer* Renderer);
	virtual void ProcessInput(Input* UserInput);
	virtual void HandleGarbage();


	virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
	{
		return true;
	}

	virtual bool OnExit()
	{
		return true;
	}

	// this id will help to identify the state 
	Uint32  StateID;

	SDL_Colour DBColour;

	bool ShouldDelete();

	void DestroyGameState();


protected:

	vector<GameObject*>GameObjectStack;

	bool bShouldDelete;
};

