#pragma once

#include <SDL.h>
#include "Vector2.h"

class Texture
{
public: 
	   Texture();
	  ~Texture();
private:

	SDL_Texture* SdlTexture;
	int Width;
	int Height;

public:

	bool LoadImageFromFile(const char* Path,SDL_Renderer* Renderer);


	void Draw(SDL_Renderer* Renderer,Vector2 Pos,SDL_Rect* SourceRect = NULL , int Scale = 1.5);
	
	int GetImageWidth()
	{
		return Width;
	}

	int GetImageHeight()

	{
		return Height;
	}

	void ResetTexture();
	


};

