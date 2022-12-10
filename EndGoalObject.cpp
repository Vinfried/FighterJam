#include "EndGoalObject.h"
#include "Game.h"
#include "MenuState.h"
#include "MSGameOver.h"

EndGoalObject::EndGoalObject(Texture* EndGoalObjectTexture, Vector2 Pos)
{
	this->Position = Pos;
	this->ObjectCenter = Position;

	ObjectTexture = EndGoalObjectTexture;
	this->NumberOfFrames = NumberOfFrames;

	float h = ObjectTexture->GetImageHeight();
	float w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);

	SetCollision(this->Position, Vector2(h/2,w/2));

}

void EndGoalObject::Draw(SDL_Renderer* Renderer)
{
	GameObject::Draw(Renderer);

	SDL_Rect Clip;
	Clip.x = 0;
	Clip.y = 0;
	Clip.h = ObjectTexture->GetImageHeight();
	Clip.w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);


	ObjectTexture->Draw(Renderer, Position, &Clip);

}

void EndGoalObject::Update(float DeltaTime)
{

	vector <Collider*> OverCols = Collisions[0]->GetOverlappingColliders();

	for (vector<Collider*>::iterator Col = OverCols.begin(); Col < OverCols.end(); Col++ )
	{
		if ((*Col)->GetOwner()->Tag == "Player")
		{
			MSGameOver* NewState = new MSGameOver();
			Game::GetGameInstance()->ChangeGameState(NewState, 2);
		}
	}


}
