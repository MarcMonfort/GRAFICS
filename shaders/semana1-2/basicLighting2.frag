#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec3 N;

void main()
{
	vec3 N = normalize(N);	//hace interpolacion, hay que volver a normalizar!
    fragColor = frontColor * N.z;
}
