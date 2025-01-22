#include "npc.h"
#include "raylib.h"
#include "drzewa_decyzyjne/follow_decision.h"

Npc::Npc(Pawn& target):
	target(target),
	rootNode(DistanceDecision(60, *this, target))
{
	manager = std::make_unique<ActionManager>();
}

void Npc::draw()
{
	DrawCircle(position.x, position.y, radius, BLUE);
}

void Npc::update()
{
	// follow target
	std::unique_ptr<DecisionTreeNode> decision = rootNode.makeDecision();
	// po tej linijce decision powinno zawierać FinalDecision, które posiada akcje Follow
	// 
	// FinalDecision* finalDecision = dynamic_cast<FinalDecision*>(decision.get());
	// tymczasowe obejście, należy zaimplementować getActionPtr w klasie bazowej - FinalDecision
	FollowDecision* finalDecision = dynamic_cast<FollowDecision*>(decision.get());
	auto actionPtr = finalDecision->getActionPtr();
	manager->scheduleAction(std::move(actionPtr));
	manager->execute(GetFrameTime());
} 
