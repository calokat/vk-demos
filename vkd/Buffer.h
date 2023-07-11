#ifndef BUFFER_H
#define BUFFER_H
#include <vulkan/vulkan.h>

namespace vkd {
    struct Buffer {
        VkBuffer buffer_;
        VkDeviceMemory memory_;
        void* mappedData_{nullptr};
    };
};


#endif