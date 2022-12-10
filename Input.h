#pragma once
#include "SDL.h"
#include <vector>

using namespace std;


class Game;


class Input
{
public:
	Input(Game* MyGame);


	~Input();
	void UpdateInput(bool& bIsGameOver, vector<SDL_Window*> SdlWindows);

	// it will detect wether the that specific key is up or down 

	bool IsKeyDown(SDL_Scancode  Key);
	bool IsKeyUp(SDL_Scancode  Key);


protected:
	void HandleMenuEvents(SDL_Event* Event, vector<SDL_Window*> SdlWindows, bool  &bIsGameOver);


private:
	// store the state of each key 

	const Uint8* KeyBoardState;

	Game* MyGame;

};

