#pragma once
#include <vector>
class Particle : public GameObject
{
public:
	Particle(Sprite* s, int life);
	bool LifeUp();
	void Update();
	~Particle();
private:
	int lifetime_, lifeUsed_;
};

class ParticleEmmiter
{
public:
	ParticleEmmiter(Sprite* sprite, int frequency, int duration);
	void Update();
	~ParticleEmmiter();
private:
	std::vector<Particle*> particleList_;
	int frequency_, buildup_, duration_;
	int particles_;
	Sprite* sprite_;

	void addParticle();
	void removeParticle(unsigned index);
};