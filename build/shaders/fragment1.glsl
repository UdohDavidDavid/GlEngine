#version 330 core
out vec4 FragColor;

in vec2 texCoord;
// uniform sampler2D rubixTexture;

uniform vec3 lightColor;
uniform vec3 objectColor;

in vec3 Normal;
in vec3 FragPos;  

uniform vec3 lightPos;

uniform vec3 viewPos;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 
  
uniform Material material;

struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Light light;

void main()
{
    float ambientStrength = 0.1;
    // vec3 ambient = lightColor * material.ambient;
    // vec3 ambient = vec3(0.1) * material.ambient;
    vec3 ambient  = light.ambient * material.ambient;

    // vec3 ambient = light.ambient;


    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    // vec3 diffuse = lightColor * (diff * material.diffuse);
    vec3 diffuse  = light.diffuse * (diff * material.diffuse);

    // vec3 diffuse  = light.diffuse * diff;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess * 128.0f);
    // vec3 specular = lightColor * (spec * material.specular);
    vec3 specular = light.specular * (spec * material.specular);

    float distance    = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
            light.quadratic * (distance * distance));

    ambient  *= attenuation; 
    diffuse  *= attenuation;
    specular *= attenuation;

    // vec4 texColor = texture(rubixTexture, texCoord);
    
    // vec3 result = (ambient * material.ambient) + (diffuse * material.diffuse) + specular;
    // vec3 result = (ambient + diffuse) * texColor.rgb + specular;
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0f);
    // FragColor = mix(texture(rubixTexture, texCoord), vec4(result, 1.0f), 0.2);
}

