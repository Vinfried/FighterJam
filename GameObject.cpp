#include "GameObject.h"
#include "Vector2.h"
#include "SDL.h"
 
GameObject::GameObject()
{
	Position = Vector2().Zero();
	ObjectTexture = nullptr;

	ObjectCenter = Position;
 	NumberOfFrames = 1;
	bSouldDelete = false;

	Tag = "";
}

GameObject::~GameObject()
{
	for ( vector<Collider*>::iterator Col =Collisions.begin(); Col < Collisions.end();Col++ )
	{
		delete* Col;
	}

	vector <Collider*>().swap(Collisions);

	if (ObjectTexture != nullptr)
	{
		SDL_Log("Delete Texture....");

		delete ObjectTexture;
		ObjectTexture = nullptr;
	}

}

void GameObject::UpDateGameObject(float DeltaTime, vector<GameObject*> GameObjectStack)
{
	FindObjectCenter();

	UpdateCollisionPosition();

	vector<Collider*> OtherColliders = {};

	for (vector<GameObject*>::iterator GO = GameObjectStack.begin(); GO < GameObjectStack.end(); GO++ )
	{

		vector <Collider*> GOColliders = (*GO)->GetCollisions();

		for (vector <Collider*>::iterator Col = GOColliders.begin(); Col <GOColliders.end(); Col++ )
		{
			OtherColliders.push_back(*Col);
		}

	}

	// hand the collision detection for our colliders 

	for (vector<Collider*>::iterator Col = OtherColliders.begin(); Col <OtherColliders.end(); Col++ )
	{
		(*Col)->Update(DeltaTime,OtherColliders);
	}
	// run the derived update 
	   Update(DeltaTime);

}

void GameObject::Draw(SDL_Renderer* Renderer)
{

	for (vector<Collider*>::iterator Col = Collisions.begin(); Col < Collisions.end(); Col++)
	{
		if ((*Col)->bDebug)
		{
			// draw each collider 
			(*Col)->Draw(Renderer);
		}
	}


}

 

 

void GameObject::SetCollision(Vector2 Position, Vector2 HalfDimensions, bool ShouldDebug)
{
	// chech if there is any collision 

	   Collider* NewCollision = new Collider(this,Position , HalfDimensions, ShouldDebug);
	   Collisions.push_back(NewCollision);
}

void GameObject::SetCollisionDimensions(Collider* Collision, Vector2 HalfDimensions)
{


	if (Collision != nullptr)
	{
		// set the width of the collider 
		Collision->ColliderRect.w = HalfDimensions.x * 2;
		// set the heigt of the collider 
		Collision->ColliderRect.h = HalfDimensions.y * 2;
	}

}

void GameObject::UpdateCollisionPosition()
{
	   for (vector<Collider*>::iterator   Col = Collisions.begin(); Col < Collisions.end(); Col++)
	   {

		float w =  (*Col)->ColliderRect.w / 2;
		float h =  (*Col)->ColliderRect.h / 2;

		// it will change the position of the collider to equal the object center 

		(*Col)->ColliderRect.x = ObjectCenter.x - w;
		(*Col)->ColliderRect.y = ObjectCenter.y - h;

	   }


	  


}

void GameObject::FindObjectCenter()
{

	ObjectCenter = Position;

	if (ObjectTexture != nullptr)

	{
 
		float w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);
		float h = ObjectTexture->GetImageHeight();


		w /= 2;
		h /= 2;


		ObjectCenter.x += w;
		ObjectCenter.y += h;
	}
}

 vector<Collider*> GameObject::GetCollisions()
{
	return Collisions;    
}

bool GameObject::ShouldDelete() const
{
	return bSouldDelete;
}

void GameObject::DestroyGameObject()
{
	bSouldDelete = true;
}
