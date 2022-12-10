
#include "iostream"
#include "Animation.h"


using namespace std;

//Animation::Animation()
//{

//}
Animation::Animation(Texture* intSpriteSheet, int InNumberofFrames , float InFrameDuration,
	        int InStartFrame, int InEndFrame )
{

	SpriteSheet = intSpriteSheet;
	StartFrame = InStartFrame;
	EndFrame = InEndFrame;
	FrameDuration = InFrameDuration;
	FrameTimer = 0.0f;
	CurrentFrame = StartFrame;

	// width and height of each fram of image
	if (SpriteSheet != nullptr) 
	{
		FrameWidth = SpriteSheet->GetImageWidth() / SDL_max(1, InNumberofFrames);
		FrameHeight = SpriteSheet->GetImageHeight();
	}
	else
	{
		cout << "No Texture Provided in the Animation - Failed!!" << endl;
	}



}


Animation::~Animation()
{
	if (SpriteSheet !=  nullptr)
	{
		// this will deallocate the sprite sheet 
		delete SpriteSheet;
		SpriteSheet = nullptr;
	}

}
 
void Animation::Update(float DeltaTime)
{

	FrameTimer += DeltaTime;
	if (FrameTimer>= FrameDuration)
	{
		CurrentFrame++;

		FrameTimer = 0.0f;

		if (CurrentFrame >= EndFrame)
		{

			CurrentFrame = StartFrame;
		}
	}





}

void Animation::Draw(SDL_Renderer* Renderer, Vector2 Pos , int Scale )
{
	// get the current rendering 
	SDL_Rect clip;
	clip.x = CurrentFrame * FrameWidth;
	clip.y = 0;
	clip.w = FrameWidth;
	clip.h = FrameHeight;

	// draw the rendering to the screen 

	SpriteSheet->Draw(Renderer,Pos,&clip, Scale);

}


