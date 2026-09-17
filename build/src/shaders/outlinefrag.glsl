#version 330

out vec4 FragColor;
in vec3 FragPos;  

struct Material {
    // sampler2D texture_ambience;
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;

    sampler2D texture_diffuse2;
    sampler2D texture_specular2;
    // sampler2D emission;
    float     shininess;
}; 

void main() {
    FragColor = vec4(0.04, 0.28, 0.26, 1.0);
}