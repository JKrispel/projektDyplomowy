#include "follow.h"

Vector2 Follow::seek()
{
	Vector2 directionVector = Vector2Normalize(Vector2Subtract(target.position, character.position));

	return Vector2Scale(directionVector, character.speed);
}
