#include "RTNCenteredTextComponentInstance.h"

namespace rnoh {

RTNCenteredTextComponentInstance::RTNCenteredTextComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {
    m_stackNode.insertChild(m_textNode, 0);
}

StackNode &RTNCenteredTextComponentInstance::getLocalRootArkUINode() { return m_stackNode; }

void RTNCenteredTextComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    if (props == nullptr) {
        return;
    }
    m_textNode.setTextContent(props->text);
    m_textNode.setFontSize(30.0);
    m_textNode.setAlignment(ARKUI_ALIGNMENT_CENTER);
}

} // namespace rnoh