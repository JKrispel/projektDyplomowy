#include "drzewa_decyzyjne/distance_decision/distance_decision.h"
#include <decisions/decision_tree/final_decision.h>
#include <raymath.h>
#include "utils/NpcAction.h"
#include "drzewa_decyzyjne/distance_decision/close_enough_decision.h"

#include <iostream> // debug

std::unique_ptr<DecisionTreeNode> DistanceDecision::getBranch()
{
    std::cout << "Distance to target: " << distanceToTarget << std::endl;   // debug

    if (distanceToTarget < slowDownThreshold) {

        return std::make_unique<CloseEnoughDecision>(distanceToTarget);
    }
    else {

        return std::make_unique<FinalDecision<NpcAction>>(NpcAction::RUN);
    }
}

void DistanceDecision::setDistanceToTarget(float newDistanceToTarget)
{
    distanceToTarget = newDistanceToTarget;
}
