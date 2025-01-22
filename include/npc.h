#pragma once
#include <memory>
#include "pawn.h"
#include "follow.h"
#include <decisions/action_manager/action_manager.h>
#include "drzewa_decyzyjne/distance_decision.h"

class Npc : public Pawn {

public:
	// AI dla testu bez decyzyjnosci
	Pawn& target;
	DistanceDecision rootNode;
	std::unique_ptr<ActionManager> manager;

	Npc(Pawn& target);

	void draw() override;
	void update() override;
};
