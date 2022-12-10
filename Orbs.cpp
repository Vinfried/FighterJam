#include "Orbs.h"

Orbs::Orbs(Texture* CollectibleTexture, Vector2 Pos, int NumberOfFrames)
:Collectible::Collectible(CollectibleTexture, Pos, NumberOfFrames)
{
	Tag = "Orb";
}

Orbs::~Orbs()
{
}

void Orbs::Update(float DeltaTime)
{
	Collectible::Update(DeltaTime);
}
