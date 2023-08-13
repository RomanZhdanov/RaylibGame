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
	void showCollisionRec(bool value) { collisionRecVisible = value; }
	void create(std::string enemy, Vector2 position, Player* target, WindowDimensions window);
	void deleteAll();
private:
	bool collisionRecVisible{ false };
	std::vector<Enemy*> enemies{};
	EnemyFactory enemyFactory;
};
