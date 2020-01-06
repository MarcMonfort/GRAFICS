#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;


uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform float time;

void main()
{
    vec3 N = normalize(normalMatrix * normal);
    frontColor = vec4(color,1.0);// * N.z;
	
	float a = (vertex.y-0.5)*sin(time);	
	//if (vertex.y < 0.5) a = 0;	//mas costoso, pero va bien
	mat3 rotate = mat3(vec3(1,0,0),vec3(0,cos(a),sin(a)),vec3(0,-sin(a),cos(a)));
	mat4 transl = mat4(vec4(1,0,0,0),vec4(0,1,0,0),vec4(0,0,1,0),vec4(0,-1,0,1));

	
	vec4 V = vec4(vertex,1);
	if (vertex.y >= 0.5) {	//mas eficiente que con el primer if

		//V = transl*V;
		V.y -= 1;

		V = vec4(rotate*V.xyz,1);

		//V = inverse(transl)*V;
		V.y += 1;
	}


    gl_Position = modelViewProjectionMatrix * vec4(V.xyz, 1.0);
}
