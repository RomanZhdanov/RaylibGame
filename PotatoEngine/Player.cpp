#include "Player.h"
#include "GameResources.h"
#include "raymath.h"

Player::Player()
{	
	auto* player = new AnimatedSprite{
		textureManager.get("player"),
		3.f,
		60,
		1
	};

	score = 0;
	speed = 300.f;
	float animationSpeed = 1.f / 12.f;
	animations.add("idle", new Animation(player, 59, 59, animationSpeed, true));
	animations.add("idle_right", new Animation(player, 0, 0, animationSpeed, true));
	animations.add("idle_up", new Animation(player, 6, 6, animationSpeed, true));
	animations.add("idle_left", new Animation(player, 12, 12, animationSpeed, true));
	animations.add("idle_down", new Animation(player, 18, 18, animationSpeed, true));
	animations.add("run_right", new Animation(player, 0, 5, animationSpeed, true));
	animations.add("run_up", new Animation(player, 6, 11, animationSpeed, true));
	animations.add("run_left", new Animation(player, 12, 17, animationSpeed, true));
	animations.add("run_down", new Animation(player, 18, 23, animationSpeed, true));
	animations.add("attack_right", new Animation(player, 24, 27, animationSpeed, false));
	animations.add("attack_up", new Animation(player, 28, 31, animationSpeed, false));
	animations.add("attack_left", new Animation(player, 32, 35, animationSpeed, false));
	animations.add("attack_down", new Animation(player, 36, 39, animationSpeed, false));
}

void Player::update(float delta)
{
	switch (state) {
		case PlayerState::MOVE:
			move(delta);
			break;
		case PlayerState::ATTACK:
			attack(delta);
			break;
	}	

	if (isHurting())
	{
		hurting -= delta;
		animations.setColor(RED);
	}
	else
	{
		hurting = 0.f;
		animations.setColor(WHITE);
	}

	if (hitboxRecVisible)
	{
		DrawRectangleLines(
			hitbox.x,
			hitbox.y,
			hitbox.width,
			hitbox.height,
			RED
		);
	}

	if (collisionRecVisible)
	{
		DrawRectangleLines(
			collisionRec.x,
			collisionRec.y,
			collisionRec.width,
			collisionRec.height,
			BLUE
		);
	}
}

void Player::move(float delta)
{
	velocity = {};

	if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
	if (IsKeyDown(KEY_D)) velocity.x += 1.0;
	if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
	if (IsKeyDown(KEY_S)) velocity.y += 1.0;

	if (IsKeyPressed(KEY_SPACE))
	{
		state = PlayerState::ATTACK;
	}
	
	if (velocity.x < 0.f) animations.set("run_left");
	else if (velocity.x > 0.f) animations.set("run_right");
	else if (velocity.y < 0.f) animations.set("run_up");
	else if (velocity.y > 0.f) animations.set("run_down");

	positionLastFrame = position;

	if (Vector2Length(velocity) != 0.0)
	{
		direction = velocity;
		position = Vector2Add(position, Vector2Scale(Vector2Normalize(velocity), speed * delta));
	}
	else
	{
		if (direction.x < 0.f) animations.set("idle_left");
		else if (direction.x > 0.f) animations.set("idle_right");
		else if (direction.y < 0.f) animations.set("idle_up");
		else if (direction.y > 0.f) animations.set("idle_down");
		else animations.set("idle");
	}		

	float halfWidth = animations.getWidth() / 2;
	float halfHeight = animations.getHeight() / 2;

	Vector2 center{
		position.x + halfWidth,
		position.y + halfHeight
	};

	float padding{ 0.335f };

	float width = animations.getWidth() * padding;
	float height = animations.getHeight() * padding;

	collisionRec = {
		position.x + width,
		position.y + height,
		width,
		height
	};

	// left
	if (direction.x < 0.f) hitbox = {
		position.x,
		position.y + height,
		width,
		height
	};
	// right
	else if (direction.x > 0.f) hitbox = {
		position.x + width * 2,
		position.y + height,
		width,
		height
	};
	// up
	else if (direction.y < 0.f) hitbox = {
		position.x + width,
		position.y,
		width,
		height
	};
	// down
	else if (direction.y > 0.f) hitbox = {
		position.x + width,
		position.y + height * 2,
		width,
		height
	};
	else hitbox = {
		position.x + width,
		position.y + height * 2,
		width,
		height
	};

	if (collisionRec.x < 0.f ||
		collisionRec.y < 0.f ||
		collisionRec.x > window.width ||
		collisionRec.y > window.height)
	{
		undoMovement();
	}
	
	animations.setPosition(position);
	animations.update(delta);
}

void Player::attack(float delta)
{
	if (direction.x < 0.f) animations.set("attack_left");
	else if (direction.x > 0.f) animations.set("attack_right");
	else if (direction.y < 0.f) animations.set("attack_up");
	else if (direction.y > 0.f) animations.set("attack_down");
	else animations.set("attack_down");

	animations.update(delta);

	if (animations.isFinished())
	{
		animations.reset();
		state = PlayerState::MOVE;
	}
}