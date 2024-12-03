#include "npc.h"
#include "raylib.h"

void Npc::draw()
{
	DrawCircle(position.x, position.y, radius, BLUE);
}

void Npc::update()
{
	// AI
}
