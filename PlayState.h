#pragma once
#include "GameState.h"
#include "Player.h"
#include "Text.h"
#include "SDL_mixer.h"
#include "Texture.h"

class PlayState : public GameState
{

public:
	PlayState();

	virtual void Update(float DeltaTime)  override;
	 
	virtual void Draw(SDL_Renderer* Renderer) override;
	 
	virtual void ProcessInput(Input* UserInput) override
	{
		GameState::ProcessInput(UserInput);
	}

	virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window) override;


	virtual bool OnExit() override;

protected:

	Player* PChar;

	Text* TXT_PPosition;

	Text* TXT_Score;

	Mix_Music* Music_BG;

};

