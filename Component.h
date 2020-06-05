#pragma once
typedef class GameObject* GameObjectPtr;
typedef class Component
{
public:
	GameObjectPtr parent_;
} Component, *ComponentPtr;