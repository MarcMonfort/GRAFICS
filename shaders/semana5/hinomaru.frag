#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec2 vtexCoord;

void main()
{

	vec4 color;
	float d = length(vec2(vtexCoord.x-0.5,vtexCoord.y-0.5));	
	color = vec4(1,vec2(smoothstep(0.2,0.25,d)),1);
	//color = vec4(1.0, vec2(step(0.2, d)), 1.0);	//sin smooth

	//forma simple
	//if (d < 0.2) color = vec4(1,0,0,1);
	//else color = vec4(1,1,1,1);

	
    fragColor = color;
}
