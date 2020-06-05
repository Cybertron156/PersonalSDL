#pragma once
#include <SDL.h>
typedef enum { RIGHT_ = 79, LEFT_, DOWN_, UP_ } KEYCODE;
bool KeyInput(KEYCODE k);