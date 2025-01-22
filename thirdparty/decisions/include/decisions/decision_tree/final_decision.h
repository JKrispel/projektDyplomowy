#pragma once
#include "decisions/decision_tree/decision_tree_node.h"
#include "decisions/action_manager/action_manager.h"
#include "decisions/action_manager/action.h"
#include <string>
#include <memory>

class FinalDecision :
    public DecisionTreeNode
{
private:
    std::unique_ptr<DecisionTreeNode> makeDecision() override;
protected:
    Action& rAction;
public:
    FinalDecision(Action& rActionNew) : rAction(rActionNew) {}
    Action& getActionRef();
};

