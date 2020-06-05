#include "GameObject.h"
#include "InputController.h"
#include <iostream>
GameObject::GameObject(Sprite* s) : sprite_(s)
{
	physics_ = new Physics();
	transform_ = new Transform();

	AddComponent(sprite_);
	AddComponent(physics_);
	AddComponent(transform_);
}
void GameObject::Update()
{
	PlayerController();
	physics_->Update();
	transform_->Update();
	sprite_->Draw();
}
void GameObject::Draw()
{
	sprite_->Draw();
}
void GameObject::AddComponent(Component* c)
{
	c->parent_ = this;
}
void GameObject::SetPos(int x, int y)
{
	transform_->SetTranslation(x, y);
}