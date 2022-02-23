
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "testSystemComponent.h"

namespace test
{
    void testSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<testSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<testSystemComponent>("test", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void testSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("testService"));
    }

    void testSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("testService"));
    }

    void testSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void testSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    testSystemComponent::testSystemComponent()
    {
        if (testInterface::Get() == nullptr)
        {
            testInterface::Register(this);
        }
    }

    testSystemComponent::~testSystemComponent()
    {
        if (testInterface::Get() == this)
        {
            testInterface::Unregister(this);
        }
    }

    void testSystemComponent::Init()
    {
    }

    void testSystemComponent::Activate()
    {
        testRequestBus::Handler::BusConnect();
    }

    void testSystemComponent::Deactivate()
    {
        testRequestBus::Handler::BusDisconnect();
    }
}
