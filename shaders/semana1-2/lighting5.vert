#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

uniform vec4 lightPosition;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

uniform mat4 viewMatrixInverse;


out vec3 Ne;	//eye space
out vec3 Ve;
out vec3 Le;

out vec3 Nw;	//world
out vec3 Vw;
out vec3 Lw;



void main()
{
	//eye space
    vec3 P = (modelViewMatrix * vec4(vertex.xyz, 1.0)).xyz;
    Ne = normalMatrix * normal;
	Ve = -P;
	Le = (lightPosition.xyz-P);

	//world
	Nw = normal;
	Vw = (viewMatrixInverse*vec4(0,0,0,1)).xyz - vertex.xyz;
	Lw = (viewMatrixInverse*lightPosition).xyz - vertex.xyz;
	


    gl_Position = modelViewProjectionMatrix * vec4(vertex, 1.0);
}

//cambiar p, n, light position, v (mult por invers)
