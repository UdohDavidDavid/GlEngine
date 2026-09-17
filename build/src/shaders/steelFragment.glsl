#version 330 core
out vec4 FragColor;

in vec2 texCoord;
uniform sampler2D steelTexture;


in vec3 Normal;
in vec3 FragPos;  


uniform vec3 viewPos;


struct Material {
    // sampler2D texture_ambience;
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;

    sampler2D texture_diffuse2;
    sampler2D texture_specular2;
    // sampler2D emission;
    float     shininess;
}; 

uniform Material material;

struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
//
uniform DirLight dirLight;
//
// struct SpotLight {
//     vec3 position;
//     vec3 direction;
//     float innerCutOff;
//     float outerCutOff;
//
//     vec3 ambient;
//     vec3 diffuse;
//     vec3 specular;
//
// };
// uniform SpotLight spotLight;
//
struct PointLight {    
    vec3 position;

    float constant;
    float linear;
    float quadratic;  

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
#define NR_POINT_LIGHTS 4
// uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform PointLight pointLight;
//
//
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
// vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos);


float near = 30.0; 
float far  = 100.0; 
  
float LinearizeDepth(float depth) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));	
}

void main()
{
    // properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    // phase 1: Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    // phase 2: Point lights
    // vec3 result = vec3(0.0f);
    // for(int i = 0; i < NR_POINT_LIGHTS; i++)
    //     result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);    
    result += CalcPointLight(pointLight, norm, FragPos, viewDir);    
    // // phase 3: Spot light
    // result += CalcSpotLight(spotLight, norm, FragPos);    
    
    FragColor = vec4(result, 1.0);
    // FragColor = vec4(vec3(gl_FragCoord.z), 1.0);
    // float depth = LinearizeDepth(gl_FragCoord.z) / far; // divide by far for demonstration
    // FragColor = vec4(vec3(depth), 1.0);
}


vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess * 128);
    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse1, texCoord));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse1, texCoord));
    // vec3 specular = light.specular * spec * vec3(texture(material.texture_specular, texCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, texCoord));
    return (ambient + diffuse + specular);
}


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess * 128.0f);
    // attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
  			     light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse1, texCoord));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse1, texCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, texCoord));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}
//
// vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos)
// {
//     // vec3 lightDir = light.position - FragPos;
//     vec3 lightDir = normalize(light.position - FragPos);
//     float theta     = dot(lightDir, normalize(-light.direction));
//     float epsilon   = light.innerCutOff - light.outerCutOff;
//     float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
//
//     vec3 ambient  = light.ambient * vec3(texture(material.diffuse, texCoord));
//
//     vec3 norm = normalize(Normal);
//     float diff = max(dot(norm, lightDir), 0.0);
//     vec3 diffuse  = light.diffuse * (diff * vec3(texture(material.diffuse, texCoord)));
//
//     vec3 viewDir = normalize(viewPos - FragPos);
//     vec3 reflectDir = reflect(-lightDir, norm);
//     float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess * 128.0f);
//     vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoord));
//
//     // we'll leave ambient unaffected so we always have a little light.
//     diffuse  *= intensity;
//     specular *= intensity;
//     vec3 result = ambient + diffuse + specular;
//     return result;
// }
