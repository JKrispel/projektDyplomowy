﻿#pragma once
#include <memory>
#include <unordered_map>
#include <raymath.h>
#include "pawn.h"
#include "decisions/action_manager/action_manager.h"
#include "drzewa_decyzyjne/distance_decision/distance_decision.h"
#include "utils/NpcAction.h"

class Npc : public Pawn {

public:

	Pawn& target;
	DistanceDecision rootNode = DistanceDecision(Vector2Distance(position, target.position));
	std::unique_ptr<ActionManager> manager;
	// mapa możliwych Akcji, unique_ptr dla polimorfizmu
	std::unordered_map<NpcAction, std::unique_ptr<Action>> npcActions;

	Npc(Pawn& target);

	void draw() override;
	void update() override;
};
