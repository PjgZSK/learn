#version 330 core
out vec4 fragColor;

in vec3 ourColor;
in vec2 texCoord;

uniform sampler2D texturel;
uniform sampler2D texture2;
uniform float percent;

void main()
{
	fragColor = mix(texture(texturel, texCoord), texture(texture2, vec2(1.0 - texCoord.x, texCoord.y)), percent);
}