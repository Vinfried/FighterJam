#pragma once
#include "Character.h"
#include "Vector2.h"
#include "SDL_mixer.h"
#include "Animation.h"

enum class playerStates
{
	idle,
	run,
	attack,
	die,
	jump
};

class Player : public Character
{
public:

	Player(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames = 1);
	~Player();

	void Draw(SDL_Renderer* Renderer) override;
	void Update(float DeltaTime)override;
	void ProcessInput(Input* UserInput)override;
	bool Flip = false;
	bool Attack = false;
	CharacterAnimations PlayerAnims;
	playerStates AnimationStates;
};

