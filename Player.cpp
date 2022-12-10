#include "Player.h"
#include "SDL.h"
#include "Game.h"
#include "Texture.h"
 
 
 

Player::Player(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
 :Character::Character(CharacterTexture, Pos, NumberOfFrames)
{
	Tag = "Player";
	MaxSpeed = 500.0f;
	AnimationStates = playerStates::idle;
}

Player::~Player()
{
}

void Player::Draw(SDL_Renderer* Renderer)
{
	GameObject::Draw(Renderer);

	Animation* PlayerAnimation = nullptr;

	switch (AnimationStates) {
	case playerStates::idle:
		PlayerAnimation = PlayerAnims.idle;
		break;

	case playerStates::run:
		PlayerAnimation = PlayerAnims.run;
		break;

	case playerStates::attack:
		PlayerAnimation = PlayerAnims.attack;
		break;

	case playerStates::die:
		PlayerAnimation = PlayerAnims.die;
		break;

	case playerStates::jump:
		PlayerAnimation = PlayerAnims.jump;
		break;
	}

	if (!Flip) {
		PlayerAnimation->Draw(Renderer, Position);
	}
	else {
		PlayerAnimation->Draw(Renderer, Position, 1, Flip = true);
	}
}

void Player::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	if (Velocity.Length() > 0) {
		AnimationStates = playerStates::run;
	}
	else {
		AnimationStates = playerStates::idle;
	}

	if (Attack) {
		AnimationStates = playerStates::attack;
		Attack = false;
	}
}

void Player::ProcessInput(Input* UserInput)
{
	float MovementX = 0.0f;
	float MovementY = 0.0f;
	float Speed = 2000.0f;

	if (UserInput->IsKeyDown(SDL_SCANCODE_W))
	{
		MovementY = -1.0f;
	}
	if (UserInput->IsKeyDown(SDL_SCANCODE_S))
	{
		MovementY = 1.0f;
	}

	if (UserInput->IsKeyDown(SDL_SCANCODE_A))
	{
		MovementX = -1.0f;
		Flip = true;
	}

	if (UserInput->IsKeyDown(SDL_SCANCODE_D))
	{
		MovementX = 1.0f;
		Flip = false;
	}


	AddForce(Speed, Vector2(MovementX, MovementY));



	// store the colliders overlapping over colliders 

	vector<Collider*> OtherColliders = GetCollisions()[0]->GetOverlappingColliders();

	if (UserInput->IsKeyDown(SDL_SCANCODE_SPACE))
	{
		Attack = true;

		//run through all the colliders we're overlapping
		for (unsigned int i = 0; i < OtherColliders.size(); ++i) {
			if (OtherColliders[i]->GetOwner()->Tag == "Enemy") {
				SDL_Log("Collider detected, Enemy: Ouch!");
				OtherColliders[i]->GetOwner()->DestroyGameObject();
			}

		}
	}

	//this will run through all the colliders overlapping each frame
	for (vector<Collider*>::iterator it = OtherColliders.begin(); it < OtherColliders.end(); ++it) {
		if ((*it)->GetOwner()->Tag == "Orb") {
			SDL_Log("Orb collected");
			(*it)->GetOwner()->DestroyGameObject();
		}
 	}
}
