#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

const vec4 GREY=vec4(vec3(0.8), 1);
const vec4 BLACK=vec4(vec3(0), 1);
const vec4 RED=vec4(vec3(1,0,0), 1);
const vec4 WHITE=vec4(vec3(1), 1);


uniform float n = 1;


void main()
{
    float d=length(vec2(vtexCoord.x-0.5, vtexCoord.y-0.5));
    fragColor=vec4(1.0, vec2(step(0.2, d)), 1.0);
}





