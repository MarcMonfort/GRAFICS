#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec2 vtexCoord;

uniform float time;

void main()
{
	fragColor = vec4(1.0,1.0,0.0,1.0);
	float a = sin(vtexCoord.s*30)/2 + .5;	//red
	float b = sin(vtexCoord.t*30)/2 + .5;		//green
	//float b = sin(vtexCoord.t*5);		//green
	fragColor = vec4(a,b,1.0,0.0);

    //fragColor = frontColor;
}
