#pragma once
#include "ShadowNodes.h"
#include "RNOH/CppComponentInstance.h"
#include "RNOH/arkui/StackNode.h"
#include "RNOH/arkui/TextNode.h"

namespace rnoh {
class RTNCenteredTextComponentInstance : public CppComponentInstance<facebook::react::RTNCenteredTextShadowNode> {
private:
    using FragmentTouchTargetByTag = std::unordered_map<facebook::react::Tag, std::shared_ptr<TouchTarget>>;

    TextNode m_textNode{};
    StackNode m_stackNode{};

public:
    RTNCenteredTextComponentInstance(Context context);
    StackNode &getLocalRootArkUINode() override;

protected:
    void onPropsChanged(SharedConcreteProps const &props) override;
};
} // namespace rnoh