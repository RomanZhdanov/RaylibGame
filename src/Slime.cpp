#include "Slime.h"
#include "GameResources.h"

Slime::Slime(int _health, int _damage, float _speed, int _points)
    : Enemy(_health, _damage, _speed, _points) {}

void Slime::loadAnimations()
{
	auto idle = std::make_shared<AnimatedSprite>(
		textureManager.get("slime_idle"),
		4.f,
		6,
		1
	);
	auto run = std::make_shared<AnimatedSprite>(
		textureManager.get("slime_run"),
		4.f,
		6,
		1
	);
	animations.add("idle", new Animation(idle, 0, 5, 1.f / 12.f, true));
	animations.add("run", new Animation(run, 0, 5, 1.f / 12.f, true));
	animations.set("idle");
}
