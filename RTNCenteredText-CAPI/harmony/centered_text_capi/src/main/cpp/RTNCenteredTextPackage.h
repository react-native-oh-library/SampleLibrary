#include "RNOH/Package.h"
#include "ComponentDescriptors.h"
#include "RTNCenteredTextJSIBinder.h"
#include "RTNCenteredTextComponentInstance.h"

namespace rnoh {

class RTNCenteredTextComponentInstanceFactoryDelegate : public ComponentInstanceFactoryDelegate {
public:
    using ComponentInstanceFactoryDelegate::ComponentInstanceFactoryDelegate;

    ComponentInstance::Shared create(ComponentInstance::Context ctx) override {
        if (ctx.componentName == "RTNCenteredText") {
            return std::make_shared<RTNCenteredTextComponentInstance>(std::move(ctx));
        }
        return nullptr;
    }
};

class RTNCenteredTextPackage : public Package {
public:
    RTNCenteredTextPackage(Package::Context ctx): Package(ctx) {}

    ComponentInstanceFactoryDelegate::Shared createComponentInstanceFactoryDelegate() override {
        return std::make_shared<RTNCenteredTextComponentInstanceFactoryDelegate>();
    }

    std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
        return {facebook::react::concreteComponentDescriptorProvider<facebook::react::RTNCenteredTextComponentDescriptor>()};
    }

    ComponentJSIBinderByString createComponentJSIBinderByName() override {
        return {{"RTNCenteredText", std::make_shared<RTNCenteredTextJSIBinder>()}};
    }
};
} // namespace rnoh