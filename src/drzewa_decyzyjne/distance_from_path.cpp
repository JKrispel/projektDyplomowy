#include "drzewa_decyzyjne/enemy_in_range/distance_from_path.h"
#include <decisions/decision_tree/final_decision.h>
#include "utils/npc_action.h"

std::unique_ptr<DecisionTreeNode> DistanceFromPath::getBranch()
{
    if (enemyRef.getPathDistance() > distanceThreshold) {

        return std::make_unique<FinalDecision<NpcAction>>(NpcAction::PATROL);
    }
    else {

        return std::make_unique<FinalDecision<NpcAction>>(NpcAction::CHASE);
    }
}