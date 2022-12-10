
#include<iostream>
#include"Game.h"

using namespace std;

int main(int argc , char** argv )
{
 

	 Game::GetGameInstance()->Run("Fighter Jam", 1280, 720, false);
	 
	 Game::DestroyGameInstance();

	return 0;
}