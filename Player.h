#pragma once
#include "Character.h"
#include "Vector2.h"
#include "SDL_mixer.h"


class Player : public Character
{
public:

	Player(Texture* CharacterTexture, Vector2 Pos, int NumberofFrames = 1);
	~Player();


	void Update(float DeltaTime)override;
	void ProcessInput(Input* UserInput)override;
	//void Draw(SDL_Renderer* Renderer)override;
};

