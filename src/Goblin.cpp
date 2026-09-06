#include "Goblin.h"
#include "GameResources.h"

Goblin::Goblin(int _health, int _damage, float _speed, int _points, float _scale, Color _color)
    : Enemy(_health, _damage, _speed, _points, _scale, _color) {}

void Goblin::loadAnimations()
{
	auto idle = std::make_shared<AnimatedSprite>(
		textureManager.get("goblin_idle"),
		scale,
		6,
		1
	);
	auto run = std::make_shared<AnimatedSprite>(
		textureManager.get("goblin_run"),
		scale,
		6,
		1
	);
	animations.add("idle", new Animation(idle, 0, 5, 1.f / 12.f, true));
	animations.add("run", new Animation(run, 0, 5, 1.f / 12.f, true));
	animations.set("idle");
}
