#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2.h"

class Collectible :
    public GameObject
{
public:
    Collectible(Texture* CollectibleTexture, Vector2 Pos, int numberOfFrames = 1);
    ~Collectible();

    void Draw(SDL_Renderer* Renderer) override;
    virtual void Update(float DeltaTime) override;

private:
    //velocity is the true representation of speed, this will gave a x and y value
    Vector2 Velocity;
    //this is going to detect input and move our character based on it's direction
    //make sure the number is normally between 0 and 1
    Vector2 MovementAxis;
};

