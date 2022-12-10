#include "Text.h"
#include"Vector2.h"

Text::Text()
{
	Colour = { 225,225,255,255 };
	Font = nullptr;
	TextBox = {};
	TextSurface = nullptr;
	TextTexture = nullptr;
	bShouldUpdateText = false;
	bCenterText = false;


}

Text::~Text()
{
	if (TextTexture  != nullptr)
	{
		SDL_DestroyTexture(TextTexture);
		TextTexture = nullptr;
	}

	if (Font != nullptr)
	{
		TTF_CloseFont(Font);
		Font = nullptr;
	}
}

bool Text::InitialiseFont(SDL_Renderer* Renderer, string FontPath, int FontSize, 
	string TextToRender, const SDL_Colour Colour, Vector2 Position )

{

	this->TextToRender = TextToRender;
	this->Colour = Colour;
	this->Position = Position;

	Font = TTF_OpenFont(FontPath.c_str(), FontSize);

	 

	return SetText(Renderer);
}

void Text::Draw(SDL_Renderer* Renderer)
{
	if (bShouldUpdateText)
	{
		SetText(Renderer);

		bShouldUpdateText = false;
	}

	if (bCenterText)
	{
		int HalfWidth = SDL_max(TextBox.w, 1) / 2;
		int HalfHeight = SDL_max(TextBox.h, 1) / 2;

		TextBox.x = HalfWidth;
		TextBox.y = HalfHeight;

		bCenterText = false;

	}

	SDL_RenderCopy(Renderer, TextTexture, nullptr, &TextBox);
}

void Text::ChangeText(string NewText)
{
	TextToRender = NewText;

	bShouldUpdateText = true;
}


Vector2 Text::GetTextDimensions()
{
	return Vector2(TextBox.w, TextBox.h);
}


void Text::CenterText(bool bCenterText)
{
	this->bCenterText = bCenterText;
}

bool Text::SetText(SDL_Renderer* Renderer)
{
	if (Font== nullptr)
	{
		SDL_Log("Text Not Found....%s", SDL_GetError());

		return false;
	}

	TextSurface = TTF_RenderText_Solid(Font, TextToRender.c_str(), Colour);

	if (TextSurface == nullptr)
	{
		SDL_Log("Text Surface Failed....");

		return false;
	}

	if (TextTexture != nullptr)
	{
		SDL_DestroyTexture(TextTexture);
		TextTexture = nullptr;
	}

	TextTexture = SDL_CreateTextureFromSurface(Renderer, TextSurface);

	if (TextTexture == nullptr)
	{
		SDL_Log("Text Texture Failed...");

		SDL_FreeSurface(TextSurface);

		return false;
	}

	 
	
	  TextBox = {static_cast<int>(Position.x), static_cast<int>(Position.y), TextSurface->w, TextSurface->h};

	SDL_FreeSurface(TextSurface);

	 return true;
}
