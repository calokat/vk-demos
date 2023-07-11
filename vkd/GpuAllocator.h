#ifndef GPU_ALLOCATOR_H
#define GPU_ALLOCATOR_H
#include <vulkan/vulkan.h>

namespace vkd {

struct Buffer;

class GpuAllocator {
public:
    void Init(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device);
    void Allocate(Buffer& buffer, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties);
    void Deallocate(Buffer& buffer);
private:
    VkDevice device_ = VK_NULL_HANDLE;
    VkPhysicalDevice physicalDevice_ = VK_NULL_HANDLE;
    VkInstance instance_ = VK_NULL_HANDLE;
    uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
};
}
#endif