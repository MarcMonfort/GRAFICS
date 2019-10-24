#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform mat4 modelViewMatrixInverse;

const float pi = 3.141592;
uniform float amp = 0.5;
uniform float freq = 0.25;
uniform float time;

void main()
{
	//vec3 vertObj = (modelViewMatrixInverse * vec4(vertex, 1.0)).xyz;

	float a = amp * sin(time  + vertex.y);
	mat3 Rx = mat3(vec3(1,0,0), vec3(0,cos(a),sin(a)), vec3(0,-sin(a),cos(a)));
    vec3 N = normalize(normalMatrix * normal);
    frontColor = vec4(color,1.0) * N.z;
	vec3 V = Rx*vertex;
    gl_Position = modelViewProjectionMatrix * vec4(V, 1.0);
}
