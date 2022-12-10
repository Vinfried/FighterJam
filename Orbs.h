#pragma once
#include "Collectible.h"
class Orbs :
    public Collectible
{
public:
    Orbs(Texture* CollectibleTexture, Vector2 Pos, int NumberOfFrames = 1);
    ~Orbs();

    void Update(float DeltaTime) override;
};

