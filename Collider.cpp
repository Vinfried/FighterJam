#include "Collider.h"
#include <vector>

using namespace std;

Collider::Collider(GameObject* OwnerObject, Vector2 Position, Vector2 HalfDimensions, bool ShouldDebug)
{

	bDebug = ShouldDebug;
	OverlappedColliders = {};
	this->OwnerObject = OwnerObject;
 

	// get the position and adjust the size of the colliders 

	float x = Position.x - HalfDimensions.x;
	float y = Position.y - HalfDimensions.y;

	// set the width and height of rect to full size 

	float w = HalfDimensions.x * 2;
	float h = HalfDimensions.y * 2;

	// set the bounds based on the algorithum 

	ColliderRect = {x,y,w,h};


}

Collider::~Collider()
{
	for ( vector <Collider*>::iterator Col = OverlappedColliders.begin(); Col < OverlappedColliders.end(); ++Col)
	{
 
		vector <Collider*>::iterator fCol = find((*Col)->OverlappedColliders.begin(), (*Col)->OverlappedColliders.end(),this);

		if (fCol < (*Col)->OverlappedColliders.end())
		{
			(*Col)->OverlappedColliders.erase(fCol);
		}
	}




}

void Collider::Update(float DeltaTime, vector<Collider*>& OtherColliders)
{
 
	for ( unsigned int i = 0; i< OtherColliders.size(); ++i)
	{
		if (OtherColliders[i] != this)
		{
			if (SDL_HasIntersectionF(&ColliderRect, &OtherColliders[i]->ColliderRect))
			{
				vector<Collider*>::iterator it = find(OverlappedColliders.begin(), OverlappedColliders.end(), OtherColliders[i]);
				if (it == OverlappedColliders.end())
				{
					OverlappedColliders.push_back(OtherColliders[i]);
				     //	SDL_Log("Entered Collider");
				}
			}

			else
			{
				vector<Collider*>::iterator it = find(OverlappedColliders.begin(), OverlappedColliders.end(), OtherColliders[i]);
				if (it < OverlappedColliders.end())
				{
					OverlappedColliders.erase(it);

				      //	SDL_Log("Entered Collider");
				}

			}
		}





	}






}

void Collider::Draw(SDL_Renderer* Renderer)
{


	if (bDebug == true)
	{
		if (OverlappedColliders.empty())
		{
			SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 1);
		}
		else
		{

			SDL_SetRenderDrawColor(Renderer, 0, 255, 0, 1);

		}

		// draw the red color as rectangule based on the collider dimension 

		SDL_RenderDrawRectF(Renderer, &ColliderRect);
	}

	

}

vector<Collider*> Collider::GetOverlappingColliders() const
{


	return OverlappedColliders;
}

GameObject* Collider::GetOwner() const
{
	return OwnerObject;
}

 
