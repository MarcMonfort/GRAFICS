#version 330 core

in vec4 gfrontColor;
out vec4 fragColor;

in vec2 gtexCoord;

uniform sampler2D sampler;

void main()
{
    //fragColor = gfrontColor;

	vec4 color = texture(sampler, gtexCoord);
	if (fragColor.a != 1) discard;
	else fragColor = color;
}
