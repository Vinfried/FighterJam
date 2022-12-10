
#include <iostream>
#include "Game.h" 
#include <vector> 
#include"resource.h"
#include <Windows.h>
#include "SDL_syswm.h"
#include"RectangleObject.h"
#include <math.h>
#include"PlayState.h"
#include"MenuState.h"
#include"SDL_mixer.h"

using namespace std;


Game* Game::GetGameInstance()
{

	if (GameInstance == nullptr)
	{
		GameInstance = new Game();
	}


	return GameInstance;
}

void Game::DestroyGameInstance()
{
	if (GameInstance != nullptr)
	{
		delete GameInstance;
		GameInstance = nullptr;
	}

}

Game::Game()
{
	 SdlWindow  = { nullptr,nullptr };
	SdlRenderer = { nullptr,nullptr };
 	LastUpdateTime = 0.0f;
 	UserInput = nullptr;
	Score = 0;
	
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) != 0)
	{
 		                bIsGameOver = true;
				cout << "Initialize SDL - failed! " << endl;

	}
	else
	{
		if (TTF_Init() == -1)
		{
			bIsGameOver = true;

			SDL_Log("Font SubSystem Failed....");

			return;
		}

		if ( SDL_Init(SDL_INIT_AUDIO) != 0 )
		{
			bIsGameOver = true;

			SDL_Log("Audio Subsystem failed...");

			return;
		}

		else
		{
			Mix_OpenAudio(48000,MIX_DEFAULT_FORMAT, 2, 4096);
		}


 		bIsGameOver = false;
		cout << "Initialize SDL - Successfull " << endl;
 
	}


}

Game::~Game()
{
	// clear the game objects from the array 

 
	vector <GameObject*>().swap(SubGameObjects);


}


void Game::ChangeGameState(GameState* NewState, Uint32 StateID)
{
	
	
	if (!GameStates.empty())
	
	{
		GameStates.back()->OnExit();
		GameStates.back()->DestroyGameState();	 
		 
	}
		NewState->StateID = StateID;
		GameStates.push_back(NewState);	 

	GameStates.back()->OnEnter(SdlRenderer[0],  SdlWindow[0]);
}



void Game::AddRandomRactangle(bool bFilled)
{
	float w = rand() % 150 + 10;
	float h = rand() % 150 + 10;

	// randmise the position of the rectangle  

	float Posx = rand() % 1280;
	float PosY = rand() % 720;

	// randomise the colour  
	SDL_Color NewColour = {rand() % 256, rand() % 256, rand() % 256, rand() % 256 };


	RectangleObject* NewRectangle = new  RectangleObject(w, h, Vector2(Posx, PosY), NewColour, bFilled);
	SubGameObjects.push_back(NewRectangle);




}

bool Game::start()
{
 // here arringing the correct renderrto the right window

	SdlRenderer[0] = SDL_CreateRenderer(SdlWindow[0], 0, -1);

	SdlRenderer[1] = SDL_CreateRenderer(SdlWindow[1], 0, -1);


	// how many seconds it will be 
	LastUpdateTime = SDL_GetTicks();


	if (SdlRenderer[0] != nullptr  && SdlRenderer[1] != nullptr)
	{
		cout << "Creat Renderer - Sucess !!!" << endl;

 
		UserInput = new Input(this);

  	  // creating a starter game state

		MenuState* StarterGameState = new MenuState();
		ChangeGameState(StarterGameState, 0);

			return true;
 

	}


	cout << "Creat Renderer - Failed !!!" << endl;
		return false;
}

void Game::ProcessInput()
{
	UserInput->UpdateInput(bIsGameOver, SdlWindow);

	GameStates.back()->ProcessInput(UserInput);
 }

void Game::Update()
{
	unsigned int tick = SDL_GetTicks() - LastUpdateTime;

	// it will change the time to seconds

 	float DeltaTime = tick / 1000.0f;

	//it will refresh the time
	LastUpdateTime = SDL_GetTicks();

 
	GameStates.back()->Update(DeltaTime);
	 
}

void Game::Draw()
{
	// this function will set the draw color 
	SDL_SetRenderDrawColor(SdlRenderer[0],15,15,15,225);

  
	for (vector<SDL_Renderer*>::iterator  it  =  SdlRenderer.begin(); it < SdlRenderer.end(); ++it)
	{
		SDL_RenderClear(*it);
	}

	// draw secondary objects to the second screen 
	for (vector<GameObject*>::iterator it =  SubGameObjects.begin(); it < SubGameObjects.end() ; ++it)
	{
		  (*it)->Draw(SdlRenderer[1]);
	}
	// run the draw in the game state
	GameStates.back()->Draw(SdlRenderer[0]);
 

// getting all the newely rendererd stuff and showing it to the screen 

	for (vector<SDL_Renderer*>::iterator it = SdlRenderer.begin(); it < SdlRenderer.end(); ++it)
	{
		SDL_RenderPresent(*it);
	}

	 

}


void Game::HandleGarbage()
{
 
	for(vector<GameState*>::iterator  State = GameStates.begin(); State < GameStates.end(); )
	{ 
		if ((*State)->ShouldDelete())
		{
			delete *State;
			State = GameStates.erase(State);
			continue;
		}
		    State++;
	}
	
 
	GameStates.back()->HandleGarbage();

}

void Game::Run(const char* title, int width, int height, bool fullScreen)
{
	int CreationFlag = 0;

	if (!fullScreen)
	{
		CreationFlag = SDL_WINDOW_SHOWN;
	}
	else
	{
		CreationFlag = SDL_WINDOW_FULLSCREEN;
	}

	// create the SDL window 
	SdlWindow[0] = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width,height,CreationFlag);

	// create the second window  

	SdlWindow[1] = SDL_CreateWindow("BGE GameEngine Second Window ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,  SDL_WINDOW_HIDDEN);

	if(SdlWindow[0] != nullptr &&   SdlWindow[1] != nullptr  && start())
	{
		cout << "Creat window Sucess !!!" << endl;


		SDL_SysWMinfo  windowInfo;

		SDL_VERSION(&windowInfo.version);

		SDL_GetWindowWMInfo(SdlWindow[0], &windowInfo);

		HWND hWindow = windowInfo.info.win.window;

		HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));


		SetMenu(hWindow, hMenu);






		while (!bIsGameOver)
		{
			// delete game objects that are marked to deleted
			HandleGarbage();

			// check for the player input 
			ProcessInput();

			Update();

			Draw();

		}

	}
	else 
	{
		cout << "Create window failed !!!" << endl;

		ShutDown();
		Destroy();
	}
	 
	 
		

}


void Game::ShutDown()
{

}

void Game::Destroy()
{
	SDL_DestroyWindow(SdlWindow[0]);
	SDL_DestroyWindow(SdlWindow[1]);

	SDL_DestroyRenderer(SdlRenderer[0]);
	SDL_DestroyRenderer(SdlRenderer[1]);


	SDL_Quit();

}
 

