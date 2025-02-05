#include "player.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>

void Player::draw()
{
	DrawCircle(position.x, position.y, radius, WHITE);
}

void Player::update()
{	
	Vector2 direction = Vector2Zero();
	
	if (IsKeyDown(KEY_UP) && position.y >= area.y + radius) {
		direction.y -= speed;
	}
	if (IsKeyDown(KEY_DOWN) && position.y <= area.y + area.height - radius) {
		direction.y += speed;
	}
	if (IsKeyDown(KEY_LEFT) && position.x >= area.x + radius) {
		direction.x -= speed;
	}
	if (IsKeyDown(KEY_RIGHT) && position.x <= area.x + area.width - radius) {
		direction.x += speed;
	}

	position = Vector2Add(position, Vector2Scale(Vector2Normalize(direction), speed));

	return;
}
