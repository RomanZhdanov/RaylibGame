#pragma once
#include <vector>
#include <string>
#include "Enemy.h"
#include "EnemyFactory.h"

class EnemyManager
{
public:
	~EnemyManager();
	void update(float delta);
	void draw();
	void create(std::string enemy, Vector2 position);
private:
	std::vector<Enemy*> enemies{};
	EnemyFactory enemyFactory;
};
