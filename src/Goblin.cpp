#include "Goblin.h"
#include "GameResources.h"

Goblin::Goblin()
{
	speed = 150.f;
	points = 200;
}

void Goblin::loadAnimations()
{
	auto idle = std::make_shared<AnimatedSprite>(
		textureManager.get("goblin_idle"),
		4.f,
		6,
		1
	);
	auto run = std::make_shared<AnimatedSprite>(
		textureManager.get("goblin_run"),
		4.f,
		6,
		1
	);
	animations.add("idle", new Animation(idle, 0, 5, 1.f / 12.f, true));
	animations.add("run", new Animation(run, 0, 5, 1.f / 12.f, true));
	animations.set("idle");
}
