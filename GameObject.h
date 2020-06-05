#include "Transform.h"
#include "Physics.h"
#include "Sprite.h"
class GameObject
{
public:
	GameObject(Sprite* s);
	void Update();
	void Draw();
	void PlayerController();
	void AddComponent(Component* c);
	void SetPos(int x, int y);
	Transform* transform_;
	Physics* physics_;
	Sprite* sprite_;
private:
};