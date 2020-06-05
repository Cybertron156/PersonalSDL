#include "InputController.h"
#include "GameObject.h"
bool KeyInput(KEYCODE k)
{
	const Uint8* kbs = SDL_GetKeyboardState(0);
	return kbs[k] != 0;
}
void GameObject::PlayerController()
{
	if (KeyInput(LEFT_))
		physics_->velocity_.x_ = -1;
	else if (KeyInput(RIGHT_))
		physics_->velocity_.x_ = 1;

	if (KeyInput(UP_))
		physics_->velocity_.y_ = -1;
	else if (KeyInput(DOWN_))
		physics_->velocity_.y_ = 1;
}