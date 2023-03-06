#include "EnemyFactory.h"
#include "Goblin.h"
#include "Slime.h"

EnemyFactory::EnemyFactory()
{
	enemies["goblin"] = new Goblin();
	enemies["slime"] = new Slime();
}

EnemyFactory::~EnemyFactory()
{
	delete enemies["goblin"];
	delete enemies["slime"];
}