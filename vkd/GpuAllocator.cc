#include "GpuAllocator.h"
#include "Buffer.h"
#include <assert.h>
#include <iostream>

namespace vkd
{
    void GpuAllocator::Init(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device) {
        instance_ = instance;
        physicalDevice_ = physicalDevice;
        device_ = device;
    }

    void GpuAllocator::Allocate(Buffer& buffer, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties) {
        VkBufferCreateInfo bufferInfo{};
        bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferInfo.size = size;
        bufferInfo.usage = usage;
        bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        assert(vkCreateBuffer(device_, &bufferInfo, nullptr, &buffer.buffer_) == VK_SUCCESS);

        VkMemoryRequirements memRequirements;
        vkGetBufferMemoryRequirements(device_, buffer.buffer_, &memRequirements);

        VkMemoryAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex = FindMemoryType(memRequirements.memoryTypeBits, properties);

        assert(device_ != VK_NULL_HANDLE);
        assert(instance_ != VK_NULL_HANDLE);
        assert(vkAllocateMemory(device_, &allocInfo, nullptr, &buffer.memory_) == VK_SUCCESS);
        vkBindBufferMemory(device_, buffer.buffer_, buffer.memory_, 0);
    }

    void GpuAllocator::Deallocate(Buffer& buffer) {
        vkDestroyBuffer(device_, buffer.buffer_, nullptr);
        vkFreeMemory(device_, buffer.memory_, nullptr);
    }

    uint32_t GpuAllocator::FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
        VkPhysicalDeviceMemoryProperties memProperties;
        vkGetPhysicalDeviceMemoryProperties(physicalDevice_, &memProperties);

        for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
            if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
                return i;
            }
        }

        throw "failed to find suitable memory type!";
    }

} // namespace vkd
