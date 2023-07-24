#version 450

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 gridPos;
layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;



void main() {
    mat4 scaleMat = {{1.1, 0, 0, 0},
                    {0, 1.1, 0, 0},
                    {0, 0, 1.1, 0},
                    {0, 0, 0, 1}};
    mat4 translateMat = {{1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {gridPos.x, gridPos.y, 0, 1}};
    gl_Position = ubo.proj * ubo.view * translateMat * scaleMat * ubo.model * vec4(inPosition, 1);
}