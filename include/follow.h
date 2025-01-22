#pragma once
#include "pawn.h"
#include <raymath.h>
#include <decisions/action_manager/action.h>

class Follow: public Action {
private:
	Pawn& character;
	Pawn& target;


public:
	Follow(Pawn& character, Pawn& target): Action(1.0f), character(character), target(target) {}

	void execute() override;
	Pawn& getTargetRef();
};
