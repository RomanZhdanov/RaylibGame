#include "EnemyManager.h"

void EnemyManager::create(std::string enemyName, Vector2 position, Player* target, WindowDimensions window)
{
	Enemy* enemy = enemyFactory.CreateEnemy(enemyName);
	enemy->setPosition(position);
	enemy->setTarget(target);
	enemy->setWindow(window);
	enemies.push_back(enemy);
}

void EnemyManager::update(float delta)
{
	for (auto enemy : enemies)
	{
		enemy->update(delta);
	}
}

void EnemyManager::draw()
{
	for (auto enemy : enemies)
	{
		enemy->draw();
	}
}

EnemyManager::~EnemyManager()
{
	for (auto enemy : enemies)
	{
		delete enemy;
	}
}