#include "Texture.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;


Texture::Texture()
{
	 SdlTexture = nullptr;
	 Width = 0;
	 Height = 0;
}

Texture::~Texture()
{
	ResetTexture();
}


bool Texture::LoadImageFromFile(const char* path, SDL_Renderer* renderer)
{
	if (SdlTexture==nullptr)
	{
		SDL_Surface* LoadSurface = IMG_Load(path);
		if (LoadSurface != nullptr)
		{
			cout << "Load Texture Sucess " << endl;


			SdlTexture = SDL_CreateTextureFromSurface(renderer, LoadSurface);
			if (SdlTexture !=nullptr)
			{
				cout << "Creat texture from surface success " << endl;

				Width = LoadSurface->w;
				Height = LoadSurface->h;

			}
			else 
			{
				cout << "Creat texture from surface failed ! " << endl;

			}

			SDL_FreeSurface(LoadSurface);
		}
		else
		{
			cout << "Load Texture Failed :"<< SDL_GetError() << endl;
		}
		  
	}
	else
	{
		cout << "Remove the existing texture before loading ! " << endl;
		return false;
	}

	return SdlTexture != nullptr;

}

void Texture::Draw(SDL_Renderer* Renderer,Vector2 Pos , SDL_Rect* SourceRect, int Scale )
{
	SDL_Rect DestnationRect = { Pos.x,Pos.y,Width,Height};

	if (SourceRect != nullptr)
	{
		DestnationRect.w = SourceRect->w * Scale;
		DestnationRect.h = SourceRect->h * Scale;
	}

	SDL_RenderCopy(Renderer, SdlTexture, SourceRect, &DestnationRect );
}

void Texture::ResetTexture()
{
	if (SdlTexture != nullptr)
	{
		SDL_DestroyTexture(SdlTexture);
		SdlTexture = nullptr;
		Width = 0;
		Height = 0;
	}

}