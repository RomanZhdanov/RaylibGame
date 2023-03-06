#pragma once
#include <unordered_map>
#include <string>
#include "Enemy.h"

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	Enemy* CreateEnemy(std::string type) {
		return enemies[type]->Clone();
	}
private:
	std::unordered_map<std::string, Enemy*> enemies;
};