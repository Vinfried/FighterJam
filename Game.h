#pragma once

#include <SDL.h>
#include "Texture.h"
#include "Animation.h"
#include"Character.h"
#include"GameObject.h"
#include <iostream>
#include <vector>
#include"Input.h"
#include "Collider.h"
#include "GameState.h"

using namespace std;

static Game* GameInstance;
 
class Game
{

public:

	  static Game* GetGameInstance();

	  static void DestroyGameInstance();

	  int Score;

private:

	Game();


	~Game();

	// the window that will be rendering 
	vector<SDL_Window*> SdlWindow;

	// 2D renderer 
	vector < SDL_Renderer*> SdlRenderer;

	bool bIsGameOver;

	vector <GameState*> GameStates;
 
	// this will initialize the sub game objects 

	vector<GameObject*> SubGameObjects;

	 


	Input*  UserInput;

	unsigned int LastUpdateTime;

public:

	void ChangeGameState(GameState* NewState, Uint32  StateID);

	// add random ractangle to the screen 

	void AddRandomRactangle(bool  bFilled = false);

	// Create the renderer 
	bool start();  // allocates any objects just like begin

	void ProcessInput();

	void Update();   

	void Draw(); //it will draw game images on screen 

	// run a function that will handle deleting objects after or before all the functionality is complete 
	void HandleGarbage();

	void Run(const char* title, int width, int height, bool fullScreen);
	 
	void ShutDown();  // deaclocating the objects 

	void Destroy();
};

