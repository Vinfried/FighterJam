#pragma once

#include <iostream>
#include <string>
#include"Vector2.h"
#include"SDL.h"
#include"SDL_ttf.h"

using namespace std;


class Text
{

public:
   	Text();
	~Text();

	bool InitialiseFont(SDL_Renderer* Renderer, string FontPath,int FontSize,
		string TextToRender,const SDL_Colour Colour, Vector2 Position = Vector2(0.0f,0.0f));


	void Draw(SDL_Renderer* Renderer);


	void ChangeText(string NewText);

	Vector2 GetTextDimensions();

	void CenterText(bool bCenterText);

 protected:

	 bool SetText(SDL_Renderer* Renderer);

	 TTF_Font* Font;

	 SDL_Surface* TextSurface;

	 SDL_Texture* TextTexture;

	 SDL_Rect TextBox;

	 bool bShouldUpdateText;

	 bool bCenterText;

	 SDL_Colour Colour;

	 string TextToRender;

	 Vector2 Position;

};

