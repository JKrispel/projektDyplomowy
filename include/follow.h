#pragma once
#include "pawn.h"
#include <raymath.h>

class Follow {
private:
	Pawn& character;
	Pawn& target;


public:
	Follow(Pawn& character, Pawn& target): character(character), target(target) {}

	Vector2 seek();
};