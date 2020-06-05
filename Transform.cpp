#include "GameObject.h"
Transform::Transform() : translation_()
{}
void Transform::Update()
{
	translation_ += parent_->physics_->velocity_;
	parent_->sprite_->getRect()->x = (int)translation_.x_;
	parent_->sprite_->getRect()->y = (int)translation_.y_;
}
void Transform::SetTranslation(int x, int y)
{
	translation_.x_ = x;
	translation_.y_ = y;
}