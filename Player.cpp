#include "Player.h"
#include "SDL.h"
#include "Game.h"
#include "Texture.h"
 
 
 

Player::Player(Texture* CharacterTexture, Vector2 Pos, int NumberofFrames)
 :Character::Character(CharacterTexture,Pos, NumberofFrames)
{
	Tag = "Player";
	MaxSpeed = 500.0f;
 
}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
	Character::Update(DeltaTime);
}
// we tried to over ride this metho to increase the player size 
/* void Draw(SDL_Renderer* Renderer)
{
	GameObject::Draw(Renderer);

	SDL_Rect Clip;
	Clip.x = 0;
	Clip.y = 0;
	Clip.h = ObjectTexture->GetImageHeight();
	Clip.w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberofFrames);


	ObjectTexture->Draw(Renderer, Position, &Clip, 1.6);
}*/

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
	}

	if (UserInput->IsKeyDown(SDL_SCANCODE_D))
	{
		MovementX = 1.0f;
	}


	AddForce(Speed, Vector2(MovementX, MovementY));



	// store the colliders overlapping over colliders 

	vector<Collider*> OtherColiders = GetCollisions()[0]->GetOverlappingColliders();

	if (UserInput->IsKeyDown(SDL_SCANCODE_SPACE))
	{
 		for ( unsigned int i = 0 ; i <OtherColiders.size(); ++i)
		{
			if (OtherColiders[i]->GetOwner()->Tag == "Enemy")
			{

				 

				OtherColiders[i]->GetOwner()->DestroyGameObject();

			}

 		}

 	}


	for ( vector<Collider*>::iterator it = OtherColiders.begin(); it < OtherColiders.end(); ++it)
	{
		if ((*it)->GetOwner()->Tag =="Enemy")
		{
			Game::GetGameInstance()->Score += 100;
			(*it)->GetOwner()->DestroyGameObject();
		}
	}


  

}
