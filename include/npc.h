#pragma once
#include <pawn.h>


class Npc : public Pawn {

public:
	void draw() override;
	void update() override;
};