#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec2 vtexCoord;

uniform sampler2D noise0;
uniform sampler2D rock1;
uniform sampler2D grass2;




void main() {
	float f=texture(noise0, vtexCoord).r;

	fragColor = mix(texture(rock1, vtexCoord), texture(grass2, vtexCoord), f); 
	//fragColor = vec4(f);



}

