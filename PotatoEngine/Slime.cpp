#include "Slime.h"
#include "GameResources.h"

Slime::Slime()
{
	auto* idle = new AnimatedSprite{
		textureManager.get("slime_idle"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	};
	auto* run = new AnimatedSprite{
		textureManager.get("slime_run"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	};
	animations.add("idle", idle);
	animations.add("run", run);
	animations.set("idle");
}