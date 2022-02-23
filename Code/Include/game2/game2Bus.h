
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace game2
{
    class game2Requests
    {
    public:
        AZ_RTTI(game2Requests, "{92bc0846-2614-4421-9bdb-eb9022c4e902}");
        virtual ~game2Requests() = default;
        // Put your public methods here
    };
    
    class game2BusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using game2RequestBus = AZ::EBus<game2Requests, game2BusTraits>;
    using game2Interface = AZ::Interface<game2Requests>;

} // namespace game2
