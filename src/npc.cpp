#include <raylib.h>
#include <decisions/decision_tree/final_decision.h>
#include "npc.h"
#include "actions/run.h"
#include "actions/walk.h"
#include "actions/stop.h"

#include <iostream>

Npc::Npc(Pawn& target):
	target(target)
{
	manager = std::make_unique<ActionManager>();
	// inicjalizacja unordered_map
	npcActions[NpcAction::RUN] = std::make_unique<Run>(*this, target);
	npcActions[NpcAction::WALK] = std::make_unique<Walk>(*this, target);
	npcActions[NpcAction::STOP] = std::make_unique<Stop>();
}

void Npc::draw()
{
	DrawCircle(position.x, position.y, radius, BLUE);
}

void Npc::update()
{
	// aktualizuj odgległość
	rootNode.setDistanceToTarget(Vector2Distance(position, target.position));
	// podejmij decyzję
	std::unique_ptr<DecisionTreeNode> decision = rootNode.makeDecision();
	auto* finalDecision = dynamic_cast<FinalDecision<NpcAction>*>(decision.get());
	NpcAction actionType = finalDecision->getActionType();
	npcActions[actionType]->execute();
} 
// Pawn position bez settera!