#include "Collectible.h"
#include "SDL.h"
#include <iostream>
#include "Vector2.h"

Collectible::Collectible(Texture* CollectibleTexture, Vector2 pos, int NumberOfFrames)
{
	Position = pos;
	ObjectCenter = pos;
	ObjectTexture = CollectibleTexture;
	this->NumberOfFrames = NumberOfFrames;
	float w = 10.0f;
	float h = 10.0f;

	//if we have a texture then update the width and height based on the texture
	if (ObjectTexture != nullptr) {
		w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);
		h = ObjectTexture->GetImageHeight();

		w /= 2;
		h /= 2;
	}
	SetCollision(ObjectCenter, Vector2(w, h));
}

Collectible::~Collectible()
{
}

void Collectible::Draw(SDL_Renderer* Renderer)
{
	SDL_Rect clip;
	clip.x = 0;
	clip.y = 0;
	clip.h = ObjectTexture->GetImageHeight();
	clip.w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);

	ObjectTexture->Draw(Renderer, Position, &clip);
}

void Collectible::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}
