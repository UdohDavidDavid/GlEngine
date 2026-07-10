#version 330 core

out vec4 FragColor;

// in vec3 ourColor;
in vec2 TexCoord;

// uniform sampler2D ftexture1;
// uniform sampler2D ftexture2;

uniform vec3 lightColor;

uniform sampler2D glowstoneTexture;

void main()
{
    vec4 texColor = texture(glowstoneTexture, TexCoord);
    // FragColor = vec4(texColor.rgb * lightColor, 1.0f);
    FragColor = vec4(lightColor, 1.0f);
}
