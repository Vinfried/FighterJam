#pragma once
#include<iostream>
#include <SDL.h>
#include"Texture.h"
#include "Vector2.h"
#include "Input.h"
#include "Collider.h"

using namespace std;

class GameObject
{
public:
		GameObject();
		~GameObject();
		// this will be tthe true update 

		void UpDateGameObject(float DeltaTime, vector<GameObject*>GameObjectStack);

	virtual	void Draw(SDL_Renderer* Renderer);
	virtual	void ProcessInput(Input* UserInput)   {}

	// this will create the collision for the game object 

	void SetCollision(Vector2 Position = Vector2().Zero(), Vector2 HalfDimensions = Vector2(1.0f, 1.0f), bool ShouldDebug = true);

	void SetCollisionDimensions(Collider* Collision,Vector2 HalfDimensions);

	void UpdateCollisionPosition();
	void FindObjectCenter();

	vector<Collider*> GetCollisions();

	bool ShouldDelete() const;

	void DestroyGameObject();

	string Tag;

	Vector2 GetPosition() { return ObjectCenter;  }

protected:

	virtual	void Update(float DeltaTime) {}
	// the position for the game object to display on the screen 

	Vector2 Position;

	Texture* ObjectTexture;

	vector<Collider*> Collisions;

	Vector2 ObjectCenter;

	unsigned int NumberOfFrames;

private:

	bool bSouldDelete;

};

