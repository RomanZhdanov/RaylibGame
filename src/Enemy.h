#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
public:
	Enemy(int _health, int _damage, float _speed, int _points, float _scale, Color _color) {
	    health = _health;
	    damage = _damage;
	    speed = _speed;
	    points = _points;
	    scale = _scale;
	    color = _color;
	}
	void setTarget(Player* player) { target = player; }
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void loadAnimations() {};
	virtual Enemy* Clone() const = 0;
protected:
	Player* target;
	int points;
	bool attacked;
};
