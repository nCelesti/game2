
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace test
{
    class testRequests
    {
    public:
        AZ_RTTI(testRequests, "{3e89ee36-dd81-4a35-8945-ff6d77c0f39b}");
        virtual ~testRequests() = default;
        // Put your public methods here
    };
    
    class testBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using testRequestBus = AZ::EBus<testRequests, testBusTraits>;
    using testInterface = AZ::Interface<testRequests>;

} // namespace test
