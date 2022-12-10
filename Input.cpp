#include "Input.h"
#include "SDL_syswm.h"
#include "resource.h"
#include "resource1.h"
#include "Game.h"
 
using namespace std;

Input::Input(Game* MyGame)
{
	KeyBoardState = nullptr;

	this->MyGame = MyGame;

	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
}

Input::~Input()
{
}

void Input::UpdateInput(bool& bIsGameOver, vector<SDL_Window*> SdlWindows)
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{

		switch (Event.type)
		{
		case  SDL_KEYDOWN:
		 
			KeyBoardState = SDL_GetKeyboardState(NULL);
			break;
		case  SDL_KEYUP:

			KeyBoardState = SDL_GetKeyboardState(NULL);
			break;
		case  SDL_SYSWMEVENT:
			HandleMenuEvents(&Event, SdlWindows, bIsGameOver );
			break;
		default:
			break;
		}





		// this will close the game if we hit cross 

		if (Event.window.event ==  SDL_WINDOWEVENT_CLOSE )
		{
			if (Event.window.windowID == SDL_GetWindowID(SdlWindows[0]))
			{
				bIsGameOver = true;
			}
			else
			{
				SDL_HideWindow(SdlWindows[1]);
			}
			
 		}

	}


}

bool Input::IsKeyDown(SDL_Scancode Key)
{

	if (KeyBoardState != nullptr && KeyBoardState [Key] == true)
	{
		return true;
	}

	return false;
}

bool Input::IsKeyUp(SDL_Scancode Key)
{
	if (KeyBoardState != nullptr && KeyBoardState[Key] == true)
	{
		return false;
	}


	return true;
}

void Input::HandleMenuEvents(SDL_Event* Event, vector<SDL_Window*> SdlWindows, bool& bIsGameOver)
{
	switch (Event->syswm.msg->msg.win.wParam)
	{

	case  ID_FILE_NEWWINDOW:  // case 01 
	
		SDL_ShowWindow(SdlWindows[1]);
		break;

	case  ID_FILE_EXIT:        // case 02 

		bIsGameOver = true;
		break;

	case ID_HELP_BGEGAMEENGINE:

		   
		SDL_ShowSimpleMessageBox
		   (SDL_MESSAGEBOX_INFORMATION, 
			" About BGE Engine " , 
			" BGE Engine is v0.1 version is an SDL2 based game engine. ",
			  SdlWindows[0]);
		break;

	case ID_SHAPES_RECTANGLE:
		MyGame->AddRandomRactangle();
		break;

	case ID_SHAPES_RECTANGLE40004:
		MyGame->AddRandomRactangle(true);
		break;

	default:

			break;
	}

}
