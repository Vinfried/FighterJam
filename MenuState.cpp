#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"


MenuState::MenuState()
{
    DBColour = {102, 255, 51, 0};
    MenuTitle = nullptr;
    SFX_Enter = nullptr;

}

void MenuState::Draw(SDL_Renderer* Renderer)
{
    GameState::Draw(Renderer);
    if(MenuTitle != nullptr)
    {
        MenuTitle->Draw(Renderer);
    }
}

void MenuState::ProcessInput(Input* UserInput)
{
    GameState::ProcessInput(UserInput);

    if (UserInput->IsKeyDown(SDL_SCANCODE_SPACE))
    {
        PlayState* NewState = new PlayState();
        Game::GetGameInstance()->ChangeGameState(NewState, 1);
    }

}

bool MenuState::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
    SDL_Log(" Menu State Entered...");

    int WWidth, WHeight = 0;
    
    SDL_GetWindowSize(Window, &WWidth, &WHeight);
    
    int HalfWidth = SDL_max(WWidth,1) /2;
    int HalfHeight = SDL_max(WHeight, 1) /2;



    
    MenuTitle = new Text();
    
    SDL_Colour TitleColour = {153,51,255,255};

    if (!MenuTitle->InitialiseFont(Renderer, "Assets/VT323-Regular.ttf", 55, " * Welcome to Fighter Jam * ", 
        TitleColour, Vector2(HalfWidth, HalfHeight)))
    {
        delete MenuTitle;

        MenuTitle = nullptr;
    }

    else
    {
         MenuTitle->CenterText(true);
    }
    // we have added a new music for our game 

    SFX_Enter = Mix_LoadWAV("Assets/introMusic.wav");

    if (SFX_Enter != nullptr)
    {
        Mix_PlayChannel(-1, SFX_Enter, 1);
    }



    return true;
}

bool MenuState::OnExit()
{
    SDL_Log(" Exited State Entered...");

    if (MenuTitle != nullptr)
    {
        delete MenuTitle;
        MenuTitle = nullptr;
    }


    if (SFX_Enter != nullptr)
    {
        Mix_FreeChunk(SFX_Enter);
        SFX_Enter = nullptr;
    }

    return true;
}
