#pragma once
#include <pawn.h>

class Player: public Pawn {

public:
	void draw() override;
	void update() override;
};