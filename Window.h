#pragma once
#include "Colors.h"
#include "GameObject.h"
#include <string>
class Window
{
public:
	Window(int w, int h, std::string name);
	Sprite* createSprite(int w, int h, Uint32 color);
	SDL_Window* getWin();
	bool checkOpen();
	void screenUpdate();
	void setBGColor(Uint32 color);
private:
	SDL_Window* window_;
	Uint32 bgColor_;
};