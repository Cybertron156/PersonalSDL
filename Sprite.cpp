#include "GameObject.h"
Sprite::Sprite(SDL_Surface* bg, int w, int h, Uint32 color) : bg_(bg), color_(color)
{
	surface_ = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface_, getRect(), color_);
}
void Sprite::Draw()
{
	SDL_BlitSurface(surface_, NULL, bg_, getRect());
}
Sprite::~Sprite()
{}
SDL_Rect* Sprite::getRect()
{
	return &surface_->clip_rect;
}