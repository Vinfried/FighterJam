

#include<iostream>
#include "Character.h"
#include "SDL.h"
#include "Vector2.h"

using namespace std;


Character::Character(Texture *CharacterTexture, Vector2 Pos,   int NumberofFrames)
{
	Position = Pos;
	ObjectCenter = Position;

	ObjectTexture = CharacterTexture;
	this->NumberOfFrames = NumberofFrames;
	Velocity = Vector2().Zero();
	MovementAxis = Vector2().Zero();
	MaxSpeed = 100.0f;
	Drag = 0.90f;
	float w = 10.0f;
	float h = 10.0f;


	if (ObjectTexture != nullptr)
	{
		w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberofFrames);
		h = ObjectTexture->GetImageHeight();
		
		w /= 2;
		h /= 2;
	}


	SetCollision(ObjectCenter, Vector2(w,h));


}

 
void Character::Draw(SDL_Renderer* Renderer)
{
	GameObject::Draw(Renderer);

	SDL_Rect Clip;
	Clip.x = 0;
	Clip.y = 0;
	Clip.h = ObjectTexture->GetImageHeight();
	Clip.w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);


	ObjectTexture->Draw(Renderer, Position, &Clip);

}

void Character::Update(float DeltaTime)
{
	// this will make sure that the gameobject code runs first 

	GameObject::Update(DeltaTime);

	Velocity += Acceleration * DeltaTime;

	if(Velocity.Length() > MaxSpeed)
	{
		Velocity = Velocity.Normalised() * MaxSpeed;
	}

	Position += Velocity * DeltaTime;
	Acceleration = Vector2().Zero();
	Velocity *= Drag;

}

void Character::AddForce(float Force, Vector2 Direction)
{

	Acceleration += Direction.Normalised() * Force;
}
 

void Character::SetMovementAxis(Vector2 Axis)
{

	MovementAxis = Axis;
}

Vector2 Character::GetMovementAxis()
{
	return MovementAxis;
}
