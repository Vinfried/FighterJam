#pragma once
#include "GameObject.h"
class RectangleObject :  public GameObject
{

public:

	RectangleObject(float Width, float Height, Vector2 Position, SDL_Color Colour, bool bFilled = false);

	void Draw(SDL_Renderer* Renderer)override;

protected:

	float Width;
	float Height;

	Vector2 Position;
	bool bFilled;
	SDL_Color Colour;




};

