#include "Slime.h"
#include "GameResources.h"

Slime::Slime(int _health, int _damage, float _speed, int _points, float _scale, Color _color)
    : Enemy(_health, _damage, _speed, _points, _scale, _color) {}

void Slime::loadAnimations()
{
	auto idle = std::make_shared<AnimatedSprite>(
		textureManager.get("slime_idle"),
		scale,
		6,
		1
	);
	auto run = std::make_shared<AnimatedSprite>(
		textureManager.get("slime_run"),
		scale,
		6,
		1
	);
	animations.add("idle", new Animation(idle, 0, 5, 1.f / 12.f, true));
	animations.add("run", new Animation(run, 0, 5, 1.f / 12.f, true));
	animations.set("idle");
}
