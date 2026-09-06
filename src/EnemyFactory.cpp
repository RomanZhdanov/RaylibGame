#include "EnemyFactory.h"
#include "Goblin.h"
#include "Slime.h"

EnemyFactory::EnemyFactory()
{
	enemies["goblin"] = new Goblin(10, 3, 150.f, 200, 4.f, WHITE);
	enemies["goblin-boss"] = new Goblin(40, 10, 70.f, 1000, 8.f, PURPLE);
	enemies["slime"] = new Slime(5, 1, 100.f, 100, 4.f, WHITE);
}

EnemyFactory::~EnemyFactory()
{
	delete enemies["goblin"];
	delete enemies["slime"];
	delete enemies["goblin-boss"];
}
