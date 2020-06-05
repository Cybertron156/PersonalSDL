#include "Window.h"
#include "ParticleEmitter.h"
#include "C:/Users/Seth/Desktop/Seed.h"
ParticleEmmiter::ParticleEmmiter(Sprite* sprite, int frequency, int duration) : 
	buildup_(0)
	, sprite_(sprite)
	, particles_(0)
	, frequency_(frequency)
	, duration_(duration)
{

}
void ParticleEmmiter::Update()
{
	unsigned seed = 0, nseed = 0;
	SeedGen(seed, nseed);

	++buildup_;
	if (buildup_ >= frequency_)
		addParticle();

	for (int i = 0; i < particles_; ++i)
	{
		if (particleList_[i])
		{
			particleList_[i]->Update();
			if (particleList_[i]->LifeUp())
				removeParticle(i);
		}
	}
}
void ParticleEmmiter::addParticle()
{
	particleList_.push_back(new Particle(sprite_, duration_));
	++particles_;
	buildup_ = 0;
}
void ParticleEmmiter::removeParticle(unsigned index)
{
	delete particleList_[index];
	particleList_[index] = NULL;
	--particles_;

}
ParticleEmmiter::~ParticleEmmiter()
{
	for (int i = 0; i < particles_; ++i)
		delete particleList_[i];
}

Particle::Particle(Sprite* s, int life) : 
	GameObject(s)
	, lifeUsed_(0)
	, lifetime_(GenMax<int>(life))
{
	SetPos(100, 100);
	physics_->velocity_ = Vector2D(GenMax<float>(360.f));
	physics_->velocity_ *= GenMax<float>(1000.f)/1000.f;
}
bool Particle::LifeUp()
{
	return lifeUsed_ >= lifetime_;
}
void Particle::Update()
{
	GameObject::Update();
	++lifeUsed_;
}
Particle::~Particle() {}