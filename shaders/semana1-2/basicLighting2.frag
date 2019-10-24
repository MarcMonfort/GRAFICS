#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec3 N;

void main()
{
	vec3 N = normalize(N);
    fragColor = frontColor * N.z;
}
