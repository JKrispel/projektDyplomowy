#include "drzewa_decyzyjne/distance_decision/close_enough_decision.h"
#include <memory>
#include <decisions/decision_tree/final_decision.h>
#include "utils/NpcAction.h"


std::unique_ptr<DecisionTreeNode> CloseEnoughDecision::getBranch()
{

    if (distanceToTarget < stopThreshold) {

        return std::make_unique<FinalDecision<NpcAction>>(NpcAction::STOP);
    }
    else {

        return std::make_unique<FinalDecision<NpcAction>>(NpcAction::WALK);
    }
}
