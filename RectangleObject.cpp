#include "RectangleObject.h"

RectangleObject::RectangleObject(float Width, float Height, Vector2 Position, SDL_Color Colour, bool bFilled)
{

	this->Width = Width;
	this->Height = Height;
	this->Position = Position;
	this->Colour = Colour;
	this->bFilled = bFilled;

}

void RectangleObject::Draw(SDL_Renderer* Renderer)
{

	SDL_FRect Rectangle = {Width, Height, Position.x, Position.y};


	SDL_SetRenderDrawColor(Renderer, Colour.r, Colour.g, Colour.b, Colour.a);


	if (!bFilled)
	{
		// draw rectangle outline 
		SDL_RenderDrawRectF(Renderer, &Rectangle);
	}
	else
	{
		// draw rectangle with filled color
		SDL_RenderFillRectF(Renderer, &Rectangle);
	}
}
