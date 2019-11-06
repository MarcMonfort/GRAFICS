#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec2 vtexCoord;

uniform bool classic = false;

uniform float pi = 3.141592;



void main()
{

	vec3 color;	

	vec2 u = vec2(vtexCoord.s-0.5, vtexCoord.t-0.5);

	float d = length(u);

	if (classic) color = vec3(1,vec2(step(0.2,d)));

	else {
		
		float a  = atan(u.t,u.s);
		if (mod(a/(pi/16)+0.5,2) < 1) color = vec3(1,0,0);
		else color  = vec3(1,vec2(step(0.2,d)));

	}

    fragColor = vec4(color,1);
}
