#include "Slime.h"
#include "GameResources.h"

Slime::Slime()
{	
	speed = 100.f;
}

void Slime::loadAnimations()
{
	auto* idle = new AnimatedSprite{
		textureManager.get("slime_idle"),
		6.f,
		6,
		1
	};
	auto* run = new AnimatedSprite{
		textureManager.get("slime_run"),
		6.f,
		6,
		1
	};
	animations.add("idle", new Animation(idle, 0, 5, 1.f / 12.f, true));
	animations.add("run", new Animation(run, 0, 5, 1.f / 12.f, true));
	animations.set("idle");
}