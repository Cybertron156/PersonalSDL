#include <SDL.h>
#include <iostream>
#include "Window.h"
#include "ParticleEmitter.h"
int main(int argc, char* args[])
{
	//Configure application window
	int winWidth = 800, winHeight = 600; //Window dimensions
	std::string winName = "Window";      //Window name
	//Create application window
	Window appWin(winWidth, winHeight, winName);

	//Change BG color for shits and giggles
	Uint32 _PNK = CreateColor(255, 150, 150);
	appWin.setBGColor(_PNK);

	//Testing GameObject/Sprite functionality
	Sprite* spr = appWin.createSprite(50, 50, _BLU);
	GameObject* Player = new GameObject(spr);
	//Testing ParticleEmitter functionality
	Sprite* pSpr = appWin.createSprite(10, 10, CreateColor(0, 0, 0));
	ParticleEmmiter* pe = new ParticleEmmiter(pSpr, 2, 500);
	//Check whether application window is still open
	while (appWin.checkOpen())
	{
		//Update window
		appWin.screenUpdate();
		//Update GameObject
		Player->Update();
		pe->Update();
	}

	SDL_DestroyWindow(appWin.getWin()); //Destroy application window
	SDL_Quit(); //Clean up SDL when finished
	return 0;
}