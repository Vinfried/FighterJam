#include "Enemy.h"

Enemy::Enemy(Texture* CharacterTexture, Vector2 Pos, int NumberofFrames)
	:Character::Character(CharacterTexture, Pos, NumberofFrames)
{
	MaxSpeed = 350.0f;
	Tag = "Enemy";
}

Enemy::~Enemy()
{
}

void Enemy::Update(float DeltaTime)
{
	Character::Update(DeltaTime);
//	Position.x += 200 * DeltaTime;
	float Speed = 1000.0f;
    AddForce(Speed , Vector2(1.0f, 0.0f));
}

 