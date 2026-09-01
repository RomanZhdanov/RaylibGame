#pragma once
#include <vector>
#include <string>
#include "Enemy.h"
#include "EnemyFactory.h"

class EnemyManager
{
public:
	~EnemyManager();
	void setLimit(int _limit) { limit = _limit; }
	int getLimit() { return limit; }
	void update(float delta);
	void draw();
	void showCollisionRec(bool value) { collisionRecVisible = value; }
	void create(std::string enemy, Vector2 position, Player* target, WindowDimensions window);
	void deleteAll();
	bool isFull() { return enemies.size() >= limit; }
private:
    int limit;
	bool collisionRecVisible{ false };
	std::vector<Enemy*> enemies{};
	EnemyFactory enemyFactory;
};
