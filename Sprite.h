#pragma once
#include <SDL.h>
#include "Component.h"
class Sprite : public Component
{
public:
	Sprite(SDL_Surface* bg, int w, int h, Uint32 color);
	void Draw();
	~Sprite();
	SDL_Rect* getRect();
	SDL_Surface* surface_;
	Uint32 color_;
	SDL_Surface* bg_;
};