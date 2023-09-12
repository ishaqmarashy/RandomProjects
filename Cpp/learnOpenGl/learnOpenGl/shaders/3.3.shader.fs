#version 330 core
#extension GL_ARB_separate_shader_objects : enable

out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = mix(texture(texture1, TexCoord/2), texture(texture2, vec2(1.0 - TexCoord.x, TexCoord.y)), 0.2)*vec4(ourColor,1);
}