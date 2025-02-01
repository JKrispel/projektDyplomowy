#pragma once
#include "decisions/decision_tree/decision_tree_node.h"
#include "decisions/action_manager/action_manager.h"
#include "decisions/action_manager/action.h"
#include <string>
#include <memory>
#include <type_traits>


// Template class for FinalDecision with user-defined enum
template <typename ActionEnum>
class FinalDecision : public DecisionTreeNode {
    static_assert(std::is_enum_v<ActionEnum>, "ActionEnum must be an enum type!");

private:
    ActionEnum actionType;  // Store the user-defined action enum

public:
    explicit FinalDecision(ActionEnum action) : actionType(action) {}

    ActionEnum getActionType() const { return actionType; }

    // ✅ Define the function in the header file (template inline definition)
    std::unique_ptr<DecisionTreeNode> makeDecision() override {
        return std::make_unique<FinalDecision<ActionEnum>>(actionType);
    }
};