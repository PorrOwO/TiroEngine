#version 460 core
out vec4 FragColor;

in vec3 FragPos;

void main()
{
    // Simple shading based on position to give some visual depth
    vec3 color = normalize(FragPos) * 0.5 + 0.5;
    FragColor = vec4(color, 1.0f);
}
