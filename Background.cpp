#include "Background.h"




Background::Background(Texture* BackgroundTexture, Vector2 Position, Vector2 Dimensions)
{
	

	this->Position = Position;
	this->ObjectCenter = Position;

	ObjectTexture = BackgroundTexture;
	this->NumberOfFrames = NumberOfFrames;

}

Background::~Background()
{
}

void Background::Draw(SDL_Renderer* Renderer)
{
	GameObject::Draw(Renderer);

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto Width = DM.w;
	auto Height = DM.h;

	SDL_Rect Clip;
	Clip.x = 0;
	Clip.y = 0;
	Clip.h = Height;
	Clip.w = Width / SDL_max(1, NumberOfFrames);

	ObjectTexture->Draw(Renderer, Position, &Clip);
}

void Background::Update(float DeltaTime)
{
}
