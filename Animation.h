#pragma once
#include "SDL.h"
#include "Texture.h"

class Animation
{
public:

	Animation();

	Animation(Texture* intSpriteSheet, int InNumberofFrames = 1, float InFrameDuration = 0.1f,
		int InStartFrame = 0, int InEndFrame = 0);

	~Animation();

	//it will update animation on each frame 
	void Update(float DeltaTime);

	// it will draw the animation on screen 
	void Draw(SDL_Renderer* Renderer, Vector2 Pos, int Scale = 1, bool Flip = false);

	int GetFrameWidth()
	{
		return FrameWidth;
	};
	int GetFrameHeight()
	{
		return FrameHeight;
	};

private:
	// start and end Frame of the animation
	unsigned int StartFrame;
	unsigned int EndFrame;

	// width and height of frame  
	unsigned int FrameWidth;
	unsigned int FrameHeight;

	Texture* SpriteSheet;

	float FrameTimer;

	float FrameDuration;

	unsigned int CurrentFrame;
};

