#pragma once
#include "Component.h"
#include "Vector2D.h"
class Transform : public Component
{
public:
	Transform();
	void Update();
	void SetTranslation(int x, int y);
private:
	Vector2D translation_;
};