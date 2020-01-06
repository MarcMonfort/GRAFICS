#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;


uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

vec4 RED=vec4(1,0,0,1);
vec4 YELLOW=vec4(1,1,0,1);
vec4 GREEN=vec4(0,1,0,1);
vec4 CYAN=vec4(0,1,1,1);
vec4 BLUE=vec4(0,0,1,1);

void main() {
  	gl_Position = modelViewProjectionMatrix*vec4(vertex, 1);
  	float y=2*((gl_Position.y/gl_Position.w)+1.0);	// gl_position.y/gl_position.w puede ir de -1 a 1. el .w es el tamaño maximo del viewport (?) max 2(-1 -> 1) -> 2* 2 = 4

	if (y<0) frontColor=RED;
	else if (y<1) frontColor=mix(RED, YELLOW, fract(y));
	else if (y<2) frontColor=mix(YELLOW, GREEN, fract(y));
	else if (y<3) frontColor=mix(GREEN, CYAN, fract(y));
	else if (y<4) frontColor=mix(CYAN, BLUE, fract(y));
	else frontColor=BLUE;
}
