#pragma once
#include <pawn.h>
#include "follow.h"

class Npc : public Pawn {

public:
	// AI dla testu bez decyzyjnosci
	Follow ai;
	
	Npc(Pawn& targetToFollow);

	void draw() override;
	void update() override;
};