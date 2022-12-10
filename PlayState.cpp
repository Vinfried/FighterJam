#include "PlayState.h"
#include "Player.h"
#include "Enemy.h"
#include "EndGoalObject.h"
#include "Game.h"
#include "Background.h"
#include <string>


PlayState::PlayState()
{
	DBColour = {255, 204, 153, 255};
     
	


	TXT_PPosition = nullptr;
	PChar = nullptr;
	Music_BG =  nullptr;
	   
	TXT_Score = nullptr;
}

void PlayState::Update(float DeltaTime)
{
	GameState::Update(DeltaTime);

	 

	if (PChar != nullptr &&  TXT_PPosition != nullptr)
	{
		int x, y = 0;

		x = static_cast<int>(PChar->GetPosition().x);
		y = static_cast<int>(PChar->GetPosition().y);

		string NewText = "X :" + to_string(x) + " Y :" + to_string(y);
	 
		TXT_PPosition->ChangeText(NewText);
 
	}

	if (TXT_Score != nullptr)
	{
		int score = Game::GetGameInstance()->Score;
		string NewText = "Score : " + to_string(score);
		TXT_Score->ChangeText(NewText);
	}

	
 
}

void PlayState::Draw(SDL_Renderer* Renderer)
{
	GameState::Draw(Renderer);

	if (TXT_PPosition != nullptr)
	{
		TXT_PPosition->Draw(Renderer);
	}

	if (TXT_Score != nullptr)
	{
		TXT_Score->Draw(Renderer);
	}
}

 
bool PlayState::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{ 
		
		Texture* BackgroundTexture = new Texture;

		BackgroundTexture->LoadImageFromFile("Assets/PlayBackground.png", Renderer);

		Background* GameBackground = new Background(BackgroundTexture, Vector2(0,0), Vector2(0,0));
		
		GameObjectStack.push_back(GameBackground);

		// initialize the player texture
		Texture* PlayerTexture = new Texture;
		// it will load the player texture

		PlayerTexture->LoadImageFromFile("Assets/hero_spritesheet_50x37_109.png", Renderer);

		// it will construct the player as character

		PChar = new Player(PlayerTexture,Vector2(0,0), 109);
		PChar->Tag = "Player";

		PChar->PlayerAnims.attack = new Animation(PlayerTexture, 109, 0.1f, 0, 2);
		PChar->PlayerAnims.idle = new Animation(PlayerTexture, 109, 0.1f, 65, 68);
		PChar->PlayerAnims.run = new Animation(PlayerTexture, 109, 0.1f, 84, 89);
		
		GameObjectStack.push_back(PChar);


		// initialize the enemy texture
		Texture* EnemyTexture = new Texture;
		// it will load the player texture

		EnemyTexture->LoadImageFromFile("Assets/goblin-spritesheet-65x35-28.png", Renderer);

		// it will construct the player as character

		 Enemy* EnemyCharacter1 = new Enemy(EnemyTexture, Vector2(-100,100), 28);
		 GameObjectStack.push_back(EnemyCharacter1);


		EnemyTexture = new Texture;

	 
		// it will load the player texture          //SPA_Enemy_Right.png

		EnemyTexture->LoadImageFromFile("Assets/SPA_Enemy_Right.png", Renderer);

		Enemy* EnemyCharacter2 = new Enemy(EnemyTexture, Vector2(-300, 120), 6);
		GameObjectStack.push_back(EnemyCharacter2);


		EnemyTexture = new Texture;


		// it will load the player texture          //SPA_Enemy_Right.png

		EnemyTexture->LoadImageFromFile("Assets/SPA_Enemy_Right.png", Renderer);

		Enemy* EnemyCharacter3 = new Enemy(EnemyTexture, Vector2(-400, 150), 6);
		GameObjectStack.push_back(EnemyCharacter3);
   


		EnemyTexture = new Texture;


		// it will load the player texture          //SPA_Enemy_Right.png

		EnemyTexture->LoadImageFromFile("Assets/SPA_Enemy_Right.png", Renderer);

		Enemy* EnemyCharacter4 = new Enemy(EnemyTexture, Vector2(-800, 200), 6);
		GameObjectStack.push_back(EnemyCharacter4);


		EnemyTexture = new Texture;


		// it will load the player texture          //SPA_Enemy_Right.png

		EnemyTexture->LoadImageFromFile("Assets/SPA_Enemy_Right.png", Renderer);

		Enemy* EnemyCharacter5 = new Enemy(EnemyTexture, Vector2(-1000, 170), 6);
		GameObjectStack.push_back(EnemyCharacter5);

        EnemyTexture = new Texture;


		// it will load the player texture          //SPA_Enemy_Right.png

		EnemyTexture->LoadImageFromFile("Assets/SPA_Enemy_Right.png", Renderer);

		Enemy* EnemyCharacter6 = new Enemy(EnemyTexture, Vector2(-1200, 140), 6);
		GameObjectStack.push_back(EnemyCharacter6);

		// it will load the player texture          //SPA_Enemy_Right.png
		EnemyTexture = new Texture;

		EnemyTexture->LoadImageFromFile("Assets/fire.png", Renderer);

		Enemy* fireball01 = new Enemy(EnemyTexture, Vector2(-600, 230), 10);
		GameObjectStack.push_back(fireball01);

		EnemyTexture = new Texture;

		EnemyTexture->LoadImageFromFile("Assets/fire.png", Renderer);

		Enemy* fireball02 = new Enemy(EnemyTexture, Vector2(-1300, 180), 10);
		GameObjectStack.push_back(fireball02);

		EnemyTexture = new Texture;

		EnemyTexture->LoadImageFromFile("Assets/fire.png", Renderer);

		Enemy* fireball03 = new Enemy(EnemyTexture, Vector2(-1400, 245), 5);
		GameObjectStack.push_back(fireball03);

		EnemyTexture = new Texture;

		EnemyTexture->LoadImageFromFile("Assets/fire.png", Renderer);

		Enemy* fireball04 = new Enemy(EnemyTexture, Vector2(-1500, 200), 5);
		GameObjectStack.push_back(fireball04);

		EnemyTexture = new Texture;

		EnemyTexture->LoadImageFromFile("Assets/bossEnemy.png", Renderer);

		Enemy* bossEnemy = new Enemy(EnemyTexture, Vector2(-1850, 250), 1);
		GameObjectStack.push_back(bossEnemy);


		Texture* EndGoalObjectTexture = new Texture;

		EndGoalObjectTexture->LoadImageFromFile("Assets/Exit Pixelated.png", Renderer);

		EndGoalObject* EndGoal = new EndGoalObject(EndGoalObjectTexture ,Vector2(1200.0f, 620.0f));	
		GameObjectStack.push_back(EndGoal);


		TXT_PPosition = new Text();

		SDL_Colour TextColour = {230, 230, 230, 255};

		if (!TXT_PPosition->InitialiseFont(Renderer, "Assets/VT323-Regular.ttf",30, 
			"X: 0, Y: 0",TextColour, Vector2(15.0f, 15.0f) ))
		{
			delete TXT_PPosition;
			TXT_PPosition = nullptr;
		}

		TXT_Score = new Text();
		if (!TXT_Score->InitialiseFont(Renderer,"Assets/VT323-Regular.ttf", 30,
			"Score :0",TextColour, Vector2(15.0f, 45.0f) ))
		{
			delete TXT_Score;
			TXT_Score = nullptr;
		}

		Music_BG = Mix_LoadMUS("Assets/BackgoundMusic.wav");


		if (Music_BG != nullptr)
		{
			Mix_PlayMusic(Music_BG, -1);
		}

		Game::GetGameInstance()->Score = 0;

        return true;
}

bool PlayState::OnExit()
{
    SDL_Log("Exited Player State !");


	if (PChar != nullptr)
	{
		PChar = nullptr;
	}



	if (TXT_PPosition != nullptr)
	{
		delete TXT_PPosition;
		TXT_PPosition = nullptr;
	}

	if (TXT_Score != nullptr)
	{
		delete TXT_Score;
		TXT_Score = nullptr;
	}

	if (Music_BG != nullptr)
	{
		Mix_FreeMusic(Music_BG);
		Music_BG = nullptr;
	}



    return true;
}
