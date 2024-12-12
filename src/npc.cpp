#include "npc.h"
#include "raylib.h"

Npc::Npc(Pawn& targetToFollow) : ai(*this, targetToFollow) {}

void Npc::draw()
{
	DrawCircle(position.x, position.y, radius, BLUE);
}

void Npc::update()
{
	// follow target
	position = Vector2Add(position, ai.seek());
}
