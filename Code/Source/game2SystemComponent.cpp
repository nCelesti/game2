
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "game2SystemComponent.h"

namespace game2
{
    void game2SystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<game2SystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<game2SystemComponent>("game2", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void game2SystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("game2Service"));
    }

    void game2SystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("game2Service"));
    }

    void game2SystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void game2SystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    game2SystemComponent::game2SystemComponent()
    {
        if (game2Interface::Get() == nullptr)
        {
            game2Interface::Register(this);
        }
    }

    game2SystemComponent::~game2SystemComponent()
    {
        if (game2Interface::Get() == this)
        {
            game2Interface::Unregister(this);
        }
    }

    void game2SystemComponent::Init()
    {
    }

    void game2SystemComponent::Activate()
    {
        game2RequestBus::Handler::BusConnect();
    }

    void game2SystemComponent::Deactivate()
    {
        game2RequestBus::Handler::BusDisconnect();
    }
}
