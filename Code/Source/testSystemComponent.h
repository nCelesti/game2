
#pragma once

#include <AzCore/Component/Component.h>

#include <test/testBus.h>

namespace test
{
    class testSystemComponent
        : public AZ::Component
        , protected testRequestBus::Handler
    {
    public:
        AZ_COMPONENT(testSystemComponent, "{63eb0fe2-2d97-4337-b49e-1b0664fa6744}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        testSystemComponent();
        ~testSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // testRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
