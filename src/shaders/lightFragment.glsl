#version 330 core

out vec4 FragColor;

// in vec3 ourColor;
in vec2 TexCoord;

// uniform sampler2D ftexture1;
// uniform sampler2D ftexture2;

uniform vec3 lightColor;

struct Material {
    sampler2D texture_ambience;
    sampler2D texture_diffuse;
    sampler2D texture_specular;
    // sampler2D emission;
    float     shininess;
}; 
uniform Material material;

void main()
{
    vec4 texColor = texture(material.texture_diffuse, TexCoord);
    FragColor = vec4(texColor.rgb * lightColor, 1.0f);
    // FragColor = vec4(lightColor, 1.0f);
}
