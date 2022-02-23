
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "testSystemComponent.h"

namespace test
{
    class testModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(testModule, "{78781feb-38d4-4411-80d5-d831c570d2a4}", AZ::Module);
        AZ_CLASS_ALLOCATOR(testModule, AZ::SystemAllocator, 0);

        testModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                testSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<testSystemComponent>(),
            };
        }
    };
}// namespace test

AZ_DECLARE_MODULE_CLASS(Gem_test, test::testModule)
