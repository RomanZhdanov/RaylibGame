#include "EnemyFactory.h"
#include "Goblin.h"
#include "Slime.h"

EnemyFactory::EnemyFactory()
{
	enemies["goblin"] = new Goblin(10, 3, 150.f, 200);
	enemies["goblin-boss"] = new Goblin(40, 3, 75.f, 1000);
	enemies["slime"] = new Slime(5, 1, 100.f, 100);
}

EnemyFactory::~EnemyFactory()
{
	delete enemies["goblin"];
	delete enemies["slime"];
	delete enemies["goblin-boss"];
}
