#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2.h"
#include "Animation.h"

struct CharacterAnimations {
    Animation* attack;
    Animation* idle;
    Animation* run;
    Animation* die;
    Animation* jump;
};

class Character :
    public GameObject
{
public:

    Character(Texture* CharacterTexture,Vector2 Pos, int NumberofFrames = 1);
    ~Character() {}

   void Draw(SDL_Renderer* Renderer)override;
   virtual void Update(float DeltaTime)override;
   virtual void ProcessInput(Input* UserInput)override {}

   void AddForce(float Force, Vector2 Direction);


protected:
    float MaxSpeed;

    void SetMovementAxis(Vector2 Axis);
    Vector2 GetMovementAxis();
    float Drag;
    Vector2 Velocity;

private :

 
    

    Vector2 MovementAxis;

    Vector2 Acceleration;

};

