#pragma once

#include<vector>
#include"Vector2.h"
#include"SDL.h"

using namespace std;

class GameObject;

class Collider
{
	public:
		Collider(GameObject* OwnerObject, Vector2 Position = Vector2().Zero(),Vector2 HalfDimensions = Vector2(1.0f,1.0f), bool ShouldDebug = true);
		
		~Collider();

		void Update(float DeltaTime, vector <Collider*>& OtherColliders);
		void Draw(SDL_Renderer* Renderer);


		// set the bounds for the colllider 

		SDL_FRect  ColliderRect;


		vector <Collider*> GetOverlappingColliders() const;

		// bDebug is used to draw draw the colliders on the screen 

		bool bDebug;

		GameObject* GetOwner() const;

	 

		protected:

	   vector <Collider*> OverlappedColliders;

	   GameObject* OwnerObject;

	 
};

