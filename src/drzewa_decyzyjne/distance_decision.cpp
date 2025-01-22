#include "drzewa_decyzyjne/distance_decision.h"
#include "follow.h"
#include <raymath.h>

DistanceDecision::DistanceDecision(int newDistance, Pawn& character, Pawn& target) :
	distance(newDistance), 
	character(character),
	target(target),
	finalDecision(std::make_unique<FinalDecision>(string identifier for action)) {
	
	
}

// cannot instatiate DecsionTreeNode
std::unique_ptr<DecisionTreeNode> DistanceDecision::getBranch()
{

	if (Vector2Distance(character.position, target.position) < distance) {

		return std::make_unique<DistanceDecision>(200, character, target);
	}
	else {

		return std::move(finalDecision);
	}
}
