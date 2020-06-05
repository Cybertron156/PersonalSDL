#include "GameObject.h"
Physics::Physics()
{
	velocity_ = Vector2D(0, 0);
	drag_ =	.992;
}
void Physics::Update()
{
	ApplyDrag();
}
void Physics::ApplyDrag()
{
	if(velocity_.Magnitude() > .1)
		velocity_ *= drag_;
	else
		velocity_ = Vector2D(0, 0);
}
void Physics::Draw()
{

}