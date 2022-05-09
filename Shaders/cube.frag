#version 330 core
out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

in vec3 Normal;
in vec3 FragPos;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(Normal);
    // 这个向量应该是逆光路的向量，这样就方便计算向量的点乘了。
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float specularStrength = 0.5;
    // 这个向量应该是逆视线的向量，这样就方便计算向量的点乘了。
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); // 32为反光度。
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular)  * objectColor;

    FragColor = vec4(result, 1.0);
}
