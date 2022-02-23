
#pragma once

#include <AzCore/Component/Component.h>

#include <game2/game2Bus.h>

namespace game2
{
    class game2SystemComponent
        : public AZ::Component
        , protected game2RequestBus::Handler
    {
    public:
        AZ_COMPONENT(game2SystemComponent, "{c38cd4a5-eee5-40dd-88fc-0ce76b111ba4}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        game2SystemComponent();
        ~game2SystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // game2RequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
