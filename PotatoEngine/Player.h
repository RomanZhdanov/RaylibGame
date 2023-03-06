#pragma once
#include "AnimationManager.h"

class Player
{
public:
	Player();
	void update(float delta);
	void draw();
private:
	AnimationManager animations;
};