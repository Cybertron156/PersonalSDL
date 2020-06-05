#include "Window.h"
Window::Window(int w, int h, std::string name) : bgColor_(_WHT)
{
	SDL_Init(SDL_INIT_VIDEO); //Initialize SDL
	window_ =  (
		SDL_CreateWindow(
			name.c_str(),           //title
			SDL_WINDOWPOS_CENTERED, //x pos
			SDL_WINDOWPOS_CENTERED, //y pos
			w,                      //width
			h,                      //height
			SDL_WINDOW_RESIZABLE    //flags
		));
}
Sprite* Window::createSprite(int w, int h, Uint32 color)
{
	Sprite* spr_ = new Sprite(SDL_GetWindowSurface(window_), w, h, color);
	return spr_;
}
SDL_Window* Window::getWin()
{
	return window_;
}
bool Window::checkOpen()
{
	SDL_Event event;
	bool open = true;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case(SDL_QUIT):
			open = false;
			break;
		}
	}
	return open;
}
void Window::screenUpdate()
{
	SDL_UpdateWindowSurface(window_);
	SDL_FillRect(SDL_GetWindowSurface(window_), NULL, bgColor_);
}
void Window::setBGColor(Uint32 color)
{
	bgColor_ = color;
}
Uint32 CreateColor(int r, int g, int b)
{
	Uint32 R = (int)(((float)r / 255) * 0x00ff0000);
	Uint32 G = (int)(((float)g / 255) * 0x0000ff00);
	Uint32 B = (int)(((float)b / 255) * 0x000000ff);
	return R | G | B;
}