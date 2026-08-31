#include "EnemyManager.h"

void EnemyManager::create(std::string enemyName, Vector2 position, Player* target, WindowDimensions window)
{
	Enemy* enemy = enemyFactory.CreateEnemy(enemyName);
	enemy->setPosition(position);
	enemy->setTarget(target);
	enemy->setWindow(window);
	enemy->loadAnimations();
	enemies.push_back(enemy);
}

void EnemyManager::update(float delta)
{
    for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end();)
	{
	    Enemy* enemy = *it;
		enemy->update(delta);

		if (!enemy->isAlive)
		{
		    it = enemies.erase(it);
			delete enemy;
			continue;
		}

		++it;
	}
}

void EnemyManager::draw()
{
	for (auto enemy : enemies)
	{
		enemy->showCollisionRec(collisionRecVisible);
		enemy->draw();
	}
}

void EnemyManager::deleteAll()
{
	for (auto enemy : enemies)
	{
		delete enemy;
	}

	enemies.clear();
}

EnemyManager::~EnemyManager()
{
	deleteAll();
}
