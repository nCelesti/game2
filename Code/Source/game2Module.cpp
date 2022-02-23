
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "game2SystemComponent.h"

namespace game2
{
    class game2Module
        : public AZ::Module
    {
    public:
        AZ_RTTI(game2Module, "{f07ef45a-7e6a-47ca-ac86-cad79ad8489e}", AZ::Module);
        AZ_CLASS_ALLOCATOR(game2Module, AZ::SystemAllocator, 0);

        game2Module()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                game2SystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<game2SystemComponent>(),
            };
        }
    };
}// namespace game2

AZ_DECLARE_MODULE_CLASS(Gem_game2, game2::game2Module)
