#pragma once
#include "MenuState.h"
class MSGameOver :  public MenuState
{
	virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window) override;

	virtual void ProcessInput(Input* UserInput) override;

};

