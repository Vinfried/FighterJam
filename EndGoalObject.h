#pragma once
#include "GameObject.h"
class EndGoalObject :  public GameObject
{
public:

	EndGoalObject(Texture* EndGoalObjectTexture, Vector2 Position);

	void Draw(SDL_Renderer* Renderer);

	virtual void Update(float DeltaTime) override;

};

