#version 450

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform DirectionalLight {
    vec3 direction;
    vec3 color;
} dirLight;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragNormal;

layout(location = 0) out vec4 outColor;

vec3 CalculateDirLight()
{
    vec3 normalizedNormal = normalize(fragNormal);
	vec3 normalizedNegatedLightDir = normalize(-dirLight.direction);
    float lightAmount = clamp(dot(normalizedNegatedLightDir, normalizedNormal), 0, 1);
	vec3 finalColor = lightAmount * dirLight.color;
	return finalColor;
}


void main() {
    outColor = texture(texSampler, fragTexCoord) * vec4(CalculateDirLight(), 1);
}
