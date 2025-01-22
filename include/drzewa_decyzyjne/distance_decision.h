#pragma once
#include <memory>
#include <decisions/decision_tree/decision.h>
#include <decisions/decision_tree/final_decision.h>

#include "Pawn.h"

class DistanceDecision : public Decision {

private:
	int distance = 1;
	Pawn& character;
	Pawn& target;
	std::unique_ptr<FinalDecision> finalDecision;  // Use smart pointer for ownership

public:
	DistanceDecision(int newDistance, Pawn& character, Pawn& target);

	std::unique_ptr<DecisionTreeNode> getBranch() override;
};
