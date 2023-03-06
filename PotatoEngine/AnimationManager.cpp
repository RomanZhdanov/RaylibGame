#include "AnimationManager.h"

void AnimationManager::add(const char* animName, Animation* animation)
{
	animations.insert(std::make_pair(animName, animation));
}

void AnimationManager::set(const char* animName)
{
	activeAnimation = animations[animName];
}

void AnimationManager::update(float delta)
{
	activeAnimation->update(delta);
}

void AnimationManager::draw()
{
	activeAnimation->draw();
}

void AnimationManager::setPosition(Vector2 position)
{
	activeAnimation->sprite->setPosition(position);
}

void AnimationManager::setRight()
{
	activeAnimation->sprite->setRightLeft(1.f);
}

void AnimationManager::setLeft()
{
	activeAnimation->sprite->setRightLeft(-1.f);
}