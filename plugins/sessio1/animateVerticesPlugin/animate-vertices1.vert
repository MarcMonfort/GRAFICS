#version 330 core

layout (location = 0) in vec3 vertex;	//object space
layout (location = 1) in vec3 normal;	//object space
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform float time;
uniform float amplitude = 0.1;
uniform float freq = 1;

const float PI = 3.141592;

void main()
{
	vec3 V = vertex + normal*abs(amplitude*sin(2*PI*freq*time+0));	//abs evita ir hacia atras
    	vec3 N = normalize(normalMatrix * normal);
	frontColor=vec4(vec3(N.z),1);

	//frontColor=vec4(1,0,1,0);

    gl_Position = modelViewProjectionMatrix * vec4(V, 1.0);	//esto transforma el vertex de object a clip
}
