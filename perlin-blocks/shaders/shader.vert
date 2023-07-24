#version 450

layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 gridPos;

layout(location = 0) out vec3 fragColor;

void main() {
    mat4 translateMat = {{1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {gridPos.x, gridPos.y, 0, 1}};
    gl_Position = ubo.proj * ubo.view * translateMat * ubo.model * vec4(inPosition, 1.0);
    fragColor = inColor;
}
