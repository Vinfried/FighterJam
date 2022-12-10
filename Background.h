#pragma once
#include "GameObject.h"
class Background : public GameObject
{
public:

	

	Background(Texture* BackgroundTexture, Vector2 Position, Vector2 Dimensions);
	~Background();

	void Draw(SDL_Renderer* Renderer);

	virtual void Update(float DeltaTime) override;

	
};

