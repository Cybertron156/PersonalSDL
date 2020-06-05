#pragma once
#include "Component.h"
#include "Vector2D.h"
class Physics : public Component
{
public:
	Physics();
	void Update();
	void Draw();
	void ApplyDrag();
	Vector2D velocity_;
private:
	double drag_;
};