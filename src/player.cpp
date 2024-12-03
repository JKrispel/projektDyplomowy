#include "player.h"
#include "raylib.h"
#include <raymath.h>
#include <iostream>

void Player::draw()
{
	DrawCircle(position.x, position.y, radius, WHITE);
}

void Player::update()
{	
	Vector2 direction = Vector2Zero();
	
	if (IsKeyDown(KEY_UP)) {
		direction.y -= speed;
	}
	if (IsKeyDown(KEY_DOWN)) {
		direction.y += speed;
	}
	if (IsKeyDown(KEY_LEFT)) {
		direction.x -= speed;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		direction.x += speed;
	}
	bool collision = !CheckCollisionCircleRec(position, radius, area);

	if (!collision) {

		position = Vector2Add(position, Vector2Scale(Vector2Normalize(direction), speed));
	}
	else {
		position = Vector2Add(position, Vector2Negate(Vector2Scale(Vector2Normalize(direction), 3*speed)));
	}
}
